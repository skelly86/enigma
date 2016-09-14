/*
 * Implement to handle encrypting a file
 * TODO make encrypted file in an (original file name).extension format
 */
#include<string>
#include<iostream>
#include<fstream>
#include"enigma.h"

bool encrypt(const string &fileName) {
	bool success = true;
	srand(static_cast<int>(time(NULL)));
	for(int i = 0, x = rand() % UINTMAX_MAX;
			i < x;
			i++)
		rand();
	try {
		string file = fileName;
		ifstream uncrypt;
		ofstream cryptFile, key;
		uncrypt.open(file.c_str());
		string message;
		int rotator = ROTOR;
		key.open(file + ".key");
		key << rotator;
		key.close();
		file += EXTENSION;
		cryptFile.open(file);
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
		ifstream cryptFile, key;
		ofstream uncrypt;
		cryptFile.open(fileName);
		key.open(fileName + ".key");
		string message;
		int rotator;
		key >> rotator;
		//TODO Take enigma extension out of file name.
		file = "";
		uncrypt.open(file);
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

void cipher(string &message, int &rotor, bool encrypt) {
	if(encrypt)
		for(int i = 0; i < message.length(); i++)
			message[i] = ~((static_cast<unsigned char>(message[i]) + rotor++) % UCHAR_MAX);
	else
		for(int i = 0; i < message.length(); i++)
			message[i] = ((~static_cast<unsigned char>(message[i])) - rotor++) % UCHAR_MAX;
}
