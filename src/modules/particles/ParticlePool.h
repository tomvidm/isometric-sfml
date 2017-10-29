#ifndef PARTICLEPOOL_H
#define PARTICLEPOOL_H

namespace modules { namespace particles {

    class ParticleEmitter;

    struct Particle
    {
        int i;
    }

    typedef std::vector<Chunk> ChunkVector;

    template <typename T>
    struct Chunk
    {
        T* ptr_;
        unsigned int chunkSize;
    }

    template <unsigned int N>
    class ParticlePool
    {
    public:
        ParticlePool();
        ChunkVector request(unsigned int numParticles);
        void cleanup(ParticleEmitter* emitterPtr);
    private:


        const unsigned int maxObjects = N;
        sf::VertexArray vertices;
    };

    ParticlePool::ParticlePool()
    {
        vertices.resize(maxObjects);
    }
}}

#endif