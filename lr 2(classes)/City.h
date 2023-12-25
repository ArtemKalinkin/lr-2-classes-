#pragma once
#include "Company.h"
#include "Branch.h"
#include "supportFunction.h"
#include "AbstractElement.h"

#define MAXCOMPANIES 5

class City : public AbstractElement
{
private:
    int numberOfCompanies;
    Company *listOfCompanies[MAXCOMPANIES];
    static unsigned totalCities;
public:
    void setNumberOfCompanies(int number);
    void setListOfCompanies(Company *companies[]);
    int getNumberOfCompanies();
    Company** getListOfCompanies();
    City();
    City(string name);
    City(string name, long popilation, int square, int number, Company *companies[]);
    void input(string s) override;
    void static cityTableHeader();
    void outputCityToConsole(int number);
    friend ostream& operator<<(ostream& os, const City& city);
    void static incrementTotalCities();
    void static printTotalCities();
    void removeCompany(Company company);
    City operator ++(int);
    City& operator ++();
    string info() const override;
};

