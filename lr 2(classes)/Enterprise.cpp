#include "Enterprise.h"


void Enterprise::setNameOfEnterprise(char* name)
{
	nameOfEnterprise = new char[strlen(name)];
	strcpy(nameOfEnterprise, name);
}

void Enterprise::setcitySubjectCountry(char* address)
{
	citySubjectCountry = new char[strlen(address)];
	strcpy(citySubjectCountry, address);
}

void Enterprise::setTurnoverPerYear(unsigned long turnover)
{
	turnoverPerYear = turnover;
}

void Enterprise::setNetProfitOfEnterprise(long profit)
{
	netProfitOfEnterprise = profit;
}

void Enterprise::setDateOfFoundationEnterprise(char* date)
{
	dateOfFoundationEnterprise = new char[strlen(date)];
	strcpy(dateOfFoundationEnterprise, date);
}

void Enterprise::setIndustryOfEnterprise(char* industry)
{
	industryOfEnterprise = new char[strlen(industry)];
	strcpy(industryOfEnterprise, industry);
}

char* Enterprise::getNameOfEnterprise()
{
	return nameOfEnterprise;
}

char* Enterprise::getcitySubjectCountry()
{
	return citySubjectCountry;
}

unsigned long Enterprise::getTurnoverPerYear()
{
	return turnoverPerYear;
}

long Enterprise::getNetProfitOfEnterprise()
{
	return netProfitOfEnterprise;
}

char* Enterprise::getDateOfFoundationEnterprise()
{
	return dateOfFoundationEnterprise;
}

char* Enterprise::getIndustryOfEnterprise()
{
	return industryOfEnterprise;
}

Enterprise::Enterprise()
{
	nameOfEnterprise = NULL;
	citySubjectCountry = NULL;
	turnoverPerYear = 0;
	netProfitOfEnterprise = 0;
	dateOfFoundationEnterprise = NULL;
	industryOfEnterprise = NULL;
}

Enterprise::Enterprise(char* name)
{
	nameOfEnterprise = new char[strlen(name)];
	strcpy(nameOfEnterprise, name);
	citySubjectCountry = NULL;
	turnoverPerYear = 0;
	netProfitOfEnterprise = 0;
	dateOfFoundationEnterprise = NULL;
	industryOfEnterprise = NULL;
}

Enterprise::Enterprise(char* name, char* address, unsigned long turnover, long profit, char* date, char* industry)
{
	nameOfEnterprise = new char[strlen(name)];
	strcpy(nameOfEnterprise, name);
	citySubjectCountry = new char[strlen(address)];
	strcpy(citySubjectCountry, address);
	turnoverPerYear = turnover;
	netProfitOfEnterprise = profit;
	dateOfFoundationEnterprise = new char[strlen(date)];
	strcpy(dateOfFoundationEnterprise, date);
	industryOfEnterprise = new char[strlen(industry)];
	strcpy(industryOfEnterprise, industry);
}


void Enterprise::inputEnterpriseFromConsole()
{
	nameOfEnterprise = new char[LENNAME];
	dateOfFoundationEnterprise = new char[20];
	industryOfEnterprise = new char[70];
	puts("\n���� �����������\n");
	do {
		puts("������� �������� �����������:");
		fgets(nameOfEnterprise, LENNAME, stdin);
	} while (protectionAgainstIncorrectTextInput(nameOfEnterprise));
	deletingNewlineTransitionCharacter(nameOfEnterprise);
	do {
		do {
			puts("������� ���� ��������� �����������:");
			fgets(dateOfFoundationEnterprise, 20, stdin);
		} while (protectionAgainstIncorrectTextInput(dateOfFoundationEnterprise));
	} while (checkingForCorrectnessOfDateEntry(dateOfFoundationEnterprise));
	do {
		puts("������� ������� �����������:");
		fgets(industryOfEnterprise, 70, stdin);
	} while (protectionAgainstIncorrectTextInput(industryOfEnterprise));
	deletingNewlineTransitionCharacter(industryOfEnterprise);
	puts("������� ������ �� ���:");
	while (scanf("%d", &turnoverPerYear) != 1) {
		while (getchar() != '\n');
		printf("\n������ �����!\n������� ������ �� ���:\n");
	}
	puts("������� ������� �����������:");
	while (scanf("%d", &netProfitOfEnterprise) != 1) {
		while (getchar() != '\n');
		printf("\n������ �����!\n������� ������� �����������:\n");
	}
	while (getchar() != '\n');
}

void Enterprise::enterpriseTableHeader()
{
	printf("*****************************************************************************************************************************************************************************\n");
	printf("* ����� *       �����������       *                  ��������������                 *   ������ �� ���   *    �������    *              �������             * ���� ��������� *\n");
	printf("*****************************************************************************************************************************************************************************\n");
}

void Enterprise::outputEnterpriseToConsole(int number)
{
	printf("* %-5d * %-23s * %-47s * ", number + 1, nameOfEnterprise, citySubjectCountry);
	printf("%-17lu * %-13ld * ", turnoverPerYear, netProfitOfEnterprise);
	printf("%-32s * %-14s *\n", industryOfEnterprise, dateOfFoundationEnterprise);
	printf("*****************************************************************************************************************************************************************************\n");
}


