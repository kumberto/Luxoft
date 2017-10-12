#pragma once
#include <vector>
#include "../Ships/Ships.h"
class Fields
{
public:
	Fields();
	virtual ~Fields();
	bool isHit(int x, int y) const;
	std::string getValueFields(int x, int y) const;
	const Ships* findShip(int x, int y) const;
protected:
	void virtual initShips() = 0;
	bool isEmpty(int deck, int x, int y, char rotation);
	void buildShip(Ships* ship, int deck, int x, int y, char rotation);
	void setShips(Ships* ship);

private:
	std::vector<Ships*> ships_;
	mutable std::vector<std::vector<std::string>> field_;
};

