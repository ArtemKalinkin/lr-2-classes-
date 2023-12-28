#include "Сontinent.h"

unsigned Continent::totalContinents = 0;


void Continent::setNumberOfCountries(int number)
{
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
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
		throw invalid_argument("Значение не может быть отрицательным!");
	numberOfCountries = number;
	listOfCountries = countries;
}


void Continent::input(string s)
{
	puts("ВВОД КОНТИНЕНТА\n");
	AbstractElement::input("континента");
	cout << "Введите количество стран на континенте:" << endl;
	while (scanf("%d", &numberOfCountries) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите количество стран на континенте:\n";
	}
	while (getchar() != '\n');
	
}

void Continent::continentTableHeader()
{
	cout << "*********************************************************************************************************************\n";
	cout << "* Номер *     Континент      * Количество стран * Площадь континента *  Население  *          Список стран          *\n";
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

string Continent::info() const
{
	return "Континент: " + name + "; " + to_string(population) + "; " + to_string(square) +
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
	cout << "Выберете критерий " << s <<" континентов: " << endl ;
	int number;
	cout << "1.Название" << endl;
	cout << "2.Площадь" << endl;
	cout << "3.Население" << endl;
	cout << "4.Количество стран" << endl;
	do {
		cout << "Введите номер: ";
		cin >> number;
		if ((number < 1) || (number > 4))
			cout << "Критерия с данным номером нет" << endl;
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
	cout << endl << "Спрособ упорядочивания" << endl;
	cout << "1.По убыванию" << endl;
	cout << "2.По возрастанию" << endl;
	do {
		cout << "Введите номер: ";
		cin >> number;
		if ((number < 1) || (number > 2))
			cout << "Введите 1 или 2" << endl;
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





