#include "../stdafx.h"
#include "Ships.h"

Ships::Ships(int shipDecks)
	: shipDecks_(shipDecks)
{
}

Ships::~Ships()
{
}

bool Ships::isHit(int x, int y)
{
	for (auto point : pointDeck_) {
		if (x == point.getX() && y == point.getY()) {
			hit_ += 1;
			if (hit_ == shipDecks_) {
				alive_ = false;
			}
		}
	}
	return true;
}

bool Ships::isAlive()
{
	return alive_;
}

int Ships::getShipDecks() const
{
	return shipDecks_;
}
void Ships::setPointDeck(std::initializer_list<Point> list)
{
	pointDeck_.insert(pointDeck_.begin(), list.begin(), list.end());
}