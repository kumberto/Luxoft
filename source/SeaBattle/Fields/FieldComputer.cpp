#include <time.h>
#include <thread>
#include "../stdafx.h"
#include "FieldComputer.h"
#include "../Ships/OneDeckShip.h"
#include "../Ships/FourDeckShip.h"
#include "../Ships/ThreeDeckShip.h"
#include "../Ships/TwoDeckShip.h"


FieldComputer::FieldComputer()
	: Fields()
{
	std::thread init(std::bind(&FieldComputer::initField, this));
	init.join();
}

FieldComputer::~FieldComputer()
{
}

void FieldComputer::initField()
{
	initShips();
}
void FieldComputer::initShips() {
	srand(unsigned(time(nullptr)));
	int rotationInt = rand() % 2;
	x_ = rand() % 10;
	y_ = rand() % 10;
	char rotation = 'v';
	if (rotationInt == 0) {
		rotation = 'h';
	}
	if (isEmpty(4, x_, y_, rotation)) {
		FourDeckShip* four = new FourDeckShip(4);
		buildShip(four, 4, x_, y_, rotation);
		setShips(four);
	}
	int countShips = 2;
	while (countShips) {
		x_ = rand() % 10;
		y_ = rand() % 10;
		rotationInt = rand() % 2;
		if (rotationInt == 0) {
			rotation = 'h';
		}
		else {
			rotation = 'v';
		}
		if (isEmpty(3, x_, y_, rotation)) {
			ThreeDeckShip* three = new ThreeDeckShip(3);
			buildShip(three, 3, x_, y_, rotation);
			setShips(three);
			countShips -= 1;
		}
	}
	countShips = 3;
	while (countShips) {
		x_ = rand() % 10;
		y_ = rand() % 10;
		rotationInt = rand() % 2;
		if (rotationInt == 0) {
			rotation = 'h';
		}
		else {
			rotation = 'v';
		}
		if (isEmpty(2, x_, y_, rotation)) {
			TwoDeckShip* two = new TwoDeckShip(2);
			buildShip(two, 2, x_, y_, rotation);
			setShips(two);
			countShips -= 1;
		}
	}
	countShips = 4;
	while (countShips) {
		x_ = rand() % 10;
		y_ = rand() % 10;
		rotationInt = rand() % 2;
		if (rotationInt == 0) {
			rotation = 'h';
		}
		else {
			rotation = 'v';
		}
		if (isEmpty(1, x_, y_, rotation)) {
			OneDeckShip* one = new OneDeckShip(1);
			buildShip(one, 1, x_, y_, rotation);
			setShips(one);
			countShips -= 1;
		}
	}
}
