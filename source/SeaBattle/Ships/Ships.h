#pragma once
#include <initializer_list>
#include <vector>
#include "Point.h"
class Ships
{
	public:
		Ships(int shipDecks);
		virtual ~Ships() = 0;
		virtual bool isHit(int x, int y);
		bool isAlive();
		virtual int getShipDecks() const;
		virtual void initDeckPoint(std::initializer_list<Point> list) = 0;
	protected:
		void setPointDeck(std::initializer_list<Point> list);
		int shipDecks_;
	private:
		
		bool alive_;
		int hit_;
		std::vector<Point> pointDeck_;
};

