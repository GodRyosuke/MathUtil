set(SRC_FILES
    Matrix.cpp
    Integration.cpp
)

add_library(math_util ${SRC_FILES})
target_include_directories(math_util PUBLIC ${PROJECT_SOURCE_DIR}/include)