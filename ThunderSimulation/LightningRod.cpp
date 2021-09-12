#include "LightningRod.h"
#include <gl/glew.h>
#include <GL/glut.h>
#include<iostream>
using namespace std;

void Rod::LightningRod(double(*lattice)[index + 1]) {
		lattice[index][pos] = index;
	}
void Rod::LightningRodDisplay() {
	double x, y, d;
	d = 1.0 / (index + 1);

	x = (double(pos) - ((double(index) + 1.0) / 2.0)) / ((double(index) + 1.0) / 2.0) + d;
	y = -(1 - d);

	glBegin(GL_LINES);
	glVertex2d(x - d, y - d);
	glVertex2d(x + d, y + d);
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(x - d, y + d);
	glVertex2d(x + d, y - d);
	glEnd();
}
