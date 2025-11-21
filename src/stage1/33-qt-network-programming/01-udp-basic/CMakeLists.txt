cmake_minimum_required(VERSION 3.20)

project(UdpDemo VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 查找 Qt6
find_package(Qt6 REQUIRED COMPONENTS Core Network)

# 启用 Qt 自动处理
set(CMAKE_AUTOMOC ON)

# 源文件
set(SOURCES
    main.cpp
    UdpSender.h
    UdpReceiver.h
)

# 创建可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# 链接 Qt 库
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Network)

