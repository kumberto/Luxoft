#pragma once
#include "Fields.h"
class FieldComputer :
	public Fields
{
public:
	FieldComputer();
	~FieldComputer();
	void initField();
	void initShips();
private:
	int x_;
	int y_;
};

