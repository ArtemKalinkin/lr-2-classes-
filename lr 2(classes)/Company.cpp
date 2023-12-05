#include "Company.h"

unsigned Company::totalCompanies = 0;


void Company::setName(string name)
{
	this->name = name;
}

void Company::setcitySubjectCountry(string address)
{
	citySubjectCountry = address;
}

void Company::setTurnoverPerYear(unsigned long turnover)
{
	turnoverPerYear = turnover;
}

void Company::setNetProfit(long profit)
{
	netProfit = profit;
}

void Company::setDateOfFoundation(string date)
{
	dateOfFoundation = date;
}

void Company::setIndustry(string industry)
{
	this->industry = industry;
}

string Company::getName()
{
	return name;
}

string Company::getcitySubjectCountry()
{
	return citySubjectCountry;
}

unsigned long Company::getTurnoverPerYear()
{
	return turnoverPerYear;
}

long Company::getNetProfit()
{
	return netProfit;
}

string Company::getDateOfFoundation()
{
	return dateOfFoundation;
}

string Company::getIndustry()
{
	return industry;
}

Company::Company()
{
	turnoverPerYear = 0;
	netProfit = 0;
}

Company::Company(string name)
{
	this->name = name;
	turnoverPerYear = 0;
	netProfit = 0;
}

Company::Company(string name, string address, unsigned long turnover, long profit, string date, string industry)
{
	this->name = name;
	citySubjectCountry = address;
	turnoverPerYear = turnover;
	netProfit = profit;
	dateOfFoundation = date;
	this->industry = industry;
}


void Company::inputCompanyFromConsole()
{
	cout << "\nВВОД КОМПАНИИ\n" << endl;
	do {
		cout << "Введите название компании:" << endl;
		getline(cin, name);
	} while (protectionAgainstIncorrectTextInput(name));
	do {
		do {
			cout << "Введите дату основания компании:" << endl;
			getline(cin, dateOfFoundation);
		} while (protectionAgainstIncorrectTextInput(dateOfFoundation));
	} while (checkingForCorrectnessOfDateEntry(dateOfFoundation));
	do {
		cout << "Введите отрасль компании:" << endl;
		getline(cin, industry);
	} while (protectionAgainstIncorrectTextInput(industry));
	cout << "Введите оборот за год:" << endl;
	while (scanf("%d", &turnoverPerYear) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите оборот за год:\n";
	}
	cout << "Введите прибыль компании:" << endl;
	while (scanf("%d", &netProfit) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите прибыль компании:\n";
	}
	while (getchar() != '\n');
}

void Company::companyTableHeader()
{
	cout << "*****************************************************************************************************************************************************************************" << endl;
	cout << "* Номер *        Компания         *                  Местоположение                 *   Оборот за год   *    Прибыль    *              Отрасль             * Дата основания *" << endl;
	cout << "*****************************************************************************************************************************************************************************" << endl;
}

void Company::outputCompanyToConsole(int number)
{
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(23) << left << name << " * ";
	cout << setw(47) << left << citySubjectCountry << " * ";
	cout << setw(17) << left << turnoverPerYear << " * ";
	cout << setw(13) << left << netProfit << " * ";
	cout << setw(32) << left << industry << " * ";
	cout << setw(14) << left << dateOfFoundation << " *" << endl;
	cout << "*****************************************************************************************************************************************************************************" << endl;
}


void Company::incrementTotalCompanies()
{
	totalCompanies++;
}

void Company::printTotalCompanies()
{
	cout << "Всего вы внесли в список " << totalCompanies << " компаний" << endl;
}

Company Company::operator+(const Company& company)
{
	Company buyingСompany = *this;
	buyingСompany.turnoverPerYear += company.turnoverPerYear;
	buyingСompany.netProfit += company.netProfit;
	return buyingСompany;
}




