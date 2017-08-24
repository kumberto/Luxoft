#include <iostream>
#include "../stdafx.h"
#include "Players.h"


Players::Players(std::string name)
	: name_(name)
	, hit_(0)
	, mishit_(0)
	, killedShips_(0)
{
}

Players::~Players()
{
}

std::string Players::getName() const
{
	return name_;
}

void Players::statistics() const
{
	std::cout << name_ << "\n";
	std::cout << "Hits: " << hit_ << "\n";
	std::cout << "Mishit: " << mishit_ << "\n";
	std::cout << "Killed ships: " << killedShips_ << std::endl;
}

int Players::getHit() const
{
	return hit_;
}

void Players::setHit()
{
	hit_ += 1;
}

int Players::getMishit() const
{
	return mishit_;
}

void Players::setMishit()
{
	mishit_ += 1;
}

int Players::getKilledShips() const
{
	return killedShips_;
}

void Players::setKilledShips()
{
	killedShips_ += 1;
}