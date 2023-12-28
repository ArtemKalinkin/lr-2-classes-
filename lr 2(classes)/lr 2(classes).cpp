#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <malloc.h>
#include <iostream>
#include "Company.h"
#include "City.h"
#include "Subject.h"
#include "Country.h"
#include "Сontinent.h"
#include "supportFunction.h"
#include "Container.h"
#include <memory>
#include <algorithm>

#define MAXCONTINENTS 6


void inputAllClasses(vector<Continent> &continents);
int menuOutput();
Continent& choosingContinent(vector<Continent>& continents);
void outputStm(vector<Continent> continets, int number);
int searchCompanies(Company* listPtrOfCompanies[], vector<Continent> continents);
void mergerOfCompanies(vector<Continent> &listOfContinents);
int yesOrNo(string s);
void qSort(vector<Company*> &companies, int nStart, int nEnd);
void infoActivityOfCompanies(vector<Company*> listOfCompanies);
City *cityForInfoActivityOfCompanies(vector<Continent> &continents);
void searchSomethingWithSameName(vector<Continent> listOfContinents);
void sortAnyList(vector<Continent>& continents);
void sortContinents(vector<Continent>& continents, int criteria);
void findAnyElement(vector<Continent>& continents);
void findContinent(vector<Continent>& continents);
void findCountry(vector<Continent>& continents);
void findSubject(vector<Continent>& continents);
void findCity(vector<Continent>& continents);
void findCompanyOrBranch(vector<Continent>& continents);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");
	vector<Continent> listOfContinents;
	int number;
	int i, n;
	int numberFirst, numberSecond;
	Company* listOfPtrCompanies[MAXCOMPANIES];
	vector<Country> countries;
	Country* theCountryOne;
	Country* theCountryTwo;
	Continent continent;
	inputAllClasses(listOfContinents);
	number = menuOutput();
	outputStm(listOfContinents, number);
	sortAnyList(listOfContinents);
	findAnyElement(listOfContinents);
	cout << "\n\n\n\nСРАВНЕНИЕ ДВУХ СТРАН\n" << endl;
	continent = choosingContinent(listOfContinents);
	countries = continent.getListOfCountries();
	i = 0;
	Country::countryTableHeader();
	while (i < countries.size()) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << countries.at(i);
		i++;
	}
	n = i;
	do {
		cout << "Введите номер первой страны в списке: ";
		scanf("%d", &numberFirst);
		if ((numberFirst < 1) || (numberFirst > n))
			puts("Страны с данным номером нет в списке");
	} while ((numberFirst < 1) || (numberFirst > n));
	do {
		cout << "Введите номер второй страны в списке: ";
		scanf("%d", &numberSecond);
		if ((numberSecond < 1) || (numberSecond > n))
			cout << "Страны с данным номером нет в списке" << endl;
		if (numberSecond == numberFirst)
			cout << "Данная страна уже выбрана" << endl;
	} while ((numberSecond < 1) || (numberSecond > n) || (numberSecond == numberFirst));
	try
	{
		theCountryOne = new Country();
	}
	catch (const std::exception& e)
	{
		cout << "Ошибка! Не удалось выделить память!" << endl;
		return -1;
	}
	try
	{
		theCountryTwo = new Country();
	}
	catch (const std::exception& e)
	{
		cout << "Ошибка! Не удалось выделить память!" << endl;
		return -1;
	}
	cout << "\n" << endl;
	*theCountryOne = countries[numberFirst - 1];
	*theCountryTwo = countries[numberSecond - 1];
	theCountryOne->countryTableHeader();
	cout << "* " << setw(5) << left << 1 << " * ";
	cout << *theCountryOne;
	cout << "* " << setw(5) << left << 2 << " * ";
	cout << *theCountryTwo;
	if (theCountryOne->comparisonOfTwoCountries(theCountryTwo) == 1)
		cout << "\nПо общим показателям страна - " << theCountryOne->getName() << " лучше страны - " << theCountryTwo->getName() << endl;
	else
		cout << "\nПо общим показателям страна - " << theCountryTwo->getName() << " лучше страны - " << theCountryOne->getName() << endl;
	cout << "\n\nСРАВНЕНИЕ КОМПАНИЙ" << endl;
	number = searchCompanies(listOfPtrCompanies, listOfContinents);
	if (number != 0)
		compareCompanies(listOfPtrCompanies, number);
	cout << "\n\n\n" << endl;
	return 0;
}

