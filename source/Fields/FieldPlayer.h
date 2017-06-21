#include "Fields.h"
#include "Player/Players.h"
class FieldPlayer : public Fields {
	public:
		FieldPlayer(Players* player, Players* computerPlayer);
		~FieldPlayer();
		void initField();
}