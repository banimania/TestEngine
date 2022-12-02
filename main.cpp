#include "Cuboid.hpp"
#include "Camera.hpp"
#include "Floor.hpp"

#include <gl/glut.h>
#include <windows.h>
#include <iostream>

void render();
void idle();
void mouseMove(int xx, int yy);
void changeSize(int w, int h);

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

float dt, old_t;

Camera camera = Camera();

int mx, my;

//Test
float cubeColors[18] = {
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};
Cuboid cuboid = Cuboid(-0.5f, 0.5f, -0.5f, 1.0f, 0.5f, 0.5f, cubeColors);

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("TEST ENGINE");

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(render);
	glutIdleFunc(idle);
	glutReshapeFunc(changeSize);
	glutPassiveMotionFunc(mouseMove);

	glutMainLoop();
	return 0;
}

void render() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	camera.camControl(dt, mx, my);
	camera.updateCam();

	//Test
	cuboid.render();

	/*glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);*/
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void idle() {
	if (GetAsyncKeyState(VK_ESCAPE)) {
		glFlush();
		exit(0);
	}

	int t = glutGet(GLUT_ELAPSED_TIME);
	dt = (t - old_t) / 1000.0f;
	old_t = t;
	glutPostRedisplay();
}

void mouseMove(int xx, int yy) {
	mx = xx;
	my = yy;
}

void changeSize(int w, int h) {
	if (h == 0) {
		h = 1;
	}

	float ratio = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
}