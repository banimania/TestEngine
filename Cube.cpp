#include "Cube.hpp"

#include <gl/glut.h>

void Cube::render() {

	float a = size / 2;

	glBegin(GL_POLYGON);
	glColor3f(faceColors[0], faceColors[1], faceColors[2]);
	glVertex3f(x-a, y+a, z-a);
	glVertex3f(x-a, y-a, z-a);
	glVertex3f(x+a, y-a, z-a);
	glVertex3f(x+a, y+a, z-a);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[3], faceColors[4], faceColors[5]);
	glVertex3f(x-a, y+a, z+a);
	glVertex3f(x-a, y-a, z+a);
	glVertex3f(x+a, y-a, z+a);
	glVertex3f(x+a, y+a, z+a);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[6], faceColors[7], faceColors[8]);
	glVertex3f(x-a, y-a, z-a);
	glVertex3f(x-a, y-a, z+a);
	glVertex3f(x+a, y-a, z+a);
	glVertex3f(x+a, y-a, z-a);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[9], faceColors[10], faceColors[11]);
	glVertex3f(x-a, y+a, z-a);
	glVertex3f(x-a, y+a, z+a);
	glVertex3f(x+a, y+a, z+a);
	glVertex3f(x+a, y+a, z-a);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[12], faceColors[13], faceColors[14]);
	glVertex3f(x-a, y+a, z+a);
	glVertex3f(x-a, y-a, z+a);
	glVertex3f(x-a, y-a, z-a);
	glVertex3f(x-a, y+a, z-a);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[15], faceColors[16], faceColors[17]);
	glVertex3f(x+a, y+a, z+a);
	glVertex3f(x+a, y-a, z+a);
	glVertex3f(x+a, y-a, z-a);
	glVertex3f(x+a, y+a, z-a);
	glEnd();
}

void Cube::logic(float deltaTime) {

}