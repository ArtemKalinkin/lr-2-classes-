#pragma once
#include "supportFunction.h"


class Enterprise
{
private:
    char* nameOfEnterprise;
    char* citySubjectCountry;
    unsigned long turnoverPerYear;
    long netProfitOfEnterprise;
    char* dateOfFoundationEnterprise;
    char* industryOfEnterprise;
public:
    void setNameOfEnterprise(char* name);
    void setcitySubjectCountry(char* address);
    void setTurnoverPerYear(unsigned long turnover);
    void setNetProfitOfEnterprise(long profit);
    void setDateOfFoundationEnterprise(char* date);
    void setIndustryOfEnterprise(char* industry);
    char * getNameOfEnterprise();
    char * getcitySubjectCountry();
    unsigned long getTurnoverPerYear();
    long getNetProfitOfEnterprise();
    char * getDateOfFoundationEnterprise();
    char * getIndustryOfEnterprise();
    Enterprise();
    Enterprise(char* name);
    Enterprise(char* name, char* address, unsigned long turnover, long profit, char* date, char* industry);
    void inputEnterpriseFromConsole();
    void enterpriseTableHeader();
    void outputEnterpriseToConsole(int number);
};

