# set (CMAKE_CXX_FLAGS "${CAKE_CXX_FLAGS} -DWANDER_CMAKE_ARG=\\\"YA HALLO\\\"")
# set (CMAKE_CXX_FLAGS "${CAKE_CXX_FLAGS} -DWANDER_CMAKE_ARG2=\\\"YA HALLO\\\"")

set(WANDER_CMAKE_ARG "This is Wander CMake ARG!")
message(STATUS "This is Test Wander Cmake Message")
message(STATUS "This is Test Project directory: ${PROJECT_SOURCE_DIR}")
add_executable (output "main.cpp")
target_link_libraries(output math_util)
