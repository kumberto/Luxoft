#include <time.h>
#include <iostream>
#include "../stdafx.h"
#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(std::string name, std::weak_ptr<FieldPlayer> field)
	: Players(name)
	, field_(field)
	, kill_(false)
	, rotation_('h')
{}

ComputerPlayer::~ComputerPlayer() {}

void ComputerPlayer::move()
{
	if (!kill_) {
		do {
			srand(unsigned(time(nullptr)));
			x_ = rand() % 10;
			y_ = rand() % 10;
		} while (!isEmpty());
	}
	else if (rotation_ == 'h') {
		x_ = hitX_;
		y_ = hitY_;
		if ((x_ = hitX_ + 1) && hitX_ != 9 && isEmpty()) {}
		else if (((x_ = hitX_ - 1)) && hitX_ != 0 && isEmpty()) {}
		else if ((x_ = hitX_) && field_.lock().get()->getValueFields(x_, y_) == "#" && field_.lock().get()->getValueFields(x_ - 1, y_) == "#") {
			while (field_.lock().get()->getValueFields(x_, y_) == "#") {
				x_ -= 1;
			}
		}
		else {
			rotation_ = 'v';
			if (y_ + 1 < 10) {
				y_ += 1;
			}
			else {
				y_ -= 1;
			}
		}
	}
	else if (rotation_ == 'v') {
		y_ = hitY_;
		x_ = hitX_;
		if ((y_ = hitY_ + 1) && hitY_ != 9 && isEmpty()) {}
		else if ((y_ = hitY_ - 1) && hitY_ != 0 && isEmpty()) {}
		else if ((y_ = hitY_)&& field_.lock().get()->getValueFields(x_, y_) == "#" && field_.lock().get()->getValueFields(x_, y_ - 1) == "#") {
			while (field_.lock().get()->getValueFields(x_, y_) == "#") {
				y_ -= 1;
			}
		}
		else {
			rotation_ = 'h';
			if (x_ + 1 < 10) {
				x_ += 1;
			}
			else {
				x_ -= 1;
			}
		}
	}
}

bool ComputerPlayer::isEmpty() {
	if (field_.lock().get()->getValueFields(x_, y_) == "+" || field_.lock().get()->getValueFields(x_, y_) == "#") {
		return false;
	}
	return true;
}
bool ComputerPlayer::shot()
{
	if (field_.lock().get()->isHit(x_, y_)) {
		setHit();
		kill_ = true;
		if (!field_.lock().get()->findShip(x_, y_)->isAlive()) {
			setKilledShips();
			kill_ = false;
		}
		else {
			hitX_ = x_;
			hitY_ = y_;
		}
		return true;
	}
	setMishit();
	return false;
}
bool ComputerPlayer::winner() {
	if (getHit() == 20) {
		return true;
	}
	return false;
}

