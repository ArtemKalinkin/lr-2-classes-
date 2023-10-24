#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
#include "Enterprise.h"
#include "City.h"
#include "Subject.h"
#include "Country.h"
#include "Сontinent.h"
#include "supportFunction.h"

#define MAXCONTINENTS 6

void inputAllClasses(Сontinent continents[]);
int menuOutput();
int choosingContinent(Сontinent continents[]);
void outputStm(Сontinent *continets, int number);


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Rus");
    int number;
    int i, n;
    int numberOfContinent;
    int numberFirst, numberSecond;
    char name[LENNAME];
    char address[LENNAME * 3];
    char industry[50];
    char date[20];
    Сontinent listOfContinents[6];
    Country* countries;
    Country* theCountryOne;
    Country* theCountryTwo;
    Сontinent* theContinent;
    inputAllClasses(listOfContinents);
    number = menuOutput();
    outputStm(listOfContinents, number);
    // Выполнение прикладных задач
    puts("\n\n\n\nСРАВНЕНИЕ ДВУХ СТРАН\n");
    numberOfContinent = choosingContinent(listOfContinents);
    countries = listOfContinents[numberOfContinent].getListOfCountries();
    i = 0;
    countries[0].countryTableHeader();
    while ((countries[i].getNameOfCountry() != NULL) && (i < MAXCOUNTRIES)) {
        countries[i].outputCountryToConsole(i);
        i++;
    }
    n = i;
    do {
        printf("Введите номер первой страны в списке: ");
        scanf("%d", &numberFirst);
        if ((numberFirst < 1) || (numberFirst > n))
            puts("Страны с данным номером нет в списке");
    } while ((numberFirst < 1) || (numberFirst > n));
    do {
        printf("Введите номер второй страны в списке: ");
        scanf("%d", &numberSecond);
        if ((numberSecond < 1) || (numberSecond > n))
            puts("Страны с данным номером нет в списке");
        if (numberSecond == numberFirst)
            puts("Данная страна уже выбрана");
    } while ((numberSecond < 1) || (numberSecond > n) || (numberSecond == numberFirst));
    try
    {
    theCountryOne = new Country();
    }
    catch (const std::exception& e)
    {
        puts("Ошибка! Не удалось выделить память!");
        return -1;
    }
    try
    {
    theCountryTwo = new Country();
    }
    catch (const std::exception& e)
    {
        puts("Ошибка! Не удалось выделить память!");
        return -1;
    }
    puts("\n");
    *theCountryOne = countries[numberFirst - 1];
    *theCountryTwo = countries[numberSecond - 1];
    theCountryOne->countryTableHeader();
    theCountryOne->outputCountryToConsole(0);
    theCountryTwo->outputCountryToConsole(1);
    if (theCountryOne->comparisonOfTwoCountries(theCountryTwo) == 1)
        printf("\nПо общим показателям страна - %s лучше страны - %s\n", theCountryOne->getNameOfCountry(), theCountryTwo->getNameOfCountry());
    else
        printf("\nПо общим показателям страна - %s лучше страны - %s\n", theCountryTwo->getNameOfCountry(), theCountryOne->getNameOfCountry());
    theContinent = new Сontinent();
    if (theContinent == NULL) {
        puts("Ошибка при выделение памяти!");
        return -2;
    }
    *theContinent = listOfContinents[0];
    i = 0;
    while ((listOfContinents[i].getNameOfContinent() != NULL) && (i < MAXCONTINENTS)) {
        if (listOfContinents[i].getNumberOfCountries() > theContinent->getNumberOfCountries())
            *theContinent = listOfContinents[i];
        i++;
    }
    printf("\nКонтинент с наибольшим количество стран - %s\n\n", theContinent->getNameOfContinent());

    // Демострация работы с динамическими массивами объектов 
    // и массивом динамических объектов

    // Динамические массивы объектов
    Subject* subjects;
    City* cities;
    Enterprise* enterprises;
    strcpy(name, "ООО Рысь");
    strcpy(address, "Россия, Приморский край, Уссурийск");
    strcpy(date, "12.12.2012");
    strcpy(industry, "Пищевая промышленность");
    try
    {
        enterprises = new Enterprise[4];
    }
    catch (const std::exception& e)
    {
        puts("Ошибка! Не удалось выделить память!");
        return -1;
    }
    strcpy(name, "ООО Рысь");
    strcpy(address, "Россия, Приморский край, Уссурийск");
    strcpy(date, "12.12.2012");
    strcpy(industry, "Пищевая промышленность");
    *enterprises = Enterprise(name, address, 1000000, 120000, date, industry);
    strcpy(name, "ООО Свобода");
    strcpy(address, "Россия, Приморский край, Уссурийск");
    strcpy(date, "29.04.2007");
    strcpy(industry, "Строительная промышленность");
    *(enterprises + 1) = Enterprise(name, address, 120000000, 30000000, date, industry);
    strcpy(name, "ООО Связь");
    strcpy(address, "Россия, Приморский край, Уссурийск");
    strcpy(date, "30.09.2002");
    strcpy(industry, "Химическая промышленность");
    *(enterprises + 2) = Enterprise(name, address, 14000000, 400000, date, industry);
    enterprises->enterpriseTableHeader();
    for (i = 0; i < 3; i++)
        (enterprises + i)->outputEnterpriseToConsole(i);
    try
    {
    cities = new City[6];
    }
    catch (const std::exception& e)
    {
        puts("Ошибка! Не удалось выделить память!");
        return -1;
    }
    strcpy(name, "Уссурийск");
    *cities = City(name, 300000, 13, enterprises);
    puts("\n\n");
    cities->cityTableHeader();
    cities->outputCityToConsole(0);
    try
    {
    subjects = new Subject[5];
    }
    catch (const std::exception& e)
    {
        puts("Ошибка! Не удалось выделить память!");
        return -1;
    }
    strcpy(name, "Приморский край");
    *subjects = Subject(name, 12, 1900000, 164673, cities);
    puts("\n\n");
    subjects->subjectTableHeader();
    subjects->outputSubjectToConsole(0);
    delete[] enterprises;
    delete[] cities;
    delete[] subjects;

    // Массивы динамических объектов 
    Enterprise* listOfPtrEnterprises[MAXENTERPRISES];
    City* listOfPtrCities[MAXCITIES];
    Subject* listOfPtrSubjects[MAXSUBJECTS];
    for (i = 0; i < MAXENTERPRISES; i++)
        listOfPtrEnterprises[i] = new Enterprise();
    for (i = 0; i < MAXCITIES; i++)
        listOfPtrCities[i] = new City();
    for (i = 0; i < MAXSUBJECTS; i++)
        listOfPtrSubjects[i] = new Subject();
    strcpy(name, "ООО Литий");
    strcpy(address, "Россия, Камчатский край, Вилючинск");
    strcpy(date, "17.03.1999");
    strcpy(industry, "Металлургия");
    listOfPtrEnterprises[0]->setNameOfEnterprise(name);
    listOfPtrEnterprises[0]->setcitySubjectCountry(address);
    listOfPtrEnterprises[0]->setTurnoverPerYear(200000000);
    listOfPtrEnterprises[0]->setNetProfitOfEnterprise(4300000);
    listOfPtrEnterprises[0]->setDateOfFoundationEnterprise(date);
    listOfPtrEnterprises[0]->setIndustryOfEnterprise(industry);
    strcpy(name, "Вилючинск");
    listOfPtrCities[0]->setNameOfCity(name);
    listOfPtrCities[0]->setPopulationOfCity(90000);
    listOfPtrCities[0]->setNumberOfEnterprises(9);
    listOfPtrCities[0]->setListOfEnterprises(listOfPtrEnterprises[0]);
    strcpy(name, "Камчатский край");
    listOfPtrSubjects[0]->setNameOfSubject(name);
    listOfPtrSubjects[0]->setNumberOfCities(5);
    listOfPtrSubjects[0]->setPopulationOfSubject(329315);
    listOfPtrSubjects[0]->setSquareOfSubject(464275);
    listOfPtrSubjects[0]->setListOfCities(listOfPtrCities[0]);
    for (i = 0; i < MAXENTERPRISES; i++)
        delete listOfPtrEnterprises[i];
    for (i = 0; i < MAXCITIES; i++)
        delete listOfPtrCities[i];
    for (i = 0; i < MAXSUBJECTS; i++)
        delete listOfPtrSubjects[i];
    return 0;
}

