#include "�ontinent.h"

unsigned Continent::totalContinents = 0;


void Continent::setNumberOfCountries(int number)
{
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	numberOfCountries = number;
}


void Continent::setListOfCountries(vector<Country> countries)
{
	listOfCountries = countries;
}


int Continent::getNumberOfCountries()
{
	return numberOfCountries;
}

vector<Country>& Continent::getListOfCountries()
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

Continent::Continent(string name, int number, long population, int square, vector<Country> countries) : AbstractElement(name, population, square)
{
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	numberOfCountries = number;
	listOfCountries = countries;
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
	os << setw(30) << left << continent.listOfCountries.at(0).getName() << " *" << endl;
	i = 1;
	while (i < continent.listOfCountries.size()) {
		os << "*       *                    *                  *                    *             * ";
		os << setw(30) << left << continent.listOfCountries.at(i).getName() << " *" << endl;
		i++;
	}
	os << "*********************************************************************************************************************\n";
	return os;
}

Country& Continent::choosingCountry()
{
	int i, n, number;
	char character;
	Country::countryTableHeader();
	i = 0;
	while (i < listOfCountries.size()) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << listOfCountries.at(i);
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

Continent::Continent(const Continent& other) : listOfCountries(other.listOfCountries)
{
	this->name = other.name;
	this->square = other.square;
	this->population = other.population;
	this->numberOfCountries = other.numberOfCountries;
}


bool Continent::compareByField(const Continent& other, ContinentCompareField field) const
{
	switch (field) {
	case ContinentCompareField::NAME:
		return name < other.name;
	case ContinentCompareField::POPULATION:
		return population < other.population;
	case ContinentCompareField::SQUARE:
		return square < other.square;
	case ContinentCompareField::NUMBEROFCOUNTRIES:
		return this->numberOfCountries < other.numberOfCountries;
	default:
		return false;
	}
}

int Continent::selectCriteria(string s)
{
	cout << "�������� �������� " << s <<" �����������: " << endl ;
	int number;
	cout << "1.��������" << endl;
	cout << "2.�������" << endl;
	cout << "3.���������" << endl;
	cout << "4.���������� �����" << endl;
	do {
		cout << "������� �����: ";
		cin >> number;
		if ((number < 1) || (number > 4))
			cout << "�������� � ������ ������� ���" << endl;
	} while ((number < 1) || (number > 4));
	return number;
}

void Continent::sortCountries(int criteria)
{
	vector<Country*> countryPointers;
	for (Country& country : listOfCountries) {
		countryPointers.push_back(&country);
	}
	int number;
	cout << endl << "������� ��������������" << endl;
	cout << "1.�� ��������" << endl;
	cout << "2.�� �����������" << endl;
	do {
		cout << "������� �����: ";
		cin >> number;
		if ((number < 1) || (number > 2))
			cout << "������� 1 ��� 2" << endl;
	} while (number < 1 || (number > 2));
	if (((number == 1) && (criteria == 1)) || ((number == 2) && (criteria != 1))) {
		switch (criteria)
		{
		case 1:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return a->compareByField(*b, Country::CountryCompareField::NAME);
				});
			break;
		case 2:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return a->compareByField(*b, Country::CountryCompareField::SQUARE);
				});
			break;
		case 3:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return a->compareByField(*b, Country::CountryCompareField::POPULATION);
				});
			break;
		case 4:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return a->compareByField(*b, Country::CountryCompareField::NUMBEROFSUBJECTS);
				});
			break;
		case 5:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return a->compareByField(*b, Country::CountryCompareField::NETPROFIT);
				});
			break;
		case 6:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return a->compareByField(*b, Country::CountryCompareField::INCOME);
				});
			break;
		case 7:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return a->compareByField(*b, Country::CountryCompareField::EXPENSES);
				});
			break;
		case 8:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return a->compareByField(*b, Country::CountryCompareField::BUDGET);
				});
			break;
		default:
			break;
		}
	}
	else {
		switch (criteria)
		{
		case 1:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return b->compareByField(*a, Country::CountryCompareField::NAME);
				});
			break;
		case 2:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return b->compareByField(*a, Country::CountryCompareField::SQUARE);
				});
			break;
		case 3:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return b->compareByField(*a, Country::CountryCompareField::POPULATION);
				});
			break;
		case 4:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return b->compareByField(*a, Country::CountryCompareField::NUMBEROFSUBJECTS);
				});
			break;
		case 5:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return b->compareByField(*a, Country::CountryCompareField::NETPROFIT);
				});
			break;
		case 6:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return b->compareByField(*a, Country::CountryCompareField::INCOME);
				});
			break;
		case 7:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return b->compareByField(*a, Country::CountryCompareField::EXPENSES);
				});
			break;
		case 8:
			sort(countryPointers.begin(), countryPointers.end(), [](const Country* a, const Country* b) {
				return b->compareByField(*a, Country::CountryCompareField::BUDGET);
				});
			break;
		default:
			break;
		}
	}
}





