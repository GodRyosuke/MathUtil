
namespace mtu {
class Vec {
protected:
    Vec(int dim);
    ~Vec();
    virtual void ShowItem();
    float& Data(unsigned int idx);
    const int mDim;

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


class Mat {
protected:
    Mat(int dim); 
    const int mDim;
    virtual void Inverse() {}
};

class Mat4 : public Mat {
public:
    Mat4();
    Mat4(Vec4 v1, Vec4 v2, Vec4 v3, Vec4 v4);
    void Inverse() override;

    class Vec4& operator[] (int idx);
    
    
private:
    class Vec4* mData;
};

}