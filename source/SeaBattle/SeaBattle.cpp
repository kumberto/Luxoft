// SeaBattle.cpp: определяет точку входа для консольного приложения.
//
#include <iostream>
#include "stdafx.h"
#include "Scene.h"


int main()
{
	Scene scene;
	scene.play();
	std::string s;
	do {
		std::cout << "Enter q" << std::endl;
		std::cin >> s;
	} while (s != "q" );
    return 0;
}

