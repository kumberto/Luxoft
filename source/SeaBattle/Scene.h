#pragma once
#include <memory>
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
		std::shared_ptr<Player>	player_;
		std::shared_ptr<ComputerPlayer> computer_;
		std::shared_ptr<FieldPlayer> fieldPlayer_;
		std::shared_ptr<FieldComputer> fieldComputer_;
};

