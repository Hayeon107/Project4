#pragma once
#include <string>
#include <iostream>
#include <list>
#include <algorithm>
#include "reserve.h"
class ReserveManager {
private:
	list<Reserve> reserveList;
public:
	//���ุ���
	void makeReserve(string member, string trainer){
		bool isin = false;

		Reserve newReservation(member, trainer);
		reserveList.push_back(newReservation);
		cout << "Reserve complete" << endl;

		showAllReservation();
	}


	//��� ���ຸ��
	void showAllReservation() {
		if (!reserveList.empty()) {
			for (Reserve reserve : reserveList) {
				cout << "Member : ";
				reserve.printMember();
				cout << "Trainer : ";
				reserve.printTrainer();
				//cout << reserve.getMember() << "of trainer " << reserve.getTrainer()<<endl;
			}
		}
		else cout << "No reservation today" << endl;
	}

	//Ʈ���̳��� �������
	void showReserve(string trainer) {
		bool isReserve = false;
		for (Reserve reserve: reserveList) {
			if (reserve.getTrainer() == trainer) {
				cout << reserve.getMember() << ", ";
				isReserve = true;
			}
		}if (!isReserve) cout << "There's no reservation!"<<endl;
	}

	//������ �����մϴ�
	/*
	void takeReserve(string member) {
		auto it = find(reserveList.begin(), reserveList.end(), member);
		if (it != reserveList.end()) {
			// Erase the found element
			reserveList.erase(it);
			cout << "Element " << member << " found and erased." << endl;
		}
		else {
			cout << "Element " << member << " not found." << endl;
		}
	
	}
*/
};