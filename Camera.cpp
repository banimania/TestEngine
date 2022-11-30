#include "Camera.hpp"

#include <gl/glut.h>
#include <windows.h>

int last_mx = 0;
int last_my = 0;
int last_mx_change = 0;
int last_my_change = 0;

Camera::Camera(float x, float y, float z, float x_rot, float y_rot, float z_rot, float mov_speed, float rot_speed) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->x_rot = x_rot;
	this->y_rot = y_rot;
	this->z_rot = z_rot;
	this->mov_speed = mov_speed;
	this->rot_speed = rot_speed;
}

void Camera::handleCameraMovement(float dt, float windowWidth, float windowHeight) {
	int wx = glutGet((GLenum)GLUT_WINDOW_X);
	int wy = glutGet((GLenum)GLUT_WINDOW_Y);
	POINT p;
	GetCursorPos(&p);
	int mouse_x = -(wx - p.x);
	int mouse_y = -(wy - p.y);

	int mx_change = last_mx - mouse_x + (windowWidth / 2);
	int my_change = last_my - mouse_y + (windowHeight / 2);

	if (mx_change - last_mx_change > 0) {
		y_rot += rot_speed * dt;
	}
	else if (mx_change - last_mx_change < 0) {
		y_rot -= rot_speed * dt;
	}

	if (my_change - last_my_change > 0) {
		x_rot += rot_speed * dt;
	}
	else if (my_change - last_my_change < 0) {
		x_rot -= rot_speed * dt;
	}

	if (GetAsyncKeyState('W')) {
		y -= mov_speed * dt;
	}

	if (GetAsyncKeyState('S')) {
		y += mov_speed * dt;
	}

	if (GetAsyncKeyState('A')) {
		x += mov_speed * dt;
	}

	if (GetAsyncKeyState('D')) {
		x -= mov_speed * dt;
	}

	last_mx_change = mx_change;
	last_my_change = my_change;
}