#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <cctype>
#include <conio.h>
#include <malloc.h>

#define LENNAME 100

int protectionAgainstIncorrectTextInput(char* line);
void deletingNewlineTransitionCharacter(char* line);
int checkingForCorrectnessOfDateEntry(char* date);
int calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(unsigned long a, unsigned long b);
