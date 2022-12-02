#pragma once

#define _USE_MATH_DEFINES
#include <GL/glut.h>
#include <cmath>
#include <windows.h>
#include <cstdio>

class Camera {
	public:
		float camX, camY, camZ, camYaw, camPitch, moveVel, mouseVel;
		void lockCam();
		void moveCam(float dist, float dir);
		void moveCamUp(float dist, float dir);
		void camControl(float deltaTime, int mX, int mY);
		void updateCam();
		Camera(float camX, float camY, float camZ, float camYaw, float camPitch, float moveVel, float mouseVel) {
			this->camX = camX;
			this->camY = camY;
			this->camZ = camZ;
			this->camYaw = camYaw;
			this->camPitch = camPitch;
			this->moveVel = moveVel;
			this->mouseVel = mouseVel;
		};

		Camera() {
			this->camX = 0.0f;
			this->camY = 1.0f;
			this->camZ = 0.0f;
			this->camYaw = 0.0f;
			this->camPitch = 0.0f;
			this->moveVel = 1.0f;
			this->mouseVel = 3.0f;
		}
};

