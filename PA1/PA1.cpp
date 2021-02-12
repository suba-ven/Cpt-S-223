
#include "PA1.h"
#include"LinkedList.h"

using namespace std;
//Name: Subashree Venkatasubramanian
//WSU ID: 011696362
//Programming Assignment 1: CptS223


/*ADVANTAGES/DISADVANTAGES LINKED LIST
1. One advantage to using a linked list is that with the linked list, it is much easier to
	shift data in the list or insert and remove elements in the middle of the list, especially when 
	compared to an array. Since the Nodes do not need to change position, all that needs to be changed
	when adding or removing nodes or shifting nodes in the list is the 'links', or pointers. In this
	assignment, I saw this when I was working on inserting elements into the front of the linked list
	as compared to doing so in the array. It is much easier to do in the linked list, which is definitely
	an advantage to data storage and reorganization.

2. One disadvantage to using a linked list is that they take up much more space than an array due to
	the nodes and pointers between nodes. This assignment required the use of many additions to the
	list, and I realized that if a list has thousands of nodes instead of just 30, it must take up a
	lot of space and memory due to memory allocation during runtime. Similarly, a doubly-linked list
	must take up even more memory and space due to the excess pointers. 
*/

/*ADVANTAGES/DISADVANTAGES ARRAYS
1. One advantage to using the array is that it is easier to access and go through the elements
	due to the indices. While in a  linked list there is no way to immediately go to a position in
	the list, in an array you can just type in the index access the data without having to parse
	through everything else. This is much more effecient and also reduces the time complexity of
	the program. In this assignement, to go through the linked list you need to set up a while
	loop and go through each node with comparisons, but for the array, a simple for loop allows
	you to iterate through and modify every element, tehrefore this iteration is definitely an 
	advantage of the array.

2. One disadvantage to using an array to store information is that the information in the array is
	very inneficient when shifting or inserting data, as all of teh cells need to be moved. In a linked
	list the programmer can just change a couple links to add in a new element, but with an array, all
	of the cells need to be moved. This is very tedious,e specially due to the threat of  off-by-one
	errors. I found this while working on this assignment as I got many off-by-one errors when working on
	the insertion of profiles into the profile array, which was very frustrating.

*/

