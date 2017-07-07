#pragma once
#include "Ships.h"
class FourDeckShip :
	public Ships
{
public:
	FourDeckShip(int shipDeck);
	~FourDeckShip();
	void initDeckPoint(std::initializer_list<Point> list);
};

