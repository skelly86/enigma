#ifndef ENIGMA_H
#define ENIGMA_H
#include<exception>
#include<string>
#include<climits>
#include<cstdlib>
using namespace std;

// randomly generate a start point at compile time (I hope)
#define ROTOR (rand() % UCHAR_MAX)
#define EXTENSION ".nga"

bool encrypt(const string &fileName);

bool decrypt(const string &fileName);

void cipher(string &message, unsigned long long int &rotor, bool encrypt);

#endif
