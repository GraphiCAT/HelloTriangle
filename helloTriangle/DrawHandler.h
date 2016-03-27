#ifndef DrawHandler_H
#define DrawHandler_H
#include <string>

// Setup our Opengl world, called once at startup.
void init();
// Draw our world to first window
void display_1(void);
// Draw our world to second window
void display_2(void);
// This is called when the window has been resized.
void reshape_1 (int w, int h);
// This is called when the window has been resized.
void reshape_2 (int w, int h);

void makePolygon(std::string filename, float R, float G, float B);
void drawGradientTriangle(std::string filename);

#endif // DrawHandler_H
