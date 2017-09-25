#pragma once
#include <memory>
#include "Players.h"
#include "../Fields/FieldComputer.h"
class Player : public Players
{
public:
	Player(std::string name, std::weak_ptr<FieldComputer> field);
	~Player();
	void move();
	bool shot();
	bool winner();
private:
	std::weak_ptr<FieldComputer> field_;
	int x_;
	int y_;
};

