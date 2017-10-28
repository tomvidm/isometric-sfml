#include "common/physics/Joint.h"

namespace common { namespace physics {
    Joint::Joint(vector::Vector2f pos, float mass)
    : mass(mass), position(pos)
    {
        mass = 1.f;
        velocity = vector::Vector2f();
    }

    void Joint::addForce(vector::Vector2f a, float dt)
    {
        velocity += (a*dt)*(1.f/mass);
    }

    void Joint::updatePosition(float dt)
    {
        position += velocity*dt;
    }
}}