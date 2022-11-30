#include "Cuboid.hpp"
#include "Camera.hpp"

#include <gl/glut.h>
#include <windows.h>
#include <iostream>

using namespace std;

void render();
void idle();

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

int last_mx = 0;
int last_my = 0;
int last_mx_change = 0;
int last_my_change = 0;

float dt;
float old_t;

Camera camera = Camera(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 10.0f);

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

	cuboid.render();

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
		camera.y_rot += camera.rot_speed * dt;
	} else if (mx_change - last_mx_change < 0) {
		camera.y_rot -= camera.rot_speed * dt;
	}

	if (my_change - last_my_change > 0) {
		camera.x_rot += camera.rot_speed * dt;
	} else if (my_change - last_my_change < 0) {
		camera.x_rot -= camera.rot_speed * dt;
	}

	//Keyboard management
	if (GetAsyncKeyState('W')) {
		camera.y -= camera.mov_speed * dt;
	}

	if (GetAsyncKeyState('S')) {
		camera.y += camera.mov_speed * dt;
	}

	if (GetAsyncKeyState('A')) {
		camera.x += camera.mov_speed * dt;
	}

	if (GetAsyncKeyState('D')) {
		camera.x -= camera.mov_speed * dt;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(camera.x_rot, 1.0f, 0.0f, 0.0f);
	glRotatef(camera.y_rot, 0.0f, 1.0f, 0.0f);
	glTranslatef(camera.x, camera.y, camera.z);

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