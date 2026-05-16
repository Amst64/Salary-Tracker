#include "SalaryTracker.hpp"

SalaryTracker::SalaryTracker() : mi_salary(0), mb_isSalarySet(false), ms_date(""), mb_isDateSet(false), mb_isExit(false), mi_leftovers(0)
{

}

void SalaryTracker::run()
{
    while(!mb_isExit)
    {
        printStart();
        printSession();
        printEnd();
    }
}

void SalaryTracker::printStart()
{
    std::cout << "===================================== Salary tracker =====================================" << std::endl;
    std::cout << std::endl;
}

void SalaryTracker::printEnd()
{
    std::cout << std::endl;
    std::cout << "==========================================================================================" << std::endl;
}

void SalaryTracker::printSession()
{
    printSalary();
    printDate();
    printExpenses();
    printLeftovers();

    printChoice();
    getUserChoice();
    
}

void SalaryTracker::printSalary()
{
    if(mb_isSalarySet)
        std::cout << "Salary :"  << mi_salary << std::endl;
    else
        std::cout << "Salary : is not set" << std::endl;
}

void SalaryTracker::printDate()
{
    if (mb_isDateSet)
        std::cout << "Date :" << ms_date << std::endl;
    else
        std::cout << "Date : is not set" << std::endl;
}

void SalaryTracker::printExpenses()
{
    if (mv_expenses.size() == 0)
        return;

    std::cout << std::endl;
    std::cout << "Expenses" << std::endl;
    for(int i = 0; i < mv_expenses.size(); i++)
    {
        setColor(ki_color_defaultWhite); //default color
        std::cout << "----------------------------------" << std::endl;
        changeColor(mv_expenses[i].mi_type);
        std::cout << i << " : " << "-" << mv_expenses[i].mi_amount << " : " << mv_expenses[i].ls_description << std::endl;
    }

    setColor(ki_color_defaultWhite); //default color
    std::cout << std::endl;

}

void SalaryTracker::printLeftovers()
{
    std::cout << std::endl;
    std::cout << "Leftovers : " << mi_leftovers << std::endl;
}

void SalaryTracker::printChoice()
{
    std::cout << "                                      1 : To set salary" << std::endl;
    std::cout << "                                      2 : To set the date" << std::endl;
    std::cout << "                                      3 : To set expenses" << std::endl;
    std::cout << "                                      0 : To exit" << std::endl;
    std::cout << std::endl;
}

void SalaryTracker::getUserChoice()
{
    int li_userChoice;
    std::cout << "Your choice :";
    std::cin >> li_userChoice;

    switch(li_userChoice)
    {
        case ki_choice_exit:
            mb_isExit = true;
            break;
        case ki_choice_salary:
            setSalary();
            break;

        case ki_choice_date:
            setDate();
            break;

        case ki_choice_expenses:
            setExpenses();
            break;
    }
    updateLeftovers();
}

void SalaryTracker::setSalary()
{
    std::cout << "Setting salary..." << std::endl;
    std::cout << "Salary = ";
    std::cin >> mi_salary;
    if(checkSalary())
        mb_isSalarySet = true;
    else
        mb_isSalarySet = false;
}

bool SalaryTracker::checkSalary()
{
    if (mi_salary < 0)
    {
        std::cout << "Salary cannot be negative" << std::endl;
        return false;
    }

    return true;
}

void SalaryTracker::setDate()
{
    std::cout << "Setting the date..." << std::endl;
    std::cout << "Date format is YYYY-MM-DD" << std::endl;
    std::cout << "Date = ";
    std::getline(std::cin >> std::ws, ms_date);

    if(checkDateFormat())
        mb_isDateSet = true;
    else
        mb_isDateSet = false;
}

bool SalaryTracker::checkDateFormat()
{
    if (ms_date.size() != 10)
    {
        std::cout << "Wrong date format" << std::endl;
        return false;
    }

    std::string ls_month = ms_date.substr(5, 2);
    if (ls_month > "12")
    {
        std::cout << "Wrong date format, the month is wrong" << std::endl;
        return false;
    }

    std::string ls_day = ms_date.substr(8, 2);
    if (ls_day > "31")
    {
        std::cout << "Wrong date format, the day is wrong" << std::endl;
        return false;
    }

    if (ls_month == "02" && ls_day > "29")
    {
        std::cout << "Wrong date format, the day is wrong" << std::endl;
        return false;
    }

    return true;
}

void SalaryTracker::setExpenses()
{
    while(!mb_isExit)
    {
        std::cout << "                                      1 : Add expense" << std::endl;
        std::cout << "                                      2 : Modify expense" << std::endl;
        std::cout << "                                      3 : Delete expense" << std::endl;
        std::cout << "                                      0 : To go back" << std::endl;
        std::cout << std::endl;
        getUserChoiceForExpenses();
    }

    mb_isExit = false; //reset
}

