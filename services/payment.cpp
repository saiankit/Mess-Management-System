#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include "../constants.cpp"
#define deb(x) cerr << #x << " is " << x << endl;
using namespace std;
void feePayment(Student student) {
	int choice;
	do {
		cout << endl;
		cout << "\nChoose any of the given options" << endl;
		cout << "1. View Due\n";
		cout << "2. View Preference\n";
		cout << "3. Clear Due\n";
		cout << "0. Exit\n";

		cout << "Enter Your choice: ";
		cin >> choice;
		cout << "\n";

		switch (choice) {

		case 1: {
			cout << "Your Due: " << student.due << endl;
			break;
		}
		case 2: {
			int pref = student.preference;

			if (pref == 0) {
				cout << "Weekly Due Clear Preference" << endl;
			} else {
				cout << "Daily Due Clear Preference" << endl;
			}
			break;
		}
		case 3: {
			int pref = student.preference;
			if (pref == 0) {
				int due = student.due;
				if (due >= 840) {
					due = due - 840;
				} else {
					due = 0;
				}
				student.due = due;
			} else {
				int due = student.due;
				if (due >= 120) {
					due = due - 120;
				} else {
					due = 0;
				}
				student.due = due;
			}
			cout << "Fee Paid" << endl;
			for(int i = 0 ; i < 10; ++i) {
				if(studentsData[i].username == student.username) {
					studentsData[i].due = student.due;
				}
			}
		}
		}
	} while (choice != 0);
}