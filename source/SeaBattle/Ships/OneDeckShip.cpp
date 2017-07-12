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
