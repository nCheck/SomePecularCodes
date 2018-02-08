/*
 * bres.c
 *
 *  Created on: Feb 8, 2018
 *      Author: universe
 */

#include<stdio.h>
#include<stdlib.h>
#include<gl.h>
#include<glu.h>
#include<glut.h>

void bres(float x1,float x2,float y1,float y2)
{

    float g;
    float dx=x2-x1;
    float dy=y2-y1;
    g=2*dy-dx;

        glBegin(GL_POINTS);
    while(x1<=x2 && y1<=y2)
    {
     glVertex2f(x1,y1);
     x1=x1+1;
     if(g>0)
     {
         y1=y1+1;
         g=g+(2*dy-2*dx);
     }
     else
     {
         g=g+2*dy;
     }

     glVertex2f(x1,y1);
    }
      glEnd();

}


void disp()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    bres(10,150,0,150);
    glFlush();
}//disp


int main(int argv,char **argc)
{
    glutInit(&argv,argc);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Window");
    gluOrtho2D(0,300,0,300);
    glutDisplayFunc(disp);
    glutMainLoop();
    return 0;
}
