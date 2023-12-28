#pragma once
#include "City.h"
#include "supportFunction.h"
#include "AbstractElement.h"

#define MAXCITIES 5

class Subject : public AbstractElement
{
private:
    int numberOfCities;
    vector<City> listOfCities;
    static unsigned totalSubjects;
public:
    enum class SubjectCompareField {
        NAME,
        POPULATION,
        SQUARE,
        NUMBEROFCITIES
    };
    void setNumberOfCities(int number);
    void setListOfCities(vector<City> cities);
    int getNumberOfCities();
    vector<City> &getListOfCities();
    Subject();
    Subject(string name);
    Subject(string name, int number, long population, int square, vector<City> cities);
    void input(string s) override;
    void static subjectTableHeader();
    void outputSubjectToConsole(int number);
    friend ostream& operator<<(ostream& os, const Subject& subject);
    City& choosingCity();
    void static incrementTotalSubjects();
    void static printTotalSubjects();
    string info() const override;
    Subject(const Subject& other);
    bool compareByField(const Subject& other, SubjectCompareField field) const;
    int static selectCriteria(string s);
    void sortCities(int criteria);
};

