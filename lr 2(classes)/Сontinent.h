#pragma once
#include "Country.h"
#include "supportFunction.h"

#define MAXCOUNTRIES 5

class —ontinent
{
private:
    char* nameOfContinent;
    int numberOfCountries;
    int squareOfContinent;
    Country listOfCountries[MAXCOUNTRIES];
public:
    void setNameOfContinent(char *name);
    void setNumberOfCountries(int number);
    void setSquareOfContinent(int square);
    void setListOfCountries(Country countries[]);
    char *getNameOfContinent();
    int getNumberOfCountries();
    int getSquareOfContinent();
    Country *getListOfCountries();
    —ontinent();
    —ontinent(char *name);
    —ontinent(char* name, int number, int square, Country countries[]);
    void input—ontinentFromConsole();
    void continentTableHeader();
    void outputContinentToConsole(int number);
    int choosingCountry();


};