//Функция ввода всех списков
void inputAllClasses(Сontinent continents[])
{
    int i, j, k, x, z;
    char address[LENNAME * 3];
    Country* countries;
    Subject* subjects;
    City* cities;
    Enterprise* enterprises;
    i = 0;
    do {
        continents[i].inputСontinentFromConsole();
        countries = continents[i].getListOfCountries();
        j = 0;
        do {
            countries[j].inputCountryFromConsole();
            subjects = countries[j].getListOfSubjects();
            k = 0;
            do {
                subjects[k].inputSubjectFromConsole();
                cities = subjects[k].getListOfCities();
                x = 0;
                do {
                    cities[x].inputCityFromConsole();
                    enterprises = cities[x].getListOfEnterprises();
                    strcpy(address, countries[j].getNameOfCountry());
                    strcat(address, ", ");
                    strcat(address, subjects[k].getNameOfSubject());
                    strcat(address, ", ");
                    strcat(address, cities[x].getNameOfCity());
                    z = 0;
                    do {
                        enterprises[z].inputEnterpriseFromConsole();
                        enterprises[z].setcitySubjectCountry(address);
                        z++;
                        if (z == MAXENTERPRISES)
                            puts("Вы ввели максимальное количество предприятий для одного города!");
                        else {
                            puts("Для завершения ввода предприятий нажмите Esc.");
                            puts("Для продолжения любую другую клавишу.\n");
                        }
                    } while ((_getch() != 27) && (z < MAXENTERPRISES));
                    x++;
                    if (x == MAXCITIES)
                        puts("Вы ввели максимальное количество городов для одного субъекта!");
                    else {
                        puts("Для завершения ввода городов нажмите Esc.");
                        puts("Для продолжения любую другую клавишу.\n");
                    }
                } while ((_getch() != 27) && (x < MAXCITIES));
                k++;
                if (k == MAXSUBJECTS)
                    puts("Вы ввели максимальное количество субъектов для одной страны!");
                else {
                    puts("Для завершения ввода субъектов нажмите Esc.");
                    puts("Для продолжения любую другую клавишу.\n");
                }
            } while ((_getch() != 27) && (k < MAXSUBJECTS));
            countries[j].calculatingProfitsFromEnterprises();
            j++;
            if (j == MAXCOUNTRIES)
                puts("Вы ввели максимальное количество стан для одного континета!");
            else {
                puts("Для завершения ввода стран нажмите Esc.");
                puts("Для продолжения любую другую клавишу.\n");
            }
        } while ((_getch() != 27) && (j < MAXCOUNTRIES));
        i++;
        if (i == MAXCONTINENTS)
            puts("Вы ввели все существующие континеты!");
        else {
            puts("Для завершения ввода континетов нажмите Esc.");
            puts("Для продолжения любую другую клавишу.\n");
        }
    } while ((_getch() != 27) && (i < MAXCONTINENTS));
}


