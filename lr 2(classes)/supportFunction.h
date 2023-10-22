#pragma once
#include <string.h>
#include <stdio.h>
#include <cctype>
#include <conio.h>

#define LENNAME 100

int protectionAgainstIncorrectTextInput(char* line);
void deletingNewlineTransitionCharacter(char* line);
int checkingForCorrectnessOfDateEntry(char* date);