int main()
{
	//seed rand
	srand(time(NULL));

	//creating profile array
	Profile profile_array[30];
	//array initiated to all blank strings and 0 values
	initArray(profile_array);

	int game_state = 0;

	fstream dataFile;
	dataFile.open("//PA1//commands.csv", ios::in | ios::out | ios::app);

	if (!dataFile.is_open()) {
		cout<<"Could not open file"<<endl;
	}

	LinkedList <string, string> commands = LinkedList<string, string>();

	string name;
	string desc;
	while (getline(dataFile, name, ',')) {
		if (name.compare("") == 0)
			getline(dataFile, name, ',');
		char a;
		dataFile.get(a);
		getline(dataFile, desc,'"');
		dataFile.get(a);
		commands.insertAtFront(name, desc);
	}
	//commands.printList();

	while (game_state != 6) {
		int user_input = 0;
		do
		{
			cout << "Please enter an integer from 1-6 from the menu below.\n\nMain Menu:\n1. Game Rules\n2. Play Game\n3. Load Previous Game\n4. Add Command\n5. Remove Command\n6. Exit" << endl;
			cin >> user_input;

		} while ((user_input<1)||(user_input>6));

		game_state = user_input;

		if (game_state == 1) {
			cout << "\nGame Rules\nThis is a matching game to learn Linux commands.\nThe command name will appear on the left side, and three possible descriptions will appear on the right.\nIf you choose the correct description, you will earn a point. if you choose the wrong one, you lose a point. \nYou can choose how many questions you want, from 5 to 30 questions.\nHave fun, and good luck!\n\n" << endl;
		}

		else if (game_state == 2) {
			//set points at 0 initially
			int point_total = 0;
			//player name
			string username;
			cout << "Please enter your name: " << endl;
			getchar();
			getline(cin, username);
			int num_questions = 0;
			//tracking array makes sure commands are only listed once
			int tracking_arr[50] = { 0 };

			do {
				//user chooses between 5 and 30 questions
				cout << "Please enter a number of questions, from 5 to 30." << endl;
				cin >> num_questions;
			} while ((num_questions < 5) || (num_questions > 30));
			
			for (int i = 0; i < num_questions; i++) {

				//num1 is the question
				int num1 = 0;
				do {
					num1 = (rand() % 30) + 1;
				} while (tracking_arr[num1] == 1);
				tracking_arr[num1] = 1;

				//num2 is a wrong answer choice
				int num2 = 0;
				do {
					num2 = (rand() % 30) + 1;
				} while (num2 == num1);

				//num3 is a wrong answer choice
				int num3 = 0;
				do {
					num3 = (rand() % 30) + 1;
				} while ((num3 == num1) || (num3 == num2));



				//now iterate through the lists to find num1, 2, and 3 and display them
				Node <string, string> temp1 = commands.findNode(num1);
				Node <string, string> temp2 = commands.findNode(num2);
				Node <string, string> temp3 = commands.findNode(num3);

				//use this to decide which order the 3 descriptions are shown
				int num4 = (rand() % 3) + 1;
				int num5 = (rand() % 2) + 1;

				//If the user selects the correct answer, then a point is awarded to the player’s total.
				//Otherwise, a point is subtracted from the player’s total.
				give_question(temp1, temp2, temp3, &point_total, num4, num5);

			}
			/* Once the game is over, the user’s profile is updated.  */
			cout << "\n\nThe game has now ended. Final Point Total: " << point_total << endl;
			shift_left(profile_array);
			profile_array[0].user_name = username;
			profile_array[0].points = point_total;

			//return to main menu
			game_state = 0;
		}

		else if (game_state == 3) {
			/*prompt the user 
			for a profile name. If the profile is located in the profiles array, then display
			the stored points to the screen. 
			From this point, the game should run the same as in the “Play Game Requirement”.*/

			string username;
			cout << "Please enter a profile name: " << endl;
			getchar();
			getline(cin, username);
			int saved_profile = -1;
			for (int i = 0; i < 30; i++) {
				if ((profile_array[i].user_name).compare(username)==0) {
					saved_profile = i;
					cout << "The profile was found. The point total for " << profile_array[i].user_name << " is: " << profile_array[i].points << endl;
				}
			}
			if (saved_profile == -1) {
				cout << "This profile was not found in the saved profiles. Going back to main menu." << endl;
			}
			else{
				cout<<"The game will now start from the saved point total."<<endl;
				int point_total = profile_array[saved_profile].points;
			int num_questions = 0;
			//tracking array makes sure commands are only listed once
			int tracking_arr[50] = { 0 };

			do {
				//user chooses between 5 and 30 questions
				cout << "Please enter a number of questions, from 5 to 30." << endl;
				cin >> num_questions;
			} while ((num_questions < 5) || (num_questions > 30));

			for (int i = 0; i < num_questions; i++) {

				//num1 is the question
				int num1 = 0;
				do {
					num1 = (rand() % 30) + 1;
				} while (tracking_arr[num1] == 1);
				tracking_arr[num1] = 1;

				//num2 is a wrong answer choice
				int num2 = 0;
				do {
					num2 = (rand() % 30) + 1;
				} while (num2 == num1);

				//num3 is a wrong answer choice
				int num3 = 0;
				do {
					num3 = (rand() % 30) + 1;
				} while ((num3 == num1) || (num3 == num2));

				//now iterate through the lists to find num1, 2, and 3 and display them
				Node <string, string> temp1 = commands.findNode(num1);
				Node <string, string> temp2 = commands.findNode(num2);
				Node <string, string> temp3 = commands.findNode(num3);

				//use this to decide which order the 3 descriptions are shown
				int num4 = (rand() % 3) + 1;
				int num5 = (rand() % 2) + 1;

				//If the user selects the correct answer, then a point is awarded to the player’s total.
				//Otherwise, a point is subtracted from the player’s total.
				give_question(temp1, temp2, temp3, &point_total, num4, num5);
			}

			/* Once the game is over, the user’s profile is updated.  */
			cout << "\n\nThe game has now ended. Final Point Total: " << point_total << endl;
			shift_left(profile_array);
			profile_array[0].user_name = username;
			profile_array[0].points = point_total;

			//return to main menu
			game_state = 0;

			}
		}

		else if (game_state == 4) {

			//first ask for the command
			string command_name;
			cout << "Please enter a command to add to the current list of commands." << endl;
			getchar();
			getline(cin, command_name);

			//look for duplicates
			bool is_duplicate = commands.find_duplicate(command_name);

			//if there is a duplicate:
			bool returntomain = false;
			while (is_duplicate) {
				cout << "This command is already in the list, please enter a new command to add to the current list of commands." << endl;
				cout << "You can also exit back to the main menu by entering 'quit'." << endl;
				getchar();
				getline(cin, command_name);
				if (command_name.compare("quit") == 0) {
					returntomain = true;
					is_duplicate = false;
				}
				else {
					bool is_duplicate = commands.find_duplicate(command_name);
				}
			}
			
			//second ask for the description
			if (!returntomain) {
				string new_desc;
				cout << "Please enter a description for the new command." << endl;
				getchar();
				getline(cin, new_desc);

				//change linked list
				commands.insertAtFront(command_name, new_desc);
			}
			//return to main menu
			game_state = 0;
		}

		else if (game_state == 5) {

		//first ask for the command
		string command_name;
		cout << "Please enter a command to remove from the current list of commands." << endl;
		getchar();
		getline(cin, command_name);

		//use is duplicate to find if the command exists
		bool is_duplicate = commands.find_duplicate(command_name);

		bool returntomain = false;


		//command doesn't exist
		while (!is_duplicate) {
			cout << "This command is not in the list, please enter a new command to remove from the current list of commands." << endl;
			cout << "You can also exit back to the main menu by entering 'quit'." << endl;
			getchar();
			cin >> command_name;
			if (command_name.compare("quit") == 0) {
				returntomain = true;
				is_duplicate = true;
			}
			else {
				bool is_duplicate = commands.find_duplicate(command_name);
			}
		}

		//command does exist, removal begins
			if (!returntomain) {
				//change linked list
				commands.removeNode(command_name);
				//commands.printList();
			}
		}
	}

	if (game_state == 6) {


		/* The contents of the linked list should be written to a file called commands.csv.
	Each line in the file should consist of the command and description pairs in the form
	command,”description”.*/
		dataFile.close();
		Node <string, string>* current = commands.getHead();
		dataFile.open("//PA1//commands.csv", fstream::out | fstream::trunc);
		while (current != nullptr) {
			dataFile << current->getCommand() << ','<<'\"' << current->getDesc() << '\"'<<endl;
			current = current->getNext();
			
		}
		dataFile.close();

		/* Each profile includes a name and current points, and should be written to a file
		called profiles.csv. If another profile exists that matches the name, then it should be
		completely overwritten with the new points. The format for a profile is name,points.*/

		ofstream outFile("//PA1//profiles.csv");
		for (int i = 0; i < 29; i++) {
			if ((profile_array[i].user_name).compare("") != 0) {
				outFile << profile_array[i].user_name << "," << profile_array[i].points << endl;
				//prevents repeats of names
				for (int j = i+1; j < 30; j++) {
					if ((profile_array[j].user_name).compare(profile_array[i].user_name) != 0)
						profile_array[j].user_name = "";
				}
			}
		}

		outFile.close();

		//destructor is called automatically
	}
	return 0;

}
