#include "Camera.hpp"

void Camera::lockCam(void) {
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

void Camera::moveCam(float dist, float dir) {
	float rad = (camYaw + dir) * M_PI / 180.0;

	camX -= sin(rad) * dist;
	camZ -= cos(rad) * dist;
}

void Camera::moveCamUp(float dist, float dir) {
	float rad = (camPitch + dir) * M_PI / 180.0;

	camY += sin(rad) * dist;
}

void Camera::camControl(float deltaTime, int mX, int mY, int ww, int wh) {
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
			moveCam(mv, 0.0);
		}
		moveCamUp(mv, 0.0);
	}

	if (GetAsyncKeyState('S')) {
		if (camPitch != 90.0 && camPitch != -90.0) {
			moveCam(mv, 180.0);
		}
		moveCamUp(mv, 180.0);
	}

	if (GetAsyncKeyState('A')) {
		moveCam(mv, 90.0);
	}

	if (GetAsyncKeyState('D')) {
		moveCam(mv, 270.0);
	}

	glRotatef(-camPitch, 1.0, 0.0, 0.0);
	glRotatef(-camYaw, 0.0, 1.0, 0.0);
}

void Camera::updateCam(void) {
	glTranslatef(-camX, -camY, -camZ);
}