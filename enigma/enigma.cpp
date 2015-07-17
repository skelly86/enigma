/*
 * Implement to handle encrypting a file
 * TODO make encrypted file in an (original file name).extension format
 */

#include"enigma.h"
bool encrypt(const string &fileName) {
	bool success = true;
	try {
		// file data
		string file = fileName;
		ifstream uncrypt;
		uncrypt.open(file.c_str());
	
		// data to hold the encrypted message
		string newMessage = "";
		string message;
		int rotator = ROTOR;
	
		// Encrypt the file name
		for (unsigned int i = 0; i < fileName.length(); i++) {
			// change letter based on position of rotor
			newMessage += (static_cast<unsigned char>(fileName[i]) + rotator) % UCHAR_MAX;
			// increment rotor
			rotator = (rotator + 1) % UCHAR_MAX;
		}
		file = newMessage;
		// create encrypted file
		ofstream cryptFile;
		cryptFile.open(file.c_str());
		// go through the unencrypted file
		while (!uncrypt.eof()) {
			// Take current line in file
			getline(uncrypt, message);
			// reset newMessage
			newMessage = "";
			// Go through the message
			for (unsigned int i = 0; i < message.length(); i++) {
				// change the letter based on position of rotor
				newMessage += (static_cast<unsigned char>(message[i]) + rotator) % UCHAR_MAX;
				// increment rotor
				rotator = (rotator + 1) % UCHAR_MAX;
			}
			// put the encrypted line in the file.
			cryptFile << newMessage << endl;
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
		string newMessage = "";
		string message;
		int rotator = ROTOR;
		// Encrypt the file name
		for (unsigned int i = 0; i < fileName.length(); i++) {
			// change letter based on position of rotor
			newMessage += (static_cast<unsigned char>(fileName[i]) + rotator) % UCHAR_MAX;
			// increment rotor
			rotator = (rotator + 1) % UCHAR_MAX;
		}
		file = newMessage;
		// create decrypted file
		ofstream uncrypt;
		uncrypt.open(file.c_str());
		// go through the unencrypted file
		while (!cryptFile.eof()) {
			// Take current line in file
			getline(cryptFile, message);
			// reset newMessage
			newMessage = "";
			// Go through the message
			for (unsigned int i = 0; i < message.length(); i++) {
				// change the letter based on position of rotor
				newMessage += (static_cast<unsigned char>(message[i]) - rotator) % UCHAR_MAX;
				// increment rotor
				rotator = (rotator + 1) % UCHAR_MAX;
			}
			// put the unencrypted line in the file.
			uncrypt << newMessage << endl;
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
// TODO Implement function cipher
bool cipher(string &message, unsigned int rotor) {
	return 1;
}
