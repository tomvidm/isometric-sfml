#include "Strandbeest.h"

namespace common { namespace physics {
    Strandbeest::Strandbeest()
    {
        varr.setPrimitiveType(sf::PrimitiveType::Lines);
    }

    void Strandbeest::connect(int v1, int v2)
    {
        float eqLength = common::vector::magnitude(joints[v1].getPosition() - joints[v2].getPosition());
        legs.push_back(Leg(v1, v2));
        legs[legs.size() - 1].setEquilibriumLength(eqLength);

        varr.append(sf::Vertex());
        varr.append(sf::Vertex());
    }

    void Strandbeest::updateVertexArray()
    {
        for (unsigned int i = 0; i < legs.size(); i++)
        {
            varr[2*i] = sf::Vertex(getFirstPosition(i).to_sfmlVector());
            varr[2*i + 1] = sf::Vertex(getSecondPosition(i).to_sfmlVector());
        }
    }

    void Strandbeest::addJoint(vector::Vector2f vec)
    {
        joints.push_back(vec);
    }

    Leg* Strandbeest::getLeg(unsigned int i)
    {
        return &legs[i];
    }

    void Strandbeest::updateBufferStep(float dt)
    {
        for (auto& leg : legs)
        {
            vector::Vector2f dr = getFirstPosition(leg) - getSecondPosition(leg);
            float equilibrium_overshoot = vector::magnitude(dr) - leg.getEquilibriumLength();
            vector::Vector2f acceleration = vector::normalize(dr) * leg.getSpringConstant() * equilibrium_overshoot;
            getFirstJoint(leg)->addForce(acceleration*(-1.f) + vector::Vector2f(0.f, 10.f), dt);
            getSecondJoint(leg)->addForce(acceleration = vector::Vector2f(0.f, 10.f), dt);
        }
    }

    void Strandbeest::updatePostBufferStep(float dt)
    {
        for (auto& joint : joints)
        {
            joint.updatePosition(dt);
        }
    }

    void Strandbeest::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(varr);
    }
}}