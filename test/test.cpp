#include <iostream>
#include <cassert>
// #ifndef WANDER_CMAKE_ARG
//     #define WANDER_CMAKE_ARG "<Not Set>"
// #endif

// #if !defined(WANDER_CMAKE_ARG2)
//     #define WANDER_CMAKE_ARG2 "<Not Set 2>"
// #endif
// #define WANDER_CMAKE_ARG @WANDER_CMAKE_ARG@

#include "MathUtil.hpp"

namespace {
void TestEpsilone(double value1, double value2) {
    assert((value1 - value2) < 0.00001);
}
}

int main(int argc, char** argv)
{
    // std::cout << "WANDER_CMAKE_ARG=" WANDER_CMAKE_ARG << std::endl;
    // std::cout << "WANDER_CMAKE_ARG2=" WANDER_CMAKE_ARG2 << std::endl;
    
    mtu::Vec3 testVec;
    testVec = mtu::Vec3(1.3f, 3.4f, 4.4f);
    {
        float x = testVec.x();
        testVec.x() = 3.4f;
    }
    testVec.ShowItem();
    
    
    mtu::Vec3 testVector = mtu::Vec3(5.6);
    TestEpsilone(testVector.x(), 5.6);
    TestEpsilone(testVector.z(), 5.6);
    
    std::cout << "hello\n";
    for (int i = 0; i < 10; i++) {
        printf("numa: %d\n", i);
    }


    return 0;
}