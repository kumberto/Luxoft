#include "../stdafx.h"
#include "ThreeDeckShip.h"


ThreeDeckShip::ThreeDeckShip(int shipDeck)
	: Ships(shipDeck)
{
}


ThreeDeckShip::~ThreeDeckShip()
{
}
void ThreeDeckShip::initDeckPoint(const Point& point)
{
	setPointDeck(point);
}

bool ThreeDeckShip::isPoint(int x, int y)
{
	return false;
}

