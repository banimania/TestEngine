#pragma once

#include "GameObject.hpp"

#define M_PI 3.141592
#include <GL/glut.h>
#include <cmath>
#include <windows.h>
#include <cstdio>
#include <vector>
#include <iostream>

bool inBetween(float q1, float q2, float q3);

class Player {
	public:
		float camX, camY, camZ, camYaw, camPitch, moveVel, mouseVel;
		bool hasMovedCam, isOnGround;
		void lockCam();
		void moveCam(float dist, float dir, std::vector<GameObject*> gameObjectPtrs);
		//void moveCamUp(float dist, float dir);
		void camControl(float deltaTime, int mX, int mY, int ww, int wh, std::vector<GameObject*> gameObjectPtrs);
		void updateCam();
		bool collidesWithRectPrism(float cx, float cy, float cz, Vec3 p1, Vec3 p7);
		Player(float camX, float camY, float camZ, float camYaw, float camPitch, float moveVel, float mouseVel) {
			this->camX = camX;
			this->camY = camY;
			this->camZ = camZ;
			this->camYaw = camYaw;
			this->camPitch = camPitch;
			this->moveVel = moveVel;
			this->mouseVel = mouseVel;
			this->hasMovedCam = false;
			this->isOnGround = true;
		};

		Player() {
			this->camX = -99.0f;
			this->camY = -0.25f;
			this->camZ = -99.0f;
			this->camYaw = 0.0f;
			this->camPitch = 0.0f;
			this->moveVel = 1.0f;
			this->mouseVel = 3.0f;
			this->hasMovedCam = false;
			this->isOnGround = true;
		}
};

