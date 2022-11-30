#pragma once

#include "GameObject.hpp"

class Cube : public GameObject {
    public:
        float faceColors[18];
        void render() override;
        void logic(float deltaTime) override;
        Cube(float x, float y, float z, float size, float faceColors[18]) : GameObject(x, y, z, size, 0.0f, 0.0f, 0.0f) {
            for (int i = 0; i < sizeof(this->faceColors) / sizeof(int); i++) {
                this->faceColors[i] = faceColors[i];
            }
        };
};