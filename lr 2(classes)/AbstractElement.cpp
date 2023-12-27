#include "AbstractElement.h"

void AbstractElement::setName(string name)
{
	this->name = name;
}

void AbstractElement::setPopulation(long population)
{
	this->population = population;
}

void AbstractElement::setSquare(int square)
{
	this->square = square;
}

string AbstractElement::getName() const
{
	return name;
}

int AbstractElement::getPopulation()
{
	return population;
}

int AbstractElement::getSquare()
{
	return square;
}

AbstractElement::AbstractElement()
{
	population = 0;
	square = 0;
}

AbstractElement::AbstractElement(string name)
{
	if (name.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;
	population = 0;
	square = 0;
}

AbstractElement::AbstractElement(string name, long population, int square)
{
	if (name.empty())
		throw invalid_argument("������ �� ����� ���� ������!");
	this->name = name;

	if (population < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->population = population;

	if(square < 0)
		throw invalid_argument("�������� �� ����� ���� �������������!");
	this->square = square;
}

void AbstractElement::input(string s)
{
	do {
		try {
			cout << "������� �������� " << s << ":" << endl;
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

	cout << "������� ��������� " << s << ":" << endl;
	while (scanf("%d", &population) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ��������� " << s << ":\n";
	}
	while (getchar() != '\n');

	cout << "������� ������� " << s << " (� ��. ��):" << endl;
	while (scanf("%d", &square) != 1) {
		while (getchar() != '\n');
		cout << "\n������ �����!\n������� ������� " << s << " (� ��. ��):\n";
	}
	while (getchar() != '\n');
}

string AbstractElement::info() const
{
	return "";
}



