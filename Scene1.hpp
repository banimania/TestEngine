#pragma once

#include "Scene.hpp"

class Scene1 : public Scene {
	Scene1(Player p, std::vector<GameObject*> gameObjectPtrs) : Scene(1, p, gameObjectPtrs) {};
};