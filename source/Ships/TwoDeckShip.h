#include "Ships.h"

class TwoDeckShip : public Ships {
	public:
		TwoDeckShip(int shipDeck);
		~TwoDeckShip();
		bool initShip();
}