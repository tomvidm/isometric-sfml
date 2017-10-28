#ifndef SPACE_H
#define SPACE_H

/*
    This header defines a set of vectors and methods for fast
    conversion from world space to screen space and other.

*/

#include "common/vector/Vector2f.h"

namespace modules {
    // Constexpr allows us to make these vectors be set at compile time
    // using methods, so this header can also be used to set angles for
    // transformations that will be held constant throughout the game.
    constexpr common::vector::Vector2f xToScreenSpace(1.f, 0.f, 0.f);
    constexpr common::vector::Vector2f yToScreenSpace(0.f, 1.f, 0.f);
    constexpr common::vector::Vector2f zToScreenSpace(0.f, 0.f, 1.f);
}

#endif