//Функция ввода всех списков
void inputAllClasses(vector<Continent> &continents)
{
	int i, j, k, x, z;
	int number;
	string address;
	Continent* continent = new Continent();
	Country* country = new Country();
	Subject* subject = new Subject();
	City* city = new City();
	Company* company;
	Branch* branch;
	vector<Country> countries;
	vector<Subject> subjects;
	vector<City> cities;
	vector<Company*> companies;
	i = 0;
	do {
		continent->input("континента");
		continents.push_back(*continent);
		j = 0;
		do {
			country->input("страны");
			countries.push_back(*country);
			k = 0;
			do {
				subject->input("субъекта");
				subjects.push_back(*subject);
				x = 0;
				do {
					city->input("города");
					cities.push_back(*city);
					address = countries.at(j).getName() + ", " + subjects.at(k).getName() + ", " + cities.at(x).getName();
					z = 0;
					do {
						cout << "\n\n\n1.Ввод компании" << endl;
						cout << "2.Ввод филиала компании" << endl;
						do {
							cout << "Введите номер действия: ";
							cin >> number;
							if ((number > 2) || (number < 1))
								cout << "Действия под данным номером нет" << endl;
						} while ((number > 2) || (number < 1));
						while (getchar() != '\n');
						if (number == 1) {
							company = new Company();
							company->inputCompanyFromConsole(0);
							companies.push_back(company);
							Company::incrementTotalCompanies();
						}
						else {
							branch = new Branch();
							branch->inputCompanyFromConsole(1);
							companies.push_back(branch);
						}
						try {
							companies.at(z)->setcitySubjectCountry(address);
						}
						catch (const invalid_argument e) {
							cerr << "Произошла ошибка: " << e.what() << endl;
						}
						z++;
						if (z == MAXCOMPANIES)
							cout << "Вы ввели максимальное количество компаний для одного города!" << endl;
						else {
							cout << "Для завершения ввода компаний нажмите Esc." << endl;
							cout << "Для продолжения любую другую клавишу.\n" << endl;
						}
					} while ((_getch() != 27) && (z < MAXCOMPANIES));
					cities.at(x).setListOfCompanies(companies);
					x++;
					City::incrementTotalCities();
					if (x == MAXCITIES)
						cout << "Вы ввели максимальное количество городов для одного субъекта!" << endl;
					else {
						cout << "Для завершения ввода городов нажмите Esc." << endl;
						cout << "Для продолжения любую другую клавишу.\n" << endl;
					}
				} while ((_getch() != 27) && (x < MAXCITIES));
				subjects.at(k).setListOfCities(cities);
				cities.clear();
				k++;
				Subject::incrementTotalSubjects();
				if (k == MAXSUBJECTS)
					cout << "Вы ввели максимальное количество субъектов для одной страны!" << endl;
				else {
					cout << "Для завершения ввода субъектов нажмите Esc." << endl;
					cout << "Для продолжения любую другую клавишу.\n" << endl;
				}
			} while ((_getch() != 27) && (k < MAXSUBJECTS));
			countries.at(j).setListOfSubjects(subjects);
			subjects.clear();
			countries.at(j).setNetProfitCountryFromCompanies(countries.at(j).calculatingProfitsFromCompanies(z));
			j++;
			Country::incrementTotalCountries();
			if (j == MAXCOUNTRIES)
				cout << "Вы ввели максимальное количество стан для одного континета!" << endl;
			else {
				cout << "Для завершения ввода стран нажмите Esc." << endl;
				cout << "Для продолжения любую другую клавишу.\n" << endl;
			}
		} while ((_getch() != 27) && (j < MAXCOUNTRIES));
		continents.at(i).setListOfCountries(countries);
		countries.clear();
		i++;
		Continent::incrementTotalContinents();
		if (i == MAXCONTINENTS)
			cout << "Вы ввели все существующие континеты!" << endl;
		else {
			cout << "Для завершения ввода континетов нажмите Esc." << endl;
			cout << "Для продолжения любую другую клавишу.\n" << endl;
		}
	} while ((_getch() != 27) && (i < MAXCONTINENTS));
	delete continent;
	delete country;
	delete subject;
	delete city;
}


