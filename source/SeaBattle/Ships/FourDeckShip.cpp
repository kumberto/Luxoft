#include "../stdafx.h"
#include "FourDeckShip.h"


FourDeckShip::FourDeckShip(int shipDeck)
	: Ships(shipDeck)
{
}

FourDeckShip::~FourDeckShip() {}

void FourDeckShip::initDeckPoint(const Point& point)
{
	int sizeVectorDeck = getSizeDeck();
	int deck = getShipDecks();
	if (sizeVectorDeck < deck) {
		setPointDeck(point);
	}
}
bool FourDeckShip::isPoint(int x, int y) {
	for (int i = 0; i < shipDecks_; i++) {
		if (pointDeck_[i].getX() == x && pointDeck_[i].getY() == y) {
			return true;
		}
	}
	return false;
}