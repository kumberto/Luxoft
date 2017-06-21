#include "Ships.h"

class FourDeckShip : public Ships {
	public:
		FourDeckShip(int shipDeck);
		~FourDeckShip();
		bool initShip();
}