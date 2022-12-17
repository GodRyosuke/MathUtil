
namespace mtu {
class Vec3 {
public:
    Vec3();
    Vec3(float item);
    Vec3(float x, float y, float z);
    float Dot(Vec3 vec);
    
    float& x() { return mData[0]; }
    float& y() { return mData[1]; }
    float& z() { return mData[2]; }
    float& operator[] (int idx) { return mData[idx]; }
    void operator = (const float* init_array);
    void operator = (Vec3 vec);

private:
    float* mData;
};

class Mat4 {
public:
    Mat4();
    void Inverse();

    class Vec3& operator[] (int idx);
    
    
private:
    class Vec3* mData;
};

}