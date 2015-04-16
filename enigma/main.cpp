/*
 * Name: Shauna Kelly
 * Date written out: 14JUN2014
 * Enigma Simulator
 * Description:	This is the concept of the mechanical/electrical
 *				encryption computer, codename enigma, implemented
 *				in C++
 */

#include"enigma.h"

// change from handling a message to handling a file
int main(int argc, char **argv)
{
	// Data to hold the two message forms
	string fileName;
	int ending = 0;
	cout << "Enter the file name: ";
	getline(cin, fileName);
	if (argc == 0) {
		prompt:
		char prompt;
		cout << "Encrypt or decrypt? (e or d) ";
		cin >> prompt;
		switch (toupper(prompt)) {
		case 'E':
			if (!encrypt(fileName)) {
				cerr << "failed to encrypt " << fileName << endl;
				ending++;
			}
			else
				cout << "encryption complete" << endl;
			break;
		case 'D':
			if (!decrypt(fileName)) {
				cerr << "failed to decrypt " << fileName << endl;
				ending++;
			} else
				cout << "decryption complete" << endl;
			break;
		default:
			cerr << "Please select d or e";
			goto prompt;
			break;
		}
	} else {
		if(strcmp(argv[0], "-e") == 0)
			if(!encrypt(fileName)){
				cerr << "failed to encrypt " << fileName << endl;
				ending++;
			}
			else
				cout << "encryption complete" << endl;
		else if(strcmp(argv[0], "-d") == 0)
			if(!decrypt(fileName)){
				cerr << "failed to decrypt " << fileName << endl;
				ending++;
			}
			else
				cout << "decryption complete" << endl;
		else{
			cerr << "unrecognized function" << argv[0] << endl;
			ending++;
		}
	}
	
	return ending;
}
