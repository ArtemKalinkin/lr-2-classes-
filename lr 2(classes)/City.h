#pragma once
#include "Enterprise.h"
#include "supportFunction.h"

#define MAXENTERPRISES 5

class City
{
private:
    char* nameOfCity;
    int populationOfCity;
    int numberOfEnterprises;
    Enterprise listOfEnterprises[MAXENTERPRISES];
public:
    void setNameOfCity(char* name);
    void setPopulationOfCity(int popilation);
    void setNumberOfEnterprises(int number);
    void setListOfEnterprises(Enterprise enterprises[]);
    char* getNameOfCity();
    int getPopulationOfCity();
    int getNumberOfEnterprises();
    Enterprise* getListOfEnterprises();
    City();
    City(char* name);
    City(char* name, int popilation, int number, Enterprise enterprises[]);
    void inputCityFromConsole();
    void cityTableHeader();
    void outputCityToConsole(int number);
};

