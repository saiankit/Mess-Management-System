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
using namespace std;

Student student;

bool isValidStudent(string userName, string password) {
	for (auto student : studentsData) {
		if (student.username == userName && student.password == password) {
			return true;
		}
	}
	return false;
}

bool studentLogin() {
	string userName, password;
	cout << endl;
	cout << "Please enter Username: ";
	cin >> userName;
	cout << "Please enter Password: ";
	cin >> password;
	if (isValidStudent(userName, password)) {
		cout << endl;
		cout << "Student Logged In successfully" << endl;

		for (auto stud : studentsData) {
			if (stud.username == userName && stud.password == password) {
				student = stud;
			}
		}
		return true;
	}
	cout << endl;
	cout << "Please enter valid username and password." << endl;
	return false;
}