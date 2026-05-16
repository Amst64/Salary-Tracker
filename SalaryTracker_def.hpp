#include <iostream>
#include <string>
#include <vector>


enum ki_choice
{
	ki_choice_exit = 0,
	ki_choice_salary,
	ki_choice_date,
	ki_choice_expenses,
};

enum ki_expense_choice
{
	ki_expense_choice_back = 0,
	ki_expense_choice_add,
	ki_expense_choice_modify,
	ki_expense_choice_delete,
};

enum ki_expense_modification_choice
{
	ki_expense_modification_choice_back = 0,
	ki_expense_modification_choice_amount,
	ki_expense_modification_choice_description,
	ki_expense_modification_choice_type,
};

enum ki_expense_type
{
	ki_expense_type_personal = 1,
	ki_expense_type_obligatory,
	ki_expense_type_donation,
};

enum ki_color
{
	ki_color_red = 31,
	ki_color_cyan = 36,
	ki_color_defaultWhite = 37,
	ki_color_brightWhite = 97,
};

struct Expense
{
	int			mi_amount;
	std::string ls_description;
	int			mi_type;

	Expense() : mi_amount(0), ls_description("description"), mi_type(1)
	{
	}
};