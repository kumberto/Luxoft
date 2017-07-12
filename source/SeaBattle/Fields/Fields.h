#pragma once
#include <vector>
#include "../Players/Players.h"
#include "../Ships/Ships.h"
class Fields
{
public:
	Fields(const Players& player, const Players& playerOwn);
	virtual ~Fields() = 0 {};
	virtual bool repeatHit();
	std::string getValueFields(int x, int y);
protected:
	void virtual initShips() = 0;
	bool isEmpty(int deck, int x, int y, char rotation);
	void buildShip(Ships* ship, int deck, int x, int y, char rotation);
	void setShips(Ships* ship);
private:
	std::vector<Ships*> ships_;
	std::vector<std::vector<std::string>> field_;
	const Players& player_;
	const Players& playerOwm_;
};

