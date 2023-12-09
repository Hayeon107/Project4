#pragma once
#include <string>
#include <vector>
#include <list>
using namespace std;
#include "reserve_manager.h"

class Trainer {
private:
	ReserveManager reserveManager;
	string name;
	char sex;
	int age;
	string major;
	string password;
public:
	Trainer(string n, char s, int a, string m, string p)
		: name(n), sex(s), age(a), major(m), password(p) {
	}
	//Ʈ���̳��� ������ �������
	void printInfo() const {
		cout << "Trainer " << name << " is good at " << major << endl;
	}

	//Ʈ���̳ʰ� �����ϴ� ȸ�� ���� ���
	void printMembers() {

	}
	//Ʈ���̳ʿ��� ���� ����� ȸ�� ���� ���
	void printTodayReserve(string trainer) {
		reserveManager.showReserve(trainer);
	}
	//������ ��������
	void giveClass() {
		string member;
		cout << "Give class of " << member << "'s" << endl;
		cin >> member;
		//reserveManager.takeReserve(member);
	}
	
	string getTrainerName() const {	return name; }
	string getTrainerPassword() const{	return password; }
	string getMajor() const{	return major; }
	

};