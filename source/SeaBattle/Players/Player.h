#pragma once
#include "Players.h"
#include "../Fields/FieldComputer.h"
class Player : public Players
{
public:
	Player(std::string name);
	~Player();
	void initField(FieldComputer *field);
	void move();
	bool shot(int x, int y);
private:
	FieldComputer *field_;
};

