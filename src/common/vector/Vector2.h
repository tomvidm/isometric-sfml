#ifndef VECTOR2_H
#define VECTOR2_H

#include "SFML/Graphics.hpp"

namespace common { namespace vector {
    template <typename T>
    class Vector2
    {
    public:
        T x, y;

        Vector2();
        Vector2(T x, T y);

        void operator += (const Vector2& other);
        void operator -= (const Vector2& other);
        void operator *= (const float factor);

        Vector2<T> operator + (const Vector2& other) const;
        Vector2<T> operator - (const Vector2& other) const;
        Vector2<T> operator * (const float factor) const;

        sf::Vector2<T> to_sfmlVector() const;
    };

    template <typename T>
    float dot(const Vector2<T>& v1, const Vector2<T>& v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }

    template <typename T>
    Vector2<T>::Vector2()
    : x(T(0)), y(T(0))
    {
        ;
    }

    template <typename T>
    Vector2<T>::Vector2(T x, T y)
    : x(x), y(y)
    {
        ;
    }

    template <typename T>
    void Vector2<T>::operator += (const Vector2& other)
    {
        x += other.x;
        y += other.y;
    }

    template <typename T>
    void Vector2<T>::operator -= (const Vector2& other)
    {
        x -= other.x;
        y -= other.y;
    }

    template <typename T>
    void Vector2<T>::operator *= (const float factor)
    {
        x *= factor;
        y *= factor;
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator + (const Vector2& other) const
    {
        return Vector2<T>(x + other.x, y + other.y);
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator - (const Vector2& other) const
    {
        return Vector2<T>(x - other.x, y - other.y);
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator * (const float factor) const
    {
        return Vector2<T>(x * factor, y * factor);
    }

    template <typename T>
    sf::Vector2<T> Vector2<T>::to_sfmlVector() const
    {
        return sf::Vector2<T>(x, y);
    }
}}

#endif