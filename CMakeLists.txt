cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project ("MathUtil" VERSION 1.2)

option("ENABLE_LIBRARY_TESTING" OFF)
add_subdirectory ("lib")

if ("${ENABLE_LIBRARY_TESTING}")
    add_subdirectory ("main")
endif()
