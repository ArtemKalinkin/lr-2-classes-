#pragma once
#include "Company.h"

class Branch : public Company
{
private:
	string status;
	int numberOfEmployees;
public:
	Branch();
	Branch(string name, string address, unsigned long turnover, long profit, string date, string industry, string activity, string status, int numberOfEmployees);
	void setStatus(string status);
	string getStatus();
	void setNumberOfEmployess(int number);
	int getNumberOfEmplyees();
	virtual void inputCompanyFromConsole(int mode) override;
	virtual void outputCompanyToConsole(int number) override;
	friend ostream& operator<<(ostream& os, const Branch& branch);
	Branch& operator=(const Company& other);
};

