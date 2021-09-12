#pragma once
#include "GL/glew.h"
#include "GL/glut.h"
#include "Global.h"

extern const short int index;

enum STATE { THUNER, POSITIVE, NEGATIVE };

class Thunder {
public:
	void Display(int order, double(*mainChanelPos)[2]);
};

class Positive {
public:
	void Display(double(*lattice)[index + 1]);
};

class Negative {
public:
	void Display(double(*lattice)[index + 1]);
};