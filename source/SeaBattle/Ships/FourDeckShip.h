#pragma once
#include "Ships.h"
class FourDeckShip :
	public Ships
{
public:
	FourDeckShip(int shipDeck);
	~FourDeckShip();
	void initPoint(std::initializer_list<Point> list);
};

