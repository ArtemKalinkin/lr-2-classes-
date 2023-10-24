#include "Ñontinent.h"

void Ñontinent::setNameOfContinent(char* name)
{
	nameOfContinent = new char[strlen(name)];
	strcpy(nameOfContinent, name);
}

void Ñontinent::setNumberOfCountries(int number)
{
	numberOfCountries = number;
}

void Ñontinent::setSquareOfContinent(int square)
{
	squareOfContinent = square;
}

void Ñontinent::setListOfCountries(Country countries[])
{
	for (int i = 0; i < MAXCOUNTRIES; i++)
	{
		listOfCountries[i] = countries[i];
	}
}

char* Ñontinent::getNameOfContinent()
{
	return nameOfContinent;
}

int Ñontinent::getNumberOfCountries()
{
	return numberOfCountries;
}

int Ñontinent::getSquareOfContinent()
{
	return squareOfContinent;
}

Country* Ñontinent::getListOfCountries()
{
	return listOfCountries;
}

Ñontinent::Ñontinent()
{
	nameOfContinent = NULL;
	numberOfCountries = 0;
	squareOfContinent = 0;
}

Ñontinent::Ñontinent(char* name)
{
	nameOfContinent = new char[strlen(name)];
	strcpy(nameOfContinent, name);
	numberOfCountries = 0;
	squareOfContinent = 0;
}

Ñontinent::Ñontinent(char* name, int number, int square, Country countries[])
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


void Ñontinent::inputÑontinentFromConsole()
{
	nameOfContinent = new char[LENNAME];
	puts("ÂÂÎÄ ÊÎÍÒÈÍÅÍÒÀ\n");
	do {
		puts("Ââåäèòå íàçâàíèå êîíòèíåíòà:");
		fgets(nameOfContinent, LENNAME, stdin);
	} while (protectionAgainstIncorrectTextInput(nameOfContinent));
	deletingNewlineTransitionCharacter(nameOfContinent);
	puts("Ââåäèòå êîëè÷åñòâî ñòðàí íà êîíòèíåíòå:");
	while (scanf("%d", &numberOfCountries) != 1) {
		while (getchar() != '\n');
		printf("\nÎøèáêà ââîäà!\nÂâåäèòå êîëè÷åñòâî ñòðàí íà êîíòèíåíòå:\n");
	}
	puts("Ââåäèòå ïëîùàäü êîíòèíåíòà (â êâ. êì):");
	while (scanf("%d", &squareOfContinent) != 1) {
		while (getchar() != '\n');
		printf("\nÎøèáêà ââîäà!\nÂâåäèòå ïëîùàäü êîíòèíåíòà (â êâ. êì):\n");
	}
	while (getchar() != '\n');
}

void Ñontinent::continentTableHeader()
{
	printf("*******************************************************************************************************\n");
	printf("* Íîìåð *     Êîíòèíåíò      * Êîëè÷åñòâî ñòðàí * Ïëîùàäü êîíòèíåíòà *          Ñïèñîê ñòðàí          *\n");
	printf("*******************************************************************************************************\n");
}

void Ñontinent::outputContinentToConsole(int number)
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

int Ñontinent::choosingCountry()
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
	puts("\nÂûáåðèòå ñòðàíó\n");
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > n));
	return number - 1;
}


