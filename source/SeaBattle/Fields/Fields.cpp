#include <time.h>
#include "../stdafx.h"
#include "Fields.h"
#include "../Ships/OneDeckShip.h"
#include "../Ships/Point.h"

Fields::Fields(const Players& player, const Players& playerOwn)
	: player_(player)
	, playerOwm_(playerOwn)
	, field_(10,{" ", " ", " ", " ", " ", " ", " ", " ", " ", " "})
{
}

bool Fields::repeatHit()
{
	return true;
}

std::string Fields::getValueFields(int x, int y)
{
	return field_[y][x];
}

void Fields::initShips()
{
	srand(unsigned(time(0)));

}

bool Fields::isEmpty(int deck, int x, int y, char rotation)
{
	int row = 0;
	int col = 0;
	if ((x == 0 && y == 0)) {
		row = 2;
	}
	else if (x + deck > 9) {
		x -= deck;
	}
	else {
		row = 3;
		x -= 1;
	}
	if (y == 0) {
		col = 2;
	}
	else if (y + deck > 9) {
		y = 9 - deck;
		col = 2;
	}
	else {
		col = 3;
		y -= 1;
	}
	if (rotation == 'h') {
		col += (deck - 1 + x);
		row += y;
	}
	else if (rotation == 'v') {
		row += (deck - 1 + y);
		col += x;
	}
	for (int i = y; i < row; i++) {
		for (int j = x; j < col; j++) {
			if (field_[y][x] == "x") {
				return false;
			}
		}
	}

	return true;
}


