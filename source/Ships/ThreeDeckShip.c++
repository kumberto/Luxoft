#include "Ships.h"

ThreeDeckShip::ThreeDeckShip(int shipDeck)
: Ships(shipDeck)
{
}

ThreeDeckShip::~ThreeDeckShip() {}

bool ThreeDeckShip::initShip()
{
	move();
}