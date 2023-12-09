#include <iostream>
#include <fstream>
#include "member.h"
#include "reserve_manager.h"
#include<list>
using namespace std;

class MemberManager {
private:
	list<Member> memberList;
	ReserveManager reserveManager;
public:
	void initialize() {
		readData(memberList);
		if (!memberList.empty()) {
			//login			
			logIn(memberList);
		}
	}

	//트레이너의 멤버를 출력한다
	void membersOfTrainer(string trainer) {
		bool isMember=false;
		for (Member member : memberList) {
			if (member.getTrainer() == trainer) {
				cout << member.getName() << " ";
				isMember = true;
			}
		}if (!isMember) cout << "No member yet" << endl;
		else cout << endl;
	}

	//회원정보를 읽어온다
	void readData(list<Member>& memberList) {
		memberList.clear();
		string line;
		ifstream file("member.txt"); //example 파일을 연다. 없으면 생성
		if (file.is_open()) {
			while (getline(file, line)) {
				string name = line;
				//getline(file, name);
				char sex;
				file.get(sex);
				int age;
				file >> age;
				file.ignore();
				string goal;
				getline(file, goal);
				string password;
				getline(file, password);
				string trainer;
				getline(file, trainer);
				int session;
				file >> session;
				file.ignore();
				file.ignore();

				Member member = Member(name, sex, age, goal, password, trainer, session);
				if (!name.empty()) {
					memberList.push_back(member);
				}
			}
			file.close();
		}
		else {
			cout << "Unable to open file" << endl;
		}
	}

	void logIn(list<Member>& memberList) {
		string name;
		cout << "Name >> ";
		cin >> name;
		cout << "Password >> ";
		string password;
		cin >> password;

		bool found = false;

		for (Member member : memberList) {
			if (member.getName() == name) {
				if (member.getPassword() == password) {
					// 이름과 입력한 비밀번호가 맞으면 로그인을 진행한다
					cout << "Welcome, " << name << "!" << endl;
					//개인 관리 첫화면
					start(member);
					found = true;
					break;
				}
				else {
					cout << "Wrong password" << endl;
					return;
				}
			}
		}
		if (!found) { cout << "No such member"<<endl; }
	}

	void start(Member member) {
		while (true) {		
			int chooseNum;
			cout << "1. Reserve Class" << endl;
			cout << "2. Manage Membership" << endl;
			cout << "3. Log out" << endl;
			cout << "> ";
			cin >> chooseNum;
			switch (chooseNum)
			{
			case 1:
				reserveManager.makeReserve(member.getName(), member.getTrainer());
				break;
			case 2:
				cout << "Your left session is " << member.getSession() << endl;
				break;
			case 3:
				return;
			default:
				break;
			}
		}
	}

	void printName(list<Member> mList) {
		string name;
		cout << "\nName >>";
		cin >> name;
		list<Member> l;
		for (Member member : mList) {
			if (member.getName() == name) {
				cout << "Password : " << member.getPassword() <<endl;
				cout << "Goal : " << member.getGoal() << endl;
				cout << "Trainer : " << member.getTrainer() << endl;
				l.push_back(member);
			}
		}
		//printMember(l);
	}

	void printMember(list<Member> l) { //리스트를 출력하는 형식
		list<Member>::iterator it;
		for (Member& member : l) {
			cout << member.getAge() << "살 " << member.getGoal() << "목적 " << endl;
			cout << "비밀번호: " << member.getPassword() << "\n" << "트레이너: " << member.getTrainer() << "\n";
		}
	}

};