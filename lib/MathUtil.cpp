#include "MathUtil.hpp"

using namespace mtu;

Vec3::Vec3() 
{
    mData = new float[3];
    
    for (int i = 0; i < 3; i++) {
        mData[i] = 0.f;
    }
}

Vec3::Vec3(float data)
{
    mData = new float[3];

    for (int i = 0; i < 3; i++) {
        mData[i] = data;
    }
}

Vec3::Vec3(float x, float y, float z)
{
    mData[0] = x;
    mData[1] = y;
    mData[2] = z;
}

float Vec3::Dot(Vec3 vec)
{
    float dot = 0;
    for (int i = 0; i < 3; i++) {
        dot += mData[i] * vec[i];
    }
    return dot;
}

void Vec3::operator = (const float* initArray)
{
    for (int i = 0; i < 3; i++) {
        mData[i] = initArray[i];
    }
}

void Vec3::operator = (Vec3 vec)
{
    for (int i = 0; i < 3; i++) {
        mData[i] = vec[i];
    }
}



