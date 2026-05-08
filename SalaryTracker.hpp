#include "SalaryTracker_def.hpp"

class SalaryTracker
{
private:
	int			mi_salary;
	bool		mb_isSalarySet;
	std::string ms_date;
	bool		mb_isDateSet;
	bool		mb_isExit;

	std::vector<Expense> mv_expenses;

	int mi_leftovers;

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
	void printExpenses();
	void printLeftovers();
	void printChoice();

	void getUserChoice();
	void setSalary();
	bool checkSalary();
	void setDate();
	bool checkDateFormat();
	void setExpenses();
	void getUserChoiceForExpenses();
	void addExpense();
	void changeColor(int pi_expenseType);
	void setColor(int pi_textColor);
	void updateLeftovers();
	int getTotalExpenses();

};