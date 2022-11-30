#include "Cuboid.hpp"

#include <gl/glut.h>
#include <windows.h>
#include <iostream>

using namespace std;

void render();
void idle();

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

double x = 0.0f;
double y = 0.0f;
double z = 0.0f;
double movement_speed = 1.0f;

int last_mx = 0;
int last_my = 0;
int last_mx_change = 0;
int last_my_change = 0;
double x_rotation = 0.0f;
double y_rotation = 0.0f;
double rotation_speed = 100.0f;

float dt;
float old_t;

//Test
float cubeColors[18] = {
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f,
	0.0f, 1.0f, 1.0f,
	1.0f, 0.0f, 1.0f
};
Cuboid cuboid = Cuboid(-0.5f, -0.5f, -0.5f, 1.0f, 0.5f, 0.5f, cubeColors);

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("TEST ENGINE");

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(render);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}

void render() {

	//Mouse management
	int wx = glutGet((GLenum)GLUT_WINDOW_X);
	int wy = glutGet((GLenum)GLUT_WINDOW_Y);
	POINT p;
	GetCursorPos(&p);
	int mouse_x = -(wx - p.x);
	int mouse_y = -(wy - p.y);

	int mx_change = last_mx - mouse_x + (WINDOW_WIDTH / 2);
	int my_change = last_my - mouse_y + (WINDOW_HEIGHT / 2);

	if (mx_change - last_mx_change > 0) {
		y_rotation += rotation_speed * dt;
	} else if (mx_change - last_mx_change < 0) {
		y_rotation -= rotation_speed * dt;
	}

	if (my_change - last_my_change > 0) {
		x_rotation += rotation_speed * dt;
	} else if (my_change - last_my_change < 0) {
		x_rotation -= rotation_speed * dt;
	}

	//Keyboard management
	if (GetAsyncKeyState('W')) {
		y -= movement_speed * dt;
	}

	if (GetAsyncKeyState('S')) {
		y += movement_speed * dt;
	}

	if (GetAsyncKeyState('A')) {
		x += movement_speed * dt;
	}

	if (GetAsyncKeyState('D')) {
		x -= movement_speed * dt;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(x_rotation, 1.0f, 0.0f, 0.0f);
	glRotatef(y_rotation, 0.0f, 1.0f, 0.0f);
	glTranslatef(x, y, z);

	//Test
	cuboid.render();

	glFlush();
	glutSwapBuffers();

	last_mx_change = mx_change;
	last_my_change = my_change;
}

void idle() {
	int t = glutGet(GLUT_ELAPSED_TIME);
	dt = (t - old_t) / 1000.0f;
	old_t = t;
	glutPostRedisplay();
}