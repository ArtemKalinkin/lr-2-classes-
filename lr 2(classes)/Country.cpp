#include "Country.h"

unsigned Country::totalCountries = 0;


void Country::setName(string name)
{
	this->name = name;
}

void Country::setNumberOfSubjects(int number)
{
	numberOfSubjects = number;
}

void Country::setNetProfitCountryFromCompanies(unsigned long profit)
{
	netProfitFromCompanies = profit;
}

void Country::setPopulation(int population)
{
	this->population = population;
}

void Country::setSquare(int square)
{
	this->square = square;
}

void Country::setIncome(unsigned long income)
{
	this->income = income;
	budgetDeficitOrSurplus = income - expenses;
}

void Country::setExpenses(unsigned long expenses)
{
	this->expenses = expenses;
	budgetDeficitOrSurplus = income - expenses;
}

void Country::setListOfSubjects(Subject subjects[])
{
	for (int i = 0; i < MAXSUBJECTS; i++)
	{
		listOfSubjects[i] = subjects[i];
	}
}

string Country::getName()
{
	return name;
}

int Country::getNumberOfSubjects()
{
	return numberOfSubjects;
}

unsigned long Country::getNetProfitCountryFromCompanies()
{
	return netProfitFromCompanies;
}

int Country::getPopulation()
{
	return population;
}

int Country::getSquare()
{
	return square;
}

unsigned long Country::getIncome()
{
	return income;
}

unsigned long Country::getExpenses()
{
	return expenses;
}

long Country::getBudgetDeficitOrSurplus()
{
	return budgetDeficitOrSurplus;
}

Subject* Country::getListOfSubjects()
{
	return listOfSubjects;
}

Country::Country()
{
	numberOfSubjects = 0;
	netProfitFromCompanies = 0;
	population = 0;
	square = 0;
	income = 0;
	expenses = 0;
	budgetDeficitOrSurplus = 0;
}

Country::Country(string name)
{
	this->name = name;
	numberOfSubjects = 0;
	netProfitFromCompanies = 0;
	population = 0;
	square = 0;
	income = 0;
	expenses = 0;
	budgetDeficitOrSurplus = 0;
}


Country::Country(string name, int number, int population, int square, unsigned long income, unsigned long expenses, Subject subjects[])
{
	this->name = name;
	this->numberOfSubjects = number;
	this->netProfitFromCompanies = calculatingProfitsFromCompanies();
	this->population = population;
	this->square = square;
	this->income = income;
	this->expenses = expenses;
	budgetDeficitOrSurplus = income - expenses;
	for (int i = 0; i < MAXSUBJECTS; i++)
	{
		listOfSubjects[i] = subjects[i];
	}
}




int Country::calculatingProfitsFromCompanies()
{
	int i, j, k;
	int numberOfProfit = 0;
	City* city;
	Company* company;
	for (i = 0; i < MAXSUBJECTS; i++) {
		city = listOfSubjects[i].getListOfCities();
		for (j = 0; j < MAXCITIES; j++) {
			company = city[j].getListOfCompanies();
			for (k = 0; k < MAXCOMPANIES; k++) {
				numberOfProfit += company[k].getNetProfit();
			}
		}
	}
	return numberOfProfit;
}

void Country::inputCountryFromConsole()
{
	puts("\nВВОД СТРАНЫ\n");
	do {
		cout << "Введите название страны:" << endl;
		getline(cin, name);
	} while (protectionAgainstIncorrectTextInput(name));
	cout << "Введите население страны:" << endl;
	while (scanf("%d", &population) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите население страны:\n";
	}
	cout << "Введите количество субъектов в стране:" << endl;
	while (scanf("%d", &numberOfSubjects) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите количество субъектов в стране:\n";
	}
	cout << "Введите площадь страны:" << endl;
	while (scanf("%d", &square) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите площадь страны:\n";
	}
	cout << "Введите доход страны:" << endl;
	while (scanf("%d", &income) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите доход страны:\n";
	}
	cout << "Введите расходы страны:" << endl;
	while (scanf("%d", &expenses) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите расходы страны:\n";
	}
	while (getchar() != '\n');
	budgetDeficitOrSurplus = income - expenses;
}

void Country::countryTableHeader()
{
	cout << "**************************************************************************************************************************************************************************************************" << endl;
	cout << "* Номер *       Страна       * Количество субъектов * Площадь страны * Население *  Прибыль компаний   *     Доходы     *     Расходы     * Профицит/дефицит бюджета *      Список субъектов     *" << endl;
	cout << "**************************************************************************************************************************************************************************************************" << endl;
}

