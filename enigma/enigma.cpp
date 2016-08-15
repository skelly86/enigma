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
		string file = fileName;
		ifstream uncrypt;
		uncrypt.open(file.c_str());
		string message;
		unsigned int rotator = ROTOR;
		file += EXTENSION;
		ofstream cryptFile;
		cryptFile.open(file.c_str());
		while (!uncrypt.eof()) {
			getline(uncrypt, message);
			cipher(message, rotator, true);
			cryptFile << message << endl;
		}
		uncrypt.close();
		cryptFile.close();
	}
	catch (exception &) {
		success = false;
	}
	return success;
}

// copied from encrypt(string), convert for decrypting
bool decrypt(const string &fileName)
{
	bool success = true;
	try {
		string file = fileName;
		ifstream cryptFile;
		cryptFile.open(file.c_str());
		string message;
		unsigned int rotator = ROTOR;
		//TODO Take enigma extension out of file name.
		file = "";
		ofstream uncrypt;
		uncrypt.open(file.c_str());
		while (!cryptFile.eof()) {
			getline(cryptFile, message);
			cipher(message, rotator, false);
			uncrypt << message << endl;
		}
		uncrypt.close();
		cryptFile.close();
	}
	catch (exception &) {
		success = false;
	}
	return success;
}

void cipher(string &message, unsigned int &rotor, bool encrypt) {
	if(encrypt)
		for(unsigned int i = 0; i < message.length(); i++)
			message[i] = ~((static_cast<unsigned char>(message[i]) + rotor++) % UCHAR_MAX);
	else
		for(unsigned int i = 0; i < message.length(); i++)
			message[i] = ((~static_cast<unsigned char>(message[i])) - rotor++) % UCHAR_MAX;
}
