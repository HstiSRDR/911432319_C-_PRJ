// testCode1.cpp : Written by Hasti Sardari


#include <iostream>
#include <string>
#include <conio.h> 
using namespace std;

/* ---------------------- METHODS -----------------------------------------*/
void showMainMenu();
void insertStudent(string firstname, string lastname, int id, int mark);
int deleteStudent(int studentID);
int search(int studentID);
int search(string fn, string ln);
void print();
float average();
void printStudent(int studentID);
void showSearchMenu();
int update(int studentID);
/*-------------------------------------------------------------------------*/

const int CAPACITY = 10;
string firstname[CAPACITY];
string lastname[CAPACITY];
int studentID[CAPACITY];
int mark[CAPACITY];
int number = 0;

int main() {
	for (;;) { // INFINITE LOOP
		showMainMenu();

		int option;
		cin >> option;


		string firstname, lastname;
		int id, mark;

		switch (option) {
		case 1: // INSERT

			cout << "Firstname : ";
			cin >> firstname;
			cout << "Lastname : ";
			cin >> lastname;
			cout << "Student ID : ";
			cin >> id;
			cout << "Mark : ";
			cin >> mark;

			if (search(id) != -1) {
				cout << "ID already exists. cannot insert";
			}
			else {
				insertStudent(firstname, lastname, id, mark);
			}

			break;
		case 2: // SEARCH
			showSearchMenu();

			int searchOption;
			cin >> searchOption;

			if (searchOption != 1 && searchOption != 2) {
				cout << "BAD INPUT." << endl;
			}
			else { // Good Input 
				int searchResult;
				if (searchOption == 1) { // SEARCH BY STD_ID
					int std_id;
					cout << "STUDENT ID : ";
					cin >> std_id;

					searchResult = search(std_id);
				}
				else if (searchOption == 2) {
					string firstname, lastname;
					cout << "Firstname : ";
					cin >> firstname;
					cout << "Lastname : ";
					cin >> lastname;

					searchResult = search(firstname, lastname);
				}

				if (searchResult != -1) {
					printStudent(searchResult);
				}
				else {
					cout << "<<<STUDENT NOT FOUND. >>>";
				}

			}

			break;
		case 3: // DELETE
			int stdID, deleteResult;
			cout << "------------ DELETE -------------\n";
			cout << "Student ID : \t";
			cin >> stdID;
			deleteResult = deleteStudent(stdID);
			if (deleteResult == 1) {//successfull delete
				cout << "Student Deleted.\n";
			}
			else {
				cout << "Delete failed" << endl;
			}
			break;
		case 4: //PRINT
			if (number == 0) {
				cout << "LIST IS EMPTY";
			}
			else {
				for (int i = 0; i < number; i++) {
					printStudent(i);
				}
			}
			break;
		case 5: // AVERAGE
			cout << "<<<Class Mark Average is : " << average() << " >>>" << endl;
			break;
		case 6:
			int std_id;
			cout << "--------------UPDATE-------------------" << endl;
			cout << "Student ID : ";
			cin >> std_id;
			update(std_id);

			break;
		case 7:
			cout << "CLOSE APPLICATION.\nPress any key...";
			_getch();
			return 0;
			break;
		default:
			cout << "BAD INPUT" << endl;
			break;
		}

	}// end for loop
}// end main

