#pragma once
#include "Ships.h"
class ThreeDeckShip :
	public Ships
{
public:
	ThreeDeckShip(int shipDeck);
	~ThreeDeckShip();
	void initDeckPoint(const Point& point);
	bool isPoint(int x, int y);
};

