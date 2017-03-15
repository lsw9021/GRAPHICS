#include <iostream>
#include <map>
#include 
#include <GL/glut.h>
static bool isClickOn = false;
static bool isPickingOn = false;
static int win_w = 1260 ,win_h = 760;
static int mouse_state = GLUT_UP;
class Sphere;
static std::map<std::string, Sphere*> sphere = {
	std::make_pair("Sphere_1",new Sphere(0.5,Eigen::Vector3d(0,0,2),Eigen::Vector3d(0.7,0,0))),
	std::make_pair("Sphere_2",new Sphere(0.5,Eigen::Vector3d(0,0,4),Eigen::Vector3d(0,0.7,0))),
	std::make_pair("Sphere_3",new Sphere(0.5,Eigen::Vector3d(0,0,6),Eigen::Vector3d(0,0,0.7)))
}; 

class Sphere
{
private:
	double r;
	Eigen::Vector3d P;
	Eigen::Vector3d color;
public:
	Sphere(double rad,const Eigen::Vector3d& center,const Eigen::Vector3d& _color)
		:r(rad),P(center),color(_color)
	{

	}
	~Sphere();

	void Draw()
	{
			
	}
};

void mouseClick(int _button, int _state, int _x, int _y) {
	mouse_state = _state;
}

void mouseDrag(int _x, int _y) {
}

void display() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(mPersp,
					static_cast<double>(win_w)/static_cast<double>(win_h),
					0.1, 100.0);
	gluLookAt(0,10,-10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void resize(int w,int h) {
	win_w = w;
	win_h = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, win_w, win_h);
	gluPerspective(mPersp,
					static_cast<double>(win_w)/static_cast<double>(win_h),
					0.1, 100.0);
	gluLookAt(0,10,-10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc,char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(win_w, win_h);
	glutCreateWindow("Home Work 1");
	glutDisplayFunc(display);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseDrag);
	glutReshapeFunc(resize);
	glutMainLoop();

	return 0;
}