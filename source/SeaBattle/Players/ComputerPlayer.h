#pragma once
#include "Players.h"
#include "../Fields/FieldPlayer.h"
class ComputerPlayer :
	public Players
{
public:
	ComputerPlayer(std::string name, const FieldPlayer& field);
	~ComputerPlayer();
	void initField(const FieldPlayer& field);
	void move();
	bool shot();
	bool winner();
private:
	bool isEmpty();
	const FieldPlayer& field_;
	int x_;
	int y_;
	int hitX_;
	int hitY_;
	bool kill_;
	char rotation_;
};

