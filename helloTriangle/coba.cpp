// Glutdualwindow.c
// By Eric Stringer 2002
// Simple examples of OpenGL and Glut usage.
// Keyboard input
// 'v' = view ortho/perspective
// 'l' = lighting on/off


#include <windows.h>  // This header file will be needed for some windows compilers
//#include <GL/gl.h>   // gl.h and glu.h also maybe needed for some compilers
//#include <GL/glu.h>
#include <GL/glut.h>  // glut (gl utility toolkit) basic windows functions, keyboard, mouse.
#include <stdio.h>    // standard (I/O library)
#include <stdlib.h>   // standard library (set of standard C functions
#include <math.h>     // Math library (Higher math functions )


// lighting
GLfloat LightAmbient[]= { 0.2f, 0.2f, 0.2f, 1.0f };
GLfloat LightDiffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightPosition[]= { 5.0f, 5.0f, -10.0f, 1.0f };
GLfloat mat_specular[] = { 0.2, 0.2, 0.2, 1.0 };

int window_1, window_2;

static int view_state = 0, light_state = 0;

int spin;

int shape;

// I use this to put text on the screen
void Sprint( int x, int y, char *st)
{
	int l,i;

	l=strlen( st ); // see how many characters are in text string.
	glRasterPos2i( x, y); // location to start printing text
	for( i=0; i < l; i++)  // loop until i is greater then l
		{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]); // Print a character on the screen
	}

}


// This creates the spinning of the cube.
static void TimeEvent(int te)
{

    spin++;  // increase cube rotation by 1
	if (spin > 360) spin = 0; // if over 360 degress, start back at zero.

	glutSetWindow( window_1 );
	glutPostRedisplay();  // Update screen with new rotation data

	glutSetWindow( window_2 );
	glutPostRedisplay();  // Update screen with new rotation data

	glutTimerFunc( 100, TimeEvent, 1);  // Reset our timmer.
}


// Setup our Opengl world, called once at startup.
void init(void)
{


   glClearColor (0.0, 0.0, 0.0, 0.0);  // When screen cleared, use black.
   glShadeModel (GL_SMOOTH);  // How the object color will be rendered smooth or flat
   glEnable(GL_DEPTH_TEST);   // Check depth when rendering
   // Lighting is added to scene
   glLightfv(GL_LIGHT1 ,GL_AMBIENT, LightAmbient);
   glLightfv(GL_LIGHT1 ,GL_DIFFUSE, LightDiffuse);
   glLightfv(GL_LIGHT1 ,GL_POSITION, LightPosition);
   glEnable(GL_LIGHTING);  // Turn on lighting
   glEnable(GL_LIGHT1);    // Turn on light 1


}


// Draw our world
void display_1(void)
{
char *p;

glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //Clear the screen

glMatrixMode (GL_PROJECTION);  // Tell opengl that we are doing project matrix work
glLoadIdentity();  // Clear the matrix
glOrtho(-8.0, 8.0, -8.0, 8.0, 0.0, 30.0);  // Setup an Ortho view
glMatrixMode(GL_MODELVIEW);  // Tell opengl that we are doing model matrix work. (drawing)
glLoadIdentity(); // Clear the model matrix


glColor3f(1.0, 1.0, 1.0);
if (shape == 0) Sprint(-3, -7 ,"Solid Cube");
if (shape == 1) Sprint(-3, -7 ,"Solid Cone");
if (shape == 2) Sprint(-3, -7 ,"Solid Sphere");
if (shape == 3) Sprint(-3, -7 ,"Solid Torus");
if (shape == 4) Sprint(-3, -7 ,"Solid Dodecahedron");
if (shape == 5) Sprint(-3, -7 ,"Solid Octahedron");
if (shape == 6) Sprint(-3, -7 ,"Solid Tetrahedron");
if (shape == 7) Sprint(-3, -7 ,"Solid Icosahedron");
if (shape == 8) Sprint(-3, -7 ,"Solid Teapot");

// Setup view, and print view state on screen
if (view_state == 1)
	{
    glColor3f( 1.0, 1.0, 1.0);
    Sprint(-2, 4, "Perspective view");
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 30);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    }else
	{
	glColor3f( 1.0, 1.0, 1.0);
    Sprint(-2, 4, "Ortho view");
    }

glColor3f( 0.0, 0.0, 1.0);  // Cube color

// Lighting on/off
if (light_state == 1)
	{
	glDisable(GL_LIGHTING);  // Turn off lighting
    glDisable(GL_COLOR_MATERIAL); // Turn off material, which needs lighting to work
    }else
	{
    glEnable(GL_LIGHTING); // Turn on lighting
    glEnable(GL_COLOR_MATERIAL); // Turn on material settings
    glColorMaterial(GL_FRONT, GL_AMBIENT);
    glColor4f(0.65, 0.65, 0.65, 0.4);
    glColorMaterial(GL_FRONT, GL_EMISSION);
    glColor4f(0.10, 0.10, 0.10, 0.0);
    glColorMaterial(GL_FRONT, GL_SPECULAR);
    glColor4f(0.5, 0.5, 0.5, 0.4);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glColor4f(0.85, 0.85, 0.85, 0.4);
    }

gluLookAt( 0, 0, 20, 0, 0, 0, 0, 1, 0);

//glRotatef( 45, 1.0, 1.0, 0.0); // rotate cube
glRotatef( spin++, 1.0, 1.0, 1.0); // spin cube

