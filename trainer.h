#pragma once
#include <string>
#include <vector>
#include <list>
using namespace std;

class Trainer {
private:
	string name;
	char sex;
	int age;
	string major;
	string password;
public:
	Trainer(string n, char s, int a, string m, string p)
		: name(n), sex(s), age(a), major(m), password(p) {
	}
	//트레이너의 정보를 출력하자
	void printInfo() const {
		cout << "Trainer " << name << " is good at " << major << endl;
	}

	//트레이너가 관리하는 회원 전부 출력
	void printMembers() {	}
	//트레이너에게 수업 예약된 회원 전부 출력
	void printTodayReserve() {}
	string getTrainerName() const {	return name; }
	string getTrainerPassword() const{	return password; }

};