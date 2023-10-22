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

�ontinent::~�ontinent()
{
	if (nameOfContinent != NULL)
		delete[] nameOfContinent;
}