if (shape == 0) glutSolidCube(10); // Draw a cube
if (shape == 1) glutSolidCone(5,10, 16,16);  // Draw a Cone
if (shape == 2) glutSolidSphere(5, 16,16 );  // Draw a Sphere
if (shape == 3) glutSolidTorus( 2.5, 5, 16, 16);
if (shape == 4)
   {
	glScalef( 3.5, 3.5, 3.5);
	glutSolidDodecahedron();
   }

if (shape == 5)
   {
	glScalef( 5.0, 5.0, 5.0);
	glutSolidOctahedron();
   }
if (shape == 6)
   {
	glScalef( 5.0, 5.0, 5.0);
	glutSolidTetrahedron();
   }

if (shape == 7)
   {
	glScalef( 5.0, 5.0, 5.0);
	glutSolidIcosahedron();
   }
if (shape == 8) glutSolidTeapot( 5 );

glutSwapBuffers();
}

void display_2(void)
{
char *p;

glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //Clear the screen

glMatrixMode (GL_PROJECTION);  // Tell opengl that we are doing project matrix work
glLoadIdentity();  // Clear the matrix
glOrtho(-8.0, 8.0, -8.0, 8.0, 0.0, 30.0);  // Setup an Ortho view
glMatrixMode(GL_MODELVIEW);  // Tell opengl that we are doing model matrix work. (drawing)
glLoadIdentity(); // Clear the model matrix


glColor3f(1.0, 1.0, 1.0);
if (shape == 0) Sprint(-3, -7 ,"Wire Cube");
if (shape == 1) Sprint(-3, -7 ,"Wire Cone");
if (shape == 2) Sprint(-3, -7 ,"Wire Sphere");
if (shape == 3) Sprint(-3, -7 ,"Wire Torus");
if (shape == 4) Sprint(-3, -7 ,"Wire Dodecahedron");
if (shape == 5) Sprint(-3, -7 ,"Wire Octahedron");
if (shape == 6) Sprint(-3, -7 ,"Wire Tetrahedron");
if (shape == 7) Sprint(-3, -7 ,"Wire Icosahedron");
if (shape == 8) Sprint(-3, -7 ,"Wire Teapot");

// Setup view, and print view state on screen
if (view_state == 1)
	{
    glColor3f( 1.0, 1.0, 1.0);
    Sprint(-2, 4, "Perspective view");
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 30);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    }else
	{
	glColor3f( 1.0, 1.0, 1.0);
    Sprint(-2, 4, "Ortho view");
    }

glColor3f( 0.0, 0.0, 1.0);  // Cube color

// Lighting on/off
if (light_state == 1)
	{
	glDisable(GL_LIGHTING);  // Turn off lighting
    glDisable(GL_COLOR_MATERIAL); // Turn off material, which needs lighting to work
    }else
	{
    glEnable(GL_LIGHTING); // Turn on lighting
    glEnable(GL_COLOR_MATERIAL); // Turn on material settings
    glColorMaterial(GL_FRONT, GL_AMBIENT);
    glColor4f(0.65, 0.65, 0.65, 0.4);
    glColorMaterial(GL_FRONT, GL_EMISSION);
    glColor4f(0.10, 0.10, 0.10, 0.0);
    glColorMaterial(GL_FRONT, GL_SPECULAR);
    glColor4f(0.5, 0.5, 0.5, 0.4);
    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glColor4f(0.85, 0.85, 0.85, 0.4);
    }

gluLookAt( 0, 0, 20, 0, 0, 0, 0, 1, 0);

//glRotatef( 45, 1.0, 1.0, 0.0); // rotate cube
glRotatef( spin++, 1.0, 1.0, 1.0); // spin cube

if (shape == 0) glutWireCube(10); // Draw a cube
if (shape == 1) glutWireCone(5,10, 16,16);  // Draw a Cone
if (shape == 2) glutWireSphere(5, 16,16 );  // Draw a Sphere
if (shape == 3) glutWireTorus( 2.5, 5, 16, 16);
if (shape == 4)
   {
	glScalef( 3.5, 3.5, 3.5);
	glutSolidDodecahedron();
   }

if (shape == 5)
   {
	glScalef( 5.0, 5.0, 5.0);
	glutWireOctahedron();
   }
if (shape == 6)
   {
	glScalef( 5.0, 5.0, 5.0);
	glutWireTetrahedron();
   }

if (shape == 7)
   {
	glScalef( 5.0, 5.0, 5.0);
	glutWireIcosahedron();
   }
if (shape == 8) glutWireTeapot( 5 );

glutSwapBuffers();
}


// This is called when the window has been resized.
void reshape_1 (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
}

// This is called when the window has been resized.
void reshape_2 (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
}

// Read the keyboard
void keyboard (unsigned char key, int x, int y)
{
   switch (key)
   {

	  case 'v':
	  case 'V':
		  view_state = abs(view_state -1);
		  break;
	  case 'l':
	  case 'L':
		  light_state = abs(light_state -1);
		  break;
	  case 's':
	  case 'S':
		  shape++;
		  break;
 	  case 27:
         exit(0); // exit program when [ESC] key presseed
         break;
      default:
         break;
   }

if (shape > 8) shape = 0;

}


// Main program
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (10, 10);
   glutTimerFunc( 10, TimeEvent, 1);
   window_1 = glutCreateWindow (argv[0]);
   glutSetWindowTitle("GlutWindow 1");
   init ();
   glutDisplayFunc(display_1);
   glutReshapeFunc(reshape_1);
   glutKeyboardFunc(keyboard);

   window_2 = glutCreateWindow (argv[0]);
   glutSetWindowTitle("GlutWindow 2");
   init ();
   glutDisplayFunc(display_2);
   glutReshapeFunc(reshape_2);
   glutMainLoop();
   return 0;
}

