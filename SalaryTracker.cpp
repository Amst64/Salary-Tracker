#include "SalaryTracker.hpp"

SalaryTracker::SalaryTracker() : mi_salary(0), mb_isSalarySet(false), ms_date(""), mb_isDateSet(false), mb_isExit(false)
{

}

void SalaryTracker::run()
{
    printStart();
    
    while(!mb_isExit)
    {
        printSession();
    }

    printEnd();
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

void SalaryTracker::printChoice()
{
    std::cout << "                                      1 : To set salary" << std::endl;
    std::cout << "                                      2 : To set the date" << std::endl;
    std::cout << "                                      3 : To give all expenses using the salary" << std::endl;
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
            break;
    }
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
    std::cin >> ms_date;

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