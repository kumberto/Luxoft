#include <array>
#include "Point"

class Ships {
	public:
		Ships(int shipDecks);
		virtual ~Ships();
		bool initShip() = 0;
		bool isHit();
		bool isAlive();
		int getShipDecks() const;
	protected:
		void move();
	private:
		int shipDecks_;
		bool alive_;
		int hit_;
		std::array<Point, shipDecks_> pointDeck_;
}