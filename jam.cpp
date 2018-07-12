#include "GL/glut.h"
#include "stdlib.h"
#include "math.h"
#define PI 3.1415926535
float sudut = 0;
int i,n;

void lingkaran(int radius, int jumlah_titik, int x_tengah, int y_tengah) {
 glBegin(GL_POLYGON);
 for (i=0;i<=360;i++){
        float sudut=i*(2*PI/jumlah_titik);
        float x=x_tengah+radius*cos(sudut);
        float y=y_tengah+radius*sin(sudut);
  glVertex2f(x,y);
 }
 glEnd();
}

void panahJam(){
 glBegin(GL_POLYGON);
 glColor3f(0,0,0);
 glVertex2i(0,80);
 glVertex2i(10,60);
 glVertex2i(5,60);
 glVertex2i(5,0);
 glVertex2i(-5,0);
 glVertex2i(-5,60);
 glVertex2i(-10,60);
 glVertex2i(0,80);
 glEnd();
}

void panahMenit(){
 glBegin(GL_POLYGON);
 glColor3f(1,1,1);
 glVertex2i(0,120);
 glVertex2i(10,100);
 glVertex2i(5,100);
 glVertex2i(5,0);
 glVertex2i(-5,0);
 glVertex2i(-5,100);
 glVertex2i(-10,100);
 glVertex2i(0,120);
 glEnd();
}
void panahDetik(){
 glBegin(GL_POLYGON);
 glColor3f(1,0,0); 
 glVertex2i(0,140);
 glVertex2i(10,120);
 glVertex2i(5,120);
 glVertex2i(5,0);
 glVertex2i(-5,0);
 glVertex2i(-5,120);
 glVertex2i(-10,120);
 glVertex2i(0,140);
 glEnd();
}

void angka(float jarak, float x, float y) {
 glPointSize(10);

 glBegin(GL_POINTS);
  glColor3f(0,0,0);
  for(n=0;n<360;n+=30)
   glVertex2f(jarak*(float)sin(n*PI/180.0)+x,jarak*(float)cos(n*PI/180.0)+y);
 glEnd();
}

void menit(float jarak, float x, float y) {
 glPointSize(2);

 glBegin(GL_POINTS);
  glColor3f(0,0,0);
  for(n=0;n<360;n+=6)
   glVertex2f(jarak*(float)sin(n*PI/180.0)+x,jarak*(float)cos(n*PI/180.0)+y);
 glEnd();
}

void display(){
 glClear(GL_COLOR_BUFFER_BIT);
 glClearColor(1,1,1,1);
 
 glColor3f(1,1,0);
 lingkaran(150,100,0,0); 
 
 menit(130,0,0); 
 angka(130,0,0);
 glPushMatrix();
 glRotatef(sudut/720,0,0,1);
 panahJam();
 glPopMatrix();

 glPushMatrix();
 glRotatef(sudut/60,0,0,1);
 panahMenit();
 glPopMatrix(); 
 
 glPushMatrix();
 glRotatef(sudut,0,0,1);
 panahDetik();
 glPopMatrix();
 
 glColor3f(0,0,0);
 lingkaran(10,100,0,0);

 glFlush();
}

void timer(int value){
 sudut-=6;
 glutPostRedisplay();
 glutTimerFunc(360*3,timer,0);
}
int main (int argc, char **argv){
 glutInit(&argc, argv);
 glutInitWindowPosition(100,100);
 glutInitWindowSize(500,500);
 glutCreateWindow("JAM DINDING");
 gluOrtho2D(-300.,300.,-300.,300.);
 glutDisplayFunc(display);
 glutTimerFunc(1,timer,0);
 glutMainLoop();
}
