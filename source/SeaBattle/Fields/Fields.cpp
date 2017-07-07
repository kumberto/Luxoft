#include <time.h>
#include "../stdafx.h"
#include "Fields.h"
#include "../Ships/OneDeckShip.h"
#include "../Ships/FourDeckShip.h"
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
	int x = rand() % 10;
	int y = rand() % 10;
	isEmpty(4, x, y, 'h');
	FourDeckShip* four = new FourDeckShip(4);
	ships_.push_back(four);
}

bool Fields::isEmpty(int deck, int x, int y, char rotation)
{
	int row = 0;
	int col = 0;
	if (rotation == 'h') {
		row = 3;
		if ((x == 0 && y == 0) || (x == 0 && y == 9) || (x == 9 && y == 0) || (x == 9 && y == 9)) {
			col = deck + 1;
			row = 2;
		}
		else if (x == 0) {
			col = deck + 1;
		}
		else if (x + deck > 9 ) {
			x = 9 - deck;
		}
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


