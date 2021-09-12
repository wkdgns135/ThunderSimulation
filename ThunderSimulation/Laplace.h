#pragma once
#include "Global.h"

using namespace std;
extern const short int index;

	struct Laplace {
	public:
		double eta;
		int order;
		int row;
		int col;
		double t;
	public:
		Laplace(double m_t, double m_eta) {
			t = m_t;
			eta = m_eta;
		}
	};

	Laplace InterpolationWidth(Laplace laplace, double(*lattice)[index + 1]);
	Laplace InterpolationHeight(Laplace laplace, double(*lattice)[index + 1]);
	Laplace InterpolationValue(Laplace laplac, double(*lattice)[index + 1]);