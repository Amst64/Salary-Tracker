#include <iostream>

class SalaryTracker
{
private:
	int			mi_salary;
	bool		mb_isSalarySet;
	std::string ms_date;
	bool		mb_isDateSet;

public:
	SalaryTracker();
	void run();
private:
	void init();
	void printStart();
	void printEnd();
	void printSession();
	void printSalary();
	void printDate();
	void printChoice();
};