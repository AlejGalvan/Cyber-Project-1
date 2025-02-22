#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getPasswordShift(string password);
bool checkPassword(string inputName, string password);
string encrypt(string text, int shiftNum);
string decrypt(string ciphertext, int shiftNum);
void encryptFile(string inputName, string outputName, string password);
void decryptFile(string inputName, string outputName, string password);

int main() {
	int choice;
	int chances = 3;
    	string inputFile;
	string outputFile;
    	string password;

	cout << "Hello, I am Sylphrena, but you can call me Syl and I can encrypt and decrypt" << endl;
	cout << "your files for you! Would you like to encrypt(1) or decrpypt(8)?: ";
    	cin >> choice;

	while (choice != 1 && choice != 8) {
		cout << "That wasn't one of the options silly!" << endl;
		cout << "Would you like for me to encrypt(1) or decrypt(8)?: ";
		cin >> choice;
	}

	// Encrypt file
	if (choice == 1) {
		cout << endl << "Which file would you like to encrpyt: ";
		cin >> inputFile;
		cout << endl << "And where would you like for me to store it: ";
		cin >> outputFile;
		cout << endl << "I'm just going to need a password to help encrpyt the file." << endl;
		cout << "Make sure it is at least 8 characters long, with no spaces." << endl;
		cout << "Go ahead: ";
		cin >> password;

		// Ensure password is at least 8 characters
		while (password.length() < 8) {
			cout << "The password needs to be at least 8 characters long, silly!" << endl;
			cout << "Enter another one please: ";
			cin >> password;
		}

		cout << endl << "Let me get that done for you! :)";
        	encryptFile(inputFile, outputFile, password);

		cout << endl << "All done! See you next time!" << endl;
	// Decrypt file
    	} else if (choice == 8) {
		cout << endl << "Which file would you like to decrpyt: ";
		cin >> inputFile;
		cout << endl << "And where would you like for me to store it: ";
		cin >> outputFile;
		cout << endl << "I'm just going to need the password you used to encrpyt the file." << endl;
		cout << "Do you remember it?: ";
		cin >> password;
		cout << "Let me make sure this is the right one.";

		// Check password
		while(chances > 0) {
			bool check = checkPassword(inputFile, password);
			if (check) {
        			decryptFile(inputFile, outputFile, password);
				break;
			} else {
				cout << endl << "That was not the right password. Are you sure you should be" << endl;
				cout << "accessing this file? Try again: ";
				cin >> password;
			}
			chances -= 1;
		}
		if (chances == 0) {
			cout << endl << "Yeah you definitely should not have access to this file!" << endl;
			cout << "Goodbye!" << endl;
		} else {
			cout << endl << "All done! See you next time!" << endl;
		}
  	}

    	return 0;
}

bool checkPassword(string inputName, string password) {
	int shift = getPasswordShift(password);
	string lastLine;
	string line;
	string encryptedPassword = encrypt(password, shift);

	// Open file and look for password
	ifstream inputFile(inputName);

	while (getline(inputFile, line)) {
        	lastLine = line;
    	}

	if (lastLine == encryptedPassword) {
		inputFile.close();
		return true;
	} else {
		inputFile.close();
		return false;
	}

}

int getPasswordShift(string password) {
	int shift = 0;
	char eighth;
	eighth = password.at(7);

	shift = 127 - eighth;

	return shift;
}

string encrypt(string text, int shiftNum) {
    	string encryptedText = text;
    	for (char &c : encryptedText) {
		if (c + shiftNum > 126) {
			c = 32 + ((c + shiftNum) - 127);
		} else {
        		c = c + shiftNum;
		}
    	}
    return encryptedText;
}

string decrypt(string text, int shiftNum) {
    string decryptedText = text;
    for (char &c : decryptedText) {
        if (c - shiftNum < 32) {
		c = 127 - ((32 + shiftNum) - c);
	} else {
		c = c - shiftNum;
	}
    }
    return decryptedText;
}

// Call getPasswordShift and encrypt to encrypt file correctly
void encryptFile(string inputName, string outputName, string password) {
	ifstream inputFile(inputName);
    	ofstream outputFile(outputName);
    	string line;
	int shiftNum = 0;

    	if (!inputFile.is_open() || !outputFile.is_open()) {
        	cout << "Error opening file!" << endl;
        	return;
    	}

	shiftNum = getPasswordShift(password);

    	while (getline(inputFile, line)) {
        	outputFile << encrypt(line, shiftNum) << endl;
    	}

	//encrypt password and add it to the bottom of the file
	outputFile << encrypt(password, shiftNum) << endl;

    	inputFile.close();
    	outputFile.close();
}

// Assumes Password is correct
// Call getPasswordShift and decrypt to decrypt file correctly
void decryptFile(string inputName, string outputName, string password) {
    	ifstream inputFile(inputName);
    	ofstream outputFile(outputName);
    	string line;
	int shiftNum = 0;

    	if (!inputFile.is_open() || !outputFile.is_open()) {
        	cout << "Error opening file!" << endl;
        	return;
    	}

	shiftNum = getPasswordShift(password);

    	while (getline(inputFile, line)) {
        	outputFile << decrypt(line, shiftNum) << endl;
    	}

    	inputFile.close();
    	outputFile.close();
}
