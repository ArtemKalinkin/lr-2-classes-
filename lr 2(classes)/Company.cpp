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

string Company::getName() const
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

Company::Company(string name, string address, unsigned long turnover, long profit, string date, string industry, string activity)
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
	if (activity.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->activity = activity;
}


void Company::inputCompanyFromConsole(int mode)
{
	string s;
	if (mode) {
		s = "������� ��������";
		cout << "\n���� ������� ��������\n" << endl;
	}
	else {
		s = "��������";
		cout << "\n���� ��������\n" << endl;
	}
	do {
		try {
			cout << "������� �������� " << s << ":" << endl;
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
			cout << "������� ���� ��������� " << s << ":" << endl;
			getline(cin, dateOfFoundation);
		} while (protectionAgainstIncorrectTextInput(dateOfFoundation));
	} while (checkingForCorrectnessOfDateEntry(dateOfFoundation));
	do {
		try {
			cout << "������� ������� " << s << ":" << endl;
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
	cout << "������� ������� " << s << ":" << endl;
	while (scanf("%d", &netProfit) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ������� " << s << ":\n";
	}
	while (getchar() != '\n');
	cout << "������� �������� ������������ " << s << ":" << endl;
	getline(cin, activity);
}

void Company::companyTableHeader()
{
	cout << "******************************************************************************************************************************************************************************************************************" << endl;
	cout << "* ����� *                          ��������                            *                  ��������������                 *   ������ �� ���   *    �������    *              �������             * ���� ��������� *" << endl;
	cout << "******************************************************************************************************************************************************************************************************************" << endl;
}

void Company::outputCompanyToConsole(int number)
{
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(60) << left << name << " * ";
	cout << setw(47) << left << citySubjectCountry << " * ";
	cout << setw(17) << left << turnoverPerYear << " * ";
	cout << setw(13) << left << netProfit << " * ";
	cout << setw(32) << left << industry << " * ";
	cout << setw(14) << left << dateOfFoundation << " *" << endl;
	cout << "******************************************************************************************************************************************************************************************************************" << endl;
}

ostream& operator<<(ostream& os, const Company& company) {
	os << setw(60) << left << company.name << " * ";
	os << setw(47) << left << company.citySubjectCountry << " * ";
	os << setw(17) << left << company.turnoverPerYear << " * ";
	os << setw(13) << left << company.netProfit << " * ";
	os << setw(32) << left << company.industry << " * ";
	os << setw(14) << left << company.dateOfFoundation << " *" << endl;
	os << "******************************************************************************************************************************************************************************************************************" << endl;
	return os;
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

Company& Company::operator=(const Company& other)
{
	if (this != &other) {
		name = other.name;
		citySubjectCountry = other.citySubjectCountry;
		turnoverPerYear = other.turnoverPerYear;
		netProfit = other.netProfit;
		dateOfFoundation = other.dateOfFoundation;
		industry = other.industry;
		activity = other.activity;
	}
	return *this;
}

void Company::performActivity() const
{
	cout << name << endl;
	cout << "������� �������� ������������ ��������" << endl;
	cout << activity << endl;
}

void Company::callPerformActivity() const
{
	performActivity();
}

string Company::info() const
{
	return "��������: " + name + "; " + citySubjectCountry + "; " + to_string(turnoverPerYear) + "; " + 
		to_string(netProfit) + "; " + dateOfFoundation + "; " + industry + ".";
}

Company::Company(const Company& other)
{
	this->name = other.name;
	this->citySubjectCountry = other.citySubjectCountry;
	this->turnoverPerYear = other.turnoverPerYear;
	this->netProfit = other.netProfit;
	this->industry = other.industry;
	this->activity = other.activity;
}

bool Company::compareByField(const Company& other, CompanyCompareField field) const
{
	int number;
	char delimiter;
	istringstream thisDate(dateOfFoundation);
	istringstream otherDate(other.dateOfFoundation);
	vector<int> thisNumbers;
	vector<int> otherNumbers;
	while (thisDate >> number) {
		thisNumbers.push_back(number);
		if (!(thisDate >> delimiter))
			break;
	}
	while (otherDate >> number) {
		otherNumbers.push_back(number);
		if (!(otherDate >> delimiter))
			break;
	}
	switch (field)
	{
	case CompanyCompareField::NAME:
		return this->name < other.name;
	case CompanyCompareField::ADDRESS:
		return this->citySubjectCountry < other.citySubjectCountry;
	case CompanyCompareField::TURNOVER:
		return this->turnoverPerYear < other.turnoverPerYear;
	case CompanyCompareField::NETPROFIT:
		return this->netProfit < other.netProfit;
	case CompanyCompareField::DATE:
		if (thisNumbers.at(2) != otherNumbers.at(2))
			return thisNumbers.at(2) < otherNumbers.at(2);
		else if (thisNumbers.at(1) != otherNumbers.at(1))
			return thisNumbers.at(1) < otherNumbers.at(1);
		else
			return thisNumbers.at(0) < otherNumbers.at(0);
	case CompanyCompareField::INDUSTRY:
		return this->industry < other.industry;
	default:
		return false;
	}
}

int Company::selectCriteria(string s)
{
	cout << "�������� �������� " << s << " ��������: " << endl;
	int number;
	cout << "1.��������" << endl;
	cout << "2.�����" << endl;
	cout << "3.������ �� ���" << endl;
	cout << "4.�������" << endl;
	cout << "5.���� ���������" << endl;
	cout << "6.�������" << endl;
	do {
		cout << "������� �����: ";
		cin >> number;
		if ((number < 1) || (number > 6))
			cout << "�������� � ������ ������� ���" << endl;
	} while ((number < 1) || (number > 6));
	return number;
}




