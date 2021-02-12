
#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#include<string>
#include<time.h>
#include"Node.h"

//profiles array struct
typedef struct profiles {
	string user_name;
	int points;
} Profile;



//display choices and user points function
//also takes user input and adjusts score
void give_question(Node <string, string> temp1, Node <string, string> temp2, Node <string, string> temp3, int* user_points, int display_opt, int opt2){
	int user_input = 0;
	bool if_won = false;
	//3 display options with two settings each, one is randomly chosen
	if (display_opt == 1) {
		if (opt2 == 1){
			cout << "The command: " << temp1.getCommand() << endl;
		cout << "\nDescriptions: \n1. " << temp1.getDesc() << "\n2. " << temp2.getDesc() << "\n3. " << temp3.getDesc() << endl;
		do {
			cout << "\nPlease enter an integer between 1 and 3 corresponding to the correct description!" << endl;
			cin >> user_input;
		} while ((user_input<1)||(user_input>3));

		if (user_input == 1)
			if_won = true;
		
		}
		else if (opt2 == 2) {
			cout << "The command: " << temp1.getCommand() << endl;
			cout << "\nDescriptions: \n1. " << temp1.getDesc() << "\n2. " << temp3.getDesc() << "\n3. " << temp2.getDesc() << endl;
			do {
				cout << "\nPlease enter an integer between 1 and 3 corresponding to the correct description!" << endl;
				cin >> user_input;
			} while ((user_input < 1) || (user_input > 3));

			if (user_input == 1)
				if_won = true;

		}

	}

	else if (display_opt == 2) {
		if (opt2 == 1) {
			cout << "The command: " << temp1.getCommand() << endl;
			cout << "\nDescriptions: \n1. " << temp2.getDesc() << "\n2. " << temp1.getDesc() << "\n3. " << temp3.getDesc() << endl;
			do {
				cout << "\nPlease enter an integer between 1 and 3 corresponding to the correct description!" << endl;
				cin >> user_input;
			} while ((user_input < 1) || (user_input > 3));

			if (user_input == 2)
				if_won = true;

		}
		else if (opt2 == 2) {
			cout << "The command: " << temp1.getCommand() << endl;
			cout << "\nDescriptions: \n1. " << temp3.getDesc() << "\n2. " << temp1.getDesc() << "\n3. " << temp2.getDesc() << endl;
			do {
				cout << "\nPlease enter an integer between 1 and 3 corresponding to the correct description!" << endl;
				cin >> user_input;
			} while ((user_input < 1) || (user_input > 3));

			if (user_input == 2)
				if_won = true;

		}
	}

	else if (display_opt == 3) {
		if (opt2 == 1) {
			cout << "The command: " << temp1.getCommand() << endl;
			cout << "\nDescriptions: \n1. " << temp3.getDesc() << "\n2. " << temp2.getDesc() << "\n3. " << temp1.getDesc() << endl;
			do {
				cout << "\nPlease enter an integer between 1 and 3 corresponding to the correct description!" << endl;
				cin >> user_input;
			} while ((user_input < 1) || (user_input > 3));

			if (user_input == 3)
				if_won = true;

		}
		else if (opt2 == 2) {
			cout << "The command: " << temp1.getCommand() << endl;
			cout << "\nDescriptions: \n1. " << temp2.getDesc() << "\n2. " << temp3.getDesc() << "\n3. " << temp1.getDesc() << endl;
			do {
				cout << "\nPlease enter an integer between 1 and 3 corresponding to the correct description!" << endl;
				cin >> user_input;
			} while ((user_input < 1) || (user_input > 3));

			if (user_input == 3)
				if_won = true;

		}
	}

	//adjusts user points, displays to screen
	if (if_won) {
		(*user_points)++;
		cout << "Correct! "<<temp1.getCommand()<<" - "<<temp1.getDesc()<< "\nYou have gained one point. Point total:  " << (*user_points) << endl<<endl;
	}
	else {
		(*user_points)--;
		cout<<"You got the question wrong. " << temp1.getCommand() << " - " << temp1.getDesc() << "\nYou have lost one point. Point total:  " << (*user_points) << endl<<endl;
	}
}

//shifts the array to make way for the new profile
void shift_left(Profile arr[30]) {
	for (int i = 29; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
}

//initializes the array
void initArray(Profile arr[30]) {
	for (int i = 0; i <30; i++) {
		arr[i].user_name = "";
		arr[i].points = 0;
	}
}



