#include <array>
#include "Player/Players.h"

class Fields {
	public:
		Fields(Players* player, Players* playerOwn);
		virtual ~Fields();
		virtual void initField() = 0;
		void changePlayer();
		bool repeatHit();
	private:
		std::array<Ships*, 10> ships_;
		Players* player_;
		Players* playerOwm_;	
}