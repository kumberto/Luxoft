#include <iostream>
#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{
	
	fieldPlayer_ = std::make_shared<FieldPlayer>();
	fieldComputer_ = std::make_shared<FieldComputer>();
	player_ = std::make_shared<Player>("player", fieldComputer_);
	computer_ = std::make_shared<ComputerPlayer>("computer", fieldPlayer_);
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
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	std::cout << "  |----------|   |----------|";
	
	for (int j = 0; j < 10; j++) {
			std::cout << "\n " << j << "|";
		for (int i = 0; i < 24; i++) {
			if (i < 10) {
				std::cout << fieldPlayer_.get()->getValueFields(i, j);
			}
			else if (i > 13) {
				if (fieldComputer_.get()->getValueFields(i - 14, j) == "x") {
					std::cout << " ";
				}
				else {
					std::cout << fieldComputer_.get()->getValueFields(i - 14, j);
				}
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
	std::cout << "  |----------|   |----------|" << std::endl;
}
void Scene::play() {
	for (; !player_->winner() && !computer_->winner();) {
		do {
			draw();
			if (player_->getHit() == 20) {
				break;
			}
			player_->move();
		} while (player_->shot());
		if (player_->getHit() != 20) {
			do {
				draw();
				if (computer_->getHit() == 20) {
					break;
				}
				computer_->move();
			} while (computer_->shot());
		}
	}
	player_->statistics();
	computer_->statistics();
}
