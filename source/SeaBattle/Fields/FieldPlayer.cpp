#include "../stdafx.h"
#include "FieldPlayer.h"


FieldPlayer::FieldPlayer(const Players& player, const Players& playerOwn)
	: Fields(player, playerOwn)
{
	initField();
}

FieldPlayer::~FieldPlayer()
{
}

void FieldPlayer::initField()
{
	initShips();
}