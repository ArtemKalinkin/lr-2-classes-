#include "Subject.h"

unsigned Subject::totalSubjects = 0;

void Subject::setName(string name)
{
	this->name = name;
}

void Subject::setNumberOfCities(int number)
{
	numberOfCities = number;
}

void Subject::setPopulation(int population)
{
	this->population = population;
}

void Subject::setSquare(int square)
{
	this->square = square;
}

void Subject::setListOfCities(City cities[])
{
	for (int i = 0; i < MAXCITIES; i++)
	{
		listOfCities[i] = cities[i];
	}
}

string Subject::getName()
{
	return name;
}

int Subject::getNumberOfCities()
{
	return numberOfCities;
}

int Subject::getPopulation()
{
	return population;
}

int Subject::getSquare()
{
	return square;
}

City* Subject::getListOfCities()
{
	return listOfCities;
}

Subject::Subject()
{
	numberOfCities = 0;
	population = 0;
	square = 0;
}

Subject::Subject(string name)
{
	this->name = name;
	numberOfCities = 0;
	population = 0;
	square = 0;
}

Subject::Subject(string name, int number, int population, int square, City cities[])
{
	this->name = name;
	this->numberOfCities = number;
	this->population = population;
	this->square = square;
	for (int i = 0; i < MAXCITIES; i++)
	{
		listOfCities[i] = cities[i];
	}
}



void Subject::inputSubjectFromConsole()
{
	cout <<"\nВВОД СУБЪЕКТА\n" << endl;
	do {
		puts("Введите название субъекта:");
		getline(cin, name);
	} while (protectionAgainstIncorrectTextInput(name));
	cout << "Введите население субъекта:" << endl;
	while (scanf("%d", &population) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите население субъекта:\n";
	}
	cout << "Введите количество городов в субъекте:" << endl;
	while (scanf("%d", &numberOfCities) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите количество городов в субъекте:\n";
	}
	cout << "Введите площадь субъекта:" << endl;
	while (scanf("%d", &square) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите площадь субъекта:\n";
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

City& Subject::choosingCity()
{
	int i, n, number;
	char character;
	listOfCities[0].cityTableHeader();
	i = 0;
	while (!listOfCities[i].getName().empty()) {
		listOfCities[i].outputCityToConsole( i);
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
	cout << "Всего вы внесли в список " << totalSubjects  << " субъектов" << endl;
}


