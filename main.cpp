#include <iostream>
#include <Eigen/Core>
#include <Eigen/LU>
#include "OBJLoader.h"
#include <GLUT/glut.h>

static int win_w = 400 ,win_h = 400;
static Object obj("../cube.obj");

void display() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, win_w, win_h);
	gluPerspective(50.0,
					static_cast<double>(win_w)/static_cast<double>(win_h),
					0.1, 100.0);
	gluLookAt(0,0,-10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(1,1,1,1);
  	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  	glEnable(GL_DEPTH_TEST);
    glColor3f(0,0,0);
    obj.Render();
	glutSwapBuffers();
}

void resize(int w,int h) {
	win_w = w;
	win_h = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, win_w, win_h);
	gluPerspective(50.0,
					static_cast<double>(win_w)/static_cast<double>(win_h),
					0.1, 100.0);
	gluLookAt(0,0,-10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

int main(int argc,char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(win_w, win_h);
	glutCreateWindow("Home Work 3");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMainLoop();

	return 0;
}