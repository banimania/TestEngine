#include "Cuboid.hpp"
#include "Vec3.hpp"

#include <gl/glut.h>
#include <iostream>

void Cuboid::render() {

	glBegin(GL_POLYGON);
	glColor3f(faceColors[0], faceColors[1], faceColors[2]);
	glVertex3f(p2.x, p2.y, p2.z);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p4.x, p4.y, p4.z);
	glVertex3f(p3.x, p3.y, p3.z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[3], faceColors[4], faceColors[5]);
	glVertex3f(p6.x, p6.y, p6.z);
	glVertex3f(p5.x, p5.y, p5.z);
	glVertex3f(p8.x, p8.y, p8.z);
	glVertex3f(p7.x, p7.y, p7.z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[6], faceColors[7], faceColors[8]);
	glVertex3f(p8.x, p8.y, p8.z);
	glVertex3f(p4.x, p4.y, p4.z);
	glVertex3f(p3.x, p3.y, p3.z);
	glVertex3f(p7.x, p7.y, p7.z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[9], faceColors[10], faceColors[11]);
	glVertex3f(p5.x, p5.y, p5.z);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p2.x, p2.y, p2.z);
	glVertex3f(p6.x, p6.y, p6.z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[12], faceColors[13], faceColors[14]);
	glVertex3f(p6.x, p6.y, p6.z);
	glVertex3f(p2.x, p2.y, p2.z);
	glVertex3f(p3.x, p3.y, p3.z);
	glVertex3f(p7.x, p7.y, p7.z);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(faceColors[15], faceColors[16], faceColors[17]);
	glVertex3f(p5.x, p5.y, p5.z);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p4.x, p4.y, p4.z);
	glVertex3f(p8.x, p8.y, p8.z);
	glEnd();

	//Draw points
	/*Vec3 points[8]{p1, p2, p3, p4, p5, p6, p7, p8};
	glPointSize(5.0f);
	
	for (int i = 0; i < sizeof(points) / sizeof(Vec3); i++) {
		glBegin(GL_POINTS);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(points[i].x, points[i].y, points[i].z);
		glEnd();

		
	}
	
	glPointSize(0.0f);*/
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(p1.x, p1.y, p1.z);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(p7.x, p7.y, p7.z);
	glEnd();
	glPointSize(1.0f);

	//std::cout << "P1 -- " << p1.getCoords() << std::endl;
	//std::cout << "P7 -- " << p7.getCoords() << std::endl;
}

void Cuboid::logic(float deltaTime) {

}