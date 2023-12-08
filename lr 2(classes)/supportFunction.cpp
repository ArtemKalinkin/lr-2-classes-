#include"supportFunction.h"
#include <stdio.h>
#include <string.h>
#include <cctype>




int protectionAgainstIncorrectTextInput(string line) {
	string letters =
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"абвгдеёжщийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	string digits = "1234567890";
	if (line.empty()) {
		throw invalid_argument("Строка не может быть пустой!");
	}
	if (line.length() > LENNAME) {
		throw length_error("Слишком большая длина строки!");
	}
	if ((line.find_first_of(letters) == string::npos) && (line.find_first_of(digits) == string::npos)) {
		throw invalid_argument("Строка должна содержать буквы или цифры!");
	}
	return 0;
}


int checkingForCorrectnessOfDateEntry(string date) {
	int i, flag;
	flag = 0;
	if (date.length() != 10) {
		cout << "\nДата содержит меньше символов, чем предусмотрено!" << endl;
		flag = 1;
	}
	else {
		if ((!isdigit(date[0])) || (!isdigit(date[1]))) {
			cout << "\nЧисло введено некорректно!" << endl;
			flag = 2;
		}
		if ((date[2] != '.') || (date[5]) != '.') {
			cout << "\nПосле числа и месяца необходимо поставить точку !!!" << endl;
			flag = 3;
		}
		if ((!isdigit(date[3])) || (!isdigit(date[4]))) {
			cout << "\nМесяц введен некорректно!" << endl;
			flag = 4;
		}
		for (i = 6; i < 10; i++)
			if (!isdigit(date[i])) {
				cout << "\nГод введен некорректно!" << endl;
				flag = 5;
				break;
			}
	}
	if (flag)
		cout << "\nШАБЛОН ВВОДА ДАТЫ - дд.мм.гггг" << endl;
	return flag;
}

int calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(unsigned long a, unsigned long b)
{
	int result;
	result = (a - b) / b * 100;
	return result;
}

