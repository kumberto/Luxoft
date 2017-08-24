#include <iostream>
#include "../stdafx.h"
#include "Player.h"


Player::Player(std::string name, const FieldComputer& field)
	: Players(name)
	, field_(field)
{
}
Player::~Player() {}


void Player::move()
{
	std::cout << "move Player" << std::endl;
	std::cout << "Enter x ";
	do {
		std::cin >> x_;
	} while (x_ < 0 || x_ > 9);

		
	std::cout << "Enter y ";
	do {
		std::cin >> y_;
	} while (y_ < 0 || y_ > 9);
}

bool Player::shot()
{
	if (field_.isHit(x_, y_)) {
		setHit();
		return true;
	}
	return false;
}

bool Player::winner() {
	if (getHit() == 20) {
		statistics();
		return true;
	}
	return false;
}