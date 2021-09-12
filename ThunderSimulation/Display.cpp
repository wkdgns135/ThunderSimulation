#include "Display.h"
#include <iostream>

#define LEN 1.0 / ((index+1) / 2.0)
using namespace std;

void Thunder::Display(int order, double(*mainChanelPos)[2]) {
	double x, y;
	unsigned int i = 0;
	unsigned int j = 0;
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= order; i++) {
		x = ((mainChanelPos[i][1] - (index) / 2.0) * LEN);
		y = -((mainChanelPos[i][0] - (index) / 2.0) * LEN);
		 
		if (!(x < -1 || y < -1 || x > 1 || y > 1)) {
			glVertex2d(x, y);
		}
	}
	glEnd();
}

void Positive::Display(double(*lattice)[index + 1]) {
	double x;
	double y;

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ZERO);

	glColor4d(0, 0, 0, 1);
	glBegin(GL_QUADS);
	glVertex2d(-1, 1);
	glVertex2d(1, 1);
	glVertex2d(-1, -1);
	glVertex2d(1, 1);
	glEnd();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	for (int i = 0; i <= index; i++) {
		glBegin(GL_QUADS);
		for (int j = 0; j <= index; j++) {
			double v = lattice[i][j];
			double r;
			double g;
			double b;

			if (v > 1) {
				r = 1;
				g = 0;
				b = 0;
			}
			else if (v >= 0.75) {
				r = 1;
				g = 1 - (v - 0.75)*(1 / 0.25);
				b = 0;
			}
			else if (v >= 0.5) {
				r = (v - 0.5)*(1 / 0.25);
				g = 1;
				b = 0;
			}
			else if (v >= 0.25) {
				r = 0;
				g = 1;
				b = 1 - (v - 0.25)*(1 / 0.25);
			}
			else if (v > 0) {
				r = 0;
				g = (v)*(1 / 0.25);
				b = 1;
			}
			else {
				r = 0;
				g = 0;
				b = 0.4;
			}
			if (v <= 0)glColor4d(r, g, b, 1);
			else glColor4d(r, g, b, 0.5f);

			x = (j - ((index + 1) / 2.0)) * LEN;
			y = -(i - ((index + 1) / 2.0)) * LEN;
			glVertex2d(x, y);
			glVertex2d(x + LEN, y);
			glVertex2d(x + LEN, y - LEN);
			glVertex2d(x, y - LEN);
		}
		glEnd();
	}
}


void Negative::Display(double(*lattice)[index + 1]) {
	double x;
	double y;

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ZERO);
	glColor4d(0, 0, 0, 1);
	glBegin(GL_QUADS);
	glVertex2d(-1, 1);
	glVertex2d(1, 1);
	glVertex2d(-1, -1);
	glVertex2d(1, 1);
	glEnd();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	for (int i = 0; i <= index; i++) {
		glBegin(GL_QUADS);
		for (int j = 0; j <= index; j++) {
			double v = lattice[i][j];
			double r;
			double g;
			double b;

			if (v <= 0) {
				r = 0.4;
				g = 0;
				b = 0;
			}
			else if (v <= 0.25) {
				r = 1;
				g = (v)*(1 / 0.25);
				b = 0;
			}
			else if (v <= 0.5) {
				r = 1 - (v - 0.25)*(1 / 0.25);
				g = 1;
				b = 0;
			}
			else if (v <= 0.75) {
				r = 0;
				g = 1;
				b = (v - 0.5)*(1 / 0.25);
			}
			else if (v <= 1) {
				r = 0;
				g = 1 - (v - 0.75)*(1 / 0.25);
				b = 1;
			}
			else {
				r = 0;
				g = 0;
				b = 1;
			}
			if (v <= 0)glColor4d(r, g, b, 1);
			else glColor4d(r, g, b, 0.5f);

			x = (j - ((index + 1) / 2.0)) * LEN;
			y = -(i - ((index + 1) / 2.0)) * LEN;
			glVertex2d(x, y);
			glVertex2d(x + LEN, y);
			glVertex2d(x + LEN, y - LEN);
			glVertex2d(x, y - LEN);
		}
		glEnd();
	}
}
