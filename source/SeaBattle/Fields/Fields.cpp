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

bool Fields::isHit(int x, int y)
{
	if (field_[x][y] == "x") {
		field_[x][y] = "#";
		return true;
	}
	else if (field_[x][y] == " ") {
		field_[x][y] = "+";
	}
	return false;
}

std::string Fields::getValueFields(int x, int y)
{
	return field_[x][y];
}

bool Fields::isEmpty(int deck, int x, int y, char rotation)
{
	int row = y;
	int col = x;
	int startY = y;
	int startX = x;
	if (rotation == 'h') {
		row += 2;
		col += 1;
		if ((x == 0 && y == 9)) {
			row -= 1;
			startY = 8;
		}
		else if (x == 9 && y == 9) {
			startY -= 1;
			row -= 1;
		}
		if (x + deck >= 9) {
			startX = 9 - deck;
			col = 10;
		}
		if (x == 0) {
			col += (deck - 1);
		}
		if (x > 0 && x + deck < 9) {
			startX -= 1;
			col += deck;
		}
		if (y > 0) {
			startY -= 1;
		}
		if (y == 9) {
			row = 10;
		}
	}
	else if (rotation == 'v') {
		col += 2;
		row += 1;
		if (x > 0 && y > 0 && (y + deck) < 9) {
			startX -= 1;
			startY -= 1;
			row += deck;
		}
		else if (x == 0 && y == 0) {
			row += deck;
			col -= 1;
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
		if (y + deck >= 9 && x > 0) {
			startY = 9 - deck;
			row = 10;
			startX -= 1;
		}
		if (x == 9) {
			col = 10;
		}
	}
	for (int i = startY; i < row; i++) {
		for (int j = startX; j < col; j++) {
			if (field_[j][i] == "x") {
				return false;
			}
		}
	}
	return true;
}

void Fields::buildShip(Ships* ship, int deck, int x, int y, char rotation) {
	if (rotation == 'h') {
		if (x + deck > 9) {
			x = 10 - deck;
		}
		for (int i = 0; i < deck; i++) {
			field_[x + i][y] = "x";
			ship->initDeckPoint(Point((x + i), y));
		}
	}
	else {
		if (y + deck > 9) {
			y = 10 - deck;
		}
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

bool Fields::isAliveShip(int x, int y) {
	return true;
}

Ships& Fields::findShip(int x, int y) {
	Ships *ship = nullptr;
	for (auto ship : ships_) {

		for (int i = 0; i < ship->getShipDecks(); i++) {
			ship->isAlive();
		}
	}
	return *ship;
}

