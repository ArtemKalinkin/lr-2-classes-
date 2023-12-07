#pragma once
#include "City.h"
#include "supportFunction.h"

#define MAXCITIES 5

class Subject
{
private:
    string name;
    int numberOfCities;
    int population;
    int square;
    City listOfCities[MAXCITIES];
    static unsigned totalSubjects;
public:
    void setName(string name);
    void setNumberOfCities(int number);
    void setPopulation(int population);
    void setSquare(int square);
    void setListOfCities(City cities[]);
    string getName();
    int getNumberOfCities();
    int getPopulation();
    int getSquare();
    City *getListOfCities();
    Subject();
    Subject(string name);
    Subject(string name, int number, int population, int square, City cities[]);
    void inputSubjectFromConsole();
    void static subjectTableHeader();
    void outputSubjectToConsole(int number);
    City& choosingCity();
    void static incrementTotalSubjects();
    void static printTotalSubjects();
};

