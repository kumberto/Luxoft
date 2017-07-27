#pragma once
#include "Players.h"
#include "../Fields/FieldPlayer.h"
class ComputerPlayer :
	public Players
{
public:
	ComputerPlayer(std::string name);
	~ComputerPlayer();
	void initField(FieldPlayer *field);
	void move();
	bool shot(int x, int y);
private:
	FieldPlayer *field_;
};

