#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>

using namespace std;
int x, y, p, radius, xmax, ymax;
bool isCircle_Drawn = false;

int divide_quadrant()
{
xmax = glutGet(GLUT_WINDOW_WIDTH);
ymax = glutGet(GLUT_WINDOW_HEIGHT);
glBegin(GL_LINES);
glVertex2i(xmax / 2, 0);
glVertex2i(xmax / 2, ymax);
glVertex2i(0, ymax / 2);
glVertex2i(xmax, ymax / 2);
glEnd();
return 0;
}

void putpixel(int x, int y)
{
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}

void filling_circle(){
xmax = glutGet(GLUT_WINDOW_WIDTH);
ymax = glutGet(GLUT_WINDOW_HEIGHT);
putpixel((xmax / 2 + x), (ymax / 2 - y));
putpixel((xmax / 2 + y), (ymax / 2 - x));
putpixel((xmax / 2 + y), (ymax / 2 + x));
putpixel((xmax / 2 + x), (ymax / 2 + y));
putpixel((xmax / 2 - x), (ymax / 2 + y));
putpixel((xmax / 2 - y), (ymax / 2 + x));
putpixel((xmax / 2 - y), (ymax / 2 - x));
putpixel((xmax / 2 - x), (ymax / 2 - y));
isCircle_Drawn = true;
}

int Bresenham_circle_drawing(){
cout << "Enter the value of first co-ordinate (x and y ) : ";
cin >> x >> y;
cout << "Enter radius :";
cin >> radius;
x = 0;
y = radius;
p = 3 - 2*radius;
while(x <= y){
if(p < 0){
x = 1 + x;
y = y;
p = p + (4*x)+6;
filling_circle();
}else{
x = 1 + x;
y = y - 1;
p = p + (4*x - 4*y) +10;
filling_circle();
}
}
return 0;
}


void myDisplay()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3i(0.0f, 0.0f, 0.0f);
divide_quadrant();
if(!isCircle_Drawn){
Bresenham_circle_drawing();
}
glFlush();
}

void init()
{
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
glFlush();
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitWindowSize(640, 480);
glutInitWindowPosition(50, 50);
glutCreateWindow("Bresenham Circle Drawing Algorithm");
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
glutDisplayFunc(myDisplay);
init();
glutMainLoop();
return 0;
}
