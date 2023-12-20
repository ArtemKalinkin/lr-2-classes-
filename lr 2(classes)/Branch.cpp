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
			cout << "Введите статус филиала:" << endl;
			getline(cin, status);
			protectionAgainstIncorrectTextInput(status);
			break;
		}
		catch (const invalid_argument e) {
			cerr << "Произошла ошибка: " << e.what() << endl;
		}
		catch (const length_error e) {
			cerr << "Произошла ошибка: " << e.what() << endl;
		}
	} while (true);
	cout << "Введите количество сотрудников:" << endl;
	while (scanf("%d", &numberOfEmployees) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите количество сотрудников:\n";
	}
}

void Branch::outputCompanyToConsole(int number)
{
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(60) << left << name + " - " + status + "филиал. Кол-во сотрудников: " + to_string(numberOfEmployees) << " * ";
	cout << setw(47) << left << citySubjectCountry << " * ";
	cout << setw(17) << left << turnoverPerYear << " * ";
	cout << setw(13) << left << netProfit << " * ";
	cout << setw(32) << left << industry << " * ";
	cout << setw(14) << left << dateOfFoundation << " *" << endl;
	cout << "*****************************************************************************************************************************************************************************" << endl;
}

Branch& Branch::operator=(const Company& other)
{
	static_cast<Company&>(*this) = other;
	do {
		try {
			cout << "Введите статус филиала:" << endl;
			getline(cin, status);
			protectionAgainstIncorrectTextInput(status);
			break;
		}
		catch (const invalid_argument e) {
			cerr << "Произошла ошибка: " << e.what() << endl;
		}
		catch (const length_error e) {
			cerr << "Произошла ошибка: " << e.what() << endl;
		}
	} while (true);
	cout << "Введите количество сотрудников:" << endl;
	while (scanf("%d", &numberOfEmployees) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите количество сотрудников:\n";
	}
	return *this;
}

ostream& operator<<(ostream& os, const Branch& branch)
{
	os << setw(60) << left << branch.name + " - " + branch.status + "филиал. Кол-во сотрудников: " + to_string(branch.numberOfEmployees) << " * ";
	os << setw(47) << left << branch.citySubjectCountry << " * ";
	os << setw(17) << left << branch.turnoverPerYear << " * ";
	os << setw(13) << left << branch.netProfit << " * ";
	os << setw(32) << left << branch.industry << " * ";
	os << setw(14) << left << branch.dateOfFoundation << " *" << endl;
	os << "*****************************************************************************************************************************************************************************" << endl;
}
