#include "Camera.hpp"

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