#include "../stdafx.h"
#include "Player.h"


Player::Player(std::string name)
	: Players(name)
{
}
Player::~Player() {}

void Player::initField(FieldComputer *field) {
	field_ = field;
}

void Player::move()
{
}

bool Player::shot(int x, int y)
{
	if (field_->isHit(x, y)) {
		return true;
	}
	return false;
}