void Country::outputCountryToConsole(int number)
{
	int i;
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(18) << left << name << " * ";
	cout << setw(20) << left << numberOfSubjects << " * ";
	cout << setw(14) << left << square << " * ";
	cout << setw(9) << left << population << " * ";
	cout << setw(19) << left << netProfitFromCompanies << " * ";
	cout << setw(14) << left << income << " * ";
	cout << setw(15) << left << expenses << " * ";
	cout << setw(24) << left << budgetDeficitOrSurplus << " * ";
	cout << setw(25) << left << listOfSubjects[0].getName() << " *" << endl;

	i = 1;
	while ((!listOfSubjects[i].getName().empty()) && (i < MAXSUBJECTS)) {
		cout << "*       *                    *                      *                *           *                     *                *                 *                          * ";
		cout << setw(25) << left << listOfSubjects[i].getName() << " *" << endl;
		i++;
	}
	cout <<"**************************************************************************************************************************************************************************************************" << endl;
}

Subject& Country::choosingSubject()
{
	int i, n, number;
	char character;
	listOfSubjects[0].subjectTableHeader();
	i = 0;
	while (!listOfSubjects[i].getName().empty()) {
		listOfSubjects[i].outputSubjectToConsole(i);
		i++;
	}
	n = i + 1;
	cout << "\nВыберите субъект\n" << endl;
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > n));
	return listOfSubjects[number - 1];
}

int Country::comparisonOfTwoCountries(Country* secondCountry)
{
	int percentageOfSquare;
	int percentageOfPopulation;
	int percentageOfProfits;
	int percentageOfIncome;
	int percentageOfExpenses;
	int numberOne = 0, numberTwo = 0;
	int value;
	cout << "\nПроцентное соотношение характеристик стран" << endl;
	cout << name << "  -  " << secondCountry->name << endl;
	// Площадь
	if (this->square > secondCountry->square) {
		percentageOfSquare = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(square, secondCountry->square);
		cout << "Площадь страны - " << name << " больше площади страны -" << secondCountry->name << " на " << percentageOfSquare << "%" << endl;
		numberOne++;
	}
	else if (this->square < secondCountry->square) {
		percentageOfSquare = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->square, square);
		cout << "Площадь страны - " << secondCountry->name << " больше площади страны -" << name << " на " << percentageOfSquare << "%" << endl;
		numberTwo++;
	}
	else
		cout << "Площади стран равны" << endl;
	// Население
	if (this->population > secondCountry->population) {
		percentageOfPopulation = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(population, secondCountry->population);
		cout << "Населeние страны - " << name << " больше населения страны - " << secondCountry->name << " на " << percentageOfPopulation << "%" << endl;
		numberOne++;
	}
	else  if (this->population < secondCountry->population) {
		percentageOfPopulation = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->population, population);
		cout << "Населeние страны - " << secondCountry->name << " больше населения страны - " << name << " на " << percentageOfPopulation << "%" << endl;
		numberTwo++;
	}
	else
		cout << "Население стран равно" << endl;
	//Прибыль предприятий 
	if (this->netProfitFromCompanies > secondCountry->netProfitFromCompanies) {
		percentageOfProfits = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(netProfitFromCompanies, secondCountry->netProfitFromCompanies);
		cout << "Прибыль компаний страны - " << this->name << " больше прибыли предприятий страны - " << secondCountry->name << " на " << percentageOfProfits << "%" << endl;
		numberOne++;
	}
	else if (this->netProfitFromCompanies < secondCountry->netProfitFromCompanies) {
		percentageOfProfits = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->netProfitFromCompanies, netProfitFromCompanies);
		cout << "Прибыль компаний страны - " << secondCountry->name << " больше прибыли предприятий страны - " << this->name << " на " << percentageOfProfits << "%" << endl;
		numberTwo++;
	}
	else cout << "Прибыли компаний стран равны" << endl;
	// Доходы
	if (this->income > secondCountry->income) {
		percentageOfIncome = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(this->income, secondCountry->income);
		cout << "Доходы страны - " << this->name << " больше доходов страны - " << secondCountry->name << " на " << percentageOfIncome << "%" << endl;
		numberOne++;
	}
	else if (this->income < secondCountry->income) {
		percentageOfIncome = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->income, this->income);
		cout << "Доходы страны - " << secondCountry->name << " больше доходов страны - " << name << " на " << percentageOfIncome << "%" << endl;
		numberTwo++;
	}
	else
		cout << "Доходы стран равны" << endl;
	// Расходы
	if (this->expenses > secondCountry->expenses) {
		percentageOfExpenses = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(expenses, secondCountry->expenses);
		cout << "Расходы страны - "<< this->name << " больше доходов страны - " << secondCountry->name << " на " << percentageOfExpenses << "%" << endl;
	}
	else if (this->expenses < secondCountry->expenses) {
		percentageOfExpenses = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->expenses, expenses);
		cout << "Расходы страны - " << secondCountry->name << " больше доходов страны - " << this->name << " на " << percentageOfExpenses << "%" << endl;
	}
	else
		cout << "Расходы стран равны" << endl;
	if (numberOne > numberTwo)
		value = 1;
	else
		value = 2;
	return value;
}


void Country::incrementTotalCountries()
{
	totalCountries++;
}

void Country::printTotalCountries()
{
	cout << "Вы внесли в список " << totalCountries << " из 195 существующих стран" << endl;
}
