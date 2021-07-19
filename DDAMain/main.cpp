//Edwin Mugambi Njeru
//dda Line Drawing
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include <cmath>
#include <ctgmath>

using namespace std;

int xstart, ystart, xend, yend;

void init()
{
	glOrtho(0, 100, 0, 100,-1,1);
}



void draw_pixel(int x, int y)
{
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}


void LineDDA(int xstart, int ystart, int xend, int yend)
{
    //step one
	double dx; //change in X
	double dy; //change in Y
	double m; //change in gradient
	int steps;
	double x,y;

	x= xstart;
	y= ystart;

	draw_pixel(x,y);
	cout<<"x: "<< x << "y: "<<y<<endl;

	dx = xend - xstart;
	dy = yend - ystart;
	m = dy / dx ;


	//step 2

	if(abs(dx) > abs(dy)){
        steps = abs(dx);
	}else{
	steps = abs(dy);
	}

	//step 3
	int stepCount = 0;

	  while(x < xend && stepCount < steps){
            if( m < 1){
            x = round(1 + x);

            y = m + y;

        }
        if(m == 1){
            x = round( 1 + x);
            y = round(1 + y);
        }
        if(m > 1){
            x = round((1/m) + x);
            y = round(1 + y);
        }

        draw_pixel(x , y);
        cout<<"x: "<< x << "  y: "<<round(y)<<endl;
        stepCount++;

        }

}


void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);

	LineDDA(7, 1, 14, 3);//my coordinates
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{


	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(200, 200);
	glutCreateWindow(".Line.");
	init();
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
