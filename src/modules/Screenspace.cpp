#include "Screenspace.h"

namespace modules {
    common::vector::Vector2f toScreenSpace(common::vector::Vector3f vector3)
    {
        return common::vector::Vector2f(vector3.x * xToScreenSpace,
                                        vector3.y * yToScreenSpace,
                                        vector3.z * zToScreenSpace);
    }
}