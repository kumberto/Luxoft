#pragma once
#include "Ships.h"
class TwoDeckShip :
	public Ships
{
public:
	TwoDeckShip(int shipDeck);
	~TwoDeckShip();
	void initDeckPoint(const Point& point);
};

