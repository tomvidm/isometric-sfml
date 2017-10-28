#ifndef JOINT_H
#define JOINT_H

#include "common/vector/Vector.h"

namespace common { namespace physics {
    class Joint
    {
    public:
        Joint(vector::Vector2f pos, float mass = 1.f);
        void addForce(vector::Vector2f a, float dt);
        void updatePosition(float dt);
        inline void setMass(float m) { mass = m; }

        inline vector::Vector2f getPosition() const { return position; }
        inline vector::Vector2f getVelocity() const { return velocity; }
        inline float getMass() const { return mass; }
    private:
        float mass;

        vector::Vector2f position;
        vector::Vector2f velocity;
    };
}}

#endif