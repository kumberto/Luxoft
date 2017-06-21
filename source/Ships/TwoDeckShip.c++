#include "TwoDeckShip.h"

TwoDeckShip::TwoDeckShip(int shipDeck)
: Ships(shipDeck)
{
}

TwoDeckShip::~TwoDeckShip() {}

bool TwoDeckShip::initShip()
{
	move();
}