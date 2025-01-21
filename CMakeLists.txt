cmake_minimum_required(VERSION 3.20)

project(MathLibrary VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(MathLibrary src/main.cpp src/Vector.hpp src/Vector.tpp)