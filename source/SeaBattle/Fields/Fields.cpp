#include <iostream>
#include "../stdafx.h"
#include "Fields.h"
#include "../Ships/Point.h"

Fields::Fields()
	: field_(10,{" ", " ", " ", " ", " ", " ", " ", " ", " ", " "})
{
}

bool Fields::isHit(int x, int y) const
{
	if (field_[x][y] == "x") {
		field_[x][y] = "#";
		findShip(x, y)->isHit(x, y);
		return true;
	}
	else if (field_[x][y] == " ") {
		field_[x][y] = "+";
	}
	return false;
}

std::string Fields::getValueFields(int x, int y) const
{
	return field_[x][y];
}

bool Fields::isEmpty(int deck, int x, int y, char rotation)
{
	int row = y;
	int col = x;
	int startY = y;
	int startX = x;
	std::cout <<" x: " << x << " y: " << y;
	if (rotation == 'h') {
		std::cout << " h-> ";
		row += 2;
		col += 1;
		if ((x == 0 && y == 9)) {
			row -= 1;
			col = deck + 1;
			startY = 8;
		}
		else if (x == 9 && y == 9) {
			startY = y - 1;
			startX = 10 - deck;
			row -= 1;
		}
		else if (x + deck > 9) {
			startX = 9 - deck;
			col = 10;
		}
		else if (x == 0) {
			col += deck;
		}
		else if (x > 0 && x + deck < 10) {
			startX = x - 1;
			col += deck;
		}
		if (y > 0) {
			startY = y - 1;
		}
		if (y == 9) {
			row = 10;
		}
		if (x == 9) {
			startX = 9 - deck;
		}
	}
	else if (rotation == 'v') {
		std::cout << " v-> ";
		col += 2;
		row += 1;
		if (x > 0 && (x + 1) < 10 && y > 0 && (y + deck) < 10) {
			startX = x -1;
			startY = y - 1;
			row += deck;
		}
		else if (x == 0 && y == 0) {
			row += (deck + 1);
		}
		else if (x == 9 && y == 0) {
			col -= 1;
			startX = x - 1;
			row += deck;
		}
		else if (y == 0) {
			startX = x - 1;
			row += deck;
		}
		else if (x == 0 && y == 9) {
			startY = y - deck;
		}
		else if (x == 9 && y == 9) {
			startY = y - deck;
			startX = x - 1;
			col -= 1;
		}
		else if (y == 9) {
			startY = y - deck;
			startX = x - 1;
		}
		else if (x == 9) {
			startX = 8;
			startY = y - 1;
			col = 10;
			row += deck;
		}
		else if (x == 0 && (y + deck) < 10) {
			startY = y - 1;
			row += deck;
		}
		if (y + deck > 9 && x > 0) {
			startY = 9 - deck;
			row = 10;
			startX = x - 1;
		}
		
	}
	std::cout << " startX: " << startX << " startY: " << startY;
	for (int i = startY; i < row; i++) {
		for (int j = startX; j < col; j++) {
			std::cout << " x = " << j << " y = " << i;
			if (field_[j][i] == "x") {
				std::cout << " false " << std::endl;
				return false;
			}
		}
	}
	std::cout << "TRUE" << std::endl;
	return true;
}

void Fields::buildShip(Ships* ship, int deck, int x, int y, char rotation) {
	std::cout << "Building ships x = " << x << " y = " << y;
	if (rotation == 'h') {
		if (x + deck > 9) {
			x = 10 - deck;
		}
		for (int i = 0; i < deck; i++) {
			std::cout << " x = " << (x+i);
			field_[x + i][y] = "x";
			ship->initDeckPoint(Point((x + i), y));
		}
	}
	else {
		if (y + deck > 9) {
			y = 10 - deck;
		}
		for (int i = 0; i < deck; i++) {
			std::cout << " y = " << (y + i);
			field_[x][y + i] = "x";
			ship->initDeckPoint(Point(x, (y + i)));
		}
	}
	std::cout << std::endl;
}

void Fields::setShips(Ships * ship)
{
	ships_.push_back(ship);
}

const Ships* Fields::findShip(int x, int y) const {
	for (auto ship : ships_) {
		if (ship->isPoint(x, y)) {
			return ship;
		}
	}
}

