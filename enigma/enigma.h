#ifndef ENIGMA_H
#define ENIGMA_H
#include<exception>
#include<string>
#include<climits>
#include<cstdint>
#include<cstdlib>
#include<ctime>
typedef uintmax_t maxint;
using namespace std;

#define ROTOR (rand() % UINTMAX_MAX)
#define EXTENSION ".nga"

bool encrypt(const string &fileName);

bool decrypt(const string &fileName);

void cipher(string &message, maxint &rotor, bool encrypt);

#endif
