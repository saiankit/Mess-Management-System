#pragma once
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
class Student {
public:
	string name;
	string username;
	string password;
	int due;
	int preference;
};
vector<Student> studentsData;