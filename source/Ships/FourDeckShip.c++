#include "Ships.h"

FourDeckShip::FourDeckShip(int shipDeck)
: Ships(shipDeck)
{
}

FourDeckShip::~FourDeckShip() {}

bool FourDeckShip::initShip()
{
	move();
}