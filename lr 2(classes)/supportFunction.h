#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <cctype>
#include <conio.h>
#include <malloc.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

#define LENNAME 50

int protectionAgainstIncorrectTextInput(string line);
int checkingForCorrectnessOfDateEntry(string date);
int calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(unsigned long a, unsigned long b);
