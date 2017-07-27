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
		virtual void initDeckPoint(const Point& point) = 0;
		int getSizeDeck() const;
		virtual bool isPoint(int x, int y) = 0;
		void setHit();
	protected:
		void setPointDeck(const Point& point);
		int shipDecks_;
		std::vector<Point> pointDeck_;
	private:
		bool alive_;
		int hit_;
		
};

