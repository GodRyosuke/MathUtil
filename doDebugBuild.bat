@REM mkdir build
@REM cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles"
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G "Ninja"
cmake --build build