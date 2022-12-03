#include "Player.hpp"
#include "Vec3.hpp"

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
	float newCamY = camY;
	float newCamZ = camZ- cos(rad) * dist;
	bool willCollideOnX = false;
	bool willCollideOnZ = false;

	float h = 0.15f;

	for (int q = 0; q < gameObjectPtrs.size(); q++) {
		float x = gameObjectPtrs[q]->x;
		float y = gameObjectPtrs[q]->y;
		float z = gameObjectPtrs[q]->z;
		Vec3 p1 = gameObjectPtrs[q]->p1;
		Vec3 p7 = gameObjectPtrs[q]->p7;
		p1 = Vec3(p1.x - h, p1.y, p1.z - h);
		p7 = Vec3(p7.x + h, p7.y, p7.z + h);
		Vec3 c = Vec3(newCamX, newCamY, newCamZ);

		if (inBetween(p1.x, p7.x, c.x) && inBetween(p1.y, p7.y, c.y) && inBetween(p1.z, p7.z, camZ)) {
			willCollideOnX = true;
		}

		if (inBetween(p1.x, p7.x, camX) && inBetween(p1.y, p7.y, c.y) && inBetween(p1.z, p7.z, c.z)) {
			willCollideOnZ = true;
		}

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

bool inBetween(float q1, float q2, float q3) {
	return q3 >= q1 && q3 <= q2 ? true : false;
}