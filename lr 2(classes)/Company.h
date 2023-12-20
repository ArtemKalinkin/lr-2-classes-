#pragma once
#include "supportFunction.h"

class Company
{
    friend void compareCompanies(Company* listPtrOfCompanies[], int number);
protected:
    string name;
    string citySubjectCountry;
    unsigned long turnoverPerYear;
    long netProfit;
    string dateOfFoundation;
    string industry;
    string activity;
private:
    static unsigned totalCompanies;
public:
    void setName(string name);
    void setcitySubjectCountry(string address);
    void setTurnoverPerYear(unsigned long turnover);
    void setNetProfit(long profit);
    void setDateOfFoundation(string date);
    void setIndustry(string industry);
    string getName() const;
    string getcitySubjectCountry();
    unsigned long getTurnoverPerYear();
    long getNetProfit();
    string getDateOfFoundation();
    string getIndustry();
    Company();
    Company(string name);
    Company(string name, string address, unsigned long turnover, long profit, string date, string industry, string activity);
    virtual void inputCompanyFromConsole(int mode);
    void static companyTableHeader();
    friend ostream& operator<<(ostream& os, const Company& company);
    virtual void outputCompanyToConsole(int number);
    void static incrementTotalCompanies();
    void static printTotalCompanies();
    Company operator +(const Company& company);
    Company& operator=(const Company& other);
    virtual void performActivity() const;
    void callPerformActivity() const;
};

