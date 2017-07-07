#include "../stdafx.h"
#include "FourDeckShip.h"


FourDeckShip::FourDeckShip(int shipDeck)
	: Ships(shipDeck)
{
}

FourDeckShip::~FourDeckShip() {}

void FourDeckShip::initDeckPoint(std::initializer_list<Point> list)
{
	setPointDeck(list);
}