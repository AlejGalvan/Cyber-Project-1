#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getPasswordShift(string password);
string encrypt(string plaintext, int key);
string decrypt(string ciphertext, int key);
void encryptFile(string inputFileName, string outputFileName, int key);
void decryptFile(string inputFileName, string outputFileName, int key);

int main() {
	int choice;
    	string inputFile, outputFile;
    	string password;

	cout << "Hello, I am Sylphrena, but you can call me Syl and I can encrypt and decrypt" << endl;
	cout << "your files for you! Would you like to encrypt(1) or decrpypt(8)?: ";
    	cin >> choice;

	while (choice != 1 || choice != 8) {
		cout << "That wasn't one of the options silly!" << endl;
		cout << "Would you like for me to encrypt(1) or decrypt(8)?: ";
		cin >> choice;
	}

	if (choice == 1) {
		cout << "Which file would you like to encrpyt: ";
		cin >> inputFile;
		cout << "And where would you like for me to store it: ";
		cin >> outputFile;
		cout << "I'm just going to need a password to help encrpyt the file." << endl
		cout << "Make sure it is at least 8 characters long, with no spaces." << endl
		cout << "Go ahead: ";
		cin >> password;
		cout << "Let me get that done for you! :)";
        	encryptFile(inputFile, outputFile, password);
    	} else if (choice == 8) {
		cout << "Which file would you like to decrpyt: ";
		cin >> inputFile;
		cout << "And where would you like for me to store it: ";
		cin >> outputFile;
		cout << "I'm just going to need the password you used to encrpyt the file." << endl
		cout << "Do you remember it?: ";
		cin >> password;
		cout << "Let me make sure this is the right one."
		// WIP
        	decryptFile(inputFile, outputFile, password);
  	}

    	return 0;
}

int getPasswordShift(string password) {
	int shift = 0;

	return shift;
}

string encrypt(string plaintext, int key) {
    string encryptedText = plaintext;
    for (char &c : encryptedText) {
        c = c + key; 
    }
    return encryptedText;
}

string decrypt(string ciphertext, int key) {
    string decryptedText = ciphertext;
    for (char &c : decryptedText) {
        c = c - key; 
    }
    return decryptedText;
}

void encryptFile(string inputFileName, string outputFileName, int key) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    string line;

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(inputFile, line)) {
        outputFile << encrypt(line, key) << endl;
    }

    inputFile.close();
    outputFile.close();
}

void decryptFile(string inputFileName, string outputFileName, int key) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    string line;

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(inputFile, line)) {
        outputFile << decrypt(line, key) << endl;
    }

    inputFile.close();
    outputFile.close();
}
