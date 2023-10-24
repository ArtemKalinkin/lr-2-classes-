#include "Subject.h"

void Subject::setNameOfSubject(char* name)
{
	nameOfSubject = new char[strlen(name)];
	strcpy(nameOfSubject, name);
}

void Subject::setNumberOfCities(int number)
{
	numberOfCities = number;
}

void Subject::setPopulationOfSubject(int population)
{
	populationOfSubject = population;
}

void Subject::setSquareOfSubject(int square)
{
	squareOfSubject = square;
}

void Subject::setListOfCities(City cities[])
{
	for (int i = 0; i < MAXCITIES; i++)
	{
		listOfCities[i] = cities[i];
	}
}

char* Subject::getNameOfSubject()
{
	return nameOfSubject;
}

int Subject::getNumberOfCities()
{
	return numberOfCities;
}

int Subject::getPopulationOfSubject()
{
	return populationOfSubject;
}

int Subject::getSquareOfSubject()
{
	return squareOfSubject;
}

City* Subject::getListOfCities()
{
	return listOfCities;
}

Subject::Subject()
{
	nameOfSubject = NULL;
	numberOfCities = 0;
	populationOfSubject = 0;
	squareOfSubject = 0;
}

Subject::Subject(char* name)
{
	nameOfSubject = new char[strlen(name)];
	strcpy(nameOfSubject, name);
	numberOfCities = 0;
	populationOfSubject = 0;
	squareOfSubject = 0;
}

Subject::Subject(char* name, int number, int population, int square, City cities[])
{
	nameOfSubject = new char[strlen(name)];
	strcpy(nameOfSubject, name);
	numberOfCities = number;
	populationOfSubject = population;
	squareOfSubject = square;
	for (int i = 0; i < MAXCITIES; i++)
	{
		listOfCities[i] = cities[i];
	}
}



void Subject::inputSubjectFromConsole()
{
	nameOfSubject = new char[LENNAME];
	puts("\nВВОД СУБЪЕКТА\n");
	do {
		puts("Введите название субъекта:");
		fgets(nameOfSubject, LENNAME, stdin);
	} while (protectionAgainstIncorrectTextInput(nameOfSubject));
	deletingNewlineTransitionCharacter(nameOfSubject);
	puts("Введите население субъекта:");
	while (scanf("%d", &populationOfSubject) != 1) {
		while (getchar() != '\n');
		printf("\nОшибка ввода!\nВведите население субъекта:\n");
	}
	puts("Введите количество городов в субъекте:");
	while (scanf("%d", &numberOfCities) != 1) {
		while (getchar() != '\n');
		printf("\nОшибка ввода!\nВведите количество городов в субъекте:\n");
	}
	puts("Введите площадь субъекта:");
	while (scanf("%d", &squareOfSubject) != 1) {
		while (getchar() != '\n');
		printf("\nОшибка ввода!\nВведите площадь субъекта:\n");
	}
	while (getchar() != '\n');
}

void Subject::subjectTableHeader()
{
	printf("*****************************************************************************************************************\n");
	printf("* Номер *       Субъект      * Количество городов * Площадь субъекта * Население *        Список городов        *\n");
	printf("*****************************************************************************************************************\n");
}

void Subject::outputSubjectToConsole(int number)
{
	int i;
	printf("* %-5d * %-18s * %-18d * ", number + 1, nameOfSubject, numberOfCities);
	printf("%-16d * %-9d * ", squareOfSubject, populationOfSubject);
	printf("%-28s *\n", listOfCities[0].getNameOfCity());
	i = 1;
	while ((listOfCities[i].getNameOfCity() != NULL) && (i < MAXCITIES)) {
		printf("*       *                    *                    *                  *           * %-28s *\n", listOfCities[i].getNameOfCity());
	}
	printf("*****************************************************************************************************************\n");
}

int Subject::choosingCity()
{
	int i, n, number;
	char character;
	listOfCities[0].cityTableHeader();
	i = 0;
	while (listOfCities[i].getNameOfCity() != NULL) {
		listOfCities[i].outputCityToConsole( i);
		i++;
	}
	n = i + 1;
	puts("\nВыберите город\n");
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > n));
	return number - 1;
}


