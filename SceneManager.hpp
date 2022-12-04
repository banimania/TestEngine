#pragma once

#include "Scene.hpp"

#include <vector>

class SceneManager {
    public:
        std::vector<Scene*> scenePtrs;
        Scene* getScenePtrFromIndex(int index);
        SceneManager() {
            this->scenePtrs = {};
        }
};