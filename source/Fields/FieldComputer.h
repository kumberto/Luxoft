#include "Fields"
#include "Players/Players.h"

class FieldComputer : public Fields {
	public:
		FieldComputer(Players* player, Players* computerPlayer);
		~FieldComputer();
		void initField();
}