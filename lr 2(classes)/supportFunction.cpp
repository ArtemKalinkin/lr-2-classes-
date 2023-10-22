#include"supportFunction.h"
#include <stdio.h>
#include <string.h>
#include <cctype>




int protectionAgainstIncorrectTextInput(char* line) {
	int i, lineLength;
	if (line[0] == '\n') {
		puts("Ошибка! Данное поле не может быть пустым!");
		return 1;
	}
	lineLength = strlen(line);
	if (line[lineLength - 1] != '\n') {
		puts("Ошибка! Количество символов превышает допустимое зачение!");
		return 2;
	}
	for (i = 0; i < lineLength; i++)
		if ((!ispunct(line[i])) && (!isspace(line[i])))
			return 0;
	puts("Ошибка! В данном поле должны присутвовать буквы или цифры!");
	return 3;
}

void deletingNewlineTransitionCharacter(char* line) {
	int lineLength;
	lineLength = strlen(line);
	line[lineLength - 1] = '\0';
}

int checkingForCorrectnessOfDateEntry(char* date) {
	int i, flag;
	flag = 0;
	if ((!isdigit(date[0])) || (!isdigit(date[1]))) {
		puts("Число введено некорректно!");
		flag = 1;
	}
	if ((date[2] != '.') || (date[5]) != '.') {
		puts("После числа и месяца необходимо поставить точку !!!");
		flag = 2;
	}
	if ((!isdigit(date[3])) || (!isdigit(date[4]))) {
		puts("Месяц введен некорректно!");
		flag = 3;
	}
	for (i = 6; i < 10; i++)
		if (!isdigit(date[i])) {
			puts("Год введен некорректно!");
			flag = 4;
			break;
		}
	if (flag)
		puts("ШАБЛОН ВВОДА ДАТЫ - дд.мм.гггг");
	date[10] = '\0';
	return flag;
}