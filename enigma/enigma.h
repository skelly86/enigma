#ifndef ENIGMA_H
#define ENIGMA_H
#include<exception>
#include<string>
#include<climits>
#include<cstdint>
#include<cstdlib>
#include<ctime>
#define int uintmax_t
using namespace std;

#ifndef NULL
#define NULL 0
#endif

#define ROTOR (rand() % UINTMAX_MAX)
#define EXTENSION ".nga"

bool encrypt(const string &fileName);

bool decrypt(const string &fileName);

void cipher(string &message, int &rotor, bool encrypt);

#endif
