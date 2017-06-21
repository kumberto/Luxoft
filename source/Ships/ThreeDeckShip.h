#include "Ships.h"

class ThreeDeckShip : public Ships {
	public:
		ThreeDeckShip(int shipDeck);
		~ThreeDeckShip();
		bool initShip();
}