// Функция выбора континента 
Continent& choosingContinent(vector<Continent>& continents) {
	int i, n, number;
	char character;
	Continent::continentTableHeader();
	i = 0;
	while (i < continents.size()) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << continents.at(i);
		i++;
	}
	n = i;
	cout << "\nВыберите континент\n" << endl;
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > n));
	return continents[number - 1];
}

// Функция вывода списков
void outputStm(vector<Continent> continents, int number)
{
	int i;
	vector<Country> countries;
	vector<Subject> subjects;
	vector<City> cities;
	vector<Company*> companies;
	Continent continent;
	Country country;
	Subject subject;
	City city;
	switch (number)
	{
	case 1:
		i = 0;
		Continent::continentTableHeader();
		while (i < continents.size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << continents.at(i);
			i++;
		}
		break;
	case 2:
		continent = choosingContinent(continents);
		countries = continent.getListOfCountries();
		i = 0;
		Country::countryTableHeader();
		while (i < countries.size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << countries.at(i);
			i++;
		}
		break;
	case 3:
		continent = choosingContinent(continents);
		country = continent.choosingCountry();
		subjects = country.getListOfSubjects();
		i = 0;
		Subject::subjectTableHeader();
		while (i < subjects.size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << subjects.at(i);
			i++;
		}
		break;
	case 4:
		continent = choosingContinent(continents);
		country = continent.choosingCountry();
		subject = country.choosingSubject();
		cities = subject.getListOfCities();
		i = 0;
		City::cityTableHeader();
		while (i < cities.size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << cities.at(i);
			i++;
		}
		break;
	case 5:
		continent = choosingContinent(continents);
		country = continent.choosingCountry();
		subject = country.choosingSubject();
		city = subject.choosingCity();
		companies = city.getListOfCompanies();
		i = 0;
		Company::companyTableHeader();
		while (i < companies.size()) {
			companies.at(i)->outputCompanyToConsole(i);
			i++;
		}
		break;
	default:
		break;
	}
}

