#pragma once
#include "Fields.h"
class FieldComputer :
	public Fields
{
	public:
		FieldComputer();
		~FieldComputer();
	protected:
		void initShips();
	private:
		void initField();
		int x_;
		int y_;
};

