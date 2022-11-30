#include "Cuboid.hpp"

#include <gl/glut.h>

void Cuboid::render() {

	float wh = w / 2;
	float hh = h / 2;
	float dh = d / 2;

	glBegin(GL_POLYGON);
	glColor3f(faceColors[0], faceColors[1], faceColors[2]);
	glVertex3f(x - wh, y + hh, z - dh);
	glVertex3f(x - wh, y - hh, z - dh);
	glVertex3f(x + wh, y - hh, z - dh);
	glVertex3f(x + wh, y + hh, z - dh);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[3], faceColors[4], faceColors[5]);
	glVertex3f(x - wh, y + hh, z + dh);
	glVertex3f(x - wh, y - hh, z + dh);
	glVertex3f(x + wh, y - hh, z + dh);
	glVertex3f(x + wh, y + hh, z + dh);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[6], faceColors[7], faceColors[8]);
	glVertex3f(x - wh, y - hh, z - dh);
	glVertex3f(x - wh, y - hh, z + dh);
	glVertex3f(x + wh, y - hh, z + dh);
	glVertex3f(x + wh, y - hh, z - dh);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[9], faceColors[10], faceColors[11]);
	glVertex3f(x - wh, y + hh, z - dh);
	glVertex3f(x - wh, y + hh, z + dh);
	glVertex3f(x + wh, y + hh, z + dh);
	glVertex3f(x + wh, y + hh, z - dh);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[12], faceColors[13], faceColors[14]);
	glVertex3f(x - wh, y + hh, z + dh);
	glVertex3f(x - wh, y - hh, z + dh);
	glVertex3f(x - wh, y - hh, z - dh);
	glVertex3f(x - wh, y + hh, z - dh);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[15], faceColors[16], faceColors[17]);
	glVertex3f(x + wh, y + hh, z + dh);
	glVertex3f(x + wh, y - hh, z + dh);
	glVertex3f(x + wh, y - hh, z - dh);
	glVertex3f(x + wh, y + hh, z - dh);
	glEnd();
}

void Cuboid::logic(float deltaTime) {

}