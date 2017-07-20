#include <iostream>
#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{
	player_ = new Player("player");
	computer_ = new ComputerPlayer("computer");
	fieldPlayer_ = new FieldPlayer(*computer_, *player_);
	fieldComputer_ = new FieldComputer(*player_, *computer_);

}


Scene::~Scene()
{
}
void Scene::draw()
{
	std::cout << "\n" << std::endl;
	std::cout << "   ";
	for (int i = 0; i < 25; i++) {
		if (i < 10) {
			std::cout << i;
		}
		else if (i > 14) {
			std::cout << (i - 15);
		}
		else {
			std::cout << "<";
		}
	}
	std::cout << std::endl;
	std::cout << "  |----------|   |----------|";
	
	for (int j = 0; j < 10; j++) {
			std::cout << "\n " << j << "|";
		for (int i = 0; i < 24; i++) {
			if (i < 10) {
				std::cout << fieldPlayer_->getValueFields(i, j);
			}
			else if (i > 13) {
				std::cout << fieldComputer_->getValueFields(i - 14, j);
			}
			else if (i == 10) {
				std::cout << "|";
			}
			else if (i == 13) {
				std::cout << j << "|";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << "|";
	}
	std::cout << std::endl;
	std::cout << "  |----------|   |----------|";

	while (true)
	{

	}
}
