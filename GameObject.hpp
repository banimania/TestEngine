#pragma once

#include "Vec3.hpp"

class GameObject {
    public:
        Vec3 p1, p2, p3, p4, p5, p6, p7, p8;
        float x, y, z, w, h, d, r, g, b;
        virtual void render() = 0;
        virtual void logic(float deltaTime) = 0;
        GameObject(float x, float y, float z, float w, float h, float d, float r, float g, float b);
};