#pragma once
#include "Country.h"
#include "supportFunction.h"

#define MAXCOUNTRIES 99

class Ñontinent
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
    Ñontinent();
    Ñontinent(char *name);
    Ñontinent(char* name, int number, int square, Country countries[]);
    ~Ñontinent();
};

