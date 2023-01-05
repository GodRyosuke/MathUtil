#include "MathUtil.hpp"
#include <cassert>
#include <stdio.h>
// #include <iostream>

namespace {
    float fabs(float data)
    {
        return (data > 0) ? data : -data; 
    }

    void swap(float& a, float& b) 
    {
        float temp = a;
        a = b;
        b = temp;
    }
}

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


// Matrix
Mat::Mat(int dim)
    :mDim(dim)
{
}

// Mat4
Mat4::Mat4()
    :Mat(4)
{
    mData = new Vec4[mDim];
    for (int i = 0; i < mDim; i++) {
        Vec4 v;
        mData[i] = v;
    }
}

Mat4::Mat4(Vec4 v1, Vec4 v2, Vec4 v3, Vec4 v4)
    :Mat(4)
{
    mData[0] = v1;
    mData[1] = v2;
    mData[2] = v3;
    mData[3] = v4;
}

void Mat4::Inverse()
{
    int* indxc = new int[mDim];
    int* indxr = new int[mDim];
    int* ipiv = new int[mDim];
    
    // std::vector<double> indxc(3, 0);
    // std::vector<double> indxr(3, 0);
    // std::vector<double> ipiv(3, 0);
    int i, icol, irow, j, k, l, ll;
    float big, dum, pivinv, temp;
    for (j = 0; j < mDim; j++) ipiv[j] = 0;
    for (i = 0; i < mDim; i++) {
        big = 0.0;
        for (j = 0; j < mDim; j++)
            if (ipiv[j] != 1)
                for (k = 0; k < mDim; k++) {
                    if (ipiv[k] == 0) {
                        if (fabs(mData[j][k]) >= big) {
                            big = fabs(mData[j][k]);
                            irow = j;
                            icol = k;
                        }
                    }
                }
        ++(ipiv[icol]);
        if (irow != icol) {
            for (l = 0; l < mDim; l++) swap(mData[irow][l], mData[icol][l]);
        }
        indxr[i] = irow;
        indxc[i] = icol;
        if (mData[icol][icol] == 0.0) printf("error: This is Singular Matrix\n");
        pivinv = 1.0 / mData[icol][icol];
        mData[icol][icol] = 1.0;
        for (l = 0; l < mDim; l++) mData[icol][l] *= pivinv;
        for (ll = 0; ll < mDim; ll++)
            if (ll != icol) {
                dum = mData[ll][icol];
                mData[ll][icol] = 0.0;
                for (l = 0; l < mDim; l++) mData[ll][l] -= mData[icol][l] * dum;
            }
    }
    for (l = mDim - 1; l >= 0; l--) {
        if (indxr[l] != indxc[l])
            for (k = 0; k < mDim; k++)
                swap(mData[k][indxr[l]], mData[k][indxc[l]]);
    }
}
