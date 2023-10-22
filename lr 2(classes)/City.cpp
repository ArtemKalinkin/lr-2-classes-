#include "City.h"

void City::setNameOfCity(char* name)
{
	nameOfCity = new char[strlen(name)];
	strcpy(nameOfCity, name);
}

void City::setPopulationOfCity(int popilation)
{
	populationOfCity = popilation;
}

void City::setNumberOfEnterprises(int number)
{
	numberOfEnterprises = number;
}

void City::setListOfEnterprises(Enterprise enterprises[])
{
	for (int i = 0; i < MAXENTERPRISES; i++)
		listOfEnterprises[i] = enterprises[i];
}

char* City::getNameOfCity()
{
	return nameOfCity;
}

int City::getPopulationOfCity()
{
	return populationOfCity;
}

int City::getNumberOfEnterprises()
{
	return numberOfEnterprises;
}

Enterprise* City::getListOfEnterprises()
{
	return listOfEnterprises;
}

City::City()
{
	nameOfCity = NULL;
	populationOfCity = 0;
	numberOfEnterprises = 0;
}

City::City(char* name)
{
	nameOfCity = new char[strlen(name)];
	strcpy(nameOfCity, name);
	populationOfCity = 0;
	numberOfEnterprises = 0;
}

City::City(char* name, int popilation, int number, Enterprise enterprises[])
{
	nameOfCity = new char[strlen(name)];
	strcpy(nameOfCity, name);
	populationOfCity = popilation;
	numberOfEnterprises = number;
	for (int i = 0; i < MAXENTERPRISES; i++)
		listOfEnterprises[i] = enterprises[i];
}

City::~City()
{
	if (nameOfCity != NULL)
		delete[] nameOfCity;
}

void City::inputCityFromConsole()
{
	nameOfCity = new char[LENNAME];
	puts("\nВВОД ГОРОДА\n");
	do {
		puts("Введите название города:");
		fgets(nameOfCity, LENNAME, stdin);
	} while (protectionAgainstIncorrectTextInput(nameOfCity));
	deletingNewlineTransitionCharacter(nameOfCity);
	puts("Введите население города:");
	while (scanf("%d", &populationOfCity) != 1) {
		while (getchar() != '\n');
		printf("\nОшибка ввода!\nВведите население города:\n");
	}
	puts("Введите количество предприятий в городе:");
	while (scanf("%d", &numberOfEnterprises) != 1) {
		while (getchar() != '\n');
		printf("\nОшибка ввода!\nВведите количество предприятий в городе:\n");
	}
	while (getchar() != '\n');
}

void City::cityTableHeader()
{
	printf("**********************************************************************************************************\n");
	printf("* Номер *       Город        * Количество предприятий * Население *          Список предприятий          *\n");
	printf("**********************************************************************************************************\n");
}

void City::outputCityToConsole(int number)
{
	int i;
	printf("* %-5d * %-18s * %-22d * %-9d * ", number + 1, nameOfCity, numberOfEnterprises, populationOfCity);
	printf("%-36s *\n", listOfEnterprises[0].getNameOfEnterprises());
	i = 1;
	while ((listOfEnterprises[i].getNameOfEnterprises() != NULL) && (i < MAXENTERPRISES)) {
		printf("*       *                    *                        *           * %-36s *\n", listOfEnterprises[i].getNameOfEnterprises());
		i++;
	}
	printf("**********************************************************************************************************\n");
}




