#pragma once
#include "Country.h"
#include "supportFunction.h"
#include "AbstractElement.h"


#define MAXCOUNTRIES 5

class Continent : public AbstractElement
{
private:
    int numberOfCountries;
    Country listOfCountries[MAXCOUNTRIES];
    static unsigned totalContinents;
public:
    void setNumberOfCountries(int number);
    void setListOfCountries(Country countries[]);
    int getNumberOfCountries();
    Country *getListOfCountries();
    Continent();
    Continent(string name);
    Continent(string name, int number, long population, int square, Country countries[]);
    void input(string s) override;
    void static continentTableHeader();
    void outputContinentToConsole(int number);
    friend ostream& operator<<(ostream& os, const Continent& continent);
    Country& choosingCountry();
    void static incrementTotalContinents();
    void static printTotalContinents();
    string info() const override;
};

