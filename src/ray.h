#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
    public:
        Ray() {}
        Ray(const Point3& origin, const Vec3& direction) : orig(origin), direc(direction) {}

        const Point3& origin() const {return orig;}
        const Vec3& direction() const {return direc;}

        Point3 at(double t) const {return orig + t*direc;}

    private:
        Point3 orig;
        Vec3 direc;
};

#endif