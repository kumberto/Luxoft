#pragma once
#include "Players.h"
#include "../Fields/FieldComputer.h"
class Player : public Players
{
public:
	Player(std::string name, const FieldComputer& field);
	~Player();
	void move();
	bool shot();
	bool winner();
private:
	const FieldComputer& field_;
	int x_;
	int y_;
};

