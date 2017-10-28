#include "common/physics/Leg.h"

namespace common { namespace physics {
    Leg::Leg(int v1, int v2, float k)
    : springConstant(k)
    {
        vectorIndices[0] = v1;
        vectorIndices[1] = v2;
    }
}}