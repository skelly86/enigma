/*
 * Name: Shauna Kelly
 * Date written out: 14JUN2014
 * Enigma Simulator
 * Description:	This is the concept of the mechanical/electrical
 *				encryption computer, codename enigma, implemented
 *				in C++
 */

#include"enigma.h"
#include<iostream>
#include<string>
#include<cstring>

bool handleArgs(int argc, const char **argv);

int main(int argc, const char **argv) {
	int ending = 0;
	if (argc > 0) {
		if(!handleArgs(argc, argv)){
			cerr << "unknown error" << endl;
			ending = EXIT_FAILURE;
		}
		else
			cout << "encryption complete" << endl;
	}
	
	return ending;
}

bool handleArgs(int argc, const char **argv) {
	bool result;
	for(int i = 0; i < argc; i++)
		if(strchr(argv[i], '-') != NULL)
			if(strchr(argv[i], 'e') != NULL ||
					strchr(argv[i], 'E') != NULL)
				result = encrypt(argv[i+1]);
			else if (strchr(argv[i], 'd') != NULL ||
					strchr(argv[i], 'D') != NULL)
				result = decrypt(argv[i+1]);
	return result;
}