int searchCompanies(Company* listPtrOfCompanies[], vector<Continent> continents)
{
	int i, j, k, x, z;
	int number;
	vector<Country> countries;
	vector<Subject> subjects;
	vector<City> cities;
	vector<Company*> companies;
	string industry;
	while (getchar() != '\n');
	do {
		cout << "Введите отрасль компаний, которые хотели бы сравнить: ";
		getline(cin, industry);
	} while (protectionAgainstIncorrectTextInput(industry));
	number = 0;
	i = 0;
	while (i < continents.size()) {
		j = 0;
		countries = continents.at(i).getListOfCountries();
		while (j < countries.size()) {
			k = 0;
			subjects = countries.at(j).getListOfSubjects();
			while (k < subjects.size()) {
				x = 0;
				cities = subjects.at(k).getListOfCities();
				while (x < cities.size()) {
					z = 0;
					companies = cities[x].getListOfCompanies();
					while (z < companies.size()) {
						if (!industry.compare(companies.at(z)->getIndustry())) {
							listPtrOfCompanies[number] = companies.at(z);
							number++;
						}
						z++;
					}
					x++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	if (number == 0)
		cout << "Не удалось найти ни одной компании данной отрасли!" << endl;
	return number;
}

void mergerOfCompanies(vector<Continent> &listOfcontinents)
{
	int i, j, k, x, z;
	int number = 0;
	int numberOne, numberTwo;
	vector<Country> countries;
	vector<Subject> subjects;
	vector<City> cities;
	vector<Company*> companies;
	Company* listPtrOfCompanies[100];
	i = 0;
	while (i < listOfcontinents.size()) {
		j = 0;
		countries = listOfcontinents.at(i).getListOfCountries();
		while (j < countries.size()) {
			k = 0;
			subjects = countries.at(j).getListOfSubjects();
			while (k < subjects.size()) {
				x = 0;
				cities = subjects.at(k).getListOfCities();
				while (x < cities.size()) {
					z = 0;
					companies = cities.at(x).getListOfCompanies();
					while (z < companies.size()) {
						listPtrOfCompanies[number] = companies.at(z);
						number++;
						z++;
					}
					x++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	Company::companyTableHeader();
	for (i = 0; i < number; i++) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << *listPtrOfCompanies[i];
	}
	do {
		cout << "Введите номер компании-покупателя: ";
		cin >> numberOne;
		if ((numberOne < 1) || (numberOne > number))
			cout << "Компании под данным номером нет в списке!" << endl;
	} while ((numberOne < 1) || (numberOne > number));
	do {
		cout << "Введите номер компании, которую покупают: ";
		cin >> numberTwo;
		if (numberTwo == numberOne)
			cout << "Данная компания выступает в роли покупателя" << endl;
		if ((numberOne < 1) || (numberOne > number))
			cout << "Компании под данным номером нет в списке!" << endl;
	} while ((numberOne < 1) || (numberOne > number) || (numberTwo == numberOne));
	*listPtrOfCompanies[numberOne - 1] = *listPtrOfCompanies[numberOne - 1] + *listPtrOfCompanies[numberTwo - 1];
}

int yesOrNo(string s)
{
	char c;
	do {
		cout << s << endl;
		c = _getch();
		if ((c != 'y') && (c != 'n')) {
			cout << "Ответы могут быть только y/n:" << endl;
			cout << "Да - y" << endl;
			cout << "Нет - n" << endl;
		}
	} while ((c != 'y') && (c != 'n'));
	if (c == 'y')
		return 1;
	else
		return 0;
}


void qSort(vector<Company*> &companies, int nStart, int nEnd)
{
	int left, right, x;
	Company* temp;
	if (nStart >= nEnd) return; 
	left = nStart; right = nEnd;
	x = companies[(left + right) / 2]->getNetProfit();
	while (left <= right) {         
		while (companies[left]->getNetProfit() < x) left++;
		while (companies[right]->getNetProfit() > x) right--;
		if (left <= right) {
			temp = companies[left];
			companies[left] = companies[right];
			companies[right] = temp;
			left++; right--;
		}
	}
	qSort(companies, nStart, right); 
	qSort(companies, left, nEnd);
}

void infoActivityOfCompanies(vector<Company*> listOfCompanies)
{
	int n, number;
	vector<Company*>::iterator it;
	do {
		int n = 0;
		Company::companyTableHeader();
		for (it = listOfCompanies.begin(); it != listOfCompanies.end(); ++it) {
			(*it)->outputCompanyToConsole(n);
			n++;
		}
		if (n == 0)
			cout << "Данный список пуст" << endl;
		else {
			do {
				cout << "\nВведите номер компании или филиала: ";
				cin >> number;
				if ((number > n) || (number < 1))
					cout << "Такого номера нет в списке!" << endl;
			} while ((number > n) || (number < 1));
			cout << endl << endl;
			listOfCompanies.at(number - 1)->callPerformActivity();
		}
		cout << "Для завершения получения информации нажмите Esc" << endl;
		cout << "Для продолжения любую другую клавишу" << endl;
	} while (_getch() != 27);
	cout << endl << endl;
	// Демострация вызова виртуальной функции через динамические объекты базового 
	// и производного классов после присваивания
	string activityOfCompany = "Компания Гул — ведущий игрок в сфере пищевой промышленности, специализирующийся на создании и производстве высококачественных пищевых продуктов. Наша миссия заключается в предоставлении потребителям вкусных и инновационных продуктов, отвечающих самым высоким стандартам качества и безопасности.";
	string activityOfBranch = "Филиал компании Гул, расположенный в регионе, специализируется на производстве эксклюзивных деликатесов и гурманских продуктов высочайшего качества. Наш фокус направлен на уникальные рецептуры и ингредиенты, чтобы удовлетворять взыскательные вкусы наших клиентов в данном регионе";
	Company* company = new Company("ООО \"Гул\"", "Россия, Алтайский край, Барнаул", 140000000, 3200000, "22.11.2008", "Пищевая промышленность", activityOfCompany);
	Branch* branch = new Branch("\"Гул\"", "Россия, Алтайский край, Бийск", 20000000, 9000000, "13.08.2014", "Пищевая промышленность", activityOfBranch, "активный", 15);
	Company* ptrCompany;
	// Указатель на объект базового класса
	cout << endl << endl;
	ptrCompany = company;
	ptrCompany->performActivity();
	// Указатель на объект производного класса
	cout << endl << endl;
	ptrCompany = branch;
	ptrCompany->performActivity();
	delete company;
	delete branch;
}

City *cityForInfoActivityOfCompanies(vector<Continent> &continents)
{
	cout << endl << endl << endl;
	cout << "ВЫБОР ГОРОДА ДЛЯ ПОЛУЧЕНИЯ ИНОФРМАЦИИ О ДЕЯТЕЛЬНОСТИ КОМПАНИЙ\\ФИЛИАЛОВ" << endl << endl;
	Continent *continent;
	Country *country;
	Subject *subject;
	City *city;
	continent = &choosingContinent(continents);
	country = &continent->choosingCountry();
	subject = &country->choosingSubject();
	city = &subject->choosingCity();
	return city;
}

void searchSomethingWithSameName(vector<Continent> listOfContinents)
{
	cout << "ПОИСК ЧЕГО-ЛИБО" << endl << endl;
	int i, j, k, z, x;
	Container<AbstractElement> container;
	Container<Company> companyContainer;
	int number, numberCompany;
	vector<Country> countries;
	vector<Subject> subjects;
	vector<City> cities;
	vector<Company*> companies;
	string searchName;
	while (getchar() != '\n');
	cout << "Поиск элементов с одинаковыми названиями" << endl << endl;
	do {
		cout << "Введите название: ";
		getline(cin, searchName);
	} while (protectionAgainstIncorrectTextInput(searchName));
	number = 0;
	numberCompany = 0;
	i = 0;
	while (i < listOfContinents.size()) {
		j = 0;
		if (!searchName.compare(listOfContinents.at(i).getName())) {
			container.addElement(&listOfContinents.at(i));
			number++;
		}
		countries = listOfContinents.at(i).getListOfCountries();
		while (j < countries.size()) {
			k = 0;
			if (!searchName.compare(countries.at(j).getName())) {
				container.addElement(&countries.at(j));
				number++;
			}
			subjects = countries.at(j).getListOfSubjects();
			while (k < subjects.size()) {
				x = 0;
				if (!searchName.compare(subjects.at(k).getName())) {
					container.addElement(&subjects.at(k));
					number++;
				}
				cities = subjects.at(k).getListOfCities();
				while (x < cities.size()) {
					z = 0;
					if (!searchName.compare(cities.at(x).getName())) {
						container.addElement(&cities.at(x));
						number++;
					}
					companies = cities.at(x).getListOfCompanies();
					while (z < companies.size()) {
						if (!searchName.compare(companies.at(z)->getName())) {
							companyContainer.addElement(companies.at(z));
							numberCompany++;
						}
						z++;
					}
					x++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	if ((number == 0) && (numberCompany == 0))
		cout << "Не удалось найти ни одной компании данной отрасли!" << endl;
	else {
		cout << "Найденные элементы" << endl;
		container.displayElements();
		companyContainer.displayElements();
	}
}

void sortAnyList(vector<Continent>& continents)
{
	cout << endl << endl << endl << "СОРТИРОВКА СПИСКОВ" << endl << endl << endl;
	int number, i;
	int criteria;
	Continent* continent;
	Country* country;
	Subject* subject;
	City* city;
	cout << "1. Список континентов" << endl;
	cout << "2. Список стран" << endl;
	cout << "3. Список субъектов" << endl;
	cout << "4. Список городов" << endl;
	cout << "5. Список компаний" << endl;
	do {
		cout << endl << "Введите номер того, что хотите отсортировать: ";
		cin >> number;
		if ((number < 1) || (number > 5))
			cout << "Действия под данным номером нет" << endl;
	} while ((number < 1) || (number > 5));
	while (getchar() != '\n');
	switch (number)
	{
	case 1:
		criteria = Continent::selectCriteria("сортировки списка");
		i = 0;
		Continent::continentTableHeader();
		while (i < continents.size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << continents.at(i);
			i++;
		}
		sortContinents(continents, criteria);
		cout << endl << "Отсортированный список континентов: " << endl << endl;
		i = 0;
		Continent::continentTableHeader();
		while (i < continents.size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << continents.at(i);
			i++;
		}
		break;
	case 2:
		continent = &choosingContinent(continents);
		i = 0;
		Country::countryTableHeader();
		while (i < continent->getListOfCountries().size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << continent->getListOfCountries().at(i);
			i++;
		}
		criteria = Country::selectCriteria("сортировки списка");
		continent->sortCountries(criteria);
		cout << endl << "Отсортированный список стран: " << endl << endl;
		i = 0;
		Country::countryTableHeader();
		while (i < continent->getListOfCountries().size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << continent->getListOfCountries().at(i);
			i++;
		}
		break;
	case 3:
		continent = &choosingContinent(continents);
		country = &continent->choosingCountry();
		i = 0;
		Subject::subjectTableHeader();
		while (i < country->getListOfSubjects().size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << country->getListOfSubjects().at(i);
			i++;
		}
		criteria = Subject::selectCriteria("сортировки списка");
		country->sortSubjects(criteria);
		cout << endl << "Отсортированный список субъектов: " << endl << endl;
		i = 0;
		Subject::subjectTableHeader();
		while (i < country->getListOfSubjects().size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << country->getListOfSubjects().at(i);
			i++;
		}
		break;
	case 4:
		continent = &choosingContinent(continents);
		country = &continent->choosingCountry();
		subject = &country->choosingSubject();
		i = 0;
		City::cityTableHeader();
		while (i < subject->getListOfCities().size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << subject->getListOfCities().at(i);
			i++;
		}
		criteria = City::selectCriteria("сортировки списка");
		subject->sortCities(criteria);
		cout << endl << "Отсортированный список городов: " << endl << endl;
		i = 0;
		City::cityTableHeader();
		while (i < subject->getListOfCities().size()) {
			cout << "* " << setw(5) << left << i + 1 << " * ";
			cout << subject->getListOfCities().at(i);
			i++;
		}
		break;
	case 5:
		continent = &choosingContinent(continents);
		country = &continent->choosingCountry();
		subject = &country->choosingSubject();
		city = &subject->choosingCity();
		i = 0;
		Company::companyTableHeader();
		while (i < city->getListOfCompanies().size()) {
			city->getListOfCompanies().at(i)->outputCompanyToConsole(i);
			i++;
		}
		criteria = Company::selectCriteria("сортировки списка");
		city->sortCompanies(criteria);
		cout << endl << "Отсортированный список компаний: " << endl << endl;
		i = 0;
		Company::companyTableHeader();
		while (i < city->getListOfCompanies().size()) {
			city->getListOfCompanies().at(i)->outputCompanyToConsole(i);
			i++;
		}
		break;
	default:
		break;
	}
}

void sortContinents(vector<Continent>& continents, int criteria)
{
	vector<Continent*> continentPointers;
	for (Continent& continent : continents) {
		continentPointers.push_back(&continent);
	}
	int number;
	cout << endl << "Спрособ упорядочивания" << endl;
	cout << "1.По убыванию" << endl;
	cout << "2.По возрастанию" << endl;
	do {
		cout << "Введите номер";
		cin >> number;
		if ((number < 1) || (number > 2))
			cout << "Введите 1 или 2" << endl;
	} while (number < 1 || (number > 2));
	if (((number == 1) && (criteria == 1)) || ((number == 2) && (criteria != 1))) {
		switch (criteria)
		{
		case 1:
			sort(continentPointers.begin(), continentPointers.end(), [](const Continent* a, const Continent* b) {
				return a->compareByField(*b, Continent::ContinentCompareField::NAME);
				});
			break;
		case 2:
			sort(continentPointers.begin(), continentPointers.end(), [](const Continent* a, const Continent* b) {
				return a->compareByField(*b, Continent::ContinentCompareField::SQUARE);
				});
			break;
		case 3:
			sort(continentPointers.begin(), continentPointers.end(), [](const Continent* a, const Continent* b) {
				return a->compareByField(*b, Continent::ContinentCompareField::POPULATION);
				});
			break;
		case 4:
			sort(continentPointers.begin(), continentPointers.end(), [](const Continent* a, const Continent* b) {
				return a->compareByField(*b, Continent::ContinentCompareField::NUMBEROFCOUNTRIES);
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
			sort(continentPointers.begin(), continentPointers.end(), [](const Continent* a, const Continent* b) {
				return b->compareByField(*a, Continent::ContinentCompareField::NAME);
				});
			break;
		case 2:
			sort(continentPointers.begin(), continentPointers.end(), [](const Continent* a, const Continent* b) {
				return b->compareByField(*a, Continent::ContinentCompareField::SQUARE);
				});
			break;
		case 3:
			sort(continentPointers.begin(), continentPointers.end(), [](const Continent* a, const Continent* b) {
				return b->compareByField(*a, Continent::ContinentCompareField::POPULATION);
				});
			break;
		case 4:
			sort(continentPointers.begin(), continentPointers.end(), [](const Continent* a, const Continent* b) {
				return b->compareByField(*a, Continent::ContinentCompareField::NUMBEROFCOUNTRIES);
				});
			break;
		default:
			break;
		}
	}
}

void findAnyElement(vector<Continent>& continents)
{
	int number;
	cout << endl << endl << "ПОИСК ЭЛЕМЕНТА" << endl << endl;
	cout << "1. Континент" << endl;
	cout << "2. Страна" << endl;
	cout << "3. Субъект" << endl;
	cout << "4. Город" << endl;
	cout << "5. Компаний" << endl;
	do {
		cout << endl << "Введите номер того, что хотите найти: ";
		cin >> number;
		if ((number < 1) || (number > 5))
			cout << "Действия под данным номером нет" << endl;
	} while ((number < 1) || (number > 5));
	while (getchar() != '\n');
	switch (number)
	{
	case 1:
		findContinent(continents);
		break;
	case 2:
		findCountry(continents);
		break;
	case 3:
		findSubject(continents);
		break;
	case 4:
		findCity(continents);
		break;
	case 5:
		findCompanyOrBranch(continents);
		break;
	default:
		break;
	}
}

void findContinent(vector<Continent>& continents)
{
	string targetName;
	vector<Continent*> continentPointers;
	for (Continent& continent : continents) {
		continentPointers.push_back(&continent);
	}
	cout << endl << endl << "ПОИСК КОНТИНЕНТА ПО НАЗВАНИЮ" << endl << endl;
	cout << "Введите название: ";
	cin >> targetName;
	vector<Continent*>::iterator it;
	it = find_if(continentPointers.begin(), continentPointers.end(), [targetName](const Continent* continent) {
		return continent->getName() == targetName;
		});
	if (it != continentPointers.end()) {
		cout << endl << "Континент найден: " << endl << endl;
		Continent::continentTableHeader();
		cout << "* " << setw(5) << left << 1 << " * ";
		cout << (*it);
	}
	else {
		cout << "Континент не найден." << endl;
	}
}

void findCountry(vector<Continent>& continents)
{
	string targetName;
	bool flag = false;
	cout << endl << endl << "ПОИСК СТРАНЫ ПО НАЗВАНИЮ" << endl << endl;
	cout << "Введите название: ";
	cin >> targetName;
	vector<Country*> countryPointers;
	for (Continent& continent : continents) {
		for (Country& country : continent.getListOfCountries()) {
			countryPointers.push_back(&country);
		}
		auto it = find_if(countryPointers.begin(), countryPointers.end(), [targetName](const Country* country) {
			return country->getName() == targetName;
			});

		if (it != countryPointers.end()) {
			cout << endl << "Страна найдена: " << endl << endl;
			Country::countryTableHeader();
			cout << "* " << setw(5) << left << 1 << " * ";
			cout << (*it);
			flag = true;
			break;
		}
	}
	if (!flag)
		cout << "Страна не найдена." << endl;
}

void findSubject(vector<Continent>& continents)
{
	string targetName;
	bool flag = false;
	cout << endl << endl << "ПОИСК СУБЪЕКТА ПО НАЗВАНИЮ" << endl << endl;
	cout << "Введите название: ";
	cin >> targetName;
	vector<Subject*> subjectPointers;
	for (Continent& continent : continents) {
		for (Country& country : continent.getListOfCountries()) {
			for (Subject& subject : country.getListOfSubjects())
				subjectPointers.push_back(&subject);
			auto it = find_if(subjectPointers.begin(), subjectPointers.end(), [targetName](const Subject* subject) {
				return subject->getName() == targetName;
				});

			if (it != subjectPointers.end()) {
				cout << endl << "Субъект найден: " << endl << endl;
				Subject::subjectTableHeader();
				cout << "* " << setw(5) << left << 1 << " * ";
				cout << (*it);
				flag = true;
				break;
			}
		}
	}
	if (!flag)
		cout << "Субъект не найден." << endl;
}

void findCity(vector<Continent>& continents)
{
	string targetName;
	bool flag = false;
	cout << endl << endl << "ПОИСК ГОРОДА ПО НАЗВАНИЮ" << endl << endl;
	cout << endl <<"Введите название: ";
	cin >> targetName;
	vector<City*> cityPointers;
	for (Continent& continent : continents) {
		for (Country& country : continent.getListOfCountries()) {
			for (Subject& subject : country.getListOfSubjects()) {
				for (City& city : subject.getListOfCities())
					cityPointers.push_back(&city);
				auto it = find_if(cityPointers.begin(), cityPointers.end(), [targetName](const City* city) {
					return city->getName() == targetName;
					});

				if (it != cityPointers.end()) {
					cout << endl << "Город найден: " << endl << endl;
					City::cityTableHeader();
					cout << "* " << setw(5) << left << 1 << " * ";
					cout << (*it);
					flag = true;
					break;
				}
			}
		}
	}
	if (!flag)
		cout << "Город не найден." << endl;
}

void findCompanyOrBranch(vector<Continent>& continents)
{
	int i;
	string targetName;
	bool flag = false;
	cout << endl << endl << "ПОИСК КОМПАНИИ ИЛИ ФИЛИАЛА ПО НАЗВАНИЮ" << endl << endl;
	cout << "Введите название: ";
	cin >> targetName;
	vector<Company*> companyPointers;
	for (Continent& continent : continents) {
		for (Country& country : continent.getListOfCountries()) {
			for (Subject& subject : country.getListOfSubjects()) {
				for (City& city : subject.getListOfCities()) {
					for (Company* company : city.getListOfCompanies())
						companyPointers.push_back(company);
					i = 0;
					auto it = find_if(companyPointers.begin(), companyPointers.end(), [targetName](const Company* company) -> bool {
						return company->getName().find(targetName) != std::string::npos;
						});
					while (it != companyPointers.end()) {
						if (!flag) {
							cout << endl << "Компании найдены: " << endl << endl;
							Company::companyTableHeader();
						}
						(*it)->outputCompanyToConsole(i);
						flag = true;

						it = find_if(++it, companyPointers.end(), [targetName](const Company* company) -> bool {
							return company->getName().find(targetName) != string::npos;
							});
						++i;
					}
				}
			}
		}
	}
	if (!flag)
		cout << "Компания не найдена." << endl;
}



void compareCompanies(Company* listPtrOfCompanies[], int number) {
	int i, count;
	int array[20];
	int numberOfCompany;
	int flag;
	int maxProfit;
	Company::companyTableHeader();
	for (i = 0; i < number; i++) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << *listPtrOfCompanies[i];
	}
	count = 0;
	do {
		flag = 0;
		do {
			cout << "Введите номер компании: ";
			cin >> numberOfCompany;
			if ((numberOfCompany < 1) || (numberOfCompany > number))
				cout << "Компании с данным номером нет в списке" << endl;
		} while ((numberOfCompany < 1) || (numberOfCompany > number));
		for (i = 0; i < count; i++) {
			if (numberOfCompany - 1 == array[i]) {
				flag = 1;
				break;
			}
		}
		if (flag) {
			cout << "Данная компания уже выбрана!" << endl;
			cout << "Для продолжения нажмите любую клавишу" << endl;
		}
		else {
			array[count] = numberOfCompany - 1;
			count++;
			if (count == number) {
				cout << "Вы выбрали все компании" << endl;
				cout << "Для продолжения нажмите любую клавишу" << endl;
			}
			else {
				cout << "Для продолжения выбора компаний нажмите любую клавишу" << endl;
				cout << "Для завершения нажмите Esc" << endl;
			}
		}
	} while ((_getch() != 27) && (count != number));
	maxProfit = listPtrOfCompanies[0]->getNetProfit();
	numberOfCompany = 0;
	for (i = 0; i < count; i++) {
		if (listPtrOfCompanies[array[i]]->getNetProfit() > maxProfit) {
			maxProfit = listPtrOfCompanies[array[i]]->getNetProfit();
			numberOfCompany = i;
		}
	}
	cout << "\n\nКомпания с наибольшим заработком в своей отрасли" << endl;
	cout << "Отрасль - " << listPtrOfCompanies[numberOfCompany]->getIndustry() << endl;
	cout << "Название - " << listPtrOfCompanies[numberOfCompany]->getName() << endl;
	cout << "Прибыль - " << listPtrOfCompanies[numberOfCompany]->getNetProfit() << endl;

}

// Меню выбора вывода
int menuOutput()
{
	char character;
	int number;
	cout << "Вывести на экран:" << endl;
	cout << "1.Все континенты" << endl;
	cout << "2.Все страны определенного континента" << endl;
	cout << "3.Все субъекты определенной страны" << endl;
	cout << "4.Все города определенного субъекта" << endl;
	cout << "5.Все компании определенного города\n\n\n" << endl;
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > 5));
	return number;
}


