#include "../stdafx.h"
#include "FourDeckShip.h"


FourDeckShip::FourDeckShip(int shipDeck)
	: Ships(shipDeck)
{
}

FourDeckShip::~FourDeckShip() {}

void FourDeckShip::initPoint(std::initializer_list<Point> list)
{
	setPointDeck(list);
}