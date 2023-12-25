#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Ñontinent.h"
#include "Country.h"
#include "Subject.h"
#include "City.h"
#include "Company.h"
#include "Branch.h"
#include "AbstractElement.h"

template <typename T>
class Container
{
private:
    vector<T*> elements;

public:
    void addElement(T* element);
    void displayElements() const;
};

