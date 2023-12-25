#pragma once
#include "supportFunction.h"


class AbstractElement
{
protected:
	string name;
	long population;
	int square;
public:
    void setName(string name);
    void setPopulation(long population);
    void setSquare(int square);
    string getName() const;
    int getPopulation();
    int getSquare();
    AbstractElement();
    AbstractElement(string name);
    AbstractElement(string name, long population, int square);
    virtual void input(string s);
    virtual string info() const;
};

