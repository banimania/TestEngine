#include "Cuboid.hpp"
#include "Player.hpp"

#include <gl/glut.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <vector>

void render();
void idle();
void mouseMove(int xx, int yy);
void changeSize(int w, int h);

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

float dt, old_t;

GLdouble fov = 60;
GLdouble aspect = 1;
GLdouble nearVal = 0.1;
GLdouble farVal = 1000;

Player player = Player();

int mx, my;

std::vector<GameObject*> gameObjectPtrs;

//Test
float cubeColors[18] = {
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};

int main(int argc, char* argv[]) {
	//TEST
	gameObjectPtrs.emplace_back(new Cuboid(-93.0f, -0.50f, -96.0f, 1.0f, 0.5f, 0.5f, cubeColors));
	gameObjectPtrs.emplace_back(new Cuboid(-100.0f, -2.0f, -100.0f, 200.0f, 200.0f, 1.0f, 1.0f, 1.0f, 1.0f));

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
	
	player.camControl(dt, mx, my, WINDOW_WIDTH, WINDOW_HEIGHT, gameObjectPtrs);
	player.updateCam();
	
	for (int i = 0; i < gameObjectPtrs.size(); i++) {
		gameObjectPtrs[i]->logic(dt);
		gameObjectPtrs[i]->render();
	}

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
	if (!player.hasMovedCam) {
		player.hasMovedCam = true;
	}
}

void changeSize(int w, int h) {
	if (h == 0) {
		h = 1;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(fov, aspect, nearVal, farVal);

	glMatrixMode(GL_MODELVIEW);
}