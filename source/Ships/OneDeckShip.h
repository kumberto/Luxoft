#include "Ships.h"

class OneDeckShip : public Ships {
	public:
		OneDeckShip(int shipDeck);
		~OneDeckShip();
		bool initShip();
}