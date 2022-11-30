#include "Cuboid.hpp"
#include "Camera.hpp"

#include <gl/glut.h>
#include <windows.h>

void render();
void idle();

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

float dt;
float old_t;

Camera camera = Camera(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 100.0f);

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

	camera.handleCameraMovement(dt, WINDOW_WIDTH, WINDOW_HEIGHT);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(camera.x_rot, 1.0f, 0.0f, 0.0f);
	glRotatef(camera.y_rot, 0.0f, 1.0f, 0.0f);
	glTranslatef(camera.x, camera.y, camera.z);

	//Test
	cuboid.render();

	glFlush();
	glutSwapBuffers();
}

void idle() {
	int t = glutGet(GLUT_ELAPSED_TIME);
	dt = (t - old_t) / 1000.0f;
	old_t = t;
	glutPostRedisplay();
}