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
	float newCamZ = camZ- cos(rad) * dist;
	bool willCollideOnX = false;
	bool willCollideOnZ = false;

	for (int q = 0; q < gameObjectPtrs.size(); q++) {
		float x = gameObjectPtrs[q]->x;
		float y = gameObjectPtrs[q]->y;
		float z = gameObjectPtrs[q]->z;
		float w = gameObjectPtrs[q]->w;
		float h = gameObjectPtrs[q]->h;
		float d = gameObjectPtrs[q]->d;
		Vec3 p1 = gameObjectPtrs[q]->p1;
		Vec3 p2 = gameObjectPtrs[q]->p2;
		Vec3 p4 = gameObjectPtrs[q]->p4;
		Vec3 p5 = gameObjectPtrs[q]->p5;

		Vec3 c = Vec3(camX, camY, camZ);

		Vec3 i = p2.substract(p1);
		Vec3 j = p4.substract(p1);
		Vec3 k = p5.substract(p1);
		Vec3 v = c.substract(p1);

		if (0 < v.dotProduct(i) < i.dotProduct(i) &&
			0 < v.dotProduct(j) < j.dotProduct(j) &&
			0 < v.dotProduct(k) < k.dotProduct(k)) {
			willCollideOnX = true;
			willCollideOnZ = true;
		}

		//std::cout << "X: " << x << " X2: " << x2 << " Y: " << y << " Y2: " << y2 << " Z: " << z << " Z2: " << z2 << std::endl;
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