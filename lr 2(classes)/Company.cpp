#include "Company.h"

unsigned Company::totalCompanies = 0;


void Company::setName(string name)
{
	if (name.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;
}

void Company::setcitySubjectCountry(string address)
{
	if (address.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	citySubjectCountry = address;
}

void Company::setTurnoverPerYear(unsigned long turnover)
{
	if (turnover < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	turnoverPerYear = turnover;
}

void Company::setNetProfit(long profit)
{
	netProfit = profit;
}

void Company::setDateOfFoundation(string date)
{
	if (date.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	dateOfFoundation = date;
}

void Company::setIndustry(string industry)
{
	if (industry.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
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
	if (name.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;
	turnoverPerYear = 0;
	netProfit = 0;
}

Company::Company(string name, string address, unsigned long turnover, long profit, string date, string industry)
{
	if (name.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;
	if (address.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	citySubjectCountry = address;
	if (turnover < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	turnoverPerYear = turnover;
	netProfit = profit;
	if (date.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	dateOfFoundation = date;
	if (industry.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->industry = industry;
}


void Company::inputCompanyFromConsole()
{
	cout << "\n���� ��������\n" << endl;
	do {
		try {
			cout << "������� �������� ���������:" << endl;
			getline(cin, name);
			protectionAgainstIncorrectTextInput(name);
			break;
		}
		catch (const invalid_argument e) {
			cerr << "��������� ������: " << e.what() << endl;
		}
		catch (const length_error e) {
			cerr << "��������� ������: " << e.what() << endl;
		}
	} while (true);
	do {
		do {
			cout << "������� ���� ��������� ��������:" << endl;
			getline(cin, dateOfFoundation);
		} while (protectionAgainstIncorrectTextInput(dateOfFoundation));
	} while (checkingForCorrectnessOfDateEntry(dateOfFoundation));
	do {
		try {
			cout << "������� ������� ��������:" << endl;
			getline(cin, industry);
			protectionAgainstIncorrectTextInput(industry);
			break;
		}
		catch (const invalid_argument e) {
			cerr << "��������� ������: " << e.what() << endl;
		}
		catch (const length_error e) {
			cerr << "��������� ������: " << e.what() << endl;
		}
	} while (true);
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




