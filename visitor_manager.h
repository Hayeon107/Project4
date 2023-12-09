#pragma once
#include "member.h"
#include "trainer_manager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
class VisitorManager {
private:
	//Member member;
	TrainerManager trainerManager;
public:
	void survey() {
		string name;
		cout << "Name : ";
		cin >> name;

		char sex;
		cout << "Sex : ";
		cin >> sex;

		int age;
		cout << "Age : ";
		cin >> age;
		cin.ignore();

		string goal;
		cout << "Goal : ";
		getline(cin, goal); //include space

		string trainer;
		trainer = matchingTrainer(goal);


		if (askJoin()) {
			string password;
			cout << "Enter four numbers for password : ";
			cin >> password;

			int session;
			cout << "Write number of sessions you want : ";
			cin >> session;

			insertion(name, sex, age, goal, password, trainer, session);
		}
		else {
			return;
		}
		
	}

	string matchingTrainer(string goal) {
		//Ʈ���̳� �߿� goal�� major�� ��ġ�ϴ� Ʈ���̳ʸ� print
		list<string> trainers;
		cout << "Trainer list for is " << goal << " : " ;
		trainers = trainerManager.searchMajor(goal);

		string trainer;
		cout << "\nChoose trainer : ";
		cin >> trainer;

		auto it = find_if(trainers.begin(), trainers.end(), [&trainer](const string& elem) {
			return elem == trainer;
			});

		if (it != trainers.end()) {
			cout << "Matching" << endl;
			return trainer;
		}
		else {
			cout << "No such trainer" << endl;
			matchingTrainer(goal);
		}

	}

	bool askJoin() {
		cout << "Do you want join us? (Y/n) : ";
		char answer;
		cin >> answer;	
		switch (answer)
		{
		case ( 'Y' || 'y') :
			return true;
			break;
		case 'n':
			return false;
			break;
		default:
			break;
		}

	}

	void insertion(string name, char sex, int age, string goal, string password, string trainer, int session) {
		ofstream out("member.txt", ios::app);

		// ȸ����ü ����
		Member member = Member(name, sex, age, goal, password, trainer, session);
		// txt�� ȸ�� ����
		if (out.is_open()) {
			out << name << endl;
			out << sex << endl;
			out << age << endl;
			out << goal << endl;
			out << password << endl;
			out << trainer << endl;
			out << session << "\n" << endl;
			out.close();
		}
		else {
			cout << "No such file" << endl;
		}
		cout << "Welcome TodayPT!\n";
	}
};