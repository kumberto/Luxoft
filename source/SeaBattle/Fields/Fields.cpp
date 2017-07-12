#include <iostream>
#include "../stdafx.h"
#include "Fields.h"
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
	return field_[x][y];
}

bool Fields::isEmpty(int deck, int x, int y, char rotation)
{
	int row = y;
	int col = x;
	std::cout << "x = " << x << " y = " << y;
	if (rotation == 'h') {
		row += 2;
		if (x == 0) {
			col += (deck + 1);
		}
		if ((x == 0 && y == 9)) {
			row -= 1;
			y = 8;
		}
		if (x == 9) {
			col += 1;
			x -= deck;
		}
		if (x == 9 && y == 9) {
			y -= 1;
			row -= 1;
		}
		std::cout << "  H deck = " << deck << "  ";
		for (int i = y - 1; i < row; i++) {
			for (int j = x - 1; j < col; j++) {
				std::cout << '(' << i << ", " << j << ')';
				if (field_[j][i] == "x") {
					return false;
				}
			}
		}
		std::cout << std::endl;
	}
	else if (rotation == 'v') {
		col += 2;
		row += 1;
		if (x != 0 && x != 9 && y != 0 && (y + deck) != 9) {
			x -= 1;
			y -= 1;
			row += deck;
		}
		else if (x == 0 && y == 0) {
			row += deck;
		}
		else if (x == 9 && y == 0) {
			col -= 1;
			x -= 1;
			row += deck;
		}
		else if (y == 0) {
			x -= 1;
			row += deck;
		}
		else if (x == 0 && y == 9) {
			y -= deck;
		}
		else if (x == 9 && y == 9) {
			y -= deck;
			x -= 1;
			col -= 1;
		}
		else if (y == 9) {
			y -= deck;
			x -= 1;
		}
		else if (x == 0 && ((y + deck) != 9)) {
			y -= 1;
			row += deck;
		}
		else if (x == 9 && ((y + deck) != 9)) {
			x -= 1;
			col -= 1;
			row += deck;
			y -= 1;
		}
		std::cout << "  V deck = " << deck << "  ";
		for (int i = y; i < row; i++) {
			for (int j = x; j < col; j++) {
				std::cout << '(' << i << ", " << j << ')';
				if (field_[j][i] == "x") {
					return false;
				}
			}
		}
		std::cout << std::endl;
	}
	return true;
}

void Fields::buildShip(Ships* ship, int deck, int x, int y, char rotation) {
	if (rotation == 'h') {
		for (int i = 0; i < deck; i++) {
			field_[x + i][y] = "x";
			ship->initDeckPoint(Point((x + i), y));
		}
	}
	else {
		for (int i = 0; i < deck; i++) {
			field_[x][y + i] = "x";
			ship->initDeckPoint(Point(x, (y + i)));
		}

	}
}

void Fields::setShips(Ships * ship)
{
	ships_.push_back(ship);
}


