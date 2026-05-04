#include <iostream>


enum ki_choice
{
	ki_choice_exit = 0,
	ki_choice_salary,
	ki_choice_date,
	ki_choice_expenses,
};

class SalaryTracker
{
private:
	int			mi_salary;
	bool		mb_isSalarySet;
	std::string ms_date;
	bool		mb_isDateSet;
	bool		mb_isExit;

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

	void getUserChoice();
	void setSalary();
	bool checkSalary();
	void setDate();
	bool checkDateFormat();

};