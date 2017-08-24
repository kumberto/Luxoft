#include <time.h>
#include <iostream>
#include "../stdafx.h"
#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(std::string name, const FieldPlayer &field)
	: Players(name)
	, field_(field)
{}

ComputerPlayer::~ComputerPlayer() {}

void ComputerPlayer::initField(const FieldPlayer &field) {
	
}

void ComputerPlayer::move()
{
	srand(unsigned int(time(nullptr)));
		std::cout << "move Computer" << std::endl;
		do {
			x_ = rand() % 10;
			y_ = rand() % 10;
		} while (!isEmpty());
}

bool ComputerPlayer::isEmpty() {
	if (field_.getValueFields(x_, y_) == " ") {
		return true;
	}
	return false;
}

bool ComputerPlayer::shot()
{
	if (field_.isHit(x_, y_)) {
		setHit();
		return true;
	}
	return false;
}
bool ComputerPlayer::winner() {
	if (getHit() == 20) {
		statistics();
		return true;
	}
	return false;
}

