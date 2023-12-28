#include "Country.h"

unsigned Country::totalCountries = 0;


void Country::setNumberOfSubjects(int number)
{
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	numberOfSubjects = number;
}

void Country::setNetProfitCountryFromCompanies(unsigned long profit)
{
	netProfitFromCompanies = profit;
}


void Country::setIncome(unsigned long income)
{
	if (income < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->income = income;
	budgetDeficitOrSurplus = income - expenses;
}

void Country::setExpenses(unsigned long expenses)
{
	if (expenses < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->expenses = expenses;
	budgetDeficitOrSurplus = income - expenses;
}

void Country::setListOfSubjects(vector<Subject> subjects)
{
	listOfSubjects = subjects;
}


int Country::getNumberOfSubjects()
{
	return numberOfSubjects;
}

unsigned long Country::getNetProfitCountryFromCompanies()
{
	return netProfitFromCompanies;
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

vector<Subject> &Country::getListOfSubjects()
{
	return listOfSubjects;
}

Country::Country()
{
	numberOfSubjects = 0;
	netProfitFromCompanies = 0;
	income = 0;
	expenses = 0;
	budgetDeficitOrSurplus = 0;
}

Country::Country(string name) : AbstractElement(name)
{
	numberOfSubjects = 0;
	netProfitFromCompanies = 0;
	income = 0;
	expenses = 0;
	budgetDeficitOrSurplus = 0;
}


Country::Country(string name, int number, long population, int square, unsigned long income, unsigned long expenses, vector<Subject> subjects)
{
	if (name.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->name = name;
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->numberOfSubjects = number;
	if (population < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->population = population;
	if (square < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->square = square;
	if (income < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->income = income;
	if (expenses < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->expenses = expenses;
	budgetDeficitOrSurplus = income - expenses;
	listOfSubjects = subjects;
	this->netProfitFromCompanies = calculatingProfitsFromCompanies(0);
}




int Country::calculatingProfitsFromCompanies(int number)
{
	int i, j, k;
	int numberOfProfit = 0;
	vector<City> cities;
	vector<Company*> companies;
	for (i = 0; i < listOfSubjects.size(); i++) {
		cities = listOfSubjects.at(i).getListOfCities();
		for (j = 0; j < cities.size(); j++) {
			companies = cities.at(j).getListOfCompanies();
			k = 0;   
			while(k < companies.size()){
				numberOfProfit += companies.at(k)->getNetProfit();
				k++;
			}
		}
	}
	return numberOfProfit;
}

void Country::input(string s)
{
	puts("\nВВОД СТРАНЫ\n");
	AbstractElement::input("страны");
	cout << "Введите количество субъектов в стране:" << endl;
	while (scanf("%d", &numberOfSubjects) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите количество субъектов в стране:\n";
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
	cout << setw(25) << left << listOfSubjects.at(0).getName() << " *" << endl;

	i = 1;
	while (i < listOfSubjects.size()) {
		cout << "*       *                    *                      *                *           *                     *                *                 *                          * ";
		cout << setw(25) << left << listOfSubjects.at(i).getName() << " *" << endl;
		i++;
	}
	cout << "**************************************************************************************************************************************************************************************************" << endl;
}

ostream& operator<<(ostream& os, const Country& country) {
	int i;
	os << setw(18) << left << country.name << " * ";
	os << setw(20) << left << country.numberOfSubjects << " * ";
	os << setw(14) << left << country.square << " * ";
	os << setw(9) << left << country.population << " * ";
	os << setw(19) << left << country.netProfitFromCompanies << " * ";
	os << setw(14) << left << country.income << " * ";
	os << setw(15) << left << country.expenses << " * ";
	os << setw(24) << left << country.budgetDeficitOrSurplus << " * ";
	os << setw(25) << left << country.listOfSubjects.at(0).getName() << " *" << endl;
	i = 1;
	while (i < country.listOfSubjects.size()) {
		os << "*       *                    *                      *                *           *                     *                *                 *                          * ";
		os << setw(25) << left << country.listOfSubjects.at(i).getName() << " *" << endl;
		i++;
	}
	os << "**************************************************************************************************************************************************************************************************" << endl;
	return os;
}

Subject& Country::choosingSubject()
{
	int i, n, number;
	char character;
	listOfSubjects[0].subjectTableHeader();
	i = 0;
	while (i < listOfSubjects.size()) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << listOfSubjects.at(i);
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
		cout << "Расходы страны - " << this->name << " больше доходов страны - " << secondCountry->name << " на " << percentageOfExpenses << "%" << endl;
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

string Country::info() const
{
	return "Страна: " + name + "; "  + to_string(population) + "; " + to_string(square) +
		"; " + to_string(numberOfSubjects) + "; " + to_string(netProfitFromCompanies) + "; " + to_string(income) + "; " + to_string(expenses) + "; " + to_string(budgetDeficitOrSurplus) + ".";
}

Country::Country(const Country& other) : listOfSubjects(other.listOfSubjects)
{
	this->name = other.name;
	this->square = other.square;
	this->population = other.population;
	this->numberOfSubjects = other.numberOfSubjects;
	this->netProfitFromCompanies = other.netProfitFromCompanies;
	this->income = other.income;
	this->expenses = other.expenses;
	this->budgetDeficitOrSurplus = other.budgetDeficitOrSurplus;
}

bool Country::compareByField(const Country& other, CountryCompareField field) const
{
	switch (field)
	{
	case CountryCompareField::NAME:
		return name < other.name;
	case CountryCompareField::POPULATION:
		return population < other.population;
	case CountryCompareField::SQUARE:
		return square < other.square;
	case CountryCompareField::NUMBEROFSUBJECTS:
		return this->numberOfSubjects < other.numberOfSubjects;
	case CountryCompareField::NETPROFIT:
		return this->netProfitFromCompanies < other.netProfitFromCompanies;
	case CountryCompareField::INCOME:
		return this->income < other.income;
	case CountryCompareField::EXPENSES:
		return this->expenses < other.expenses;
	case CountryCompareField::BUDGET:
		return this->budgetDeficitOrSurplus < other.expenses;
	default:
		return false;
	}
}

int Country::selectCriteria(string s)
{
	cout << "Выберете критерий " << s << " стран: ";
	int number;
	cout << "1.Название" << endl;
	cout << "2.Площадь" << endl;
	cout << "3.Население" << endl;
	cout << "4.Количество субъектов" << endl;
	cout << "5.Прибыль от компаний" << endl;
	cout << "6.Доход" << endl;
	cout << "7.Расхооды" << endl;
	cout << "8.Профицит\\дефицит" << endl;
	do {
		cout << "Введите номер: " << endl;
		cin >> number;
		if ((number < 1) || (number > 8))
			cout << "Критерия с данным номером нет" << endl;
	} while ((number < 1) || (number > 8));
	return number;
}

void Country::sortSubjects(int criteria)
{
	vector<Subject*> subjectPointers;
	for (Subject& subject : listOfSubjects) {
		subjectPointers.push_back(&subject);
	}
	int number;
	cout << endl << "Спрособ упорядочивания" << endl;
	cout << "1.По убыванию" << endl;
	cout << "2.По возрастанию" << endl;
	do {
		cout << "Введите номер: ";
		cin >> number;
		if ((number < 1) || (number > 2))
			cout << "Введите 1 или 2" << endl;
	} while (number < 1 || (number > 2));
	if (((number == 1) && (criteria == 1)) || ((number == 2) && (criteria != 1))) {
		switch (criteria)
		{
		case 1:
			sort(subjectPointers.begin(), subjectPointers.end(), [](const Subject* a, const Subject* b) {
				return a->compareByField(*b, Subject::SubjectCompareField::NAME);
				});
			break;
		case 2:
			sort(subjectPointers.begin(), subjectPointers.end(), [](const Subject* a, const Subject* b) {
				return a->compareByField(*b, Subject::SubjectCompareField::SQUARE);
				});
			break;
		case 3:
			sort(subjectPointers.begin(), subjectPointers.end(), [](const Subject* a, const Subject* b) {
				return a->compareByField(*b, Subject::SubjectCompareField::POPULATION);
				});
			break;
		case 4:
			sort(subjectPointers.begin(), subjectPointers.end(), [](const Subject* a, const Subject* b) {
				return a->compareByField(*b, Subject::SubjectCompareField::NUMBEROFCITIES);
				});
			break;
		default:
			break;
		}
	}
	else {
		switch (criteria)
		{
		case 1:
			sort(subjectPointers.begin(), subjectPointers.end(), [](const Subject* a, const Subject* b) {
				return b->compareByField(*a, Subject::SubjectCompareField::NAME);
				});
			break;
		case 2:
			sort(subjectPointers.begin(), subjectPointers.end(), [](const Subject* a, const Subject* b) {
				return b->compareByField(*a, Subject::SubjectCompareField::SQUARE);
				});
			break;
		case 3:
			sort(subjectPointers.begin(), subjectPointers.end(), [](const Subject* a, const Subject* b) {
				return b->compareByField(*a, Subject::SubjectCompareField::POPULATION);
				});
			break;
		case 4:
			sort(subjectPointers.begin(), subjectPointers.end(), [](const Subject* a, const Subject* b) {
				return b->compareByField(*a, Subject::SubjectCompareField::NUMBEROFCITIES);
				});
			break;
		default:
			break;
		}
	}
}
