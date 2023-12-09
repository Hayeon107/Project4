#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include "trainer.h"
class TrainerManager {
private:
	list<Trainer> trainerList;
public:
	void initialize() {
		readData(trainerList);
		showAllTrainer(trainerList);
		login(trainerList);
	}

	//지원자가 트레이너를 등록한다
	void insertion() {
		ofstream out("trainer.txt", ios::app);

		cin.ignore(); // cin과 getline을 혼용하기 위해서 넣어줘야한다
		cout << "Name : ";
		string name;
		getline(cin, name);

		cout << "Sex(F/M) : ";
		char sex;
		cin >> sex;

		cout << "Age : ";
		int age;
		cin >> age;
		cin.ignore();

		cout << "major : ";
		string major;
		getline(cin, major);

		cout << "Password : ";
		string password;
		cin >> password;


		// 트레이너 객체 생성
		Trainer newTrainer(name, sex, age, major, password);
		// txt에 회원 저장
		if (out.is_open()) {
			out << name << endl;
			out << sex << endl;
			out << age << endl;
			out << major << endl;
			out << password << endl;
			out << "\n";
		}
		else {
			cout << "No such file" << endl;
		}

		// 리스트에 트레이너 저장
		trainerList.push_back(newTrainer);


		cout << "입력이 끝났습니다.\n";
	}

	void readData(list<Trainer>& trainerList) {
		trainerList.clear();
		string line;
		ifstream file("trainer.txt"); //example 파일을 연다. 없으면 생성
		if (file.is_open()) {
			while (getline(file,line)) {
				string name = line;
				char sex;
				file.get(sex);
				int age;
				file >> age;
				file.ignore();

				string major;
				getline(file, major);

				string password;
				getline(file, password);

				file.ignore();
				Trainer trainer = Trainer(name, sex, age, major, password);
				if (!name.empty()) {
					trainerList.push_back(trainer);
				}
			}
			file.close();
		}
		else {
			cout << "Unable to open file";
		}
	}

	void showAllTrainer(list<Trainer>& trainerList) {
		for (Trainer trainer : trainerList) {
			cout << trainer.getTrainerName() << endl;
		}
	}

	void login(list<Trainer>& trainerList) {
		string name;
		cout << "Name >> ";
		cin >> name;
		cout << "Password >> ";
		string password;
		cin >> password;

		bool found = false;

		for (Trainer trainer: trainerList) {
			if (trainer.getTrainerName() == name) {
				if (trainer.getTrainerPassword() == password) {
					// 이름과 입력한 비밀번호가 맞으면 로그인을 진행한다
					cout << "Welcome, " << name << "!" << endl;
					//개인 관리 첫화면
					start(trainer);
					found = true;
					break;
				}
				else {
					cout << "Wrong password" << endl;
					break;
				}
			}
		}
		if (!found) cout << "No such member" << endl;
	}

	void start(Trainer trainer) {
		while (true) {		
			int chooseNum;
			cout << "1. Manage members" << endl;
			cout << "2. Check Schedule" << endl;
			cout << "3. Give class" << endl;
			cout << "4. Log out" << endl;
			cout << "> ";
			cin >> chooseNum;
			switch (chooseNum)
			{
			case 1:
				cout << "Your members : ";
				trainer.printMembers();
				break;
			case 2:
				cout << "Today resevations : ";
				trainer.printTodayReserve(trainer.getTrainerName());
				break;
			case 3:
				trainer.giveClass();
			case 4:
				return;
			default:
				break;
			}
		}
	}

	//major로 출력
	list<string> searchMajor(string major) {
		list<string> trainers;
		readData(trainerList);
		for (Trainer trainer : trainerList) {
			if (trainer.getMajor() == major) {
				cout << trainer.getTrainerName() << " ";
				trainers.push_back(trainer.getTrainerName());
			}
		}
		return trainers;
	}
};