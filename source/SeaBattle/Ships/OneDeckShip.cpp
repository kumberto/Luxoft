#include "../stdafx.h"
#include "OneDeckShip.h"


OneDeckShip::OneDeckShip(int shipDeck)
	: Ships(shipDeck)
{
}

OneDeckShip::~OneDeckShip()
{
}

void OneDeckShip::initDeckPoint(std::initializer_list<Point> list)
{
	setPointDeck(list);
}
