#pragma once
#include "Fields.h"
class FieldPlayer :
	public Fields
{
public:
	FieldPlayer(const Players& player, const Players& playerOwn);
	~FieldPlayer();
	void initField();
	void draw();
};

