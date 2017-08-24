#pragma once
#include "Players/Player.h"
#include "Players/ComputerPlayer.h"
#include "Fields/FieldComputer.h"
#include "Fields/FieldPlayer.h"
class Scene
{
	public:
		Scene();
		~Scene();
		void draw();
		void play();
	private:
		Player*			player_;
		ComputerPlayer* computer_;
		FieldPlayer*	fieldPlayer_;
		FieldComputer*	fieldComputer_;
};

