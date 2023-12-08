#include <iostream>
#include <fstream>
#include "member.h";
#include<list>
using namespace std;

class MemberManager {
private:
	list<Member> memberList;
public:
	void initialize() {
		readData(memberList);
		if (!memberList.empty()) {
			//login			
			logIn(memberList);
		}
	}


	//방문자가 회원을 등록한다
	void insertion() {
		ofstream out("member.txt", ios::app);

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

		cout << "Goal : ";
		string goal;
		getline(cin, goal);

		cout << "Password : ";
		string password;
		cin >> password;
		cin.ignore();

		cout << "trainer : ";
		string trainer;
		getline(cin, trainer);

		cout << "session : ";
		int session;
		cin >> session;

		// 회원객체 생성
		Member member = Member(name, sex, age, goal, password, trainer,session);
		// txt에 회원 저장
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

		// 리스트에 멤버 저장
		memberList.push_back(member);
		//그리고 트레이너의 회원 리스트에도 추가해야함


		cout << "입력이 끝났습니다.\n";
	}
	void readFile() {
		string line;
		ifstream file("member.txt"); 
		if (file.is_open()) {
			while (getline(file, line)) {
				cout << line << endl;
			}
			file.close();
		}
		else {
			cout << "Unable to open file";
		}
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
			//printMember(plaveList);
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



	void search() {
		readData(memberList);
		cout << "Let's search" <<endl;
		printName(memberList);
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
			case 2:
				cout << "Your left session is " << member.getSession() << endl;
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