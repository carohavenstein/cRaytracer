#pragma once

#include <cmath>
#include <iostream>

class Vec3 {
    public:
    double x, y, z;

    Vec3()
        : x(0), y(0), z(0)
    {}

    Vec3(double x_, double y_, double z_)
        : x{x_}, y{y_}, z{z_}
    {}

    // const means it doesnt change original instance of Vec3
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3& operator+=(const Vec3 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    Vec3& operator*=(double t) {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }

    Vec3& operator/=(double t) {
        return *this *= 1/t;
    }

    //modulus
    double length() const {
        return std::sqrt(length_squared());
    }

    double length_squared() const {
        return x*x + y*y + z*z;
    }

};

using Point3 = Vec3;
//using RGB = Vec3;

// Vector Utility Functions

inline std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
    return out << v.x << ' ' << v.y << ' ' << v.z;
}

inline Vec3 operator+(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x + v.x,
                u.y + v.y,
                u.z + v.z);
}

inline Vec3 operator-(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x - v.x, 
                u.y - v.y, 
                u.z - v.z);
}

inline Vec3 operator*(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.x * v.x,
                u.y * v.y,
                u.z * v.z);
}

inline Vec3 operator*(double t, const Vec3 &v) {
    return Vec3(t*v.x, t*v.y, t*v.z);
}

inline Vec3 operator*(const Vec3 &v, double t) {
    return t * v;
}

inline Vec3 operator/(Vec3 v, double t) {
    return (1/t) * v;
}

inline double dot(const Vec3 &u, const Vec3 &v) {
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

inline Vec3 cross(const Vec3 &u, const Vec3 &v) {
    return Vec3(u.y * v.z - u.z * v.y,
                u.z * v.x - u.x * v.z,
                u.x * v.y - u.y * v.x);
}

inline Vec3 unit_vector(Vec3 v) {
    return v / v.length();
}
