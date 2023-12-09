#pragma once
#include <iostream>
#include <string>
using namespace std;
class Reserve {
private:
	string member;
	string trainer;
public:
	Reserve(string member, string trainer) : member(member), trainer(trainer) {}
	void printMember() const { cout << member << endl; }
	void printTrainer() const { cout << trainer << endl; }
	string getMember(){ return member; }
	string getTrainer() { return trainer; }
};