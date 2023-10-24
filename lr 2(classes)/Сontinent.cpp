#include "�ontinent.h"

void �ontinent::setNameOfContinent(char* name)
{
	nameOfContinent = new char[strlen(name)];
	strcpy(nameOfContinent, name);
}

void �ontinent::setNumberOfCountries(int number)
{
	numberOfCountries = number;
}

void �ontinent::setSquareOfContinent(int square)
{
	squareOfContinent = square;
}

void �ontinent::setListOfCountries(Country countries[])
{
	for (int i = 0; i < MAXCOUNTRIES; i++)
	{
		listOfCountries[i] = countries[i];
	}
}

char* �ontinent::getNameOfContinent()
{
	return nameOfContinent;
}

int �ontinent::getNumberOfCountries()
{
	return numberOfCountries;
}

int �ontinent::getSquareOfContinent()
{
	return squareOfContinent;
}

Country* �ontinent::getListOfCountries()
{
	return listOfCountries;
}

�ontinent::�ontinent()
{
	nameOfContinent = NULL;
	numberOfCountries = 0;
	squareOfContinent = 0;
}

�ontinent::�ontinent(char* name)
{
	nameOfContinent = new char[strlen(name)];
	strcpy(nameOfContinent, name);
	numberOfCountries = 0;
	squareOfContinent = 0;
}

�ontinent::�ontinent(char* name, int number, int square, Country countries[])
{
	nameOfContinent = new char[strlen(name)];
	strcpy(nameOfContinent, name);
	numberOfCountries = number;
	squareOfContinent = square;
	for (int i = 0; i < MAXCOUNTRIES; i++)
	{
		listOfCountries[i] = countries[i];
	}
}


void �ontinent::input�ontinentFromConsole()
{
	nameOfContinent = new char[LENNAME];
	puts("���� ����������\n");
	do {
		puts("������� �������� ����������:");
		fgets(nameOfContinent, LENNAME, stdin);
	} while (protectionAgainstIncorrectTextInput(nameOfContinent));
	deletingNewlineTransitionCharacter(nameOfContinent);
	puts("������� ���������� ����� �� ����������:");
	while (scanf("%d", &numberOfCountries) != 1) {
		while (getchar() != '\n');
		printf("\n������ �����!\n������� ���������� ����� �� ����������:\n");
	}
	puts("������� ������� ���������� (� ��. ��):");
	while (scanf("%d", &squareOfContinent) != 1) {
		while (getchar() != '\n');
		printf("\n������ �����!\n������� ������� ���������� (� ��. ��):\n");
	}
	while (getchar() != '\n');
}

void �ontinent::continentTableHeader()
{
	printf("*******************************************************************************************************\n");
	printf("* ����� *     ���������      * ���������� ����� * ������� ���������� *          ������ �����          *\n");
	printf("*******************************************************************************************************\n");
}

void �ontinent::outputContinentToConsole(int number)
{
	int i;
	printf("* %-5d * %-18s * %-16d * %-18d * ", number + 1, nameOfContinent, numberOfCountries, squareOfContinent);
	printf("%-30s *\n", listOfCountries[0].getNameOfCountry());
	i = 1;
	while ((listOfCountries[i].getNameOfCountry() != NULL) && (i < MAXCOUNTRIES)) {
		printf("*       *                    *                  *                    * %-30s *\n", listOfCountries[i].getNameOfCountry());
		i++;
	}
	printf("*******************************************************************************************************\n");
}

int �ontinent::choosingCountry()
{
	int i, n, number;
	char character;
	listOfCountries[0].countryTableHeader();
	i = 0;
	while (listOfCountries[i].getNameOfCountry() != NULL) {
		listOfCountries[i].outputCountryToConsole(i);
		i++;
	}
	n = i + 1;
	puts("\n�������� ������\n");
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > n));
	return number - 1;
}


