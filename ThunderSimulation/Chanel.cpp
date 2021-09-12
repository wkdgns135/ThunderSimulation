#include "Chanel.h"
#include <random>
#include <iostream>
#include <math.h>

using namespace std;

Laplace MainChanel(Laplace laplace, double(*lattice)[index + 1], double(*mainChanelPos)[2]) {
	double phi[9];
	double totalPhi = 0;
	int count = 0;
	double temp = 0;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (laplace.row + i > index || laplace.row + i < 0 || laplace.col + j > index || laplace.col + j < 0) {
				phi[count] = 0;
				count++;
				continue;
			}
			phi[count] = lattice[laplace.row + i][laplace.col + j];
			phi[count] = pow(phi[count], laplace.eta);

			count++;
		}
	}
	for (double i : phi) {
		totalPhi += i;
	}
	for (int i = 0; i < 9; i++) {
		phi[i] = phi[i] / totalPhi * 100;
	}

	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_real_distribution<double> distr(0, 101);
	double rand = distr(eng);
	if (rand < 1)rand = distr(eng);

	count = 0;
	bool exitLoop = false;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			temp += phi[count];
			if (temp >= rand) {
				laplace.row += i;
				laplace.col += j;
				laplace.order++;
				mainChanelPos[laplace.order][0] = laplace.row;
				mainChanelPos[laplace.order][1] = laplace.col;
				lattice[laplace.row][laplace.col] = 0;

				exitLoop = true;
				break;
			}
			count++;
		}
		if (exitLoop) break;
	}
	return laplace;
}

/*
Laplace SubChanel(Laplace laplace, int subRow, int subCol, double(*lattice)[index + 1], double(*chanel)[index + 1], double(*chanelPos)[2], double(*subChanelPos)[index * 2][2]) {
	double phi[9];
	double totalPhi = 0;
	int count = 0;
	double temp = 0;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (subRow + i > index || subRow + i < 0 || subCol + j > index || subCol + j < 0) {
				phi[count] = 0;
				count++;
				continue;
			}
			//phi[count] = lattice[laplace.row+i][laplace.point+j];
			phi[count] = lattice[subRow][subCol + j]; // Nomalize phi
			phi[count] = pow(phi[count], laplace.eta); // 조절 인자 eta 제곱
			count++;
		}
	}
	for (double i : phi) {
		totalPhi += i;
	}
	if (totalPhi != 0) {

		for (int i = 0; i < 9; i++) {
			phi[i] = phi[i] / totalPhi * 100;
			cout << "phi = " << phi[i] << endl;
		}

		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_real_distribution<double> distr(0, 101);
		count = 0;
		bool exitLoop = false;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				double rand = distr(eng);
				cout << "rand = " << rand << endl;
				if (phi[count] > rand) {
					lattice[subRow][subCol] = 0;

					laplace.subChanelCount++;
					exitLoop = true;
					break;
				}
				count++;
			}
			if (exitLoop) break;
		}

		return laplace;

	}
}
*/
