#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER_H

#include <iostream>

#include "User_Manager.h"
#include "UserFinances_Manager.h"
#include "Minor_Methods.h"

using namespace std;

class Financial_Manager
{
    ////////// OBJECTS ////////////
    User_Manager user_Manager;
    UserFinances_Manager *userFinances_Manager;
    ///////////////////////////////
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;



public:
    Financial_Manager(string USERFILENAME, string incomes_FileName, string expenses_FileName)
    : user_Manager(USERFILENAME), INCOMES_FILENAME(incomes_FileName), EXPENSES_FILENAME(expenses_FileName)
    {
        userFinances_Manager = NULL;
    };
    ~Financial_Manager()
    {
        delete userFinances_Manager;
        userFinances_Manager = NULL;
    };

    //////////// MENU ////////////
    char getMainMenuChoice();
    char getFinanceMenuChoice();
    //////////// USER /////////////
    void user_Login();
    void show_Users();
    void user_Register();
    int getLoggedUserId();
    //////////// FINANCES /////////
    void addIncome();
    void addExpense();
    void userLogout();
    void currentMonth();
    void previousMonth();
    void choosePeriod();

    /// TMP ///
    void show_Incomes();
    void show_Expenses();
    //int getLastIncomeId();
    /// TMP ///

};

#endif
