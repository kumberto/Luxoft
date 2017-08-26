#include <time.h>
#include <iostream>
#include "../stdafx.h"
#include "ComputerPlayer.h"


ComputerPlayer::ComputerPlayer(std::string name, const FieldPlayer &field)
	: Players(name)
	, field_(field)
	, kill_(false)
	, rotation_('h')
{}

ComputerPlayer::~ComputerPlayer() {}

void ComputerPlayer::initField(const FieldPlayer &field) {
	
}

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
		std::cout << "x_ = " << x_ << " y_ = " << y_ << " hitX_ = " << hitX_ << " hitY_ = " << hitY_ << std::endl;
		if ((x_ = hitX_ + 1) && hitX_ != 9 && isEmpty()) {}
		else if (((x_ = hitX_ - 1)) && hitX_ != 0 && isEmpty()) {}
		else if ((x_ = hitX_) && field_.getValueFields(x_, y_) == "#" && field_.getValueFields(x_ - 1, y_) == "#") {
			while (field_.getValueFields(x_, y_) == "#") {
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
		std::cout << "x_ = " << x_ << " y_ = " << y_ << " hitX_ = " << hitX_ << " hitY_ = " << hitY_ << std::endl;
		if ((y_ = hitY_ + 1) && hitY_ != 9 && isEmpty()) {}
		else if ((y_ = hitY_ - 1) && hitY_ != 0 && isEmpty()) {}
		else if ((y_ = hitY_)&& field_.getValueFields(x_, y_) == "#" && field_.getValueFields(x_, y_ - 1) == "#") {
			while (field_.getValueFields(x_, y_) == "#") {
				y_ -= 1;
			}
		}
		else {
			std::cout << " Data before change rotation -> x_ = " << x_ << " y_ = " << y_ << " hitX_ = " << hitX_ << " hitY_ = " << hitY_ << std::endl;
			rotation_ = 'h';
			if (x_ + 1 < 10) {
				x_ += 1;
			}
			else {
				x_ -= 1;
			}
			std::cout << " Data after change rotation -> x_ = " << x_ << " y_ = " << y_ << " hitX_ = " << hitX_ << " hitY_ = " << hitY_ << std::endl;
		}
	}
}

bool ComputerPlayer::isEmpty() {
	if (field_.getValueFields(x_, y_) == "+" || field_.getValueFields(x_, y_) == "#") {
		return false;
	}
	return true;
}
bool ComputerPlayer::shot()
{
	if (field_.isHit(x_, y_)) {
		setHit();
		kill_ = true;
		if (!field_.findShip(x_, y_)->isAlive()) {
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

