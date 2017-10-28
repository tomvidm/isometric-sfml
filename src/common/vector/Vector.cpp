#include "Vector.h"

namespace common { namespace vector {
    float magnitude(const Vector2f& vector)
    {
        return sqrtf(vector.x * vector.x + 
                    vector.y * vector.y);
    }

    float magnitude(const Vector3f& vector)
    {
        return sqrtf(vector.x * vector.x + 
                    vector.y * vector.y +
                    vector.z * vector.z);
    }

    Vector2f normalize(const Vector2f& vector)
    {
        float r = magnitude(vector);
        return Vector2f(vector.x / r,
                        vector.y / r);
    }

    Vector3f normalize(const Vector3f& vector)
    {
        float r = magnitude(vector);
        return Vector3f(vector.x / r,
                        vector.y / r,
                        vector.z / r);
    }

    Vector3f cross(const Vector3f& v1, const Vector3f& v2)
    {
        return Vector3f(v1.y * v2.z - v1.z * v2.y,
                        v1.z * v2.x - v1.x * v2.z,
                        v1.x * v2.y - v1.y * v2.x);
    }

    Vector3f normal(const Vector3f& v1, const Vector3f& v2)
    {
        return normalize(cross(v1, v2));
    }
}}