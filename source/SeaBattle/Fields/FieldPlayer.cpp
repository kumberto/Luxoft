#include <ctime>
#include <cstdlib>
#include <thread>
#include <iostream>
#include "../stdafx.h"
#include "FieldPlayer.h"
#include "../Ships/OneDeckShip.h"
#include "../Ships/FourDeckShip.h"
#include "../Ships/ThreeDeckShip.h"
#include "../Ships/TwoDeckShip.h"


FieldPlayer::FieldPlayer()
	: Fields()
{
	std::thread *init = new std::thread(std::bind(&FieldPlayer::initField, this));
	init->join();
}

FieldPlayer::~FieldPlayer()
{
}

void FieldPlayer::initField()
{

	initShips();
}

void FieldPlayer::initShips() {
	srand(time(0));
	int rotationInt = rand() % 2;
	int x = rand() % 10;
	int y = rand() % 10;
	char rotation = 'v';
	if (rotationInt == 0) {
		rotation = 'h';
	}
	std::cout << "FourDeckShip" << std::endl;
	if (isEmpty(4, x, y, rotation)) {
		FourDeckShip* four = new FourDeckShip(4);
		buildShip(four, 4, x, y, rotation);
		setShips(four);
	}
	int countShips = 2;
	while (countShips) {
		x = rand() % 10;
		y = rand() % 10;
		rotationInt = rand() % 2;
		if (rotationInt == 0) {
			rotation = 'h';
		}
		else {
			rotation = 'v';
		}
		if (isEmpty(3, x, y, rotation)) {
			std::cout << "ThreeDeckShip" << std::endl;
			ThreeDeckShip* three = new ThreeDeckShip(3);
			buildShip(three, 3, x, y, rotation);
			setShips(three);
			countShips -= 1;
		}
	}
	countShips = 3;
	while (countShips) {
		x = rand() % 10;
		y = rand() % 10;
		rotationInt = rand() % 2;
		if (rotationInt == 0) {
			rotation = 'h';
		}
		else {
			rotation = 'v';
		}
		std::cout << "TwoDeckShips" << std::endl;
		if (isEmpty(2, x, y, rotation)) {
			TwoDeckShip* two = new TwoDeckShip(2);
			buildShip(two, 2, x, y, rotation);
			setShips(two);
			countShips -= 1;
		}
	}
	countShips = 4;
	while (countShips) {
		x = rand() % 10;
		y = rand() % 10;
		std::cout << "OneDeckShips" << std::endl;
		if (isEmpty(1, x, y, 'h')) {
			OneDeckShip* one = new OneDeckShip(1);
			buildShip(one, 1, x, y, 'h');
			setShips(one);
			countShips -= 1;
		}
	}
}