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

void printFoods(vector<string> foods) {
	cout << "The foods available for poll" << endl;
	for (int i = 0; i < foods.size(); ++i) {
		cout << i + 1 << " " << foods[i] << endl;
	}
}

void vote() {
	int choice, i, N;
	vector<string> foods = {"Pani Puri", "Noodles", "Samosa Ragada"};
	N = foods.size();
	vector<int> votes(N);

	do {
		cout << endl;
		printFoods(foods);
		cout << "\n1. Vote for your favorite food." << endl;
		cout << "2. Check the number of votes of each food.\n";
		cout << "3. Check the food who is leading.\n";
		cout << "0. Exit\n";

		cout << "Enter Your choice: ";
		cin >> choice;
		cout << "\n";

		switch (choice) {

		case 1: {
			int candidatechoice;
			printFoods(foods);
			cout << "Choose your Food: ";
			cin >> candidatechoice;
			cout << "\n";

			votes[candidatechoice - 1]++;
			break;
		}
		case 2: {
			for (i = 0; i < N; i++)
				cout << i + 1 << "."
				     << foods[i] << " "
				     << votes[i] << "\n";
			break;
		}
		case 3: {
			int maximumVotes = 0;
			string winner;

			for (int i = 0; i < N; i++)
				if (votes[i] > maximumVotes) {
					maximumVotes = votes[i];
					winner = foods[i];
				}
			int flag = 0;

			for (int i = 0; i < N; i++)
				if (votes[i] == maximumVotes && winner != foods[i]) {
					flag = 1;
					break;
				}
			if (!flag)
				cout << "The current winner is "
				     << winner    << ".\n";
			else
				cout << "No clear winner\n";
		}
		}
	} while (choice != 0);
}