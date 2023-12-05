#pragma once
#include "Country.h"
#include "supportFunction.h"


#define MAXCOUNTRIES 5

class Continent
{
private:
    string name;
    int numberOfCountries;
    int square;
    Country listOfCountries[MAXCOUNTRIES];
    static unsigned totalContinents;
public:
    void setName(string name);
    void setNumberOfCountries(int number);
    void setSquare(int square);
    void setListOfCountries(Country countries[]);
    string getName();
    int getNumberOfCountries();
    int getSquare();
    Country *getListOfCountries();
    Continent();
    Continent(string name);
    Continent(string name, int number, int square, Country countries[]);
    void input—ontinentFromConsole();
    void static continentTableHeader();
    void outputContinentToConsole(int number);
    Country& choosingCountry();
    void static incrementTotalContinents();
    void static printTotalContinents();
};

