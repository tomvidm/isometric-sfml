#ifndef PARTICLEPOOL_H
#define PARTICLEPOOL_H

namespace modules { namespace particles {

    class ParticleEmitter;

    struct Particle
    {
        int i;
    }

    class ParticlePool
    {
    public:

        std::vector<sf::Vertex*> request(unsigned int numParticles);
        void cleanup(ParticleEmitter* emitterPtr);
    private:
        const unsigned int maxParticles;

        sf::VertexArray vertices;
    }
}}

#endif