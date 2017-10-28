#ifndef VECTOR3_H
#define VECTOR3_H

namespace common { namespace vector {
    template <typename T>
    class Vector3
    {
    public:
        T x, y, z;

        Vector3();
        Vector3(T x, T y, T z);

        void operator += (const Vector3& other);
        void operator -= (const Vector3& other);
        void operator *= (const float factor);

        Vector3<T> operator + (const Vector3& other) const;
        Vector3<T> operator - (const Vector3& other) const;
        Vector3<T> operator * (const float factor) const;
    };

    template <typename T>
    float dot(const Vector3<T>& v1, const Vector3<T>& v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    template <typename T>
    Vector3<T>::Vector3()
    : x(T(0)), y(T(0)), z(T(0))
    {
        ;
    }
    

    template <typename T>
    Vector3<T>::Vector3(T x, T y, T z)
    : x(x), y(y), z(z)
    {
        ;
    }

    template <typename T>
    void Vector3<T>::operator += (const Vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
    }

    template <typename T>
    void Vector3<T>::operator -= (const Vector3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
    }

    template <typename T>
    void Vector3<T>::operator *= (const float factor)
    {
        x *= factor;
        y *= factor;
        z *= factor;
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator + (const Vector3& other) const
    {
        return Vector3<T>(x + other.x, y + other.y, z + other.z);
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator - (const Vector3& other) const
    {
        return Vector3<T>(x - other.x, y - other.y, z - other.z);
    }

    template <typename T>
    Vector3<T> Vector3<T>::operator * (const float factor) const
    {
        return Vector3<T>(x * factor, y * factor, z * factor);
    }
}}

#endif