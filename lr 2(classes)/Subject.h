#pragma once
#include "City.h"
#include "supportFunction.h"
#include "AbstractElement.h"

#define MAXCITIES 5

class Subject : public AbstractElement
{
private:
    int numberOfCities;
    City listOfCities[MAXCITIES];
    static unsigned totalSubjects;
public:
    void setNumberOfCities(int number);
    void setListOfCities(City cities[]);
    int getNumberOfCities();
    City *getListOfCities();
    Subject();
    Subject(string name);
    Subject(string name, int number, long population, int square, City cities[]);
    void input(string s) override;
    void static subjectTableHeader();
    void outputSubjectToConsole(int number);
    friend ostream& operator<<(ostream& os, const Subject& subject);
    City& choosingCity();
    void static incrementTotalSubjects();
    void static printTotalSubjects();
    string info() const override;
};

