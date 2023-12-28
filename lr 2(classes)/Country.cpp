#include "Country.h"

unsigned Country::totalCountries = 0;


void Country::setNumberOfSubjects(int number)
{
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	numberOfSubjects = number;
}

void Country::setNetProfitCountryFromCompanies(unsigned long profit)
{
	netProfitFromCompanies = profit;
}


void Country::setIncome(unsigned long income)
{
	if (income < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->income = income;
	budgetDeficitOrSurplus = income - expenses;
}

void Country::setExpenses(unsigned long expenses)
{
	if (expenses < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
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
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->numberOfSubjects = number;
	if (population < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->population = population;
	if (square < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->square = square;
	if (income < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->income = income;
	if (expenses < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
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
	puts("\n���� ������\n");
	AbstractElement::input("������");
	cout << "������� ���������� ��������� � ������:" << endl;
	while (scanf("%d", &numberOfSubjects) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ���������� ��������� � ������:\n";
	}
	cout << "������� ����� ������:" << endl;
	while (scanf("%d", &income) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ����� ������:\n";
	}
	cout << "������� ������� ������:" << endl;
	while (scanf("%d", &expenses) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ������� ������:\n";
	}
	while (getchar() != '\n');
	budgetDeficitOrSurplus = income - expenses;
}

void Country::countryTableHeader()
{
	cout << "**************************************************************************************************************************************************************************************************" << endl;
	cout << "* ����� *       ������       * ���������� ��������� * ������� ������ * ��������� *  ������� ��������   *     ������     *     �������     * ��������/������� ������� *      ������ ���������     *" << endl;
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
	cout << "\n�������� �������\n" << endl;
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
	cout << "\n���������� ����������� ������������� �����" << endl;
	cout << name << "  -  " << secondCountry->name << endl;
	// �������
	if (this->square > secondCountry->square) {
		percentageOfSquare = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(square, secondCountry->square);
		cout << "������� ������ - " << name << " ������ ������� ������ -" << secondCountry->name << " �� " << percentageOfSquare << "%" << endl;
		numberOne++;
	}
	else if (this->square < secondCountry->square) {
		percentageOfSquare = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->square, square);
		cout << "������� ������ - " << secondCountry->name << " ������ ������� ������ -" << name << " �� " << percentageOfSquare << "%" << endl;
		numberTwo++;
	}
	else
		cout << "������� ����� �����" << endl;
	// ���������
	if (this->population > secondCountry->population) {
		percentageOfPopulation = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(population, secondCountry->population);
		cout << "�����e��� ������ - " << name << " ������ ��������� ������ - " << secondCountry->name << " �� " << percentageOfPopulation << "%" << endl;
		numberOne++;
	}
	else  if (this->population < secondCountry->population) {
		percentageOfPopulation = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->population, population);
		cout << "�����e��� ������ - " << secondCountry->name << " ������ ��������� ������ - " << name << " �� " << percentageOfPopulation << "%" << endl;
		numberTwo++;
	}
	else
		cout << "��������� ����� �����" << endl;
	//������� ����������� 
	if (this->netProfitFromCompanies > secondCountry->netProfitFromCompanies) {
		percentageOfProfits = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(netProfitFromCompanies, secondCountry->netProfitFromCompanies);
		cout << "������� �������� ������ - " << this->name << " ������ ������� ����������� ������ - " << secondCountry->name << " �� " << percentageOfProfits << "%" << endl;
		numberOne++;
	}
	else if (this->netProfitFromCompanies < secondCountry->netProfitFromCompanies) {
		percentageOfProfits = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->netProfitFromCompanies, netProfitFromCompanies);
		cout << "������� �������� ������ - " << secondCountry->name << " ������ ������� ����������� ������ - " << this->name << " �� " << percentageOfProfits << "%" << endl;
		numberTwo++;
	}
	else cout << "������� �������� ����� �����" << endl;
	// ������
	if (this->income > secondCountry->income) {
		percentageOfIncome = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(this->income, secondCountry->income);
		cout << "������ ������ - " << this->name << " ������ ������� ������ - " << secondCountry->name << " �� " << percentageOfIncome << "%" << endl;
		numberOne++;
	}
	else if (this->income < secondCountry->income) {
		percentageOfIncome = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->income, this->income);
		cout << "������ ������ - " << secondCountry->name << " ������ ������� ������ - " << name << " �� " << percentageOfIncome << "%" << endl;
		numberTwo++;
	}
	else
		cout << "������ ����� �����" << endl;
	// �������
	if (this->expenses > secondCountry->expenses) {
		percentageOfExpenses = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(expenses, secondCountry->expenses);
		cout << "������� ������ - " << this->name << " ������ ������� ������ - " << secondCountry->name << " �� " << percentageOfExpenses << "%" << endl;
	}
	else if (this->expenses < secondCountry->expenses) {
		percentageOfExpenses = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->expenses, expenses);
		cout << "������� ������ - " << secondCountry->name << " ������ ������� ������ - " << this->name << " �� " << percentageOfExpenses << "%" << endl;
	}
	else
		cout << "������� ����� �����" << endl;
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
	cout << "�� ������ � ������ " << totalCountries << " �� 195 ������������ �����" << endl;
}

string Country::info() const
{
	return "������: " + name + "; "  + to_string(population) + "; " + to_string(square) +
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
	cout << "�������� �������� " << s << " �����: ";
	int number;
	cout << "1.��������" << endl;
	cout << "2.�������" << endl;
	cout << "3.���������" << endl;
	cout << "4.���������� ���������" << endl;
	cout << "5.������� �� ��������" << endl;
	cout << "6.�����" << endl;
	cout << "7.��������" << endl;
	cout << "8.��������\\�������" << endl;
	do {
		cout << "������� �����: " << endl;
		cin >> number;
		if ((number < 1) || (number > 8))
			cout << "�������� � ������ ������� ���" << endl;
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
	cout << endl << "������� ��������������" << endl;
	cout << "1.�� ��������" << endl;
	cout << "2.�� �����������" << endl;
	do {
		cout << "������� �����: ";
		cin >> number;
		if ((number < 1) || (number > 2))
			cout << "������� 1 ��� 2" << endl;
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
