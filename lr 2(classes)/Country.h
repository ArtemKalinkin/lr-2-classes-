#pragma once
#include "Subject.h"
#include "supportFunction.h"

#define MAXSUBJECTS 85

class Country
{
private:
    char* nameOfCountry;
    int numberOfSubjects;
    unsigned long netProfitCountryEnterprises;
    int populationOfCountry;
    int squareOfCountry;
    unsigned long incomeOfCountry;
    unsigned long expensesOfCountry;
    long budgetDeficitOrSurplusOfCountry;
    Subject listOfSubjects[MAXSUBJECTS];
    int calculatingProfitsFromEnterprises();
public:
    void setNameOfCountry(char *name);
    void setNumberOfSubjects(int number);
    void setNetProfitCountryEnterprises(unsigned long profit);
    void setPopulationOfCountry(int population);
    void setSquareOfCountry(int square);
    void setIncomeOfCountry(unsigned long income);
    void setExpensesOfCountry(unsigned long expenses);
    void setListOfSubjects(Subject subjects[]);
    char *getNameOfCountry();
    int getNumberOfSubjects();
    unsigned long getNetProfitCountryEnterprises();
    int getPopulationOfCountry();
    int getSquareOfCountry();
    unsigned long getIncomeOfCountry();
    unsigned long getExpensesOfCountry();
    long getBudgetDeficitOrSurplusOfCountry();
    Subject *getListOfSubjects();
    Country();
    Country(char* name);
    Country(char* name, int number, int population, int square, unsigned long income, unsigned long expenses, Subject subjects[]);
    ~Country();
};

