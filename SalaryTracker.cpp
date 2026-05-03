#include "SalaryTracker.hpp"

SalaryTracker::SalaryTracker() : mi_salary(0), mb_isSalarySet(false), ms_date(""), mb_isDateSet(false)
{

}

void SalaryTracker::run()
{
    printStart();
    
    //std::cout << "What is the amount :";
    //std::cin >> mi_salary;

    //std::cout << "Your Salary for this month is " << mi_salary << std::endl;
    printSession();

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
}