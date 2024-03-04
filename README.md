#include <GL/glut.h>     //Guarantees that gl.h and glu.h are preperly included
#include <iostream>
#include <math.h>

using namespace std;
int ch = 0;
int dx,dy;

void display(int x, int y)
{
 glColor3f(0,0,0);
 glPointSize(2);
 glBegin(GL_POINTS);
 glVertex2i(x, y);
 glEnd();
}

void SimpleLine(int x1, int y1, int x2, int y2){
dx = x2 - x1;
dy = y2 - y1;
int steps;
if(abs(dx) >= abs(dy)){             //abs function is used to find the absolute value of integer number.   abs(-1)=1, abs(1)=1.
steps = abs(dx);
}
else{
steps = abs(dy);
}
float Xin = dx / (float) steps;
float Yin = dy / (float) steps;
float x = x1;
float y = y1;
for(int i=0; i<=steps; i++){
display(x, y);
x = x + Xin;
y = y + Yin;
}
glFlush();
}

void mouse(int button, int state, int x, int y)
{
 	static int x1, y1, pt = 0;
 	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
 	{
 		if (pt == 0)
 		{
 			x1 = x;
 			y1 = y;
 			pt = pt + 1;
 		}
 		else
 		{
 			if (ch == 1)
 			{
 				SimpleLine(x1, y1, x, y);
 			}
 			
 			x1 = x;
 			y1 = y;
 		}
 	}
 	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
 		pt = 0;
	}
 	glFlush(); 
}

void keyboard(unsigned char key, int x, int y)
{
 switch (key)
 {
case 's':
{
ch = 1;
cout << "Simple Line is opted" << endl;
glutMouseFunc(mouse);                      // It allows to link mouse button with a routine that's invoked when the mouse button is pressed or released. 
break;
}

 }
 glutPostRedisplay();
}

void initialize()
{
 glClearColor(1.0, 1.0, 1.0, 1.0);           //to this color the window will be cleared
 glClear(GL_COLOR_BUFFER_BIT);              //actually clears the window. Once the clearing color is set, the window is cleared to that color whenever glClear() is called. This clearing color can be changed with another call to glClearColor().
 gluOrtho2D(0, 600, 600, 0);                // creates a matrix for projecting 2D coordinates onto the screen and multiplies the current projection matrix by it. 
}
void initialaxis(){
 glColor3f(0,0,0);              //establishes the color used to drawing an object
 glLineWidth(2);              //sets width in pixels for rendered lines. It should be >0. By default, it is 1.0. 
 glBegin(GL_LINES);          //Defines the object to be drawn
 glVertex2i(300, 0);        // It specifies the vertex coordinates as 32 bit integer. 
 glVertex2i(300, 600);
 glVertex2i(0, 300);
 glVertex2i(600, 300);
 glEnd();                    // Marks the end of a vertex data list
glFlush();                    // Ensures drawing commands are actually executed rather than stored in a buffer awaiting additional OpenGL. 
glutKeyboardFunc(keyboard);    // It allows you to link a keyboard key with a routine that's invoked when the key button is pressed or released. 
}

int main(int argc, char **argv)
{
 glutInit(&argc, argv);            // Initializes Glut and processes any command line argument. It should be called before any other Glut routines.
 glutInitDisplayMode(GLUT_SINGLE);  // specifies whether to use RGBA/ Color index color model. 
 glutInitWindowSize(600, 600);
 glutInitWindowPosition(800, 100);
 glutCreateWindow("DDA Algorithm");
 initialize();
 cout << "Choose your Line type: " << endl;
 cout << "--------------------------------------------" << endl;
 cout << "s => simple" << endl;


 glutDisplayFunc(initialaxis);          // First and most important event callback function whenever GLUT determines that contents of the window need to be redisplayed the callback function registered by glutDisplayFunc() is executed. 
                                      // You should put all the routines you need to redraw the scene in the display callback function. 
 glutMainLoop();
 return 0;
}
