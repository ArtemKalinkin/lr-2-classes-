#include "�ontinent.h"

unsigned Continent::totalContinents = 0;


void Continent::setNumberOfCountries(int number)
{
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	numberOfCountries = number;
}


void Continent::setListOfCountries(Country countries[])
{
	for (int i = 0; i < MAXCOUNTRIES; i++)
	{
		listOfCountries[i] = countries[i];
	}
}


int Continent::getNumberOfCountries()
{
	return numberOfCountries;
}


Country* Continent::getListOfCountries()
{
	return listOfCountries;
}

Continent::Continent() : AbstractElement()
{
	numberOfCountries = 0;
}

Continent::Continent(string name) : AbstractElement(name)
{
	numberOfCountries = 0;
}

Continent::Continent(string name, int number, long population, int square, Country countries[]) : AbstractElement(name, population, square)
{
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	numberOfCountries = number;
	for (int i = 0; i < MAXCOUNTRIES; i++)
	{
		listOfCountries[i] = countries[i];
	}
}


void Continent::input(string s)
{
	puts("���� ����������\n");
	AbstractElement::input("����������");
	cout << "������� ���������� ����� �� ����������:" << endl;
	while (scanf("%d", &numberOfCountries) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ���������� ����� �� ����������:\n";
	}
	while (getchar() != '\n');
	
}

void Continent::continentTableHeader()
{
	cout << "*********************************************************************************************************************\n";
	cout << "* ����� *     ���������      * ���������� ����� * ������� ���������� *  ���������  *          ������ �����          *\n";
	cout << "*********************************************************************************************************************\n";
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
	cout << "*********************************************************************************************************************\n";
}

ostream& operator<<(ostream& os, const Continent& continent) {
	int i;
	os << setw(18) << left << continent.name << " * ";
	os << setw(16) << left << continent.numberOfCountries << " * ";
	os << setw(18) << left << continent.square << " * ";
	os << setw(11) << left << continent.population << " * ";
	os << setw(30) << left << continent.listOfCountries[0].getName() << " *" << endl;
	i = 1;
	while ((!continent.listOfCountries[i].getName().empty()) && (i < MAXCOUNTRIES)) {
		os << "*       *                    *                  *                    *             * ";
		os << setw(30) << left << continent.listOfCountries[i].getName() << " *" << endl;
		i++;
	}
	os << "*********************************************************************************************************************\n";
	return os;
}

Country& Continent::choosingCountry()
{
	int i, n, number;
	char character;
	listOfCountries[0].countryTableHeader();
	i = 0;
	while (!listOfCountries[i].getName().empty()) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << listOfCountries[i];
		i++;
	}
	n = i + 1;
	cout << "\n\n�������� ������\n" << endl;
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
	cout << "�� ������ � ������ " << totalContinents << " �� 6 ������������ ����������" << endl;
}

string Continent::info() const
{
	return "���������: " + name + "; " + to_string(population) + "; " + to_string(square) +
		"; " + to_string(numberOfCountries) + ".";
}




