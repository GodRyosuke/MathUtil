cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project ("MathUtil" VERSION 1.2)

add_subdirectory ("lib")
add_subdirectory ("main")
# add_executable (output "main/main.cpp")