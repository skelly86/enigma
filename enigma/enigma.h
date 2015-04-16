#ifndef ENIGMA_H
#define ENIGMA_H
#include<exception>
#include<iostream>
#include<fstream>
#include<string>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;

// randomly generate a start point at compile time (I hope)
#define ROTOR (rand() % UCHAR_MAX)

bool encrypt(const string &fileName);

bool decrypt(const string &fileName);

#endif
