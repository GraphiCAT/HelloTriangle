#include <windows.h>  // This header file will be needed for some windows compilers
#include <GL/glut.h>  // glut (gl utility toolkit) basic windows functions, keyboard, mouse.
#include <stdio.h>    // standard (I/O library)
#include <stdlib.h>   // standard library (set of standard C functions
#include <math.h>     // Math library (Higher math functions )
#include "DrawHandler.h"
#include "Coordinate.h"
#include "Point.h"

int window_1, window_2;
int window_size = 500;

// Main program
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
   glutInitWindowSize (1000, 1000);
   glutInitWindowPosition (10, 10);
   window_1 = glutCreateWindow (argv[0]);
   glutSetWindowTitle("Three Triangles");
   init ();
   glutDisplayFunc(display_1);
   glutReshapeFunc(reshape_1);
   display_1();

   glutInitWindowSize (506, 506);
   glutInitWindowPosition (window_size + 50, 10);
   window_2 = glutCreateWindow (argv[0]);
   glutSetWindowTitle("Gradient Triangle");
   init ();
   glutDisplayFunc(display_2);
   glutReshapeFunc(reshape_2);

   glutMainLoop();
   return 0;
}
