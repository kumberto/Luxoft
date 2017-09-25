#pragma once
#include <memory>
#include "Players.h"
#include "../Fields/FieldPlayer.h"
class ComputerPlayer :
	public Players
{
public:
	ComputerPlayer(std::string name, std::weak_ptr<FieldPlayer> field);
	~ComputerPlayer();
	void move();
	bool shot();
	bool winner();
private:
	bool isEmpty();
	std::weak_ptr<FieldPlayer> field_;
	int x_;
	int y_;
	int hitX_;
	int hitY_;
	bool kill_;
	char rotation_;
};

