#include "Сontinent.h"

unsigned Continent::totalContinents = 0;

void Continent::setName(string name)
{
	if (name.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->name = name;
}

void Continent::setNumberOfCountries(int number)
{
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	numberOfCountries = number;
}

void Continent::setSquare(int square)
{
	if (square < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->square = square;
}

void Continent::setListOfCountries(Country countries[])
{
	for (int i = 0; i < MAXCOUNTRIES; i++)
	{
		listOfCountries[i] = countries[i];
	}
}

string Continent::getName() const
{
	return name;
}

int Continent::getNumberOfCountries()
{
	return numberOfCountries;
}

int Continent::getSquare()
{
	return square;
}

Country* Continent::getListOfCountries()
{
	return listOfCountries;
}

Continent::Continent()
{
	numberOfCountries = 0;
	square = 0;
}

Continent::Continent(string name)
{
	if (name.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->name = name;
	numberOfCountries = 0;
	square = 0;
}

Continent::Continent(string name, int number, int square, Country countries[])
{
	if (name.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->name = name;
	if (number < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	numberOfCountries = number;
	if (square < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	this->square = square;
	for (int i = 0; i < MAXCOUNTRIES; i++)
	{
		listOfCountries[i] = countries[i];
	}
}


void Continent::inputСontinentFromConsole()
{
	puts("ВВОД КОНТИНЕНТА\n");
	do {
		try {
			cout << "Введите название континента:" << endl;
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
	cout << "Введите количество стран на континенте:" << endl;
	while (scanf("%d", &numberOfCountries) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите количество стран на континенте:\n";
	}
	cout << "Введите площадь континента (в кв. км):" << endl;
	while (scanf("%d", &square) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите площадь континента (в кв. км):\n";
	}
	while (getchar() != '\n');
}

void Continent::continentTableHeader()
{
	cout << "*******************************************************************************************************\n";
	cout << "* Номер *     Континент      * Количество стран * Площадь континента *          Список стран          *\n";
	cout << "*******************************************************************************************************\n";
}

void Continent::outputContinentToConsole(int number)
{
	int i;
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(18) << left << name << " * ";
	cout << setw(16) << left << numberOfCountries << " * ";
	cout << setw(18) << left << square << " * ";
	cout << setw(30) << left << listOfCountries[0].getName() << " *" << endl;
	i = 1;
	while ((!listOfCountries[i].getName().empty()) && (i < MAXCOUNTRIES)) {
		cout << "*       *                    *                  *                    * ";
		cout << setw(30) << left << listOfCountries[i].getName() << " *" << endl;
		i++;
	}
	cout << "*******************************************************************************************************\n";
}

ostream& operator<<(ostream& os, const Continent& continent) {
	int i;
	os << setw(18) << left << continent.name << " * ";
	os << setw(16) << left << continent.numberOfCountries << " * ";
	os << setw(18) << left << continent.square << " * ";
	os << setw(30) << left << continent.listOfCountries[0].getName() << " *" << endl;
	i = 1;
	while ((!continent.listOfCountries[i].getName().empty()) && (i < MAXCOUNTRIES)) {
		os << "*       *                    *                  *                    * ";
		os << setw(30) << left << continent.listOfCountries[i].getName() << " *" << endl;
		i++;
	}
	os << "*******************************************************************************************************\n";
}

Country& Continent::choosingCountry()
{
	int i, n, number;
	char character;
	listOfCountries[0].countryTableHeader();
	i = 0;
	while (!listOfCountries[i].getName().empty()) {
		cout << "* " << setw(5) << left << i + 1 << " * ";
		cout << listOfCountries[i];
		i++;
	}
	n = i + 1;
	cout << "\n\nВыберите страну\n" << endl;
	do {
		character = _getch();
		number = character - '0';
	} while ((number < 1) || (number > n));
	return listOfCountries[number - 1];
}


void Continent::incrementTotalContinents()
{
	totalContinents++;
}

void Continent::printTotalContinents()
{
	cout << "Вы внесли в список " << totalContinents << " из 6 существующих континетов" << endl;
}




