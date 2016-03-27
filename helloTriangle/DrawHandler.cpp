#include <windows.h>  // This header file will be needed for some windows compilers
#include <GL/glut.h>  // glut (gl utility toolkit) basic windows functions, keyboard, mouse.
#include "DrawHandler.h"

// Setup our Opengl world, called once at startup.
void init()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear (GL_COLOR_BUFFER_BIT);  //Clear the screen

}

// Draw our world
void display_1(void)
{

   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
          glVertex2f(-1.0f,-0.25f);
          glVertex2f(-0.5f,-0.25f);
          glVertex2f(-0.75f,0.25f);
        glColor3f(0.0f, 1.0f, 0.0f);
          glVertex2f(-0.25f,-0.25f);
          glVertex2f(0.25f,-0.25f);
          glVertex2f(0.0f,0.25f);
        glColor3f(0.0f, 0.0f, 1.0f);
          glVertex2f(0.5f,-0.25f);
          glVertex2f(1.0f,-0.25f);
          glVertex2f(0.75f,0.25f);

    glEnd();
   glFlush();  // Render now
}

// Draw our world
void display_2(void)
{

   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_TRIANGLES);              // Each set of 4 vertices form a quad
      //segitiga gradien
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.25f,-0.25f);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex2f(0.25f,-0.25f);
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex2f(0.0f,0.25f);
   glEnd();

   glFlush();  // Render now
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

