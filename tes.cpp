#include <stdlib.h>

#include <gl/glut.h>
//GLfloat a = 0;
int x=10;

void Triangles(){

glBegin(GL_TRIANGLES);
	glColor3f(0,1,0);//hijau
	glVertex2f (0.,0.);
	glVertex2f(10.,30.);
	glVertex2f(-10.,30.);
	glColor3f(0,1,1);
	glVertex2f (0.,0.);
	glVertex2f(-10.,-30.);
	glVertex2f(10.,-30.);
glEnd();

}

void renderScene(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,1);
	glRotatef(x,0,0,1);//sudut
	Triangles();
	glFlush();
	
}

void myKeyboard(unsigned char key,int x1,int y){

	if(key == 'k'){
		x=-10;	
	}

	else if(key =='l'){
		x=+10;
	}
}

void timer(int value){
	
	glutPostRedisplay();
	glutTimerFunc(15,timer,0);
}

int main(int argc,char **argv){

	glutInit(&argc,argv);

	glutInitWindowPosition(100,100);

	glutInitWindowSize(400,400);

	glutCreateWindow("Praktikum 6 ? Baling-Baling khumaini");

	gluOrtho2D(-50.,50.,-50.,50.);

	glutDisplayFunc(renderScene);

	glutTimerFunc(1,timer,0);

	glutKeyboardFunc(myKeyboard);

	glutMainLoop();

}
