cmake_minimum_required(VERSION 3.15)
project(Optikos)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-lGL -lGLEW -lglfw")

add_executable(Optikos src/main.cpp src/optikos/application/application.cpp src/optikos/application/application.hpp src/optikos/common.hpp)