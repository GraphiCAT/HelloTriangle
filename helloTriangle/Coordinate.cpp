#include "Coordinate.h"

Point convertToOpenGLCoordinates(int x, int y, int max_x, int max_y){
    float x_temp = (float)(max_x)/(float)2;
    float y_temp = (float)(max_y)/(float)2;
    Point result;

    result.setX((float)(x-x_temp)/(float)x_temp);
    result.setY((float)(y_temp-y)/(float)y_temp);

    return result;

}

