#include "Subject.h"

unsigned Subject::totalSubjects = 0;

void Subject::setName(string name)
{
	if (name.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;
}

void Subject::setNumberOfCities(int number)
{
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	numberOfCities = number;
}

void Subject::setPopulation(int population)
{
	if (population < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->population = population;
}

void Subject::setSquare(int square)
{
	if (square < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->square = square;
}

void Subject::setListOfCities(City cities[])
{
	for (int i = 0; i < MAXCITIES; i++)
	{
		listOfCities[i] = cities[i];
	}
}

string Subject::getName()
{
	return name;
}

int Subject::getNumberOfCities()
{
	return numberOfCities;
}

int Subject::getPopulation()
{
	return population;
}

int Subject::getSquare()
{
	return square;
}

City* Subject::getListOfCities()
{
	return listOfCities;
}

Subject::Subject()
{
	numberOfCities = 0;
	population = 0;
	square = 0;
}

Subject::Subject(string name)
{
	if (name.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;
	numberOfCities = 0;
	population = 0;
	square = 0;
}

Subject::Subject(string name, int number, int population, int square, City cities[])
{
	if (name.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;
	if (number < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->numberOfCities = number;
	if (population < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->population = population;
	if (square < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->square = square;
	for (int i = 0; i < MAXCITIES; i++)
	{
		listOfCities[i] = cities[i];
	}
}



void Subject::inputSubjectFromConsole()
{
	cout << "\n���� ��������\n" << endl;
	do {
		try {
			cout << "������� �������� ��������:" << endl;
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
	cout << "������� ��������� ��������:" << endl;
	while (scanf("%d", &population) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ��������� ��������:\n";
	}
	cout << "������� ���������� ������� � ��������:" << endl;
	while (scanf("%d", &numberOfCities) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ���������� ������� � ��������:\n";
	}
	cout << "������� ������� ��������:" << endl;
	while (scanf("%d", &square) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ������� ��������:\n";
	}
	while (getchar() != '\n');
}

void Subject::subjectTableHeader()
{
	cout << "*****************************************************************************************************************" << endl;
	cout << "* ����� *       �������      * ���������� ������� * ������� �������� * ��������� *        ������ �������        *" << endl;
	cout << "*****************************************************************************************************************" << endl;
}

void Subject::outputSubjectToConsole(int number)
{
	int i;
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(18) << left << name << " * ";
	cout << setw(18) << left << numberOfCities << " * ";
	cout << setw(16) << left << square << " * ";
	cout << setw(9) << left << population << " * ";
	cout << setw(28) << left << listOfCities[0].getName() << " *" << endl;
	i = 1;
	while ((!listOfCities[i].getName().empty()) && (i < MAXCITIES)) {
		cout << "*       *                    *                    *                  *           * ";
		cout << setw(28) << left << listOfCities[i].getName() << " *" << endl;
	}
	cout << "*****************************************************************************************************************" << endl;
}

City& Subject::choosingCity()
{
	int i, n, number;
	char character;
	listOfCities[0].cityTableHeader();
	i = 0;
	while (!listOfCities[i].getName().empty()) {
		listOfCities[i].outputCityToConsole(i);
		i++;
	}
	n = i + 1;
	cout << "\n\n�������� �����\n" << endl;
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > n));
	return listOfCities[number - 1];
}


void Subject::incrementTotalSubjects()
{
	totalSubjects++;
}

void Subject::printTotalSubjects()
{
	cout << "����� �� ������ � ������ " << totalSubjects << " ���������" << endl;
}


