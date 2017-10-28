#ifndef LEG_H
#define LEG_H

namespace common { namespace physics {
    class Leg
    {
    public:
        Leg(int v1, int v2, float k = 10.f);
        inline void setEquilibriumLength(float r) { equilibriumLength = r; }
        inline int getFirst() const { return vectorIndices[0]; }
        inline int getSecond() const { return vectorIndices[1]; }
        inline float getEquilibriumLength() const { return equilibriumLength; }
        inline float getSpringConstant() const { return springConstant; }
        inline void setOscillationAmp(float amp) { oscillation_amplitude = amp; }
        inline void setOscillationFreq(float freq) { oscillation_frequency = freq; }
    private:
        int vectorIndices[2];
        float equilibriumLength;
        float springConstant;

        float oscillation_amplitude;
        float oscillation_frequency;
    };
}}

#endif