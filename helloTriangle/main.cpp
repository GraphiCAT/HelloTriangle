#include <windows.h>  // This header file will be needed for some windows compilers
#include <GL/glut.h>  // glut (gl utility toolkit) basic windows functions, keyboard, mouse.
#include <stdio.h>    // standard (I/O library)
#include <stdlib.h>   // standard library (set of standard C functions
#include <math.h>     // Math library (Higher math functions )
#include "DrawHandler.h"

int window_1, window_2;

// Main program
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   //glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (10, 10);
   window_1 = glutCreateWindow (argv[0]);
   glutSetWindowTitle("Three Triangles");
   init ();
   glutDisplayFunc(display_1);
   glutReshapeFunc(reshape_1);
   display_1();

   glutInitWindowSize (500, 500);
   glutInitWindowPosition (550, 10);
   window_2 = glutCreateWindow (argv[0]);
   glutSetWindowTitle("Gradient Triangle");
   init ();
   glutDisplayFunc(display_2);
   glutReshapeFunc(reshape_2);

   glutMainLoop();
   return 0;
}
