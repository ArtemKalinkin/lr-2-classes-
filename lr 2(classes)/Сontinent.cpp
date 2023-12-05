#include "Сontinent.h"

unsigned Continent::totalContinents = 0;

void Continent::setName(string name)
{
	this->name = name;
}

void Continent::setNumberOfCountries(int number)
{
	numberOfCountries = number;
}

void Continent::setSquare(int square)
{
	this->square = square;
}

void Continent::setListOfCountries(Country countries[])
{
	for (int i = 0; i < MAXCOUNTRIES; i++)
	{
		listOfCountries[i] = countries[i];
	}
}

string Continent::getName()
{
	return name;
}

int Continent::getNumberOfCountries()
{
	return numberOfCountries;
}

int Continent::getSquare()
{
	return square;
}

Country* Continent::getListOfCountries()
{
	return listOfCountries;
}

Continent::Continent()
{
	numberOfCountries = 0;
	square = 0;
}

Continent::Continent(string name)
{
	this->name = name;
	numberOfCountries = 0;
	square = 0;
}

Continent::Continent(string name, int number, int square, Country countries[])
{
	this->name = name;
	numberOfCountries = number;
	this->square = square;
	for (int i = 0; i < MAXCOUNTRIES; i++)
	{
		listOfCountries[i] = countries[i];
	}
}


void Continent::inputСontinentFromConsole()
{
	name = new char[LENNAME];
	puts("ВВОД КОНТИНЕНТА\n");
	do {
		cout << "Введите название континента:" << endl;
		getline(cin, name);
	} while (protectionAgainstIncorrectTextInput(name));
	cout << "Введите количество стран на континенте:" << endl;
	while (scanf("%d", &numberOfCountries) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите количество стран на континенте:\n";
	}
	cout << "Введите площадь континента (в кв. км):" << endl;
	while (scanf("%d", &square) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите площадь континента (в кв. км):\n";
	}
	while (getchar() != '\n');
}

void Continent::continentTableHeader()
{
	cout << "*******************************************************************************************************\n";
	cout << "* Номер *     Континент      * Количество стран * Площадь континента *          Список стран          *\n";
	cout << "*******************************************************************************************************\n";
}

void Continent::outputContinentToConsole(int number)
{
	int i;
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(18) << left << name << " * ";
	cout << setw(16) << left << numberOfCountries << " * ";
	cout << setw(18) << left << square << " * ";
	cout << setw(30) << left << listOfCountries[0].getName() << " *" << endl;
	i = 1;
	while ((!listOfCountries[i].getName().empty()) && (i < MAXCOUNTRIES)) {
		cout << "*       *                    *                  *                    * ";
		cout << setw(30) << left << listOfCountries[i].getName() << " *" << endl;
		i++;
	}
	cout <<"*******************************************************************************************************\n";
}

Country& Continent::choosingCountry()
{
	int i, n, number;
	char character;
	listOfCountries[0].countryTableHeader();
	i = 0;
	while (!listOfCountries[i].getName().empty()) {
		listOfCountries[i].outputCountryToConsole(i);
		i++;
	}
	n = i + 1;
	cout << "\n\nВыберите страну\n" << endl;
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > n));
	return listOfCountries[number - 1];
}


void Continent::incrementTotalContinents()
{
	totalContinents++;
}

void Continent::printTotalContinents()
{
	cout << "Вы внесли в список " << totalContinents << " из 6 существующих континетов" << endl;
}




