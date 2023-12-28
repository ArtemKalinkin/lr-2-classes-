#pragma once
#include "Subject.h"
#include "supportFunction.h"
#include "AbstractElement.h"

#define MAXSUBJECTS 5

class Country : public AbstractElement
{
private:
    int numberOfSubjects;
    unsigned long netProfitFromCompanies;
    unsigned long income;
    unsigned long expenses;
    long budgetDeficitOrSurplus;
    vector<Subject> listOfSubjects;
    static unsigned totalCountries;
public:
    enum class CountryCompareField{
        NAME,
        POPULATION,
        SQUARE,
        NUMBEROFSUBJECTS,
        NETPROFIT,
        INCOME,
        EXPENSES,
        BUDGET
    };
    void setNumberOfSubjects(int number);
    void setNetProfitCountryFromCompanies(unsigned long profit);
    void setIncome(unsigned long income);
    void setExpenses(unsigned long expenses);
    void setListOfSubjects(vector<Subject> subjects);
    int getNumberOfSubjects();
    unsigned long getNetProfitCountryFromCompanies();
    unsigned long getIncome();
    unsigned long getExpenses();
    long getBudgetDeficitOrSurplus();
    vector<Subject> &getListOfSubjects();
    Country();
    Country(string name);
    Country(string name, int number, long population, int square, unsigned long income, unsigned long expenses, vector<Subject> subjects);
    void input(string s) override;
    void static countryTableHeader();
    void outputCountryToConsole(int number);
    friend ostream& operator<<(ostream& os, const Country& country);
    int calculatingProfitsFromCompanies(int number);
    Subject& choosingSubject();
    int comparisonOfTwoCountries(Country* secondCountry);
    void static incrementTotalCountries();
    void static printTotalCountries();
    string info() const override;
    Country(const Country& other);
    bool compareByField(const Country& other, CountryCompareField field) const;
    int static selectCriteria(string s);
    void sortSubjects(int criteria);
};

