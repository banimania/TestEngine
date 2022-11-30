#pragma once

#include "GameObject.hpp"

class Cuboid : public GameObject {
public:
    float faceColors[18];
    void render() override;
    void logic(float deltaTime) override;
    Cuboid(float x, float y, float z, float w, float h, float d, float faceColors[18]) : GameObject(x, y, z, w, d, h, 0.0f, 0.0f, 0.0f) {
        for (int i = 0; i < sizeof(this->faceColors) / sizeof(int); i++) {
            this->faceColors[i] = faceColors[i];
        }
    };
};