#include "�ontinent.h"

unsigned Continent::totalContinents = 0;

void Continent::setName(string name)
{
	if (name.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;
}

void Continent::setNumberOfCountries(int number)
{
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	numberOfCountries = number;
}

void Continent::setSquare(int square)
{
	if (square < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->square = square;
}

void Continent::setListOfCountries(Country countries[])
{
	for (int i = 0; i < MAXCOUNTRIES; i++)
	{
		listOfCountries[i] = countries[i];
	}
}

string Continent::getName() const
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
	if (name.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;
	numberOfCountries = 0;
	square = 0;
}

Continent::Continent(string name, int number, int square, Country countries[])
{
	if (name.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	numberOfCountries = number;
	if (square < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->square = square;
	for (int i = 0; i < MAXCOUNTRIES; i++)
	{
		listOfCountries[i] = countries[i];
	}
}


void Continent::input�ontinentFromConsole()
{
	puts("���� ����������\n");
	do {
		try {
			cout << "������� �������� ����������:" << endl;
			getline(cin, name);
			protectionAgainstIncorrectTextInput(name);
			break;
		}
		catch (const invalid_argument e) {
			cerr << "��������� ������: " << e.what() << endl;
		}
		catch (const length_error e) {
			cerr << "��������� ������: " << e.what() << endl;
		}
	} while (true);
	cout << "������� ���������� ����� �� ����������:" << endl;
	while (scanf("%d", &numberOfCountries) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ���������� ����� �� ����������:\n";
	}
	cout << "������� ������� ���������� (� ��. ��):" << endl;
	while (scanf("%d", &square) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ������� ���������� (� ��. ��):\n";
	}
	while (getchar() != '\n');
}

void Continent::continentTableHeader()
{
	cout << "*******************************************************************************************************\n";
	cout << "* ����� *     ���������      * ���������� ����� * ������� ���������� *          ������ �����          *\n";
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
	cout << "*******************************************************************************************************\n";
}

ostream& operator<<(ostream& os, const Continent& continent) {
	int i;
	os << setw(18) << left << continent.name << " * ";
	os << setw(16) << left << continent.numberOfCountries << " * ";
	os << setw(18) << left << continent.square << " * ";
	os << setw(30) << left << continent.listOfCountries[0].getName() << " *" << endl;
	i = 1;
	while ((!continent.listOfCountries[i].getName().empty()) && (i < MAXCOUNTRIES)) {
		os << "*       *                    *                  *                    * ";
		os << setw(30) << left << continent.listOfCountries[i].getName() << " *" << endl;
		i++;
	}
	os << "*******************************************************************************************************\n";
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




