#include "GameObject.hpp"

GameObject::GameObject(float x, float y, float z, float w, float h, float d, float r, float g, float b) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
	this->h = h;
	this->d = d;
	this->r = r;
	this->g = g;
	this->b = b;

	this->p1 = Vec3(x, y, z);
	this->p2 = Vec3(x, y, z + d);
	this->p3 = Vec3(x + w, y, z + d);
	this->p4 = Vec3(x + w, y, z);
	this->p5 = Vec3(x, y + h, z);
	this->p6 = Vec3(x, y + h, z + d);
	this->p7 = Vec3(x + w, y + h, z + d);
	this->p8 = Vec3(x + w, y + h, z);
}