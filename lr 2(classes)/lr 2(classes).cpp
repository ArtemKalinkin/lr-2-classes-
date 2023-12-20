#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <malloc.h>
#include <iostream>
#include "Company.h"
#include "City.h"
#include "Subject.h"
#include "Country.h"
#include "Сontinent.h"
#include "supportFunction.h"

#define MAXCONTINENTS 6

using namespace std;

void inputAllClasses(Continent continents[]);
int menuOutput();
Continent& choosingContinent(Continent continents[]);
void outputStm(Continent* continets, int number);
int searchCompanies(Company* listPtrOfCompanies[], Continent continents[]);
void mergerOfCompanies(Continent listOfcontinents[]);
int yesOrNo(string s);
void workWithArrays();
void qSort(Company companies[], int nStart, int nEnd);

Continent listOfContinents[6];

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	int number;
	int i, n;
	int numberOfContinent;
	int numberFirst, numberSecond;
	Company* listOfPtrCompanies[MAXCOMPANIES];
	string name;
	string address;
	string industry;
	string date;
	Country* countries;
	Country* theCountryOne;
	Country* theCountryTwo;
	Continent* theContinent;
	Continent continent;
	workWithArrays();
	inputAllClasses(listOfContinents);
	number = menuOutput();
	outputStm(listOfContinents, number);
	cout << "\n\n\n\nСРАВНЕНИЕ ДВУХ СТРАН\n" << endl;
	continent = choosingContinent(listOfContinents);
	countries = continent.getListOfCountries();
	i = 0;
	countries[0].countryTableHeader();
	while ((!countries[i].getName().empty()) && (i < MAXCOUNTRIES)) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << countries[i];
		i++;
	}
	n = i;
	do {
		cout << "Введите номер первой страны в списке: ";
		scanf("%d", &numberFirst);
		if ((numberFirst < 1) || (numberFirst > n))
			puts("Страны с данным номером нет в списке");
	} while ((numberFirst < 1) || (numberFirst > n));
	do {
		cout << "Введите номер второй страны в списке: ";
		scanf("%d", &numberSecond);
		if ((numberSecond < 1) || (numberSecond > n))
			cout << "Страны с данным номером нет в списке" << endl;
		if (numberSecond == numberFirst)
			cout << "Данная страна уже выбрана" << endl;
	} while ((numberSecond < 1) || (numberSecond > n) || (numberSecond == numberFirst));
	try
	{
		theCountryOne = new Country();
	}
	catch (const std::exception& e)
	{
		cout << "Ошибка! Не удалось выделить память!" << endl;
		return -1;
	}
	try
	{
		theCountryTwo = new Country();
	}
	catch (const std::exception& e)
	{
		cout << "Ошибка! Не удалось выделить память!" << endl;
		return -1;
	}
	cout << "\n" << endl;
	*theCountryOne = countries[numberFirst - 1];
	*theCountryTwo = countries[numberSecond - 1];
	theCountryOne->countryTableHeader();
	cout << "* " << setw(5) << left << 1 << " * ";
	cout << *theCountryOne;
	cout << "* " << setw(5) << left << 2 << " * ";
	cout << *theCountryTwo;
	if (theCountryOne->comparisonOfTwoCountries(theCountryTwo) == 1)
		cout << "\nПо общим показателям страна - " << theCountryOne->getName() << " лучше страны - " << theCountryTwo->getName() << endl;
	else
		cout << "\nПо общим показателям страна - " << theCountryTwo->getName() << " лучше страны - " << theCountryOne->getName() << endl;
	cout << "\n\nСРАВНЕНИЕ КОМПАНИЙ" << endl;
	number = searchCompanies(listOfPtrCompanies, listOfContinents);
	if (number != 0)
		compareCompanies(listOfPtrCompanies, number);
	cout << "\n\n\n" << endl;
	Continent::printTotalContinents();
	Country::printTotalCountries();
	Subject::printTotalSubjects();
	City::printTotalCities();
	Company::printTotalCompanies();
	return 0;
}

