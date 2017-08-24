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
	for (int i = 0; i < shipDecks_; i++) {
		if (pointDeck_[i].getX() == x && pointDeck_[i].getY() == y) {
			setHit();
			return true;
		}
	}
	return false;
}

