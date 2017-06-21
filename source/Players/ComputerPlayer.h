#include <string>
#include "Players.h"

class ComputerPlayer : public Players{
	public:
		ComputerPlayer(std::string name);
		~ComputerPlayer();
		void move();
		bool shot(int x, int y);
}