cmake_minimum_required(VERSION 3.16)

project(MyProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fsanitize=address,undefined")

# Tell compiler where headers are
include_directories(include)

add_executable(main
    src/main.cpp
)