void SalaryTracker::getUserChoiceForExpenses()
{
    int li_userChoice;
    std::cout << "Your choice :";
    std::cin >> li_userChoice;

    switch (li_userChoice)
    {
        case ki_expense_choice_back:
            mb_isExit = true;
            break;

        case ki_expense_choice_add:
            addExpenses();
            break;

        case ki_expense_choice_modify:
            modifyExpenses();
            break;

        case ki_expense_choice_delete:
            break;
    }
}

void SalaryTracker::addExpenses()
{
    Expense lc_expense;
    changeExpenseAmount(lc_expense.mi_amount);
    changeExpenseDescription(lc_expense.ls_description);
    changeExpenseType(lc_expense.mi_type);

    mv_expenses.push_back(lc_expense);
}

void SalaryTracker::modifyExpenses()
{
    std::cout << std::endl;
    std::cout << "Choose expense to modify (index)" << std::endl;
    std::cout << std::endl;
    printExpenses();
    std::cout << std::endl;

    int li_index;
    std::cout << "Index = ";
    std::cin >> li_index;
    modifyExpense(li_index);

}

void SalaryTracker::modifyExpense(int pi_index)
{
    bool lb_isFinish = false;

    while(!lb_isFinish)
    {
        std::cout << "What do you want to modify for this expense : ";
        int li_expenseType = mv_expenses[pi_index].mi_type;
        changeColor(li_expenseType);
        std::cout << mv_expenses[pi_index].mi_amount << " : " << mv_expenses[pi_index].ls_description << ": ";
        switch (li_expenseType)
        {
        case ki_expense_type_personal:
            std::cout << "Personal" << std::endl;
            break;

        case ki_expense_type_obligatory:
            std::cout << "Mandatory" << std::endl;
            break;

        case ki_expense_type_donation:
            std::cout << "Donation" << std::endl;
            break;
        }
        setColor(ki_color_defaultWhite); //default color

        std::cout << "1 : amount" << std::endl;
        std::cout << "2 : description" << std::endl;
        std::cout << "3 : type" << std::endl;
        std::cout << "0 : go back" << std::endl;

        int li_choice;
        std::cout << "Choice for modification = ";
        std::cin >> li_choice;

        switch (li_choice)
        {
        case ki_expense_modification_choice_back:
            lb_isFinish = true;
            break;
        case ki_expense_modification_choice_amount:
            changeExpenseAmount(mv_expenses[pi_index].mi_amount);
            break;

        case ki_expense_modification_choice_description:
            changeExpenseDescription(mv_expenses[pi_index].ls_description);
            break;

        case ki_expense_modification_choice_type:
            changeExpenseType(mv_expenses[pi_index].mi_type);
            break;
        }
    }
}

void SalaryTracker::changeExpenseAmount(int& pir_amount)
{
    std::cout << std::endl;
    std::cout << "Expense amount = ";
    std::cin >> pir_amount;
}

void SalaryTracker::changeExpenseDescription(std::string& psr_descritpion)
{
    std::cout << std::endl;
    std::cout << "Expense description = ";
    std::getline(std::cin >> std::ws, psr_descritpion);
}

void SalaryTracker::changeExpenseType(int& pir_type)
{
    std::cout << std::endl;
    std::cout << "Choose expense type..." << std::endl;
    std::cout << "1 : personal expenses" << std::endl;
    std::cout << "2 : obligatory expenses" << std::endl;
    std::cout << "3 : donation" << std::endl;
    std::cout << "Expense type = ";
    std::cin >> pir_type;
}

void SalaryTracker::changeColor(int pi_expenseType)
{
    switch(pi_expenseType)
    {
        case ki_expense_type_personal:
            setColor(ki_color_brightWhite);
            break;

        case ki_expense_type_obligatory:
            setColor(ki_color_red);
            break;

        case ki_expense_type_donation:
            setColor(ki_color_cyan);
            break;
    }
}

void SalaryTracker::setColor(int pi_textColor)
{
    std::cout << "\033[" << pi_textColor << "m";
}

void SalaryTracker::updateLeftovers()
{
    if(mv_expenses.size() > 0 && mb_isSalarySet)
    {
        mi_leftovers = mi_salary - getTotalExpenses();
    }
}

int SalaryTracker::getTotalExpenses()
{
    int li_total = 0;

    for(int i = 0; i < mv_expenses.size(); i++)
    {
        li_total += mv_expenses[i].mi_amount;
    }

    return li_total;
}