//Функция ввода всех списков
void inputAllClasses(Continent continents[])
{
	int i, j, k, x, z;
	string address;
	Country* countries;
	Subject* subjects;
	City* cities;
	Company* companies;
	i = 0;
	do {
		continents[i].inputСontinentFromConsole();
		countries = continents[i].getListOfCountries();
		j = 0;
		do {
			countries[j].inputCountryFromConsole();
			subjects = countries[j].getListOfSubjects();
			k = 0;
			do {
				subjects[k].inputSubjectFromConsole();
				cities = subjects[k].getListOfCities();
				x = 0;
				do {
					cities[x].inputCityFromConsole();
					companies = cities[x].getListOfCompanies();
					address = countries[j].getName() + ", " + subjects[k].getName() + ", " + cities[x].getName();
					z = 0;
					do {
						companies[z].inputCompanyFromConsole(0);
						try {
							companies[z].setcitySubjectCountry(address);
						}
						catch (const invalid_argument e) {
							cerr << "Произошла ошибка: " << e.what() << endl;
						}
						z++;
						Company::incrementTotalCompanies();
						if (z == MAXCOMPANIES)
							cout << "Вы ввели максимальное количество компаний для одного города!" << endl;
						else {
							cout << "Для завершения ввода компаний нажмите Esc." << endl;
							cout << "Для продолжения любую другую клавишу.\n" << endl;
						}
					} while ((_getch() != 27) && (z < MAXCOMPANIES));
					x++;
					City::incrementTotalCities();
					if (x == MAXCITIES)
						cout << "Вы ввели максимальное количество городов для одного субъекта!" << endl;
					else {
						cout << "Для завершения ввода городов нажмите Esc." << endl;
						cout << "Для продолжения любую другую клавишу.\n" << endl;
					}
				} while ((_getch() != 27) && (x < MAXCITIES));
				k++;
				Subject::incrementTotalSubjects();
				if (k == MAXSUBJECTS)
					cout << "Вы ввели максимальное количество субъектов для одной страны!" << endl;
				else {
					cout << "Для завершения ввода субъектов нажмите Esc." << endl;
					cout << "Для продолжения любую другую клавишу.\n" << endl;
				}
			} while ((_getch() != 27) && (k < MAXSUBJECTS));
			countries[j].setNetProfitCountryFromCompanies(countries[j].calculatingProfitsFromCompanies());
			j++;
			Country::incrementTotalCountries();
			if (j == MAXCOUNTRIES)
				cout << "Вы ввели максимальное количество стан для одного континета!" << endl;
			else {
				cout << "Для завершения ввода стран нажмите Esc." << endl;
				cout << "Для продолжения любую другую клавишу.\n" << endl;
			}
		} while ((_getch() != 27) && (j < MAXCOUNTRIES));
		i++;
		Continent::incrementTotalContinents();
		if (i == MAXCONTINENTS)
			cout << "Вы ввели все существующие континеты!" << endl;
		else {
			cout << "Для завершения ввода континетов нажмите Esc." << endl;
			cout << "Для продолжения любую другую клавишу.\n" << endl;
		}
	} while ((_getch() != 27) && (i < MAXCONTINENTS));
}


// Функция выбора континента 
Continent& choosingContinent(Continent continents[]) {
	int i, n, number;
	char character;
	continents[0].continentTableHeader();
	i = 0;
	while ((!continents[i].getName().empty()) && (i < MAXCONTINENTS)) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << continents[i];
		i++;
	}
	n = i;
	cout << "\nВыберите континент\n" << endl;
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > n));
	return continents[number - 1];
}

// Функция вывода списков
void outputStm(Continent* continets, int number)
{
	int i;
	Country* countries;
	Subject* subjects;
	City* cities;
	Company* companies;
	Continent continent;
	Country country;
	Subject subject;
	City city;
	switch (number)
	{
	case 1:
		i = 0;
		Continent::continentTableHeader();
		while ((!continets[i].getName().empty()) && (i < MAXCONTINENTS)) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << continets[i];
			i++;
		}
		break;
	case 2:
		continent = choosingContinent(continets);
		countries = continent.getListOfCountries();
		i = 0;
		Country::countryTableHeader();
		while ((!countries[i].getName().empty()) && (i < MAXCOUNTRIES)) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << countries[i];
			i++;
		}
		break;
	case 3:
		continent = choosingContinent(continets);
		country = continent.choosingCountry();
		subjects = country.getListOfSubjects();
		i = 0;
		Subject::subjectTableHeader();
		while ((!subjects[i].getName().empty()) && (i < MAXSUBJECTS)) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << subjects[i];
			i++;
		}
		break;
	case 4:
		continent = choosingContinent(continets);
		country = continent.choosingCountry();
		subject = country.choosingSubject();
		cities = subject.getListOfCities();
		i = 0;
		City::cityTableHeader();
		while ((!cities[i].getName().empty()) && (i < MAXCITIES)) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << cities[i];
			i++;
		}
		break;
	case 5:
		continent = choosingContinent(continets);
		country = continent.choosingCountry();
		subject = country.choosingSubject();
		city = subject.choosingCity();
		companies = city.getListOfCompanies();
		i = 0;
		Company::companyTableHeader();
		while ((!companies[i].getName().empty()) && (i < MAXCOMPANIES)) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << companies[i];
			i++;
		}
		break;
	default:
		break;
	}
}