void showMainMenu() {
	cout << "                  MENU                   ";
	cout << endl << "=======================================" << endl;
	cout << "1- INSERT" << endl;
	cout << "2- SEARCH" << endl;
	cout << "3- DELETE" << endl;
	cout << "4- PRINT" << endl;
	cout << "5- AVERAGE" << endl;
	cout << "6- UPDATE" << endl;
	cout << "7- EXIT" << endl;
	cout << ">> ";
}
void insertStudent(string fn, string ln, int id, int m) {
	firstname[number] = fn;
	lastname[number] = ln;
	studentID[number] = id;
	mark[number] = m;

	number++;
	cout << "<<< New student inserted successfully >>>" << endl;
}
void printStudent(int place) {
	/*int searchResult = search(id);
	if (searchResult == -1) {
	cout << "Student not found."<<endl;
	return;
	}*/
	//else {
	cout << "------- ID : " << studentID[place] << " -------" << endl;
	cout << "Fullname : " << firstname[place] << " " << lastname[place] << endl;
	cout << "Mark : " << mark[place] << endl;
	//}
}
float average() {
	float average;
	int sum = 0;
	for (int i = 0; i < number; i++) {
		sum += mark[i];
	}
	average = (float)sum / number;
	return average;
}
void showSearchMenu() {
	cout << "---------------------------------------" << endl;
	cout << "1- Search by Student ID" << endl;
	cout << "2- Search by Student Fullname" << endl;
}
int search(int id) {
	for (int i = 0; i < number; i++) {
		if (studentID[i] == id) {
			return i;
		}
	}
	return -1; // NOT FOUND
}
int search(string fn, string ln) {
	for (int i = 0; i < number; i++) {
		if (firstname[i] == fn && lastname[i] == ln) {
			return i;
		}
	}
	return -1;
}
int update(int stdid) {
	int answer;
	int searchResult = search(stdid);
	if (searchResult == -1) {
		cout << "Student Not Found \n";
		return -1; // unsuccessful update
	}
	else {
		printStudent(searchResult);
		// ------------------------ CHANGE ID ------------------------
		cout << "change Student ID? 1- YES 2- NO 3- Cancel" << "\t";
		cin >> answer;
		if (answer == 1) {
			int newID;
			cout << "New ID : ";
			cin >> newID;
			studentID[searchResult] = newID;
		}
		else if (answer == 2) {

		}
		else if (answer == 3) {
			cout << "UPDATE CANCELLED.\n";
			return -1;
		}
		else {
			cout << "BAD INPUT";
			return -1; // UNSUCCESSFULL UPDATE
		}
		// ------------------------ CHANGE FIRSTNAME ------------------------
		cout << "change firstname? 1- YES 2- NO 3- Cancel" << "\t";
		cin >> answer;
		if (answer == 1) {
			string fn;
			cout << "New Firstname : ";
			cin >> fn;
			firstname[searchResult] = fn;
		}
		else if (answer == 2) {

		}
		else if (answer == 3) {
			cout << "UPDATE CANCELLED.\n";
			return -1;
		}
		else {
			cout << "BAD INPUT";
			return -1; // UNSUCCESSFULL UPDATE
		}

		// ------------------------ CHANGE LASTNAME ------------------------
		cout << "Change Lastname ? 1- YES 2- NO 3- Cancel \t";
		cin >> answer;
		if (answer == 1) {
			string ln;
			cout << "New Lastname : ";
			cin >> ln;
			lastname[searchResult] = ln;
		}
		else if (answer == 2) {

		}
		else if (answer == 3) {
			cout << "UPDATE CANCELLED.\n";
			return -1;
		}
		else {
			cout << "BAD INPUT";
			return -1; // UNSUCCESSFULL UPDATE
		}

		// ------------------------ CHANGE MARK ------------------------
		cout << "Change Mark ? 1- YES 2- NO 3- Cancel\t";
		cin >> answer;
		if (answer == 1) {
			int newMark;
			cout << "New Mark : ";
			cin >> newMark;
			mark[searchResult] = newMark;
		}
		else if (answer == 2) {

		}
		else if (answer == 3) {
			cout << "UPDATE CANCELLED.\n";
			return -1;
		}
		else {
			cout << "BAD INPUT";
			return -1; // UNSUCCESSFULL UPDATE
		}

		cout << "Student Updated successfully." << endl;
		return 1;
	}
}

int deleteStudent(int id) {
	int searchResult = search(id);
	if (searchResult == -1) {
		cout << "Student not found. ";
		return -1;
	}
	else {
		cout << "Delete this student ? \n";
		printStudent(searchResult);
		cout << "1- YES 2- NO \t";
		int answer;
		cin >> answer;
		if (answer == 1) {
			for (int i = searchResult; i < number; i++) {
				firstname[searchResult] = firstname[searchResult + 1];
				lastname[searchResult] = lastname[searchResult + 1];
				studentID[searchResult] = studentID[searchResult + 1];
				mark[searchResult] = mark[searchResult + 1];
			}
			firstname[number - 1] = "";
			lastname[number - 1] = "";
			studentID[number - 1] = 0;
			mark[number - 1] = 0;

			number--;
			return 1;
		}
		else if (answer == 2) {
			cout << "Delete cancelled" << endl;
			return -1;
		}
		else {
			cout << "BAD INPuT\n";
			return -1;
		}
	}
}
