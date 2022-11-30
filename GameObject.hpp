#pragma once

class GameObject {
    public:
        float x, y, z, w, h, d, r, g, b;
        virtual void render() = 0;
        virtual void logic(float deltaTime) = 0;
        GameObject(float x, float y, float z, float w, float h, float d, float r, float g, float b);
};