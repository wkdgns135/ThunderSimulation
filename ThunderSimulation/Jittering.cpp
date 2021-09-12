#include "Jittering.h"
#include <random>

	void Jittering(int order, double(*chanelPos)[2], int w, int h) {
		double width, height;
		random_device rd;
		default_random_engine eng(rd());
		width = double(index) / double(w);
		height = double(index) / double(h);
		uniform_real_distribution<double> distr(-width, height);
		for (int i = 1; i < order; i++) {
			chanelPos[i][0] = chanelPos[i][0] + distr(eng);
			chanelPos[i][1] = chanelPos[i][1] + distr(eng);
		}
	}