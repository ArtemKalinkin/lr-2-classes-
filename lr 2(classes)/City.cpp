#include "City.h"

unsigned City::totalCities = 0;


void City::setNumberOfCompanies(int number)
{
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	numberOfCompanies = number;
}

void City::setListOfCompanies(vector<Company*> companies)
{
	listOfCompanies = companies;
}


int City::getNumberOfCompanies()
{
	return numberOfCompanies;
}

vector<Company*> &City::getListOfCompanies()
{
	return listOfCompanies;
}

City::City() : AbstractElement()
{
	numberOfCompanies = 0;
}

City::City(string name) : AbstractElement(name)
{
	numberOfCompanies = 0;
}

City::City(string name, long population, int square, int number, vector<Company*> companies) : AbstractElement (name, population, square)
{
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	numberOfCompanies = number;
	listOfCompanies = companies;
}



void City::input(string s)
{
	cout << "\n���� ������\n" << endl;
	AbstractElement::input("������");
	cout << "������� ���������� �������� � ������:" << endl;
	while (scanf("%d", &numberOfCompanies) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ���������� �������� � ������:\n";
	}
	while (getchar() != '\n');
}

void City::cityTableHeader()
{
	cout << "***************************************************************************************************************************" << endl;
	cout << "* ����� *       �����        *  ���������� ��������   * ������� ������ * ��������� *      ������ �������� � ��������      *" << endl;
	cout << "***************************************************************************************************************************" << endl;
}

void City::outputCityToConsole(int number)
{
	int i;
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(18) << left << name << " * ";
	cout << setw(22) << left << numberOfCompanies << " * ";
	cout << setw(14) << left << square << " * ";
	cout << setw(9) << left << population << " * ";
	cout << setw(36) << left << listOfCompanies.at(0)->getName() << " *" << endl;
	i = 1;
	while (i < listOfCompanies.size()) {
		cout << "*       *                    *                        *           * ";
		cout << setw(36) << left << listOfCompanies.at(i)->getName() << " *" << endl;
		i++;
	}
	cout << "***************************************************************************************************************************" << endl;
}

ostream& operator<<(ostream& os, const City& city) {
	int i;
	Branch* branchPtr;
	os << setw(18) << left << city.name << " * ";
	os << setw(22) << left << city.numberOfCompanies << " * ";
	os << setw(14) << left << city.square << " * ";
	os << setw(9) << left << city.population << " * ";
	os << setw(36) << left << city.listOfCompanies.at(0)->getName() << " *" << endl;
	i = 1;
	while (i < city.listOfCompanies.size()) {
		os << "*       *                    *                        *                *           * ";
		branchPtr = dynamic_cast<Branch*>(city.listOfCompanies.at(i));
		if (branchPtr) {
			os << setw(36) << left << city.listOfCompanies.at(i)->getName() + " - ������" << " *" << endl;
		}
		else {
			os << setw(36) << left << city.listOfCompanies.at(i)->getName() << " *" << endl;
		}
		i++;
	}
	os << "***************************************************************************************************************************" << endl;
	return os;
}


void City::incrementTotalCities()
{
	totalCities++;
}

void City::printTotalCities()
{
	cout << "����� �� ������ � ������ " << totalCities << " �������" << endl;
}

void City::removeCompany(Company company)
{
	vector<Company*>::iterator it;
	for(it = listOfCompanies.begin(); it != listOfCompanies.end(); ++it){
		if ((*it)->getName() == company.getName()) {
			delete* it;
			break;
		}
	}

	if (it != listOfCompanies.end()) {
		listOfCompanies.erase(it);
	}
}


City City::operator++(int)
{
	City oldCity = *this;
	Company *company = new Company();
	company->inputCompanyFromConsole(0);
	listOfCompanies.push_back(company);
	Company::incrementTotalCompanies();
	return oldCity;
}

City& City::operator++()
{
	int i;
	Company *company = new Company();
	company->inputCompanyFromConsole(0);
	listOfCompanies.push_back(company);
	Company::incrementTotalCompanies();
	return *this;
}

string City::info() const
{
	return "�����: " + name + "; " + to_string(population) + "; " + to_string(square) +
		"; " + to_string(numberOfCompanies) + ".";
}

City::City(const City& other) : listOfCompanies(other.listOfCompanies)
{
	this->name = other.name;
	this->square = other.square;
	this->population = other.population;
	this->numberOfCompanies = other.numberOfCompanies;
}

bool City::compareByField(const City& other, CityCompareField field) const
{
	switch (field)
	{
	case CityCompareField::NAME:
		return name < other.name;
	case CityCompareField::POPULATION:
		return population < other.population;
	case CityCompareField::SQUARE:
		return square < other.square;
	case CityCompareField::NUMBEROFCOMPANIES:
		return this->numberOfCompanies < other.numberOfCompanies;
	default:
		return false;
	}
}

int City::selectCriteria(string s)
{
	cout << "�������� �������� " << s << " �������: " << endl;
	int number;
	cout << "1.��������" << endl;
	cout << "2.�������" << endl;
	cout << "3.���������" << endl;
	cout << "4.���������� ��������" << endl;
	do {
		cout << "������� �����: ";
		cin >> number;
		if ((number < 1) || (number > 4))
			cout << "�������� � ������ ������� ���" << endl;
	} while ((number < 1) || (number > 4));
	return number;
}

void City::sortCompanies(int criteria)
{
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
	if (((number == 1) && ((criteria == 1)||(criteria == 6))) || ((number == 2) && (criteria != 1) && (criteria != 6))) {
		switch (criteria)
		{
		case 1:
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return a->compareByField(*b, Company::CompanyCompareField::NAME);
				});
			break;
		case 2:
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return a->compareByField(*b, Company::CompanyCompareField::ADDRESS);
				});
			break;
		case 3:
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return a->compareByField(*b, Company::CompanyCompareField::NETPROFIT);
				});
			break;
		case 4:
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return a->compareByField(*b, Company::CompanyCompareField::NETPROFIT);
				});
			break;
		case 5:
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return a->compareByField(*b, Company::CompanyCompareField::DATE);
				});
			break;
		case 6:
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return a->compareByField(*b, Company::CompanyCompareField::INDUSTRY);
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
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return b->compareByField(*a, Company::CompanyCompareField::NAME);
				});
			break;
		case 2:
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return b->compareByField(*a, Company::CompanyCompareField::ADDRESS);
				});
			break;
		case 3:
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return b->compareByField(*a, Company::CompanyCompareField::TURNOVER);
				});
			break;
		case 4:
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return b->compareByField(*a, Company::CompanyCompareField::NETPROFIT);
				});
			break;
		case 5:
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return b->compareByField(*a, Company::CompanyCompareField::DATE);
				});
			break;
		case 6:
			sort(listOfCompanies.begin(), listOfCompanies.end(), [](const Company* a, const Company* b) {
				return b->compareByField(*a, Company::CompanyCompareField::INDUSTRY);
				});
			break;
		default:
			break;
		}
	}
}

