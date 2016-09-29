/*
 * Name: Shauna Kelly
 * Date written out: 14JUN2014
 * Enigma Simulator
 * Description:	This is the concept of the mechanical/electrical
 *				encryption computer, codename enigma, implemented
 *				in C++
 */

#include"enigma.h"
//int has to be redefined as 32-bit if enigma.h is included
#define int int32_t
#include<iostream>
#include<string>
#include<cstring>

// TODO: Allow file to be sent in main argument string array
// TODO: Only use the program by sending arguments to it
bool handleArgs(int argc, const char ** argv);
int main(int argc, const char **argv) {
	int ending = 0;
	if (argc > 0) {
		if(!handleArgs(argc, argv))
			ending++;
		else
			cout << "encryption complete" << endl;
	}
	
	return ending;
}
// TODO: implement function
bool handleArgs(int argc, const char ** argv) {
	for(int i = 0; i < argc; i++) {
		bool result;
		if(argv[i,0] == '-')
			for(int j = 1; j < strlen(argv[i]); j++)
				char arg = argv[i,j];
				switch(arg) {
				case 'e':
				case 'E':
					result = encrypt(argv[i+1]);
					break;
				case 'd':
				case 'D':
					result = decrypt(argv[i+1]);
					break;
				default:
					break;
				}
	}
	return true;
}
