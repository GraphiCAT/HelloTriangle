#ifndef Point_H
#define Point_H

#include <iostream>

class Point {
public:
	// Constructor
	Point(float _x, float _y) { x = _x; y = _y;};
	Point() { Point(0,0); };

	// Getter
	float getX() const { return x; };
	float getY() const { return y; };

	// Setter
	void setX(float _x) {x = _x; };
	void setY(float _y) {y = _y; };

	void printPoint() {
        std::cout << "x : " << x << ", y : " << y << std::endl;
	}

private:
	float x;
	float y;
};


#endif
