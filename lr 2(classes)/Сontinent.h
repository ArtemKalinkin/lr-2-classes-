#pragma once
#include "Country.h"
#include "supportFunction.h"
#include "AbstractElement.h"


#define MAXCOUNTRIES 5

class Continent : public AbstractElement
{
private:
    int numberOfCountries;
    vector<Country> listOfCountries;
    static unsigned totalContinents;
public:
    enum ContinentCompareField {
        NAME,
        POPULATION,
        SQUARE,
        NUMBEROFCOUNTRIES
    };
    void setNumberOfCountries(int number);
    void setListOfCountries(vector<Country> countries);
    int getNumberOfCountries();
    vector<Country> &getListOfCountries();
    Continent();
    Continent(string name);
    Continent(string name, int number, long population, int square, vector<Country> countries);
    void input(string s) override;
    void static continentTableHeader();
    void outputContinentToConsole(int number);
    friend ostream& operator<<(ostream& os, const Continent& continent);
    Country& choosingCountry();
    void static incrementTotalContinents();
    void static printTotalContinents();
    string info() const override;
    Continent(const Continent& other);
    bool compareByField(const Continent& other, ContinentCompareField field) const;
    int static selectCriteria(string s);
    void sortCountries(int criteria);
};

