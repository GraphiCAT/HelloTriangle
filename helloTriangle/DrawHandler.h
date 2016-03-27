#ifndef DrawHandler_H
#define DrawHandler_H

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

#endif // DrawHandler_H
