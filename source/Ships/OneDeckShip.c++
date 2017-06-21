#include "OneDeckShip.h"

OneDeckShip::OneDeckShip(int shipDeck)
: Ships(shipDeck)
{
}

OneDeckShip::~OneDeckShip()
{
}

bool OneDeckShip::initShip()
{
	move();
}