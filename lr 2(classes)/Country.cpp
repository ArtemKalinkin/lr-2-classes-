#include "Country.h"


void Country::setNameOfCountry(char* name)
{
	nameOfCountry = new char(strlen(name));
	strcpy(nameOfCountry, name);
}

void Country::setNumberOfSubjects(int number)
{
	numberOfSubjects = number;
}

void Country::setNetProfitCountryEnterprises(unsigned long profit)
{
	netProfitCountryEnterprises = profit;
}

void Country::setPopulationOfCountry(int population)
{
	populationOfCountry = population;
}

void Country::setSquareOfCountry(int square)
{
	squareOfCountry = square;
}

void Country::setIncomeOfCountry(unsigned long income)
{
	incomeOfCountry = income;
	budgetDeficitOrSurplusOfCountry = incomeOfCountry - expensesOfCountry;
}

void Country::setExpensesOfCountry(unsigned long expenses)
{
	expensesOfCountry = expenses;
	budgetDeficitOrSurplusOfCountry = incomeOfCountry - expensesOfCountry;
}

void Country::setListOfSubjects(Subject subjects[])
{
	for (int i = 0; i < MAXSUBJECTS; i++)
	{
		listOfSubjects[i] = subjects[i];
	}
}

char* Country::getNameOfCountry()
{
	return nameOfCountry;
}

int Country::getNumberOfSubjects()
{
	return numberOfSubjects;
}

unsigned long Country::getNetProfitCountryEnterprises()
{
	return netProfitCountryEnterprises;
}

int Country::getPopulationOfCountry()
{
	return populationOfCountry;
}

int Country::getSquareOfCountry()
{
	return squareOfCountry;
}

unsigned long Country::getIncomeOfCountry()
{
	return incomeOfCountry;
}

unsigned long Country::getExpensesOfCountry()
{
	return expensesOfCountry;
}

long Country::getBudgetDeficitOrSurplusOfCountry()
{
	return budgetDeficitOrSurplusOfCountry;
}

Subject* Country::getListOfSubjects()
{
	return listOfSubjects;
}

Country::Country()
{
	nameOfCountry = NULL;
	numberOfSubjects = 0;
	netProfitCountryEnterprises = 0;
	populationOfCountry = 0;
	squareOfCountry = 0;
	incomeOfCountry = 0;
	expensesOfCountry = 0;
	budgetDeficitOrSurplusOfCountry = 0;
}

Country::Country(char* name)
{
	nameOfCountry = new char(strlen(name));
	strcpy(nameOfCountry, name);
	numberOfSubjects = 0;
	netProfitCountryEnterprises = 0;
	populationOfCountry = 0;
	squareOfCountry = 0;
	incomeOfCountry = 0;
	expensesOfCountry = 0;
	budgetDeficitOrSurplusOfCountry = 0;
}


Country::Country(char* name, int number, int population, int square, unsigned long income, unsigned long expenses, Subject subjects[])
{
	nameOfCountry = new char(strlen(name));
	strcpy(nameOfCountry, name);
	numberOfSubjects = number;
	netProfitCountryEnterprises = calculatingProfitsFromEnterprises();
	populationOfCountry = population;
	squareOfCountry = square;
	incomeOfCountry = income;
	expensesOfCountry = expenses;
	budgetDeficitOrSurplusOfCountry = income - expenses;
	for (int i = 0; i < MAXSUBJECTS; i++)
	{
		listOfSubjects[i] = subjects[i];
	}
}




int Country::calculatingProfitsFromEnterprises()
{
	int i, j, k;
	int numberOfProfit = 0;
	City* city;
	Enterprise* enterprise;
	for (i = 0; i < MAXSUBJECTS; i++) {
		city = listOfSubjects[i].getListOfCities();
		for (j = 0; j < MAXCITIES; j++) {
			enterprise = city[j].getListOfEnterprises();
			for (k = 0; k < MAXENTERPRISES; k++) {
				numberOfProfit += enterprise[k].getNetProfitOfEnterprise();
			}
		}
	}
	return numberOfProfit;
}

