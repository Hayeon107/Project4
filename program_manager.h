#include <iostream>
#include "member_manager.h"
#include "trainer_manager.h"

using namespace std;

class ProgramManager {
private:
	MemberManager memberManager;
	TrainerManager trainerManager;
public:
	void initialize() {
		while (true) {
			int chooseMenu;
			cout << "1. Sign in (Member) " << endl;
			cout << "2. Sign in (Trainer) " << endl;
			cout << "3. Visitor " << endl;
			cout << "4. Applicant" << endl;
			cout << "5. Exit" << endl;
			chooseMenu = chooseNum();
			switch (chooseMenu)
			{
			case 1:
				memberManager.initialize();
				break;
			case 2:
				trainerManager.initialize();
				break;
			case 3:
				memberManager.insertion();
				break;
			case 4:
				trainerManager.insertion();
				break;
			case 5:
				return;
			default:
				break;
			}
		}
	}

	int chooseNum() {
		int num;
		cout << "> ";
		cin >> num;
		return num;
	}

};