#include "Subject.h"

unsigned Subject::totalSubjects = 0;


void Subject::setNumberOfCities(int number)
{
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	numberOfCities = number;
}

void Subject::setListOfCities(vector<City> cities)
{
	listOfCities = cities;
}

int Subject::getNumberOfCities()
{
	return numberOfCities;
}

vector<City> &Subject::getListOfCities()
{
	return listOfCities;
}

Subject::Subject() : AbstractElement()
{
	numberOfCities = 0;
}

Subject::Subject(string name)
{
	if (name.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->name = name;
	numberOfCities = 0;
	population = 0;
	square = 0;
}

Subject::Subject(string name, int number, long population, int square, vector<City> cities) : AbstractElement(name, population, square)
{
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->numberOfCities = number;
	listOfCities = cities;
}



void Subject::input(string s)
{
	cout << "\nВВОД СУБЪЕКТА\n" << endl;
	AbstractElement::input("субъекта");
	cout << "Введите количество городов в субъекте:" << endl;
	while (scanf("%d", &numberOfCities) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите количество городов в субъекте:\n";
	}
	while (getchar() != '\n');
}

void Subject::subjectTableHeader()
{
	cout << "*****************************************************************************************************************" << endl;
	cout << "* Номер *       Субъект      * Количество городов * Площадь субъекта * Население *        Список городов        *" << endl;
	cout << "*****************************************************************************************************************" << endl;
}

void Subject::outputSubjectToConsole(int number)
{
	int i;
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(18) << left << name << " * ";
	cout << setw(18) << left << numberOfCities << " * ";
	cout << setw(16) << left << square << " * ";
	cout << setw(9) << left << population << " * ";
	cout << setw(28) << left << listOfCities.at(0).getName() << " *" << endl;
	i = 1;
	while (i < listOfCities.size()) {
		cout << "*       *                    *                    *                  *           * ";
		cout << setw(28) << left << listOfCities.at(i).getName() << " *" << endl;
	}
	cout << "*****************************************************************************************************************" << endl;
}

ostream& operator<<(ostream& os, const Subject& subject) {
	int i;
	os << setw(18) << left << subject.name << " * ";
	os << setw(18) << left << subject.numberOfCities << " * ";
	os << setw(16) << left << subject.square << " * ";
	os << setw(9) << left << subject.population << " * ";
	os << setw(28) << left << subject.listOfCities.at(0).getName() << " *" << endl;
	i = 1;
	while (i < subject.listOfCities.size()) {
		os << "*       *                    *                    *                  *           * ";
		os << setw(28) << left << subject.listOfCities.at(i).getName() << " *" << endl;
	}
	os << "*****************************************************************************************************************" << endl;
	return os;
}

City& Subject::choosingCity()
{
	int i, n, number;
	char character;
	City::cityTableHeader();
	i = 0;
	while (i < listOfCities.size()) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << listOfCities.at(i);
		i++;
	}
	n = i + 1;
	cout << "\n\nВыберите город\n" << endl;
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > n));
	return listOfCities[number - 1];
}


void Subject::incrementTotalSubjects()
{
	totalSubjects++;
}

void Subject::printTotalSubjects()
{
	cout << "Всего вы внесли в список " << totalSubjects << " субъектов" << endl;
}

string Subject::info() const
{
	return "Субъект: " + name + "; " + to_string(population) + "; " + to_string(square) +
		"; " + to_string(numberOfCities) + ".";
}

Subject::Subject(const Subject& other) : listOfCities(other.listOfCities)
{
	this->name = other.name;
	this->square = other.square;
	this->population = other.population;
	this->numberOfCities = other.numberOfCities;
}

bool Subject::compareByField(const Subject& other, SubjectCompareField field) const
{
	switch (field)
	{
	case SubjectCompareField::NAME:
		return name < other.name;
	case SubjectCompareField::POPULATION:
		return population < other.population;
	case SubjectCompareField::SQUARE:
		return square < other.square;
	case SubjectCompareField::NUMBEROFCITIES:
		return this->numberOfCities < other.numberOfCities;
	default:
		return false;
	}
}

int Subject::selectSortingCriteria()
{
	cout << "Выберете критерий сортировки списка субъектов: " << endl;
	int number;
	cout << "1.Название" << endl;
	cout << "2.Площадь" << endl;
	cout << "3.Население" << endl;
	cout << "4.Количество городов";
	do {
		cout << "Введите номер: " << endl;
		cin >> number;
		if ((number < 1) || (number > 4))
			cout << "Критерия с данным номером нет" << endl;
	} while ((number < 1) || (number > 4));
	return number;
}

void Subject::sortCities(int criteria)
{
	vector<City*> cityPointers;
	for (City& city : listOfCities) {
		cityPointers.push_back(&city);
	}
	int number;
	cout << endl << "Спрособ упорядочивания" << endl;
	cout << "1.По возрастанию" << endl;
	cout << "2.По убыванию" << endl;
	do {
		cout << "Введите номер: ";
		cin >> number;
		if ((number < 1) || (number > 2))
			cout << "Введите 1 или 2" << endl;
	} while (number < 1 || (number > 2));
	if (number == 1) {
		switch (criteria)
		{
		case 1:
			sort(cityPointers.begin(), cityPointers.end(), [](const City* a, const City* b) {
				return a->compareByField(*b, City::CityCompareField::NAME);
				});
			break;
		case 2:
			sort(cityPointers.begin(), cityPointers.end(), [](const City* a, const City* b) {
				return a->compareByField(*b, City::CityCompareField::SQUARE);
				});
			break;
		case 3:
			sort(cityPointers.begin(), cityPointers.end(), [](const City* a, const City* b) {
				return a->compareByField(*b, City::CityCompareField::POPULATION);
				});
			break;
		case 4:
			sort(cityPointers.begin(), cityPointers.end(), [](const City* a, const City* b) {
				return a->compareByField(*b, City::CityCompareField::NUMBEROFCOMPANIES);
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
			sort(cityPointers.begin(), cityPointers.end(), [](const City* a, const City* b) {
				return b->compareByField(*a, City::CityCompareField::NAME);
				});
			break;
		case 2:
			sort(cityPointers.begin(), cityPointers.end(), [](const City* a, const City* b) {
				return b->compareByField(*a, City::CityCompareField::SQUARE);
				});
			break;
		case 3:
			sort(cityPointers.begin(), cityPointers.end(), [](const City* a, const City* b) {
				return b->compareByField(*a, City::CityCompareField::POPULATION);
				});
			break;
		case 4:
			sort(cityPointers.begin(), cityPointers.end(), [](const City* a, const City* b) {
				return b->compareByField(*a, City::CityCompareField::NUMBEROFCOMPANIES);
				});
			break;
		default:
			break;
		}
	}
}