// Функция выбора континента 
int choosingContinent(Сontinent continents[]) {
    int i, n, number;
    char character;
    continents[0].continentTableHeader();
    i = 0;
    while ((continents[i].getNameOfContinent() != NULL) && (i < MAXCONTINENTS)) {
        continents[i].outputContinentToConsole(i);
        i++;
    }
    n = i;
    puts("\nВыберите континент\n");
    do {
        character = _getch();
        number = character - '0';
    } while ((number < 1) || (number > n));
    return number - 1;
}

// Функция вывода списков
void outputStm(Сontinent *continets, int number)
{
    int numberOfContinent;
    int numberOfCountry;
    int numberOfSubject;
    int numberOfCity;
    int numberOfEnterprise;
    int i;
    Country* countries;
    Subject* subjects;
    City* cities;
    Enterprise* enterprises;
    switch (number)
    {
    case 1:
        i = 0;
        continets[0].continentTableHeader();
        while ((continets[i].getNameOfContinent() != NULL) && (i < MAXCONTINENTS)) {
            continets[i].outputContinentToConsole(i);
            i++;
        }
        break;
    case 2:
        numberOfContinent = choosingContinent(continets);
        countries = continets[numberOfContinent].getListOfCountries();
        i = 0;
        countries[0].countryTableHeader();
        while ((countries[i].getNameOfCountry() != NULL) && (i < MAXCOUNTRIES)) {
            countries[i].outputCountryToConsole(i);
            i++;
        }
        break;
    case 3:
        numberOfContinent = choosingContinent(continets);
        countries = continets[numberOfContinent].getListOfCountries();
        numberOfCountry = continets[numberOfContinent].choosingCountry();
        subjects = countries[numberOfCountry].getListOfSubjects();
        i = 0;
        subjects[0].subjectTableHeader();
        while ((subjects[i].getNameOfSubject() != NULL) && (i < MAXSUBJECTS)) {
            subjects[i].outputSubjectToConsole(i);
            i++;
        }
        break;
    case 4:
        numberOfContinent = choosingContinent(continets);
        countries = continets[numberOfContinent].getListOfCountries();
        numberOfCountry = continets[numberOfContinent].choosingCountry();
        subjects = countries[numberOfCountry].getListOfSubjects();
        numberOfSubject = countries[numberOfCountry].choosingSubject();
        cities = subjects[numberOfSubject].getListOfCities();
        i = 0;
        cities[0].cityTableHeader();
        while ((cities[i].getNameOfCity() != NULL) && (i < MAXCITIES)) {
            cities[i].outputCityToConsole(i);
            i++;
        }
        break;
    case 5:
        numberOfContinent = choosingContinent(continets);
        countries = continets[numberOfContinent].getListOfCountries();
        numberOfCountry = continets[numberOfContinent].choosingCountry();
        subjects = countries[numberOfCountry].getListOfSubjects();
        numberOfSubject = countries[numberOfCountry].choosingSubject();
        cities = subjects[numberOfSubject].getListOfCities();
        numberOfCity = subjects[numberOfSubject].choosingCity();
        enterprises = cities[numberOfCity].getListOfEnterprises();
        i = 0;
        enterprises[0].enterpriseTableHeader();
        while ((enterprises[i].getNameOfEnterprise() != NULL) && (i < MAXENTERPRISES)) {
            enterprises[i].outputEnterpriseToConsole(i);
            i++;
        }
        break;
    default:
        break;
    }
}

// Меню выбора вывода
int menuOutput()
{
    char character;
    int number;
    puts("Вывести на экран:");
    puts("1.Все континенты");
    puts("2.Все страны определенного континента");
    puts("3.Все субъекты определенной страны");
    puts("4.Все города определенного субъекта");
    puts("5.Все предприятия определенного города");
    do {
        character = _getch();
        number = character - '0';
    } while ((number < 1) || (number > 5));
    return number;
}
