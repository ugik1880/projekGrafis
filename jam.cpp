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
 glVertex2i(0,200);
 glVertex2i(10,180);
 glVertex2i(5,180);
 glVertex2i(5,0);
 glVertex2i(-5,0);
 glVertex2i(-5,180);
 glVertex2i(-10,180);
 glVertex2i(0,200);
 glEnd();
}

void panahMenit(){
 glBegin(GL_POLYGON);
 glColor3f(1,1,1);
 glVertex2i(0,220);
 glVertex2i(10,200);
 glVertex2i(5,200);
 glVertex2i(5,0);
 glVertex2i(-5,0);
 glVertex2i(-5,200);
 glVertex2i(-10,200);
 glVertex2i(0,220);
 glEnd();
}
void panahDetik(){
 glBegin(GL_POLYGON);
 glColor3f(1,0,0);
 glVertex2i(0,240);
 glVertex2i(10,210);
 glVertex2i(5,210);
 glVertex2i(5,0);
 glVertex2i(-5,0);
 glVertex2i(-5,210);
 glVertex2i(-10,210);
 glVertex2i(0,240);
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

void renderScene(void){
 glClear(GL_COLOR_BUFFER_BIT);
 glClearColor(1,1,1,1);

 glPushMatrix();
 glColor3f(0.7,0.7,0.7);
 lingkaran(250,100,0,0);

 angka(230.,0.,0.);
 menit(230.,0.,0.);
 glPopMatrix();

 glPushMatrix();
 glRotatef(sudut,0,0,1);
 panahDetik();
 glPopMatrix();

 glPushMatrix();
 glRotatef(sudut/60,0,0,1);
 panahMenit();
 glPopMatrix();

 glPushMatrix();
 glRotatef(sudut/720,0,0,1);
 panahJam();
 glPopMatrix();
 
 glColor3f(0,0,0);
 lingkaran(20,100,0,0);

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
 glutInitWindowSize(300,300);
 glutCreateWindow("JAM ANALOG");
 gluOrtho2D(-300.,300.,-300.,300.);
 glutDisplayFunc(renderScene);
 glutTimerFunc(1,timer,0);
 glutMainLoop();
}
