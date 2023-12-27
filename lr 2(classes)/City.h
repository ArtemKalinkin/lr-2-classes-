#pragma once
#include "Company.h"
#include "Branch.h"
#include "supportFunction.h"
#include "AbstractElement.h"

#define MAXCOMPANIES 15

class City : public AbstractElement
{
private:
    int numberOfCompanies;
    vector<Company*> listOfCompanies;
    static unsigned totalCities;
public:
    enum class CityCompareField {
        NAME,
        POPULATION,
        SQUARE,
        NUMBEROFCOMPANIES
    };
    void setNumberOfCompanies(int number);
    void setListOfCompanies(vector<Company*> companies);
    int getNumberOfCompanies();
    vector<Company*> &getListOfCompanies();
    City();
    City(string name);
    City(string name, long popilation, int square, int number, vector<Company*> companies);
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
    City(const City& other);
    bool compareByField(const City& other, CityCompareField field) const;
    int static selectSortingCriteria();
    void sortCompanies(int criteria);
};

