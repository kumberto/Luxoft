#include "../stdafx.h"
#include "Player.h"


Player::Player(std::string name)
	: Players(name)
{
}
Player::~Player() {}

void Player::move()
{
}

bool Player::shot(int x, int y)
{
	return true;
}