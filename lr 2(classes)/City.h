#pragma once
#include "Company.h"
#include "Branch.h"
#include "supportFunction.h"

#define MAXCOMPANIES 5

class City
{
private:
    string name;
    int population;
    int numberOfCompanies;
    Company listOfCompanies[MAXCOMPANIES];
    static unsigned totalCities;
public:
    void setName(string name);
    void setPopulation(int popilation);
    void setNumberOfCompanies(int number);
    void setListOfCompanies(Company companies[]);
    string getName() const;
    int getPopulation();
    int getNumberOfCompanies();
    Company* getListOfCompanies();
    City();
    City(string name);
    City(string name, int popilation, int number, Company companies[]);
    void inputCityFromConsole();
    void static cityTableHeader();
    void outputCityToConsole(int number);
    friend ostream& operator<<(ostream& os, const City& city);
    void static incrementTotalCities();
    void static printTotalCities();
    void removeCompany(Company company);
    City operator ++(int);
    City& operator ++();
};

