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
bool isValidAdmin(string userName, string password) {
	string adminUserName = "admin";
	string adminPassword = "admin";
	if (userName == adminUserName && password == adminPassword) return true;
	return false;
}

bool adminLogin() {

	string userName, password;
	cout << endl;
	cout << "Please enter Admin Username: ";
	cin >> userName;
	cout << "Please enter Admin Password: ";
	cin >> password;
	if (isValidAdmin(userName, password)) {
		cout << endl;
		cout << "Admin Logged In successfully" << endl;
		return true;
	}
	cout << endl;
	cout << "Please enter valid username and password." << endl;
	return false;
}