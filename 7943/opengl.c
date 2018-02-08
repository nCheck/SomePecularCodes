#include<stdio.h>
#include<stdlib.h>
#include<gl.h>
#include<glu.h>
#include<glut.h>

void WriteFunctionName()
{
	//Use pixel plotting in glBegin and glEnd
	glBegin(GL_POINTS);

		//glVertex2f(x,y); //Sample for ploting pixel at (x,y)

	glEnd();
}


void disp()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	//call your function define at beginning
	//for example WriteFunctionName();

	glFlush();
}//disp


int main(int argv,char **argc)
{
	glutInit(&argv,argc);
	glutInitWindowSize(300,300);
	glutCreateWindow("window");
	gluOrtho2D(0,300,0,300);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
