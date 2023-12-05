#pragma once
#include "supportFunction.h"

class Enterprise;

class Company
{
    friend void compareCompanies(Company* listPtrOfCompanies[], int number);
private:
    string name;
    string citySubjectCountry;
    unsigned long turnoverPerYear;
    long netProfit;
    string dateOfFoundation;
    string industry;
    static unsigned totalCompanies;
public:
    void setName(string name);
    void setcitySubjectCountry(string address);
    void setTurnoverPerYear(unsigned long turnover);
    void setNetProfit(long profit);
    void setDateOfFoundation(string date);
    void setIndustry(string industry);
    string getName();
    string getcitySubjectCountry();
    unsigned long getTurnoverPerYear();
    long getNetProfit();
    string getDateOfFoundation();
    string getIndustry();
    Company();
    Company(string name);
    Company(string name, string address, unsigned long turnover, long profit, string date, string industry);
    void inputCompanyFromConsole();
    void static companyTableHeader();
    void outputCompanyToConsole(int number);
    void static incrementTotalCompanies();
    void static printTotalCompanies();
    Company operator +(const Company& company);
};

