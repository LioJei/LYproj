#指定CMAKE版本
cmake_minimum_required(VERSION 3.15)
#指定程序名
project(PadDemo)
#指定c++版本
set(CMAKE_CXX_STANDARD 14)
#加载源文件
aux_source_directory(. src)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src src)
#加载头文件
include_directories(.)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
include_directories("/usr/local/include/log4cplus")
#加载需要的库
link_directories("/usr/local/lib")
#生成可执行程序
add_executable(${PROJECT_NAME} ${src})
#链接需要的库
target_link_libraries(${PROJECT_NAME} log4cplus)
