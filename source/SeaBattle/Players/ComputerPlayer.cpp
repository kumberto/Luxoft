#include "../stdafx.h"
#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(std::string name)
	: Players(name)
{}

ComputerPlayer::~ComputerPlayer() {}

void ComputerPlayer::initField(FieldPlayer *field) {
	field_ = field;
}

void ComputerPlayer::move()
{}

bool ComputerPlayer::shot(int x, int y)
{
	if (field_->isHit(x, y)) {
		if (field_->isAliveShip(x, y)) {}
		return true;
	}
	return true;
}

