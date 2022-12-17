
namespace mtu {
class Vec {
public:
    virtual void ShowItem();
    
protected:
    Vec(int dim);
    ~Vec();
    const int mDim;
    float& Data(unsigned int idx);

private:
    float* mData;
};
    
class Vec3 : public Vec {
public:
    Vec3();
    Vec3(float item);
    Vec3(float x, float y, float z);
    float Dot(Vec3 vec);
    void ShowItem() override { Vec::ShowItem(); }
    
    float& x() { return Data(0); }
    float& y() { return Data(1); }
    float& z() { return Data(2); }
    float& operator[] (int idx) { return Data(idx); }
    void operator = (const float* init_array);
    void operator = (Vec3 vec);

};

class Vec4 : public Vec {
public:
    Vec4();
    Vec4(float item);
    Vec4(float x, float y, float z, float w);
    float Dot(Vec4 vec);
    
    float& x() { return Data(0); }
    float& y() { return Data(1); }
    float& z() { return Data(2); }
    float& w() { return Data(3); }
    float& operator[] (int idx) { return Data(idx); }
    void operator = (const float* init_array);
    void operator = (Vec4 vec);

};


class Mat4 {
public:
    Mat4();
    void Inverse();

    class Vec4& operator[] (int idx);
    
    
private:
    class Vec4* mData;
};

}