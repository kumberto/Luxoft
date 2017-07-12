#pragma once
#include "Ships.h"
class OneDeckShip :
	public Ships
{
public:
	OneDeckShip(int shipDeck);
	~OneDeckShip();
	void initDeckPoint(const Point& point);
};

