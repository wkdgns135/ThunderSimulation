#pragma once
#include "Global.h"

class Rod {
public:
	int pos;
	bool state;
public:
	Rod(int _pos) {
		pos = _pos;
		state = false;
	}
public:
	void LightningRod(double(*lattice)[index + 1]);
	void LightningRodDisplay();
};