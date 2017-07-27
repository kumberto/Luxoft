#pragma once
#include "Fields.h"
class FieldComputer :
	public Fields
{
public:
	FieldComputer(const Players& player, const Players& playerOwn);
	~FieldComputer();
	void initField();
	void initShips();
};

