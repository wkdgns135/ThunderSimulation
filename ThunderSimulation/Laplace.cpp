#include "Laplace.h"
#include <math.h>
#include <string>
#include <iostream>
#include <cstdlib>
#include <random>

	Laplace InterpolationHeight(Laplace laplace, double(*lattice)[index + 1]) {
		double potential;
		for (int i = 0; i <= index; i++) {
			for (int j = index - 1; j >= 0; j--) {
				if (j == 0 && i == 0) {
					potential = 0.25 * (lattice[j][i] + lattice[j][i + 1]);
					if (!lattice[j][i] == 0)lattice[j][i] = potential;
					continue;
				}
				else if (j == 0 && i == index) {
					potential = 0.25 * (lattice[j + 1][i] + lattice[j][i - 1]);
					if (!lattice[j][i] == 0)lattice[j][i] = potential;
					continue;
				}
				else if (j == 0) {
					potential = 0.25 * (lattice[j + 1][i] + lattice[j][i + 1] + lattice[j][i - 1]);
					if (!lattice[j][i] == 0)lattice[j][i] = potential;
					continue;
				}
				else if (i == 0) {
					potential = 0.25 * (lattice[j + 1][i] + lattice[j - 1][i] + lattice[j][i + 1]);
					if (!lattice[j][i] == 0)lattice[j][i] = potential;
					continue;
				}
				else if (i == index) {
					potential = 0.25 * (lattice[j + 1][i] + lattice[j - 1][i] + lattice[j][i - 1]);
					if (!lattice[j][i] == 0)lattice[j][i] = potential;
					continue;
				}
				potential = 0.25 * (lattice[j + 1][i] + lattice[j - 1][i] + lattice[j][i - 1] + lattice[j][i + 1]);
				if (!lattice[j][i] == 0)lattice[j][i] = potential;
			}
		}
		return laplace;
	}
	Laplace InterpolationWidth(Laplace laplace, double(*lattice)[index + 1]) {
		double potential;
		for (int i = index - 1; i >= 0; i--) {
			for (int j = 0; j <= index; j++) {
				if (i == 0 && j == 0) {
					potential = 0.25 * (lattice[i + 1][j] + lattice[i][j + 1]);
					if (!lattice[i][j] == 0)lattice[i][j] = potential;
					continue;
				}
				else if (i == 0 && j == index) {
					potential = 0.25 * (lattice[i + 1][j] + lattice[i][j - 1]);
					if (!lattice[i][j] == 0)lattice[i][j] = potential;
					continue;
				}
				else if (i == 0) {
					potential = 0.25 * (lattice[i + 1][j] + lattice[i][j + 1] + lattice[i][j - 1]);
					if (!lattice[i][j] == 0)lattice[i][j] = potential;
					continue;
				}
				else if (j == 0) {
					potential = 0.25 * (lattice[i + 1][j] + lattice[i - 1][j] + lattice[i][j + 1]);
					if (!lattice[i][j] == 0)lattice[i][j] = potential;
					continue;
				}
				else if (j == index) {
					potential = 0.25 * (lattice[i + 1][j] + lattice[i - 1][j] + lattice[i][j - 1]);
					if (!lattice[i][j] == 0)lattice[i][j] = potential;
					continue;
				}
				potential = 0.25 * (lattice[i + 1][j] + lattice[i - 1][j] + lattice[i][j - 1] + lattice[i][j + 1]);
				if (!lattice[i][j] == 0)lattice[i][j] = potential;
			}
		}
		return laplace;
	}
	Laplace InterpolationValue(Laplace laplace, double(*lattice)[index + 1]) {
		for (int i = laplace.row; i < index; i++) {
			for (int j = 0; j <= index; j++) {
				if (lattice[i][j] != 0)lattice[i][j] = laplace.t;
			}
		}
		return laplace;
	}