void Country::inputCountryFromConsole()
{
	nameOfCountry = new char[LENNAME];
	puts("\nВВОД СТРАНЫ\n");
	do {
		puts("Введите название страны:");
		fgets(nameOfCountry, LENNAME, stdin);
	} while (protectionAgainstIncorrectTextInput(nameOfCountry));
	deletingNewlineTransitionCharacter(nameOfCountry);
	puts("Введите население страны:");
	while (scanf("%d", &populationOfCountry) != 1) {
		while (getchar() != '\n');
		printf("\nОшибка ввода!\nВведите население страны:\n");
	}
	puts("Введите количество субъектов в стране:");
	while (scanf("%d", &numberOfSubjects) != 1) {
		while (getchar() != '\n');
		printf("\nОшибка ввода!\nВведите количество субъектов в стране:\n");
	}
	puts("Введите площадь страны:");
	while (scanf("%d", &squareOfCountry) != 1) {
		while (getchar() != '\n');
		printf("\nОшибка ввода!\nВведите площадь страны:\n");
	}
	puts("Введите доход страны:");
	while (scanf("%d", &incomeOfCountry) != 1) {
		while (getchar() != '\n');
		printf("\nОшибка ввода!\nВведите доход страны:\n");
	}
	puts("Введите расходы страны:");
	while (scanf("%d", &expensesOfCountry) != 1) {
		while (getchar() != '\n');
		printf("\nОшибка ввода!\nВведите расходы страны:\n");
	}
	while (getchar() != '\n');
	budgetDeficitOrSurplusOfCountry = incomeOfCountry - expensesOfCountry;
}

void Country::countryTableHeader()
{
	printf("**************************************************************************************************************************************************************************************************\n");
	printf("* Номер *       Страна       * Количество субъектов * Площадь страны * Население * Прибыль предприятий *     Доходы     *     Расходы     * Профицит/дефицит бюджета *      Список субъектов     *\n");
	printf("**************************************************************************************************************************************************************************************************\n");
}

void Country::outputCountryToConsole(int number)
{
	int i;
	printf("* %-5d * %-18s * %-20d * %-14d * ", number + 1, nameOfCountry, numberOfSubjects, squareOfCountry);
	printf("%-9d * %-19d * %-14lu * ", populationOfCountry, netProfitCountryEnterprises, incomeOfCountry);
	printf("%-15lu * %-24ld * ", expensesOfCountry, budgetDeficitOrSurplusOfCountry);
	printf("%-25s *\n", listOfSubjects[0].getNameOfSubject());
	i = 1;
	while ((listOfSubjects[i].getNameOfSubject() != NULL) && (i < MAXSUBJECTS)) {
		printf("*       *                    *                      *                *           *                     *                *                 *                          * %-25s *\n", listOfSubjects[i].getNameOfSubject());
		i++;
	}
	printf("**************************************************************************************************************************************************************************************************\n");
}

int Country::choosingSubject()
{
	int i, n, number;
	char character;
	listOfSubjects[0].subjectTableHeader();
	i = 0;
	while (listOfSubjects[i].getNameOfSubject() != NULL) {
		listOfSubjects[i].outputSubjectToConsole(i);
		i++;
	}
	n = i + 1;
	puts("\nВыберите субъект\n");
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > n));
	return number - 1;
}

