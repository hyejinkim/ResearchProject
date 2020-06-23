#include "barry.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void barrysProgram() {
	string message;
	string fileName = "cmd.exe /C start notepad ./original.txt";
	fstream originalFile("./original.txt", ios::out); //Creates file in output mode

	//Triggers if file doesn't open
	if(!originalFile) {
		cout << "ERROR OPENING FILE! SHUTTING DOWN PROGRAM!";
		exit(1);
	}

	cout << "STARTING PART 1!";
	cin.ignore();
	system("cls");

	cout << "Enter message: ";
	getline(cin, message);
	originalFile << message << endl; //Transfers message from code to file
	originalFile.close();

	system(fileName.c_str()); //Shows message BEFORE conversion

	cout << "Now converting the message to ALL CAPS..." << endl;

	originalFile.open("./original.txt", ios::in); //Opens file in input mode
	if(!originalFile.is_open()) { //Checks if file is in the proper directory
		cout << "ERROR! WRONG DIRECTORY! SHUTTING DOWN PROGRAM!";
		exit(1);
	}
	getline(originalFile, message); //Transfers message from file to code
	originalFile.close();

	originalFile.open("./original.txt", ios::out | ios::trunc); //Opens file in output mode and DELETES content in the file

	/* Converts message from code to all uppercase
		and puts them to file*/
	for(int ch = 0; ch < message.length(); ch++) {

		originalFile.put(toupper(message[ch]));

	}
	originalFile << endl;

	system(fileName.c_str()); //Shows message AFTER conversion
	originalFile.close();
	system("clear");

	cout << "PART 1 COMPLETE! MOVING ONTO PART 2!";
	cin.ignore();
	system("clear");

	string folderNum;
	stringstream hi;

	//Creates trash folders
	for (int count = 1; count <= 10; count++) {
		cout << "Creating Trash #" << count << endl;

		string folderName = "mkdir -p /mnt/d/project/trashtrash";
		hi << count; //Converts int variable (count) to string variable
		folderNum = hi.str();
		folderName = folderName + folderNum;
        system(folderName.c_str());

		cout << "Created Trash #" << count << endl;

		//Clean up crew
		hi.str("");
		folderNum.erase();
		folderName.erase();
	}
	cout << "\nSuccessfully created all 10 Trash folders!";
	cin.ignore();
	system("clear");

	cout << "PART 2 COMPLETE! MOVING ONTO THE FINAL PART!";
	cin.ignore();
	system("clear");

	cout << "Creating Word Doc with message...\n";
	fstream wordDoc("./Hax.doc", ios::out); //Opens Word doc in output mode
	message = "U got hekd!";
	wordDoc << message << endl; //Transfers message from code to doc
	wordDoc.close();

	system("cmd.exe /C start ./Hax.doc"); //Opens Word doc in Microsoft Word
	cout << "Press Enter to continue...\n";
	cin.ignore();
	system("clear");

	//SUCCESS!!!
	cout << "FINAL PART COMPLETE! RESULTS: SUCCESS!!!\n";
	cout << "HOPE U ENJOYED :-)";
}