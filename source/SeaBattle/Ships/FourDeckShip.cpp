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