int searchCompanies(Company* listPtrOfCompanies[], Continent continents[])
{
	int i, j, k, x, z;
	int number;
	Country* countries;
	Subject* subjects;
	City* cities;
	Company* companies;
	string industry;
	while (getchar() != '\n');
	do {
		cout << "Введите отрасль компаний, которые хотели бы сравнить: ";
		getline(cin, industry);
	} while (protectionAgainstIncorrectTextInput(industry));
	number = 0;
	i = 0;
	while ((!continents[i].getName().empty()) && (i < MAXCONTINENTS)) {
		j = 0;
		countries = continents[i].getListOfCountries();
		while ((!countries[j].getName().empty()) && (j < MAXCOUNTRIES)) {
			k = 0;
			subjects = countries[j].getListOfSubjects();
			while ((!subjects[k].getName().empty()) && (k < MAXSUBJECTS)) {
				x = 0;
				cities = subjects[k].getListOfCities();
				while ((!cities[x].getName().empty()) && (x < MAXCITIES)) {
					z = 0;
					companies = cities[x].getListOfCompanies();
					while ((!companies[z].getName().empty()) && (z < MAXCOMPANIES)) {
						if (!industry.compare(companies[z].getIndustry())) {
							listPtrOfCompanies[number] = &companies[z];
							number++;
						}
						z++;
					}
					x++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	if (number == 0)
		cout << "Не удалось найти ни одной компании данной отрасли!" << endl;
	return number;
}

void mergerOfCompanies(Continent listOfcontinents[])
{
	int i, j, k, x, z;
	int number = 0;
	int numberOne, numberTwo;
	int numberOfContinent;
	int numberOfCountry;
	int numberOfSubject;
	int numberOfCity;
	Country* countries;
	Subject* subjects;
	City* cities;
	Company* companies;
	Company* listPtrOfCompanies[100];
	i = 0;
	while ((!listOfcontinents[i].getName().empty()) && (i < MAXCONTINENTS)) {
		j = 0;
		countries = listOfcontinents[i].getListOfCountries();
		while ((!countries[j].getName().empty()) && (j < MAXCOUNTRIES)) {
			k = 0;
			subjects = countries[j].getListOfSubjects();
			while ((!subjects[k].getName().empty()) && (k < MAXSUBJECTS)) {
				x = 0;
				cities = subjects[k].getListOfCities();
				while ((!cities[x].getName().empty()) && (x < MAXCITIES)) {
					z = 0;
					companies = cities[x].getListOfCompanies();
					while ((!companies[z].getName().empty()) && (z < MAXCOMPANIES)) {
						listPtrOfCompanies[number] = &companies[z];
						number++;
						z++;
					}
					x++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	Company::companyTableHeader();
	for (i = 0; i < number; i++) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << *listPtrOfCompanies[i];
	}
	do {
		cout << "Введите номер компании-покупателя: ";
		cin >> numberOne;
		if ((numberOne < 1) || (numberOne > number))
			cout << "Компании под данным номером нет в списке!" << endl;
	} while ((numberOne < 1) || (numberOne > number));
	do {
		cout << "Введите номер компании, которую покупают: ";
		cin >> numberTwo;
		if (numberTwo == numberOne)
			cout << "Данная компания выступает в роли покупателя" << endl;
		if ((numberOne < 1) || (numberOne > number))
			cout << "Компании под данным номером нет в списке!" << endl;
	} while ((numberOne < 1) || (numberOne > number) || (numberTwo == numberOne));
	*listPtrOfCompanies[numberOne - 1] = *listPtrOfCompanies[numberOne - 1] + *listPtrOfCompanies[numberTwo - 1];
}

int yesOrNo(string s)
{
	char c;
	do {
		cout << s << endl;
		c = _getch();
		if ((c != 'y') && (c != 'n')) {
			cout << "Ответы могут быть только y/n:" << endl;
			cout << "Да - y" << endl;
			cout << "Нет - n" << endl;
		}
	} while ((c != 'y') && (c != 'n'));
	if (c == 'y')
		return 1;
	else
		return 0;
}

void workWithArrays()
{
	Company companiesOne[16];
	Company companiesTwo[4][4];
	int k = 0;
	cout << "Ввод барнаульских компаний" << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			companiesTwo[i][j].inputCompanyFromConsole(0);
			companiesTwo[i][j].setcitySubjectCountry("Россия, Алтайский край, Барнаул");
			companiesOne[k] = companiesTwo[i][j];
			k++;
		}
	}
	cout << "\n\nСписок до сортировки:\n" << endl;
	Company::companyTableHeader();
	k = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "* " << setw(5) << left << k + 1 << " * ";
			cout << companiesTwo[i][j];
			k++;
		}
	}
	qSort(companiesOne, 0, 15);
	cout << "\n\nСписок после сортировки:\n" << endl;
	Company::companyTableHeader();
	for (int i = 0; i < 16; i++) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << companiesOne[i];
	}
}

void qSort(Company companies[], int nStart, int nEnd)
{
	int left, right, x;
	Company temp;
	if (nStart >= nEnd) return; 
	left = nStart; right = nEnd;
	x = companies[(left + right) / 2].getNetProfit();
	while (left <= right) {         
		while (companies[left].getNetProfit() < x) left++;
		while (companies[right].getNetProfit() > x) right--;
		if (left <= right) {
			temp = companies[left];
			companies[left] = companies[right];
			companies[right] = temp;
			left++; right--;
		}
	}
	qSort(companies, nStart, right); 
	qSort(companies, left, nEnd);
}


void compareCompanies(Company* listPtrOfCompanies[], int number) {
	int i, count, j;
	int array[20];
	char character;
	int numberOfCompany;
	int flag;
	int maxProfit;
	Company::companyTableHeader();
	for (i = 0; i < number; i++) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << *listPtrOfCompanies[i];
	}
	count = 0;
	do {
		flag = 0;
		do {
			cout << "Введите номер компании: ";
			cin >> numberOfCompany;
			if ((numberOfCompany < 1) || (numberOfCompany > number))
				cout << "Компании с данным номером нет в списке" << endl;
		} while ((numberOfCompany < 1) || (numberOfCompany > number));
		for (i = 0; i < count; i++) {
			if (numberOfCompany - 1 == array[i]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << "Данная компания уже выбрана!" << endl;
			cout << "Для продолжения нажмите любую клавишу" << endl;
		}
		else {
			array[count] = numberOfCompany - 1;
			count++;
			if (count == number) {
				cout << "Вы выбрали все компании" << endl;
				cout << "Для продолжения нажмите любую клавишу" << endl;
			}
			else {
				cout << "Для продолжения выбора компаний нажмите любую клавишу" << endl;
				cout << "Для завершения нажмите Esc" << endl;
			}
		}
	} while ((_getch() != 27) && (count != number));
	maxProfit = listPtrOfCompanies[0]->getNetProfit();
	numberOfCompany = 0;
	for (i = 0; i < count; i++) {
		if (listPtrOfCompanies[array[i]]->getNetProfit() > maxProfit) {
			maxProfit = listPtrOfCompanies[array[i]]->getNetProfit();
			numberOfCompany = i;
		}
	}
	cout << "\n\nКомпания с наибольшим заработком в своей отрасли" << endl;
	cout << "Отрасль - " << listPtrOfCompanies[numberOfCompany]->getIndustry() << endl;
	cout << "Название - " << listPtrOfCompanies[numberOfCompany]->getName() << endl;
	cout << "Прибыль - " << listPtrOfCompanies[numberOfCompany]->getNetProfit() << endl;

}

// Меню выбора вывода
int menuOutput()
{
	char character;
	int number;
	cout << "Вывести на экран:" << endl;
	cout << "1.Все континенты" << endl;
	cout << "2.Все страны определенного континента" << endl;
	cout << "3.Все субъекты определенной страны" << endl;
	cout << "4.Все города определенного субъекта" << endl;
	cout << "5.Все компании определенного города\n\n\n" << endl;
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > 5));
	return number;
}


