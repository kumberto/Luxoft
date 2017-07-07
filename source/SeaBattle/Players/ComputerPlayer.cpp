#include "../stdafx.h"
#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(std::string name)
	: Players(name)
{}

ComputerPlayer::~ComputerPlayer() {}

void ComputerPlayer::move()
{}

bool ComputerPlayer::shot(int x, int y)
{
	return true;
}

