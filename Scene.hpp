#pragma once

#include "GameObject.hpp"
#include "Player.hpp"

#include <vector>

class Scene {
    public:
        int index;
        Player p;
        std::vector<GameObject*> gameObjectPtrs;
        virtual void renderScene(float deltaTick, float mx, float my, int WINDOW_WIDTH, int WINDOW_HEIGHT) {
            p.camControl(deltaTick, mx, my, WINDOW_WIDTH, WINDOW_HEIGHT, gameObjectPtrs);
            p.updateCam();

            for (int i = 0; i < gameObjectPtrs.size(); i++) {
                gameObjectPtrs[i]->logic(deltaTick);
                gameObjectPtrs[i]->render();
            }
        };
        Scene(int index, Player p, std::vector<GameObject*> gameObjectPtrs) {
            this->index = index;
            this->p = p;
            this->gameObjectPtrs = gameObjectPtrs;
        }
};