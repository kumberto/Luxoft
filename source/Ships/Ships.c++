#include "Ships.h"

Ships::Ships(int shipDecks)
: shipDecks_(shipDecks)
{
}
Ships::~Ships()
{
}

bool isHit(int x, int y)
{
	for (auto point : pointDeck_) {
		if (x == point.getX() && y == point.getY()) {
			hit_ += 1;
			if (hit_ == shipDecks_) {
				alive_ = false;
			}
		}
	}
}

bool isAlive()
{
	return alive
}

int getShipDecks() const
{
	return shipDecks_;
}
void Ships::move()
{
	
}
