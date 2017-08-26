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
	for (int i = 0; i < shipDecks_; i++) {
		if (pointDeck_[i].getX() == x && pointDeck_[i].getY() == y) {
			return true;
		}
	}
	return false;
}

