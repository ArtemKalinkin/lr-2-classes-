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

Ñontinent::~Ñontinent()
{
	if (nameOfContinent != NULL)
		delete[] nameOfContinent;
}


