#pragma once
#include "Fields.h"
class FieldPlayer :
	public Fields
{
	public:
		FieldPlayer();
		~FieldPlayer();
		void initField();
	protected:
		void initShips();
};

