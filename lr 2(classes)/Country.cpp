#include "Country.h"


void Country::setNameOfCountry(char* name)
{
	nameOfCountry = new char(strlen(name));
	strcpy(nameOfCountry, name);
}

void Country::setNumberOfSubjects(int number)
{
	numberOfSubjects = number;
}

void Country::setNetProfitCountryEnterprises(unsigned long profit)
{
	netProfitCountryEnterprises = profit;
}

void Country::setPopulationOfCountry(int population)
{
	populationOfCountry = population;
}

void Country::setSquareOfCountry(int square)
{
	squareOfCountry = square;
}

void Country::setIncomeOfCountry(unsigned long income)
{
	incomeOfCountry = income;
	budgetDeficitOrSurplusOfCountry = incomeOfCountry - expensesOfCountry;
}

void Country::setExpensesOfCountry(unsigned long expenses)
{
	expensesOfCountry = expenses;
	budgetDeficitOrSurplusOfCountry = incomeOfCountry - expensesOfCountry;
}

void Country::setListOfSubjects(Subject subjects[])
{
	for (int i = 0; i < MAXSUBJECTS; i++)
	{
		listOfSubjects[i] = subjects[i];
	}
}

char* Country::getNameOfCountry()
{
	return nameOfCountry;
}

int Country::getNumberOfSubjects()
{
	return numberOfSubjects;
}

unsigned long Country::getNetProfitCountryEnterprises()
{
	return netProfitCountryEnterprises;
}

int Country::getPopulationOfCountry()
{
	return populationOfCountry;
}

int Country::getSquareOfCountry()
{
	return squareOfCountry;
}

unsigned long Country::getIncomeOfCountry()
{
	return incomeOfCountry;
}

unsigned long Country::getExpensesOfCountry()
{
	return expensesOfCountry;
}

long Country::getBudgetDeficitOrSurplusOfCountry()
{
	return budgetDeficitOrSurplusOfCountry;
}

Subject* Country::getListOfSubjects()
{
	return listOfSubjects;
}

Country::Country()
{
	nameOfCountry = NULL;
	numberOfSubjects = 0;
	netProfitCountryEnterprises = 0;
	populationOfCountry = 0;
	squareOfCountry = 0;
	incomeOfCountry = 0;
	expensesOfCountry = 0;
	budgetDeficitOrSurplusOfCountry = 0;
}

Country::Country(char* name)
{
	nameOfCountry = new char(strlen(name));
	strcpy(nameOfCountry, name);
	numberOfSubjects = 0;
	netProfitCountryEnterprises = 0;
	populationOfCountry = 0;
	squareOfCountry = 0;
	incomeOfCountry = 0;
	expensesOfCountry = 0;
	budgetDeficitOrSurplusOfCountry = 0;
}


Country::Country(char* name, int number, int population, int square, unsigned long income, unsigned long expenses, Subject subjects[])
{
	nameOfCountry = new char(strlen(name));
	strcpy(nameOfCountry, name);
	numberOfSubjects = number;
	netProfitCountryEnterprises = calculatingProfitsFromEnterprises();
	populationOfCountry = population;
	squareOfCountry = square;
	incomeOfCountry = income;
	expensesOfCountry = expenses;
	budgetDeficitOrSurplusOfCountry = income - expenses;
	for (int i = 0; i < MAXSUBJECTS; i++)
	{
		listOfSubjects[i] = subjects[i];
	}
}

Country::~Country()
{
	if (nameOfCountry != NULL)
		delete[] nameOfCountry;
}

int Country::calculatingProfitsFromEnterprises()
{
	int i, j, k;
	int numberOfProfit = 0;
	City* city;
	Enterprise* enterprise;
	for (i = 0; i < MAXSUBJECTS; i++) {
		city = listOfSubjects[i].getListOfCities();
		for (j = 0; j < MAXCITIES; j++) {
			enterprise = city[j].getListOfEnterprises();
			for (k = 0; k < MAXENTERPRISES; k++) {
				numberOfProfit += enterprise[k].getNetProfitOfEnterprise();
			}
		}
	}
	return numberOfProfit;
}