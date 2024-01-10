#pragma once

#include "Vec3.h"

class Ray {
    public:
    Ray() {}

    Ray(const Point3 origin_, const Vec3 direction_)
        : origin(origin_), direction(direction_) {}

    Point3 at(double t) const {
        return origin + t*direction;
    }

    Point3 origin;
    Vec3 direction;

};