#include "Player.hpp"

void Player::lockCam(void) {
	if (camPitch > 90.0) {
		camPitch = 90.0;
	}

	if (camPitch < -90.0) {
		camPitch = -90.0;
	}

	if (camYaw > 360.0) {
		camYaw -= 360;
	}
}

void Player::moveCam(float dist, float dir, std::vector<GameObject*> gameObjectPtrs) {
	float rad = (camYaw + dir) * M_PI / 180.0;

	float newCamX = camX - sin(rad) * dist;
	float newCamZ = camZ- cos(rad) * dist;
	bool willCollideOnX = false;
	bool willCollideOnZ = false;

	for (int i = 0; i < gameObjectPtrs.size(); i++) {
		float x = gameObjectPtrs[i]->x;
		float y = gameObjectPtrs[i]->y;
		float z = gameObjectPtrs[i]->z;
		float w = gameObjectPtrs[i]->w;
		float h = gameObjectPtrs[i]->h;
		float d = gameObjectPtrs[i]->d;
	}

	if (!willCollideOnX) {
		camX = newCamX;
	}

	if (!willCollideOnZ) {
		camZ = newCamZ;
	}
}

/*void Player::moveCamUp(float dist, float dir) {
	float rad = (camPitch + dir) * M_PI / 180.0;

	camY += sin(rad) * dist;
}*/

void Player::camControl(float deltaTime, int mX, int mY, int ww, int wh, std::vector<GameObject*> gameObjectPtrs) {
	int midX = ww / 2;
	int midY = wh / 2;

	glutSetCursor(GLUT_CURSOR_NONE);

	if (hasMovedCam) {
		camYaw += mouseVel * (midX - mX) * deltaTime;
		camPitch += mouseVel * (midY - mY) * deltaTime;
	}

	lockCam();

	glutWarpPointer(midX, midY);

	float mv = moveVel * deltaTime;
	if (GetAsyncKeyState('W')) {
		if (camPitch != 90.0 && camPitch != -90.0) {
			moveCam(mv, 0.0, gameObjectPtrs);
		}
		//moveCamUp(mv, 0.0);
	}

	if (GetAsyncKeyState('S')) {
		if (camPitch != 90.0 && camPitch != -90.0) {
			moveCam(mv, 180.0, gameObjectPtrs);
		}
		//moveCamUp(mv, 180.0);
	}

	if (GetAsyncKeyState('A')) {
		moveCam(mv, 90.0, gameObjectPtrs);
	}

	if (GetAsyncKeyState('D')) {
		moveCam(mv, 270.0, gameObjectPtrs);
	}

	glRotatef(-camPitch, 1.0, 0.0, 0.0);
	glRotatef(-camYaw, 0.0, 1.0, 0.0);
}

void Player::updateCam(void) {
	glTranslatef(-camX, -camY, -camZ);
}