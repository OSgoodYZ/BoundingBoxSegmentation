
#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <GL/freeglut.h>//#include <GL/freeglut.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> //for matrices
#include <glm/gtc/type_ptr.hpp>

#include <Object.h>
#include <TriangularMesh.h>
#include <ClothSimulator.h>

#pragma comment(lib, "glew32.lib")

using namespace std;  
const int width = 1024, height = 1024;

#define PI 3.1415926536f
#define EPSILON  0.0000001f

TriangularMesh* myObj = new TriangularMesh((char*)"./OBJ\\cl.obj");//			parsing
ClothSimulator cloth(myObj); //												initialize


char info[MAX_PATH]={0};

//MOUSE
int oldX=0, oldY=0; // for mouse draging
float rX=15, rY=0;  // for mouse rotation
int state =1 ;
float distanc=-50;//-23 // viewing distancance
 
// viewing
GLint viewport[4];
GLdouble MV[16];
GLdouble P[16];
glm::vec3 Up = glm::vec3(0, 1, 0), Right, viewDir;




void OnMouseDown(int button, int s, int x, int y)
{
	if (s == GLUT_DOWN) 
	{
		oldX = x; 
		oldY = y; 

		

	}	

	if(button == GLUT_MIDDLE_BUTTON)
		state = 0;
	else
		state = 1;


}

void OnMouseMove(int x, int y)
{

	if (state == 0)
		distanc *= (1 + (y - oldY) / 60.0f);
	else
	{
		rY += (x - oldX) / 5.0f;
		rX += (y - oldY) / 5.0f;

	}


	
	oldX = x; 
	oldY = y; 

	glutPostRedisplay(); 
}




void InitGL() { 

	glEnable(GL_DEPTH_TEST);

}

void OnRender() {
	size_t i = 0;



	sprintf_s(info, "Bounding Box Construction");
	glutSetWindowTitle(info);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//set viewing transformation
	glTranslatef(0, 0, distanc);
	glRotatef(rX, 1, 0, 0);
	glRotatef(rY, 0, 1, 0);

	glGetDoublev(GL_MODELVIEW_MATRIX, MV);
	viewDir.x = (float)-MV[2];
	viewDir.y = (float)-MV[6];
	viewDir.z = (float)-MV[10];
	//Right = glm::cross(viewDir, Up);
	Right.x = (float)MV[0];
	Right.y = (float)MV[4];
	Right.z = (float)MV[8];
	
	Up.x = (float)MV[1];
	Up.y = (float)MV[5];
	Up.z = (float)MV[9];



	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	//glTranslatef(0, -0.000001, 0);
	glColor3f(1, 1, 1);

	glBegin(GL_LINES);//GL_POLYGON//GL_POINTS//GL_TRIANGLES//
	for (int i = 0; i < cloth.nT; i++)
	{
		Vector3d p1 = cloth.pos[cloth.triangles[i].x];
		Vector3d p2 = cloth.pos[cloth.triangles[i].y];
		Vector3d p3 = cloth.pos[cloth.triangles[i].z];

		glVertex3d(p1.x, p1.y, p1.z);
		glVertex3d(p2.x, p2.y, p2.z);

		glVertex3d(p2.x, p2.y, p2.z);
		glVertex3d(p3.x, p3.y, p3.z);

		glVertex3d(p3.x, p3.y, p3.z);
		glVertex3d(p1.x, p1.y, p1.z);



	}
	glEnd();


	glutSwapBuffers();
}

void OnReshape(int nw, int nh) {
	glViewport(0,0,nw, nh);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80, (GLfloat)nw / (GLfloat)nh, 1.f, 200.0f);
	
	glGetIntegerv(GL_VIEWPORT, viewport); 
	glGetDoublev(GL_PROJECTION_MATRIX, P);

	glMatrixMode(GL_MODELVIEW);
}


void OnIdle() {	
	


	
	glutPostRedisplay(); 
	Sleep(5); //TODO
}



void main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("OSGOOD'S PRATICE PROJECT [Position based Dynamics]");


	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnReshape);

	glutIdleFunc(OnIdle);
	
	glutMouseFunc(OnMouseDown);
	glutMotionFunc(OnMouseMove);	


	glewInit();
	InitGL();
	
	glutMainLoop();		
}

