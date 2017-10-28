#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>

#include "common/vector/Vector2.h"
#include "common/vector/Vector3.h"

namespace common { namespace vector {
    typedef float Radians;

    typedef Vector2<int> Vector2i;
    typedef Vector3<int> Vector3i;

    typedef Vector2<float> Vector2f;
    typedef Vector3<float> Vector3f;

    float magnitude(const Vector2f& vector);
    float magnitude(const Vector3f& vector);

    Vector2f normalize(const Vector2f& vector);
    Vector3f normalize(const Vector3f& vector);

    Vector3f cross(const Vector3f& v1, const Vector3f& v2);
    Vector3f normal(const Vector3f& v1, const Vector3f& v2);
}}

#endif