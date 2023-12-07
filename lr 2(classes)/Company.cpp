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
	cout << "\n���� ��������\n" << endl;
	do {
		cout << "������� �������� ��������:" << endl;
		getline(cin, name);
	} while (protectionAgainstIncorrectTextInput(name));
	do {
		do {
			cout << "������� ���� ��������� ��������:" << endl;
			getline(cin, dateOfFoundation);
		} while (protectionAgainstIncorrectTextInput(dateOfFoundation));
	} while (checkingForCorrectnessOfDateEntry(dateOfFoundation));
	do {
		cout << "������� ������� ��������:" << endl;
		getline(cin, industry);
	} while (protectionAgainstIncorrectTextInput(industry));
	cout << "������� ������ �� ���:" << endl;
	while (scanf("%d", &turnoverPerYear) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ������ �� ���:\n";
	}
	cout << "������� ������� ��������:" << endl;
	while (scanf("%d", &netProfit) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ������� ��������:\n";
	}
	while (getchar() != '\n');
}

void Company::companyTableHeader()
{
	cout << "*****************************************************************************************************************************************************************************" << endl;
	cout << "* ����� *        ��������         *                  ��������������                 *   ������ �� ���   *    �������    *              �������             * ���� ��������� *" << endl;
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
	cout << "����� �� ������ � ������ " << totalCompanies << " ��������" << endl;
}

Company Company::operator+(const Company& company)
{
	Company buying�ompany = *this;
	buying�ompany.turnoverPerYear += company.turnoverPerYear;
	buying�ompany.netProfit += company.netProfit;
	return buying�ompany;
}




