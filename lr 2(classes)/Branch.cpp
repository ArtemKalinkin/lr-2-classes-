#include "Branch.h"

Branch::Branch()
{
}

Branch::Branch(string name, string address, unsigned long turnover, long profit, string date, string industry, string activity, string status, int numberOfEmployees) : Company(name, address, turnover, profit, date, industry, activity)
{
	this->status = status;
	this->numberOfEmployees = numberOfEmployees;
}


void Branch::setStatus(string status)
{
	this->status = status;
}

string Branch::getStatus()
{
	return status;
}

void Branch::setNumberOfEmployess(int number)
{
	numberOfEmployees = number;
}

int Branch::getNumberOfEmplyees()
{
	return numberOfEmployees;
}

void Branch::inputCompanyFromConsole(int mode)
{
	Company::inputCompanyFromConsole(1);
	do {
		try {
			cout << "������� ������ �������:" << endl;
			getline(cin, status);
			protectionAgainstIncorrectTextInput(status);
			break;
		}
		catch (const invalid_argument e) {
			cerr << "��������� ������: " << e.what() << endl;
		}
		catch (const length_error e) {
			cerr << "��������� ������: " << e.what() << endl;
		}
	} while (true);
	cout << "������� ���������� �����������:" << endl;
	while (scanf("%d", &numberOfEmployees) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ���������� �����������:\n";
	}
}

void Branch::outputCompanyToConsole(int number)
{
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(60) << left << name + " - " + status + " ������. ���-�� �����������: " + to_string(numberOfEmployees) << " * ";
	cout << setw(47) << left << citySubjectCountry << " * ";
	cout << setw(17) << left << turnoverPerYear << " * ";
	cout << setw(13) << left << netProfit << " * ";
	cout << setw(32) << left << industry << " * ";
	cout << setw(14) << left << dateOfFoundation << " *" << endl;
	cout << "******************************************************************************************************************************************************************************************************************" << endl;
}

Branch& Branch::operator=(const Company& other)
{
	static_cast<Company&>(*this) = other;
	do {
		try {
			cout << "������� ������ �������:" << endl;
			getline(cin, status);
			protectionAgainstIncorrectTextInput(status);
			break;
		}
		catch (const invalid_argument e) {
			cerr << "��������� ������: " << e.what() << endl;
		}
		catch (const length_error e) {
			cerr << "��������� ������: " << e.what() << endl;
		}
	} while (true);
	cout << "������� ���������� �����������:" << endl;
	while (scanf("%d", &numberOfEmployees) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ���������� �����������:\n";
	}
	return *this;
}

void Branch::performActivity() const
{
	cout << name << endl;
	cout << "������� �������� ������������ ������� ��������" << endl;
	cout << activity << endl;
	cout << "���������� �����������: " << numberOfEmployees << endl;
	cout << "������ �������: " << status << endl;
}

string Branch::info() const
{
	return "������ ��������: " + name + " - " + status + "������. ���-�� �����������: " + to_string(numberOfEmployees) + "; " + citySubjectCountry + "; " + to_string(turnoverPerYear) + "; " +
		to_string(netProfit) + "; " + dateOfFoundation + "; " + industry + ".";
}

Branch::Branch(const Branch& other)
{
	this->name = other.name;
	this->citySubjectCountry = other.citySubjectCountry;
	this->turnoverPerYear = other.turnoverPerYear;
	this->netProfit = other.netProfit;
	this->industry = other.industry;
	this->activity = other.activity;
	this->status = other.status;
	this->numberOfEmployees = other.numberOfEmployees;
}

bool Branch::compareByField(const Branch& other, BranchCompareField field) const
{
	switch (field)
	{
	case Branch::BranchCompareField::STATUS:
		return this->status < other.status;
	case Branch::BranchCompareField::NUMBEROFEMPLOYEES:
		return this->numberOfEmployees < other.numberOfEmployees;
	default:
		return Company::compareByField(other, static_cast<Company::CompanyCompareField>(field));
	}
}

ostream& operator<<(ostream& os, const Branch& branch)
{
	os << setw(60) << left << branch.name + " - " + branch.status + "������. ���-�� �����������: " + to_string(branch.numberOfEmployees) << " * ";
	os << setw(47) << left << branch.citySubjectCountry << " * ";
	os << setw(17) << left << branch.turnoverPerYear << " * ";
	os << setw(13) << left << branch.netProfit << " * ";
	os << setw(32) << left << branch.industry << " * ";
	os << setw(14) << left << branch.dateOfFoundation << " *" << endl;
	os << "******************************************************************************************************************************************************************************************************************" << endl;
	return os;
}
