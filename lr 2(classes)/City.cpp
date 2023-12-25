#include "City.h"

unsigned City::totalCities = 0;


void City::setNumberOfCompanies(int number)
{
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	numberOfCompanies = number;
}

void City::setListOfCompanies(Company *companies[])
{
	for (int i = 0; i < MAXCOMPANIES; i++)
		listOfCompanies[i] = companies[i];
}


int City::getNumberOfCompanies()
{
	return numberOfCompanies;
}

Company** City::getListOfCompanies()
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

City::City(string name, long population, int square, int number, Company *companies[]) : AbstractElement (name, population, square)
{
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	numberOfCompanies = number;
	for (int i = 0; i < MAXCOMPANIES; i++)
		listOfCompanies[i] = companies[i];
}



void City::input(string s)
{
	cout << "\nВВОД ГОРОДА\n" << endl;
	AbstractElement::input("города");
	cout << "Введите количество предприятий в городе:" << endl;
	while (scanf("%d", &numberOfCompanies) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите количество компаний в городе:\n";
	}
	while (getchar() != '\n');
}

void City::cityTableHeader()
{
	cout << "***************************************************************************************************************************" << endl;
	cout << "* Номер *       Город        * Количество предприятий * Площадь города * Население *      Список компаний и филиалов      *" << endl;
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
	cout << setw(36) << left << listOfCompanies[0]->getName() << " *" << endl;
	i = 1;
	while ((listOfCompanies[i] != nullptr) && (i < MAXCOMPANIES)) {
		cout << "*       *                    *                        *           * ";
		cout << setw(36) << left << (*listOfCompanies[i]).getName() << " *" << endl;
		i++;
	}
	cout << "***************************************************************************************************************************" << endl;
}

ostream& operator<<(ostream& os, const City& city) {
	int i;
	os << setw(18) << left << city.name << " * ";
	os << setw(22) << left << city.numberOfCompanies << " * ";
	os << setw(14) << left << city.square << " * ";
	os << setw(9) << left << city.population << " * ";
	os << setw(36) << left << city.listOfCompanies[0]->getName() << " *" << endl;
	i = 1;
	while ((city.listOfCompanies[i] != nullptr) && (i < MAXCOMPANIES)) {
		os << "*       *                    *                        *           * ";
		try {
			Branch* branchPtr = dynamic_cast<Branch*>(city.listOfCompanies[i]);
			os << setw(36) << left << city.listOfCompanies[i]->getName() + " - филиал" << " *" << endl;
		}
		catch (const bad_cast& e){
			os << setw(36) << left << city.listOfCompanies[i]->getName() << " *" << endl;
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
	cout << "Всего вы внесли в список " << totalCities << " городов" << endl;
}

void City::removeCompany(Company company)
{
	int i = 0;
	while ((!listOfCompanies[i]->getName().empty()) && (i < MAXCOMPANIES)) {
		if (listOfCompanies[i]->getName() == company.getName())
			break;
		i++;
	}
	while ((!listOfCompanies[i]->getName().empty()) && (i < MAXCOMPANIES)) {
		if (i != MAXCOMPANIES - 1)
			listOfCompanies[i] = listOfCompanies[i + 1];
		else {
			listOfCompanies[i]->setName("");
			listOfCompanies[i]->setcitySubjectCountry("");
			listOfCompanies[i]->setTurnoverPerYear(0);
			listOfCompanies[i]->setNetProfit(0);
			listOfCompanies[i]->setDateOfFoundation("");
			listOfCompanies[i]->setIndustry("");
		}

	}
}


City City::operator++(int)
{
	int i;
	City oldCity = *this;
	Company company;
	company.inputCompanyFromConsole(0);
	i = 0;
	while ((!listOfCompanies[i]->getName().empty()) && (i < MAXCOMPANIES))
		i++;
	listOfCompanies[i] = &company;
	Company::incrementTotalCompanies();
	return oldCity;
}

City& City::operator++()
{
	int i;
	Company company;
	company.inputCompanyFromConsole(0);
	i = 0;
	while ((!listOfCompanies[i]->getName().empty()) && (i < MAXCOMPANIES))
		i++;
	listOfCompanies[i] = &company;
	Company::incrementTotalCompanies();
	return *this;
}

string City::info() const
{
	return "Город: " + name + "; " + to_string(population) + "; " + to_string(square) +
		"; " + to_string(numberOfCompanies) + ".";
}

