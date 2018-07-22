// Source: https://www.ntu.edu.sg/home/ehchua/programming/opengl/CG_Examples.html
// Compile: g++ 3d.cpp -o 3d -lglut -lGL -lGLU

#include "GL/glut.h"
#define PI 3.1415926535
#include <stdlib.h>
#include <math.h>

GLfloat jam1 = 0.0f;
GLfloat angle = 0.0f;
GLfloat direction = 25.0f;

float sudut = 0;
int i;
int n;

int x = 0;


void initGL() {
	glClearColor(0.5,0.5,0.1,0);    
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
void lingkaran(float radius, float jumlah_titik, int x_tengah, int y_tengah) {
	glBegin(GL_POLYGON);
	for (i=0;i<=360;i++){
		float sudut=i*(2*PI/jumlah_titik);
		float x=x_tengah+radius*cos(sudut);
		float y=y_tengah+radius*sin(sudut);
		glVertex2f(x,y);
	}
	glEnd();
}

void angka(float jarak, float x, float y) {
	glPointSize(13); //Mengatur besar titik
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	for(n=0;n<360;n+=30)
		glVertex2f(jarak*(float)sin(n*PI/180.0)+x,jarak*(float)cos(n*PI/180.0)+y);
	glEnd();
}
void menit(float jarak, float x, float y) {
	glPointSize(2); //Mengatur besar titik
	glBegin(GL_POINTS);
	glColor3f(0,0,0);
	for(n=0;n<360;n+=6)
		glVertex2f(jarak*(float)sin(n*PI/180.0)+x,jarak*(float)cos(n*PI/180.0)+y);
	glEnd();
}
void panahDetik(){
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);				
	glVertex2f(0,16);
	glVertex2f(1.5,14);
	glVertex2f(0.5,14);
	glVertex2f(0.5,0);
	glVertex2f(-0.5,0);
	glVertex2f(-0.5,14);
	glVertex2f(-1.5,14);
	glVertex2f(0,16);
	glEnd();
}
void panahMenit(){
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);	

	glVertex2f(0,14);
	glVertex2f(1.5,12);
	glVertex2f(0.5,12);
	glVertex2f(0.5,0);
	glVertex2f(-0.5,0);
	glVertex2f(-0.5,12);
	glVertex2f(-1.5,12);
	glVertex2f(0,14);
	glEnd();
}
void panahJam(){
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);	

	glVertex2f(0,12);
	glVertex2f(1.5,10);
	glVertex2f(0.5,10);
	glVertex2f(0.5,0);
	glVertex2f(-0.5,0);
	glVertex2f(-0.5,10);
	glVertex2f(-1.5,10);
	glVertex2f(0,12);
	glEnd();
}
void bandul(){
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(0.5,-18);
	glVertex2f(0.5,0);
	glVertex2f(-0.5,0);				
	glVertex2f(-0.5,-18);			
	glEnd();				
	glTranslatef(0.0f, -18.0f, 0.02f);
	lingkaran(4.5,100,0,0);
	glTranslatef(0.0f, 0.0f, 0.02f);
	glColor3f(0.5,0.5,0.5);
	lingkaran(4.,100,0,0);
}



void kotak1(){
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.5,0.5);

	glVertex2f(-10, 22.5);
	glVertex2f(10, 22.5);
	glVertex2f(10,-32.5);
	glVertex2f(-10,-32.5);
	glEnd();
}
void kotak2(){
	glBegin(GL_POLYGON);
	glColor3f (0.0f, 1.0f, 0.0f);
	glVertex2f(-5, 25);
	glVertex2f(5, 25);
	glVertex2f(5,-35);
	glVertex2f(-5,-35);
	glEnd();
}

void myKeyboard(unsigned char key,int x1,int y){

	if(key == 'k'){
		x=x-10;	
	}
	else if(key =='l'){
		x=x+10;
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
//
	glLoadIdentity();
	glTranslatef(0.0f, 4.0f, -80.0f);
	glRotatef(x, 0.0f, 1.0f, 0.0f);


	kotak1();
	glTranslatef(0.0f, 0.0f, 0.1f);
	kotak2();
	glTranslatef(0.0f, 0.0f, 0.1f);

	glColor3f(1,1,1);;//warna putih
	lingkaran(20,100,0,0);


	glTranslatef(0.0f, 0.0f, 0.02f);//warna abu-abu
	glColor3f(0.5,0.5,0.5);
	lingkaran(18,100,0,0);

	glTranslatef(0.0f, 0.0f, 0.1f);
	angka(16,0,0); //Jam

	glTranslatef(0.0f, 0.0f, 0.1f);
	menit(16,0,0); //Jam

	glTranslatef(0.0f, 0.0f, 0.1f);
	glPushMatrix();
	glRotatef(sudut/720,0,0,1);
	panahJam();
	glPopMatrix();


	glTranslatef(0.0f, 0.0f, 0.1f);
	glPushMatrix();
	glRotatef(sudut/60,0,0,1);
	panahMenit();
	glPopMatrix();

	glTranslatef(0.0f, 0.0f, 0.1f);
	glPushMatrix();
	glRotatef(sudut,0,0,1);
	panahDetik();
	glPopMatrix();

	glTranslatef(0.0f, 0.0f, 0.1f);
	glColor3f(0,0,0);
	lingkaran(1,100,0,0);

	glTranslatef(0.0f, -9.0f, -0.7f);
	glPushMatrix();
	glRotatef(angle,0,0,1);
	bandul();
	glPopMatrix();

	angle += direction;
	if (angle >= 25 || angle <= -25) {
		direction = -direction;
	}
	//
	glutSwapBuffers();
//	jam1 += 10.0f;
}

void timer(int value) {
	sudut-=6; 
	glutPostRedisplay();
	glutTimerFunc(360*3,timer,0);
}

void reshape(GLsizei width, GLsizei height) {
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(480, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Jam");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	initGL();
	glutTimerFunc(0, timer, 0);
	glutKeyboardFunc(myKeyboard);
	glutMainLoop();
	return 0;
}