int Country::comparisonOfTwoCountries(Country* secondCountry)
{
	int percentageOfSquare;
	int percentageOfPopulation;
	int percentageOfProfits;
	int percentageOfIncome;
	int percentageOfExpenses;
	int numberOne = 0, numberTwo = 0;
	int value;
	puts("\nПроцентное соотношение характеристик стран");
	printf("%s     %s\n", nameOfCountry, secondCountry->nameOfCountry);
	// Площадь
	if (squareOfCountry > secondCountry->squareOfCountry) {
		percentageOfSquare = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(squareOfCountry, secondCountry->squareOfCountry);
		printf("Площадь страны - %s больше площади страны - %s на %d %%\n", nameOfCountry, secondCountry->nameOfCountry, percentageOfSquare);
		numberOne++;
	}
	else if (squareOfCountry < secondCountry->squareOfCountry) {
		percentageOfSquare = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->squareOfCountry, squareOfCountry);
		printf("Площадь страны - %s больше площади страны - %s на %d %%\n", secondCountry->nameOfCountry, nameOfCountry, percentageOfSquare);
		numberTwo++;
	}
	else
		printf("Площади стран равны\n");
	// Население
	if (populationOfCountry > secondCountry->populationOfCountry) {
		percentageOfPopulation = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(populationOfCountry, secondCountry->populationOfCountry);
		printf("Населeние страны - %s больше населения страны - %s на %d %%\n", nameOfCountry, secondCountry->nameOfCountry, percentageOfPopulation);
		numberOne++;
	}
	else  if (populationOfCountry < secondCountry->populationOfCountry) {
		percentageOfPopulation = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->populationOfCountry, populationOfCountry);
		printf("Населeние страны - %s больше населения страны - %s на %d %%\n", secondCountry->nameOfCountry, nameOfCountry, percentageOfPopulation);
		numberTwo++;
	}
	else
		printf("Население стран равно");
	//Прибыль предприятий 
	if (netProfitCountryEnterprises > secondCountry->netProfitCountryEnterprises) {
		percentageOfProfits = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(netProfitCountryEnterprises, secondCountry->netProfitCountryEnterprises);
		printf("Прибыль предприятий страны - %s больше прибыли предприятий страны - %s на %d %%\n", nameOfCountry, secondCountry->nameOfCountry, percentageOfProfits);
		numberOne++;
	}
	else if (netProfitCountryEnterprises < secondCountry->netProfitCountryEnterprises) {
		percentageOfProfits = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->netProfitCountryEnterprises, netProfitCountryEnterprises);
		printf("Прибыль предприятий страны - %s больше прибыли предприятий страны - %s на %d %%\n", secondCountry->nameOfCountry, nameOfCountry, percentageOfProfits);
		numberTwo++;
	}
	else printf("Прибыли предприятий стран равны\n");
	// Доходы
	if (incomeOfCountry > secondCountry->incomeOfCountry) {
		percentageOfIncome = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(incomeOfCountry, secondCountry->incomeOfCountry);
		printf("Доходы страны - %s больше доходов страны - %s на %d %%\n", nameOfCountry, secondCountry->nameOfCountry, percentageOfIncome);
		numberOne++;
	}
	else if (incomeOfCountry < secondCountry->incomeOfCountry) {
		percentageOfIncome = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->incomeOfCountry, incomeOfCountry);
		printf("Доходы страны - %s больше доходов страны - %s на %d %%\n", secondCountry->nameOfCountry, nameOfCountry, percentageOfIncome);
		numberTwo++;
	}
	else
		printf("Доходы стран равны\n");
	// Расходы
	if (expensesOfCountry > secondCountry->expensesOfCountry) {
		percentageOfExpenses = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(expensesOfCountry, secondCountry->expensesOfCountry);
		printf("Расходы страны - %s больше доходов страны - %s на %d %%\n", nameOfCountry, secondCountry->nameOfCountry, percentageOfExpenses);
	}
	else if (expensesOfCountry < secondCountry->expensesOfCountry) {
		percentageOfExpenses = calculatingByHowManyPercentFirstNumberIsGreaterThanSecond(secondCountry->expensesOfCountry, expensesOfCountry);
		printf("Расходы страны - %s больше расходов страны - %s на %d %%\n", secondCountry->nameOfCountry, nameOfCountry, percentageOfExpenses);
	}
	else
		printf("Расходы стран равны\n");
	if (numberOne > numberTwo)
		value = 1;
	else
		value = 2;
	return value;
}
