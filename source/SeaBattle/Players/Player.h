#pragma once
#include "Players.h"
class Player :
	public Players
{
public:
	Player(std::string name);
	~Player();
	void move();
	bool shot(int x, int y);
};

