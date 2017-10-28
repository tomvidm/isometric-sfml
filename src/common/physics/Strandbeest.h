#ifndef STRANDBEEST_H
#define STRANDBEEST_H

#include <vector>

#include "SFML/Graphics.hpp"

#include "common/physics/Joint.h"
#include "common/physics/Leg.h"

namespace common { namespace physics {
    class Strandbeest : public sf::Drawable
    {
    public:
        Strandbeest();
        void addJoint(vector::Vector2f vec);
        void connect(int v1, int v2);
        void updateVertexArray();
        void updateBufferStep(float dt);
        void updatePostBufferStep(float dt);
        Leg* getLeg(unsigned int i);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
        inline Joint* getFirstJoint(const Leg& leg) { return &joints[leg.getFirst()]; }
        inline Joint* getSecondJoint(const Leg& leg) { return &joints[leg.getSecond()]; }
    private:
        inline vector::Vector2f getFirstPosition(const Leg& leg) { return getFirstJoint(leg)->getPosition(); }
        inline vector::Vector2f getSecondPosition(const Leg& leg) { return getSecondJoint(leg)->getPosition(); }
        inline vector::Vector2f getFirstPosition(const int i) { return getFirstJoint(legs[i])->getPosition(); }
        inline vector::Vector2f getSecondPosition(const int i) { return getSecondJoint(legs[i])->getPosition(); }

        std::vector<Joint> joints;
        std::vector<Leg> legs;

        sf::VertexArray varr;

    };
}}

#endif