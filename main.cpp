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
using namespace std;
#include "login/adminLogin.cpp"
#include "login/studentLogin.cpp"
#include "services/payment.cpp"
#include "services/voting.cpp"
#include "constants.cpp"
int main() {
	for (int i = 1; i < 11; ++i) {
		Student newStudent;
		newStudent.name = "user" + to_string(i);
		newStudent.username = "user" + to_string(i);
		newStudent.password = "user" + to_string(i);
		newStudent.due = i * 1254;
		newStudent.preference = (i % 2);
		studentsData.push_back(newStudent);
	}
	cout << endl << "Welcome to Mess Management Portal" << endl;
	cout << "[Admin] : Please login" << endl;
	bool isAdminLoggedIn = false;
	do {
		isAdminLoggedIn = adminLogin();
	} while (!isAdminLoggedIn);

	cout << endl << "Choose any of the given services" << endl;
	cout << "1. Vote for a new food inclusion" << endl;
	cout << "2. Fee Payment" << endl;
	cout << "Enter the option:";
	int option; cin >> option;
	if (option == 1) {
		// Food Voting System
		cout << "Food Voting System" << endl;
		cout << endl;
		vote();
	} else {
		// Fee Payment System
		cout << "Fee Payment System" << endl;

		bool isStudentLoggedIn = false;
		do {
			isStudentLoggedIn = studentLogin();
		} while (!isStudentLoggedIn);

		Student newStudent = student;

		feePayment(newStudent);
	}
}