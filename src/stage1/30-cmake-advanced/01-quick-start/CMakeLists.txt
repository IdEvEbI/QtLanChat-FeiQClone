cmake_minimum_required(VERSION 3.20)

project(MyQtApp VERSION 1.0.0 LANGUAGES CXX)

# 基本配置
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 生成 compile_commands.json（用于 IntelliSense/clangd）
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 查找 Qt6（自动查找库的位置）
# 注意：如果系统安装的 Qt6 版本低于 6.12，可以移除版本要求或降低版本要求
# 例如：find_package(Qt6 REQUIRED COMPONENTS Core Network)  # 使用任何可用版本
# 或者：find_package(Qt6 6.9 REQUIRED COMPONENTS Core Network)  # 要求最低 6.9
find_package(Qt6 REQUIRED COMPONENTS Core Network)

# Qt 自动处理（自动处理 MOC、UIC、RCC 工具）
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 源文件
set(SOURCES
    src/main.cpp
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接 Qt6 模块（自动处理头文件路径和库文件路径）
target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Network
)

