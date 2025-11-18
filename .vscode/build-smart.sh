#!/bin/bash
# 智能构建脚本：自动检测 CMakeLists.txt 并使用 CMake 或普通编译

set +f

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
    echo "[SUCCESS] Executable: $EXECUTABLE"
else
    echo "[INFO] CMakeLists.txt not found (searched up to: $CMAKEDIR), using direct compilation..."
    if ! clang++ -std=c++17 -g -Wall "$FILE_DIR"/*.cpp -o "$FILE_DIR/program"; then
        echo "[ERROR] Compilation failed"
        exit 1
    fi
    echo "[SUCCESS] Compiled: $FILE_DIR/program"
fi
