#pragma once
#include <string>
using namespace std;

class Member {
private:
	string name;
	char sex;
	int age;
	string goal;
	string password;
	string trainer;
	int session;
public:
	Member(
		string _name,
		char _sex,
		int _age,
		string _goal,
		string _password,
		string _trainer,
		int _session)
	{
		name = _name;
		sex = _sex;
		age = _age;
		goal = _goal;
		password = _password;
		trainer = _trainer;
		session = _session;
	};

	string getName() { return name; }
	char getSex() { return sex; }
	int getAge() { return age; }
	string getGoal() { return goal; }
	string getTrainer() { return trainer; }
	string getPassword() { return password; }
	int getSession() { return session; }
	//세션을 진행하면 1씩 줄어듭니다
	void haveSession() {
		session -= 1;
	}

};