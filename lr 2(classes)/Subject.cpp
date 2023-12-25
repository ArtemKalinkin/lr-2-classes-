#include "Subject.h"

unsigned Subject::totalSubjects = 0;


void Subject::setNumberOfCities(int number)
{
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	numberOfCities = number;
}

void Subject::setListOfCities(City cities[])
{
	for (int i = 0; i < MAXCITIES; i++)
	{
		listOfCities[i] = cities[i];
	}
}

int Subject::getNumberOfCities()
{
	return numberOfCities;
}

City* Subject::getListOfCities()
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

Subject::Subject(string name, int number, long population, int square, City cities[]) : AbstractElement(name, population, square)
{
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->numberOfCities = number;
	for (int i = 0; i < MAXCITIES; i++)
	{
		listOfCities[i] = cities[i];
	}
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
	cout << setw(28) << left << listOfCities[0].getName() << " *" << endl;
	i = 1;
	while ((!listOfCities[i].getName().empty()) && (i < MAXCITIES)) {
		cout << "*       *                    *                    *                  *           * ";
		cout << setw(28) << left << listOfCities[i].getName() << " *" << endl;
	}
	cout << "*****************************************************************************************************************" << endl;
}

ostream& operator<<(ostream& os, const Subject& subject) {
	int i;
	os << setw(18) << left << subject.name << " * ";
	os << setw(18) << left << subject.numberOfCities << " * ";
	os << setw(16) << left << subject.square << " * ";
	os << setw(9) << left << subject.population << " * ";
	os << setw(28) << left << subject.listOfCities[0].getName() << " *" << endl;
	i = 1;
	while ((!subject.listOfCities[i].getName().empty()) && (i < MAXCITIES)) {
		os << "*       *                    *                    *                  *           * ";
		os << setw(28) << left << subject.listOfCities[i].getName() << " *" << endl;
	}
	os << "*****************************************************************************************************************" << endl;
	return os;
}

City& Subject::choosingCity()
{
	int i, n, number;
	char character;
	listOfCities[0].cityTableHeader();
	i = 0;
	while (!listOfCities[i].getName().empty()) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << listOfCities[i];
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


