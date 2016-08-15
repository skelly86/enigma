/*
 * Implement to handle encrypting a file
 * TODO make encrypted file in an (original file name).extension format
 */
#include<string>
#include<iostream>
#include<fstream>
#include"enigma.h"
using namespace std;
bool encrypt(const string &fileName) {
	bool success = true;
	try {
		// file data
		string file = fileName;
		ifstream uncrypt;
		uncrypt.open(file.c_str());
	
		// data to hold the encrypted message
		string message;
		unsigned int rotator = ROTOR;
		file += EXTENSION;
		// create encrypted file
		ofstream cryptFile;
		cryptFile.open(file.c_str());
		// go through the unencrypted file
		while (!uncrypt.eof()) {
			// Take current line in file
			getline(uncrypt, message);
			// Go through the message
			cipher(message, rotator, true);
			// put the encrypted line in the file.
			cryptFile << message << endl;
		}
		uncrypt.close();
		cryptFile.close();
	}
	catch (exception &) {
		success = false;
	}
	// return if file was encrypted
	return success;
}

// copied from encrypt(string), convert for decrypting
bool decrypt(const string &fileName)
{
	bool success = true;
	try {
		// file data
		string file = fileName;
		ifstream cryptFile;
		cryptFile.open(file.c_str());
		// data to hold the encrypted message
		string message;
		unsigned int rotator = ROTOR;
		// Encrypt the file name
		//TODO Take enigma extension out of file name.
		file = "";
		// create decrypted file
		ofstream uncrypt;
		uncrypt.open(file.c_str());
		// go through the unencrypted file
		while (!cryptFile.eof()) {
			// Take current line in file
			getline(cryptFile, message);
			cipher(message, rotator, false);
			// put the unencrypted line in the file.
			uncrypt << message << endl;
		}
		uncrypt.close();
		cryptFile.close();
	}
	catch (exception &) {
		success = false;
	}
	// return if file was encrypted
	return success;
}

void cipher(string &message, unsigned int &rotor, bool encrypt) {
	if(encrypt) {
		for(unsigned int i = 0; i < message.length(); i++) {
			message[i] = ~((message[i] + rotor) % UCHAR_MAX);
			rotor++;
		}
	} else {
		for(unsigned int i = 0; i < message.length(); i++) {
			message[i] = ((~message[i]) - rotor) % UCHAR_MAX);
			rotor++;
		}
	}
}
