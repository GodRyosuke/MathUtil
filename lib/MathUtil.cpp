#include "MathUtil.hpp"
#include <cassert>
#include <iostream>

using namespace mtu;

Vec::Vec(int dim)
    :mDim(dim)
{
    mData = new float[dim];
}

Vec::~Vec()
{
    delete mData;
}

void Vec::ShowItem()
{
    for (int i = 0; i < mDim; i++) {
        printf("%f ", mData[i]);
    }
    printf("\n");
}

float& Vec::Data(unsigned int idx)
{
    assert(idx < mDim);
    return mData[idx];
}

Vec3::Vec3() 
    :Vec(3)
{
    for (int i = 0; i < mDim; i++) {
        Data(i) = 0.f;
    }
}

Vec3::Vec3(float data)
    :Vec(3)
{
    for (int i = 0; i < mDim; i++) {
        Data(i) = data;
    }
}

Vec3::Vec3(float x, float y, float z)
    :Vec(3)
{
    Data(0) = x;
    Data(1) = y;
    Data(2) = z;
}

float Vec3::Dot(Vec3 vec)
{
    float dot = 0;
    for (int i = 0; i < mDim; i++) {
        dot += Data(i) * vec[i];
    }
    return dot;
}

void Vec3::operator = (const float* initArray)
{
    for (int i = 0; i < mDim; i++) {
        Data(i) = initArray[i];
    }
}

void Vec3::operator = (Vec3 vec)
{
    for (int i = 0; i < 3; i++) {
        Data(i) = vec[i];
    }
}


// Vec4
Vec4::Vec4() 
    :Vec(4)
{
    for (int i = 0; i < mDim; i++) {
        Data(i) = 0.f;
    }
}

Vec4::Vec4(float data)
    :Vec(4)
{
    for (int i = 0; i < mDim; i++) {
        Data(i) = data;
    }
}

Vec4::Vec4(float x, float y, float z, float w)
    :Vec(4)
{
    Data(0) = x;
    Data(1) = y;
    Data(2) = z;
    Data(3) = w;
}

float Vec4::Dot(Vec4 vec)
{
    float dot = 0;
    for (int i = 0; i < mDim; i++) {
        dot += Data(i) * vec[i];
    }
    return dot;
}

void Vec4::operator = (const float* initArray)
{
    for (int i = 0; i < mDim; i++) {
        Data(i) = initArray[i];
    }
}

void Vec4::operator = (Vec4 vec)
{
    for (int i = 0; i < mDim; i++) {
        Data(i) = vec[i];
    }
}


// Mat4
Mat4::Mat4()
{
    mData = new Vec4[4];
    for (int i = 0; i < 4; i++) {
        mData[i] = Vec4();
    }
}

