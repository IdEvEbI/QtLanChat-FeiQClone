#!/bin/bash
# 智能构建脚本：自动检测 CMakeLists.txt 并使用 CMake 或普通编译

set +f

# 获取工作区根目录（假设脚本在 .vscode 目录下）
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

FILE_DIR="$1"
if [ -z "$FILE_DIR" ]; then
    echo "[ERROR] File directory not provided"
    exit 1
fi

# 向上查找 CMakeLists.txt
CMAKEDIR="$FILE_DIR"
while [ ! -f "$CMAKEDIR/CMakeLists.txt" ] && [ "$CMAKEDIR" != "/" ]; do
    CMAKEDIR="$(dirname "$CMAKEDIR")"
done

if [ -f "$CMAKEDIR/CMakeLists.txt" ]; then
    echo "[CMake] Found CMakeLists.txt: $CMAKEDIR/CMakeLists.txt"
    echo "[CMake] Configuring..."
    
    if ! cmake -S "$CMAKEDIR" -B "$CMAKEDIR/build" -DCMAKE_BUILD_TYPE=Debug; then
        echo "[ERROR] CMake configuration failed"
        exit 1
    fi
    
    echo "[CMake] Building..."
    if ! cmake --build "$CMAKEDIR/build"; then
        echo "[ERROR] CMake build failed"
        exit 1
    fi
    
    # 提取项目名称（支持带引号和不带引号的项目名）
    PROJNAME=$(grep -E '^project\(' "$CMAKEDIR/CMakeLists.txt" | head -1 | sed -E 's/^project\([[:space:]]*["'\'']?([^"'\'' ]+).*/\1/')
    
    if [ -z "$PROJNAME" ]; then
        echo "[ERROR] Cannot extract project name from CMakeLists.txt"
        exit 1
    fi
    
    # 创建符号链接（支持 Unix 和 Windows 可执行文件）
    EXECUTABLE=""
    SYMLINK=""
    if [ -f "$CMAKEDIR/build/$PROJNAME" ]; then
        EXECUTABLE="$PROJNAME"
        SYMLINK="cmake-app"
    elif [ -f "$CMAKEDIR/build/$PROJNAME.exe" ]; then
        EXECUTABLE="$PROJNAME.exe"
        SYMLINK="cmake-app.exe"
    else
        echo "[ERROR] Executable not found: $CMAKEDIR/build/$PROJNAME (or $PROJNAME.exe)"
        exit 1
    fi
    
    # 保存可执行文件名并创建符号链接
    echo "$EXECUTABLE" > "$CMAKEDIR/build/.executable_name"
    ln -sf "$EXECUTABLE" "$CMAKEDIR/build/$SYMLINK"
    # 创建符号链接到工作区根目录，供 launch.json 使用
    # 使用绝对路径确保符号链接正确
    CMAKE_BUILD_DIR_ABS="$(cd "$CMAKEDIR/build" && pwd)"
    mkdir -p "$WORKSPACE_ROOT/.vscode"
    ln -sfn "$CMAKE_BUILD_DIR_ABS" "$WORKSPACE_ROOT/.vscode/.cmake_build_dir"
    echo "[SUCCESS] Executable: $EXECUTABLE"
    echo "[SUCCESS] Build directory: $CMAKE_BUILD_DIR_ABS"
else
    echo "[INFO] CMakeLists.txt not found (searched up to: $CMAKEDIR), using direct compilation..."
    if ! clang++ -std=c++17 -g -Wall "$FILE_DIR"/*.cpp -o "$FILE_DIR/program"; then
        echo "[ERROR] Compilation failed"
        exit 1
    fi
    echo "[SUCCESS] Compiled: $FILE_DIR/program"
fi
