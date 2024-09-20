cmake_minimum_required(VERSION 3.10)

# Project name
project(ChProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(ch02_2 ch02_2.cpp globals.cpp)