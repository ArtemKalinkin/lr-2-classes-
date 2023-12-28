#include "Company.h"

unsigned Company::totalCompanies = 0;


void Company::setName(string name)
{
	if (name.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->name = name;
}

void Company::setcitySubjectCountry(string address)
{
	if (address.empty())
		throw invalid_argument("Строка не может быть пустой!");
	citySubjectCountry = address;
}

void Company::setTurnoverPerYear(unsigned long turnover)
{
	if (turnover < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	turnoverPerYear = turnover;
}

void Company::setNetProfit(long profit)
{
	netProfit = profit;
}

void Company::setDateOfFoundation(string date)
{
	if (date.empty())
		throw invalid_argument("Строка не может быть пустой!");
	dateOfFoundation = date;
}

void Company::setIndustry(string industry)
{
	if (industry.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->industry = industry;
}

string Company::getName() const
{
	return name;
}

string Company::getcitySubjectCountry()
{
	return citySubjectCountry;
}

unsigned long Company::getTurnoverPerYear()
{
	return turnoverPerYear;
}

long Company::getNetProfit()
{
	return netProfit;
}

string Company::getDateOfFoundation()
{
	return dateOfFoundation;
}

string Company::getIndustry()
{
	return industry;
}

Company::Company()
{
	turnoverPerYear = 0;
	netProfit = 0;
}

Company::Company(string name)
{
	if (name.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->name = name;
	turnoverPerYear = 0;
	netProfit = 0;
}

Company::Company(string name, string address, unsigned long turnover, long profit, string date, string industry, string activity)
{
	if (name.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->name = name;
	if (address.empty())
		throw invalid_argument("Строка не может быть пустой!");
	citySubjectCountry = address;
	if (turnover < 0)
		throw invalid_argument("Значение не может быть отрицательным!");
	turnoverPerYear = turnover;
	netProfit = profit;
	if (date.empty())
		throw invalid_argument("Строка не может быть пустой!");
	dateOfFoundation = date;
	if (industry.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->industry = industry;
	if (activity.empty())
		throw invalid_argument("Строка не может быть пустой!");
	this->activity = activity;
}


void Company::inputCompanyFromConsole(int mode)
{
	string s;
	if (mode) {
		s = "филиала компании";
		cout << "\nВВОД ФИЛИАЛА КОМПАНИИ\n" << endl;
	}
	else {
		s = "компании";
		cout << "\nВВОД КОМПАНИИ\n" << endl;
	}
	do {
		try {
			cout << "Введите название " << s << ":" << endl;
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
	do {
		do {
			cout << "Введите дату основания " << s << ":" << endl;
			getline(cin, dateOfFoundation);
		} while (protectionAgainstIncorrectTextInput(dateOfFoundation));
	} while (checkingForCorrectnessOfDateEntry(dateOfFoundation));
	do {
		try {
			cout << "Введите отрасль " << s << ":" << endl;
			getline(cin, industry);
			protectionAgainstIncorrectTextInput(industry);
			break;
		}
		catch (const invalid_argument e) {
			cerr << "Произошла ошибка: " << e.what() << endl;
		}
		catch (const length_error e) {
			cerr << "Произошла ошибка: " << e.what() << endl;
		}
	} while (true);
	cout << "Введите оборот за год:" << endl;
	while (scanf("%d", &turnoverPerYear) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите оборот за год:\n";
	}
	cout << "Введите прибыль " << s << ":" << endl;
	while (scanf("%d", &netProfit) != 1) {
		while (getchar() != '\n');
		cout << "\nОшибка ввода!\nВведите прибыль " << s << ":\n";
	}
	while (getchar() != '\n');
	cout << "Введите описание деятельности " << s << ":" << endl;
	getline(cin, activity);
}

void Company::companyTableHeader()
{
	cout << "******************************************************************************************************************************************************************************************************************" << endl;
	cout << "* Номер *                          Компания                            *                  Местоположение                 *   Оборот за год   *    Прибыль    *              Отрасль             * Дата основания *" << endl;
	cout << "******************************************************************************************************************************************************************************************************************" << endl;
}

void Company::outputCompanyToConsole(int number)
{
	cout << "* " << setw(5) << left << number + 1 << " * ";
	cout << setw(60) << left << name << " * ";
	cout << setw(47) << left << citySubjectCountry << " * ";
	cout << setw(17) << left << turnoverPerYear << " * ";
	cout << setw(13) << left << netProfit << " * ";
	cout << setw(32) << left << industry << " * ";
	cout << setw(14) << left << dateOfFoundation << " *" << endl;
	cout << "******************************************************************************************************************************************************************************************************************" << endl;
}

ostream& operator<<(ostream& os, const Company& company) {
	os << setw(60) << left << company.name << " * ";
	os << setw(47) << left << company.citySubjectCountry << " * ";
	os << setw(17) << left << company.turnoverPerYear << " * ";
	os << setw(13) << left << company.netProfit << " * ";
	os << setw(32) << left << company.industry << " * ";
	os << setw(14) << left << company.dateOfFoundation << " *" << endl;
	os << "******************************************************************************************************************************************************************************************************************" << endl;
	return os;
}


void Company::incrementTotalCompanies()
{
	totalCompanies++;
}

void Company::printTotalCompanies()
{
	cout << "Всего вы внесли в список " << totalCompanies << " компаний" << endl;
}

Company Company::operator+(const Company& company)
{
	Company buyingСompany = *this;
	buyingСompany.turnoverPerYear += company.turnoverPerYear;
	buyingСompany.netProfit += company.netProfit;
	return buyingСompany;
}

Company& Company::operator=(const Company& other)
{
	if (this != &other) {
		name = other.name;
		citySubjectCountry = other.citySubjectCountry;
		turnoverPerYear = other.turnoverPerYear;
		netProfit = other.netProfit;
		dateOfFoundation = other.dateOfFoundation;
		industry = other.industry;
		activity = other.activity;
	}
	return *this;
}

void Company::performActivity() const
{
	cout << name << endl;
	cout << "Краткое описание деятельности компании" << endl;
	cout << activity << endl;
}

void Company::callPerformActivity() const
{
	performActivity();
}

string Company::info() const
{
	return "Компания: " + name + "; " + citySubjectCountry + "; " + to_string(turnoverPerYear) + "; " + 
		to_string(netProfit) + "; " + dateOfFoundation + "; " + industry + ".";
}

Company::Company(const Company& other)
{
	this->name = other.name;
	this->citySubjectCountry = other.citySubjectCountry;
	this->turnoverPerYear = other.turnoverPerYear;
	this->netProfit = other.netProfit;
	this->industry = other.industry;
	this->activity = other.activity;
}

bool Company::compareByField(const Company& other, CompanyCompareField field) const
{
	int number;
	char delimiter;
	istringstream thisDate(dateOfFoundation);
	istringstream otherDate(other.dateOfFoundation);
	vector<int> thisNumbers;
	vector<int> otherNumbers;
	while (thisDate >> number) {
		thisNumbers.push_back(number);
		if (!(thisDate >> delimiter))
			break;
	}
	while (otherDate >> number) {
		otherNumbers.push_back(number);
		if (!(otherDate >> delimiter))
			break;
	}
	switch (field)
	{
	case CompanyCompareField::NAME:
		return this->name < other.name;
	case CompanyCompareField::ADDRESS:
		return this->citySubjectCountry < other.citySubjectCountry;
	case CompanyCompareField::TURNOVER:
		return this->turnoverPerYear < other.turnoverPerYear;
	case CompanyCompareField::NETPROFIT:
		return this->netProfit < other.netProfit;
	case CompanyCompareField::DATE:
		if (thisNumbers.at(2) != otherNumbers.at(2))
			return thisNumbers.at(2) < otherNumbers.at(2);
		else if (thisNumbers.at(1) != otherNumbers.at(1))
			return thisNumbers.at(1) < otherNumbers.at(1);
		else
			return thisNumbers.at(0) < otherNumbers.at(0);
	case CompanyCompareField::INDUSTRY:
		return this->industry < other.industry;
	default:
		return false;
	}
}

int Company::selectCriteria(string s)
{
	cout << "Выберете критерий " << s << " компаний: " << endl;
	int number;
	cout << "1.Название" << endl;
	cout << "2.Адрес" << endl;
	cout << "3.Оборот за год" << endl;
	cout << "4.Прибыль" << endl;
	cout << "5.Дата основания" << endl;
	cout << "6.Отрасль" << endl;
	do {
		cout << "Введите номер: ";
		cin >> number;
		if ((number < 1) || (number > 6))
			cout << "Критерия с данным номером нет" << endl;
	} while ((number < 1) || (number > 6));
	return number;
}




