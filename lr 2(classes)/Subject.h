#pragma once
#include "City.h"
#include "supportFunction.h"

#define MAXCITIES 5

class Subject
{
private:
    char* nameOfSubject;
    int numberOfCities;
    int populationOfSubject;
    int squareOfSubject;
    City listOfCities[MAXCITIES];
public:
    void setNameOfSubject(char *name);
    void setNumberOfCities(int number);
    void setPopulationOfSubject(int population);
    void setSquareOfSubject(int square);
    void setListOfCities(City cities[]);
    char *getNameOfSubject();
    int getNumberOfCities();
    int getPopulationOfSubject();
    int getSquareOfSubject();
    City *getListOfCities();
    Subject();
    Subject(char* name);
    Subject(char* name, int number, int population, int square, City cities[]);
    void inputSubjectFromConsole();
    void subjectTableHeader();
    void outputSubjectToConsole(int number);
    int choosingCity();
};

