#include "SceneManager.hpp"

Scene* SceneManager::getScenePtrFromIndex(int index) {
	for (Scene* scenePtr : scenePtrs) {
		if (scenePtr->index == index) {
			return scenePtr;
		}
	}
	return nullptr;
}