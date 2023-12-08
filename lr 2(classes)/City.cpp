#include "City.h"

unsigned City::totalCities = 0;

void City::setName(string name)
{
	if (name.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->name = name;
}

void City::setPopulation(int population)
{
	if (population < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->population = population;
}

void City::setNumberOfCompanies(int number)
{
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	numberOfCompanies = number;
}

void City::setListOfCompanies(Company companies[])
{
	for (int i = 0; i < MAXCOMPANIES; i++)
		listOfCompanies[i] = companies[i];
}

string City::getName()
{
	return name;
}

int City::getPopulation()
{
	return population;
}

int City::getNumberOfCompanies()
{
	return numberOfCompanies;
}

Company* City::getListOfCompanies()
{
	return listOfCompanies;
}

City::City()
{
	population = 0;
	numberOfCompanies = 0;
}

City::City(string name)
{
	if (name.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->name = name;
	population = 0;
	numberOfCompanies = 0;
}

City::City(string name, int population, int number, Company companies[])
{
	if (name.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->name = name;
	if (population < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->population = population;
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	numberOfCompanies = number;
	for (int i = 0; i < MAXCOMPANIES; i++)
		listOfCompanies[i] = companies[i];
}



void City::inputCityFromConsole()
{
	cout << "\nВВОД ГОРОДА\n" << endl;
	do {
		try {
			cout << "Введите название города:" << endl;
			getline(cin, name);
			protectionAgainstIncorrectTextInput(name);
			break;
		}
		catch (const invalid_argument e) {
			cerr << "Произошла ошибка: " << e.what() << endl;
		}
		catch (const length_error e) {
			cerr << "Произошла ошибка: " << e.what() << endl;
		}
	} while (true);
	cout << "Введите население города:" << endl;
	while (scanf("%d", &population) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите население города:\n";
	}
	cout << "Введите количество предприятий в городе:" << endl;
	while (scanf("%d", &numberOfCompanies) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите количество компаний в городе:\n";
	}
	while (getchar() != '\n');
}

void City::cityTableHeader()
{
	cout << "**********************************************************************************************************" << endl;
	cout << "* Номер *       Город        * Количество предприятий * Население *           Список компаний            *" << endl;
	cout << "**********************************************************************************************************" << endl;
}

void City::outputCityToConsole(int number)
{
	int i;
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(18) << left << name << " * ";
	cout << setw(22) << left << numberOfCompanies << " * ";
	cout << setw(9) << left << population << " * ";
	cout << setw(36) << left << listOfCompanies[0].getName() << " *" << endl;
	i = 1;
	while ((!listOfCompanies[i].getName().empty()) && (i < MAXCOMPANIES)) {
		cout << "*       *                    *                        *           * ";
		cout << setw(36) << left << listOfCompanies[i].getName() << " *" << endl;
		i++;
	}
	printf("**********************************************************************************************************\n");
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
	while ((!listOfCompanies[i].getName().empty()) && (i < MAXCOMPANIES)) {
		if (listOfCompanies[i].getName() == company.getName())
			break;
		i++;
	}
	while ((!listOfCompanies[i].getName().empty()) && (i < MAXCOMPANIES)) {
		if (i != MAXCOMPANIES - 1)
			listOfCompanies[i] = listOfCompanies[i + 1];
		else {
			listOfCompanies[i].setName("");
			listOfCompanies[i].setcitySubjectCountry("");
			listOfCompanies[i].setTurnoverPerYear(0);
			listOfCompanies[i].setNetProfit(0);
			listOfCompanies[i].setDateOfFoundation("");
			listOfCompanies[i].setIndustry("");
		}

	}
}


City City::operator++(int)
{
	int i;
	City oldCity = *this;
	Company company;
	company.inputCompanyFromConsole();
	i = 0;
	while ((!listOfCompanies[i].getName().empty()) && (i < MAXCOMPANIES))
		i++;
	listOfCompanies[i] = company;
	Company::incrementTotalCompanies();
	return oldCity;
}

City& City::operator++()
{
	int i;
	Company company;
	company.inputCompanyFromConsole();
	i = 0;
	while ((!listOfCompanies[i].getName().empty()) && (i < MAXCOMPANIES))
		i++;
	listOfCompanies[i] = company;
	Company::incrementTotalCompanies();
	return *this;
}

