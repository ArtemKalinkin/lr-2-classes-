#include"supportFunction.h"
#include <stdio.h>
#include <string.h>
#include <cctype>




int protectionAgainstIncorrectTextInput(string line) {
	string letters =
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"�������������������������������������Ũ��������������������������";
	string digits = "1234567890";
	if (line.empty()) {
		throw invalid_argument("������ �� ����� ���� ������!");
	}
	if (line.length() > LENNAME) {
		throw length_error("������� ������� ����� ������!");
	}
	if ((line.find_first_of(letters) == string::npos) && (line.find_first_of(digits) == string::npos)) {
		throw invalid_argument("������ ������ ��������� ����� ��� �����!");
	}
	return 0;
}


int checkingForCorrectnessOfDateEntry(string date) {
	int i, flag;
	flag = 0;
	if (date.length() != 10) {
		cout << "\n���� �������� ������ ��������, ��� �������������!" << endl;
		flag = 1;
	}
	else {
		if ((!isdigit(date[0])) || (!isdigit(date[1]))) {
			cout << "\n����� ������� �����������!" << endl;
			flag = 2;
		}
		if ((date[2] != '.') || (date[5]) != '.') {
			cout << "\n����� ����� � ������ ���������� ��������� ����� !!!" << endl;
			flag = 3;
		}
		if ((!isdigit(date[3])) || (!isdigit(date[4]))) {
			cout << "\n����� ������ �����������!" << endl;
			flag = 4;
		}
		for (i = 6; i < 10; i++)
			if (!isdigit(date[i])) {
				cout << "\n��� ������ �����������!" << endl;
				flag = 5;
				break;
			}
	}
	if (flag)
		cout << "\n������ ����� ���� - ��.��.����" << endl;
	return flag;
}

int calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(unsigned long a, unsigned long b)
{
	int result;
	result = (a - b) / b * 100;
	return result;
}

