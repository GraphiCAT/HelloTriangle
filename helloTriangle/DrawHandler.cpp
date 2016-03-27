#include <windows.h>  // This header file will be needed for some windows compilers
#include <GL/glut.h>  // glut (gl utility toolkit) basic windows functions, keyboard, mouse.
#include <string>
#include <vector>
#include <fstream>
#include "DrawHandler.h"
#include "Point.h"
#include "Coordinate.h"

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

    makePolygon("C:\\Users\\User\\Documents\\OpenGL\\triangle\\HelloTriangle\\helloTriangle\\bin\\Debug\\polygon.txt",1,0,0);

    glEnd();


   glFlush();  // Render now
}

// Draw our world
void display_2(void)
{
    drawGradientTriangle("C:\\Users\\User\\Documents\\OpenGL\\triangle\\HelloTriangle\\assets\\kucing_2\\triangle-1.txt");
    drawGradientTriangle("C:\\Users\\User\\Documents\\OpenGL\\triangle\\HelloTriangle\\assets\\kucing_2\\triangle-2.txt");
    drawGradientTriangle("C:\\Users\\User\\Documents\\OpenGL\\triangle\\HelloTriangle\\assets\\kucing_2\\triangle-3.txt");
    drawGradientTriangle("C:\\Users\\User\\Documents\\OpenGL\\triangle\\HelloTriangle\\assets\\kucing_2\\triangle-4.txt");
    drawGradientTriangle("C:\\Users\\User\\Documents\\OpenGL\\triangle\\HelloTriangle\\assets\\kucing_2\\triangle-5.txt");
    drawGradientTriangle("C:\\Users\\User\\Documents\\OpenGL\\triangle\\HelloTriangle\\assets\\kucing_2\\triangle-6.txt");
    drawGradientTriangle("C:\\Users\\User\\Documents\\OpenGL\\triangle\\HelloTriangle\\assets\\kucing_2\\triangle-7.txt");
    drawGradientTriangle("C:\\Users\\User\\Documents\\OpenGL\\triangle\\HelloTriangle\\assets\\kucing_2\\triangle-8.txt");
    drawGradientTriangle("C:\\Users\\User\\Documents\\OpenGL\\triangle\\HelloTriangle\\assets\\kucing_2\\triangle-9.txt");
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

void makePolygon(std::string filename, float R, float G, float B) {
    std::vector<Point> point_vec;

    std::fstream file(filename.c_str(), std::ios_base::in);

    if (!file) {
        std::cout<<"file not found\n";
    } else {
        int x,y;
        int a;
        bool cek = 0;
        while (file >> a) {
            if (cek == 0) {
                x = a;
                cek = 1;
            } else {
                y = a;
                Point temp = Point(x,y);
                point_vec.push_back(temp);
                //temp.printPoint();
                cek = 0;
            }
        }
    }

    glBegin(GL_POLYGON);
    glColor3f(R,G,B);

    for (int i = 0; i < point_vec.size(); i++) {
        Point p;
        p = convertToOpenGLCoordinates(point_vec.at(i).getX(),point_vec.at(i).getY(),1000,1000);
        glVertex2f(p.getX(),p.getY());
    }

}

void drawGradientTriangle(std::string filename){
    std::vector<Point> point_vec;

    std::fstream file(filename.c_str(), std::ios_base::in);

    if (!file) {
        std::cout<<"file not found\n";
    } else {
        int x,y;
        int a;
        bool cek = 0;
        while (file >> a) {
            if (cek == 0) {
                x = a;
                cek = 1;
            } else {
                y = a;
                Point temp = Point(x,y);
                point_vec.push_back(temp);
                //temp.printPoint();
                cek = 0;
            }
        }
    }

    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    Point p1;
    p1 = convertToOpenGLCoordinates(point_vec.at(0).getX(),point_vec.at(0).getY(),506,506);
    glVertex2f(p1.getX(),p1.getY());

    glColor3f(0,1,0);
    Point p2;
    p2 = convertToOpenGLCoordinates(point_vec.at(1).getX(),point_vec.at(1).getY(),506,506);
    glVertex2f(p2.getX(),p2.getY());

    glColor3f(0,0,1);
    Point p3;
    p3 = convertToOpenGLCoordinates(point_vec.at(2).getX(),point_vec.at(2).getY(),506,506);
    glVertex2f(p3.getX(),p3.getY());
}
