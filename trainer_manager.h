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

	//�����ڰ� Ʈ���̳ʸ� ����Ѵ�
	void insertion() {
		ofstream out("trainer.txt", ios::app);

		cin.ignore(); // cin�� getline�� ȥ���ϱ� ���ؼ� �־�����Ѵ�
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


		// Ʈ���̳� ��ü ����
		Trainer newTrainer(name, sex, age, major, password);
		// txt�� ȸ�� ����
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

		// ����Ʈ�� Ʈ���̳� ����
		trainerList.push_back(newTrainer);


		cout << "�Է��� �������ϴ�.\n";
	}

	void readData(list<Trainer>& trainerList) {
		trainerList.clear();
		string line;
		ifstream file("trainer.txt"); //example ������ ����. ������ ����
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
					// �̸��� �Է��� ��й�ȣ�� ������ �α����� �����Ѵ�
					cout << "Welcome, " << name << "!" << endl;
					//���� ���� ùȭ��
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

	//major�� ���
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