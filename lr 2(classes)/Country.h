#pragma once
#include "Subject.h"
#include "supportFunction.h"

#define MAXSUBJECTS 5

class Country
{
private:
    string name;
    int numberOfSubjects;
    unsigned long netProfitFromCompanies;
    int population;
    int square;
    unsigned long income;
    unsigned long expenses;
    long budgetDeficitOrSurplus;
    Subject listOfSubjects[MAXSUBJECTS];
    static unsigned totalCountries;
public:
    void setName(string name);
    void setNumberOfSubjects(int number);
    void setNetProfitCountryFromCompanies(unsigned long profit);
    void setPopulation(int population);
    void setSquare(int square);
    void setIncome(unsigned long income);
    void setExpenses(unsigned long expenses);
    void setListOfSubjects(Subject subjects[]);
    string getName();
    int getNumberOfSubjects();
    unsigned long getNetProfitCountryFromCompanies();
    int getPopulation();
    int getSquare();
    unsigned long getIncome();
    unsigned long getExpenses();
    long getBudgetDeficitOrSurplus();
    Subject *getListOfSubjects();
    Country();
    Country(string name);
    Country(string name, int number, int population, int square, unsigned long income, unsigned long expenses, Subject subjects[]);
    void inputCountryFromConsole();
    void static countryTableHeader();
    void outputCountryToConsole(int number);
    int calculatingProfitsFromCompanies();
    Subject& choosingSubject();
    int comparisonOfTwoCountries(Country* secondCountry);
    void static incrementTotalCountries();
    void static printTotalCountries();
};

