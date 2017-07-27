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
int Ships::getSizeDeck() const
{
	return pointDeck_.size();
}
void Ships::setHit()
{
	hit_ += 1;
}
void Ships::setPointDeck(const Point & point)
{
	pointDeck_.push_back(point);
}