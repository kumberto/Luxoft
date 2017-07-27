#include "../stdafx.h"
#include "TwoDeckShip.h"


TwoDeckShip::TwoDeckShip(int shipDeck)
	: Ships(shipDeck)
{
}


TwoDeckShip::~TwoDeckShip()
{
}
void TwoDeckShip::initDeckPoint(const Point& point)
{
	setPointDeck(point);
}

bool TwoDeckShip::isPoint(int x, int y)
{
	return false;
}

