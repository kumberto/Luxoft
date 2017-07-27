#pragma once
#include "Ships.h"
class FourDeckShip :
	public Ships
{
public:
	FourDeckShip(int shipDeck);
	~FourDeckShip();
	void initDeckPoint(const Point& point);
	bool isPoint(int x, int y);
};

