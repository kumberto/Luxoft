#include "../stdafx.h"
#include "OneDeckShip.h"


OneDeckShip::OneDeckShip(int shipDeck)
	: Ships(shipDeck)
{
}

OneDeckShip::~OneDeckShip()
{
}

void OneDeckShip::initDeckPoint(const Point& point)
{
	setPointDeck(point);
}

bool OneDeckShip::isPoint(int x, int y)
{
	for (int i = 0; i < shipDecks_; i++) {
		if (pointDeck_[i].getX() == x && pointDeck_[i].getY() == y) {
			return true;
		}
	}
	return false;
}
