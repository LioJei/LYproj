cmake_minimum_required(VERSION 3.15)
project(PadDemo)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(. src)
include_directories(.)

add_executable(${PROJECT_NAME} ${src})
