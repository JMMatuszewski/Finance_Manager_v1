#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER_H

#include <iostream>

#include "UserManager.h"
#include "UserFinancesManager.h"
#include "MinorMethods.h"

using namespace std;

class FinancialManager
{
    ////////// OBJECTS ////////////
    UserManager userManager;
    UserFinancesManager *userFinancesManager;
    ///////////////////////////////
    const string INCOMES_FILENAME;
    const string EXPENSES_FILENAME;



public:
    FinancialManager(string USERFILENAME, string incomesFileName, string expensesFileName)
    : userManager(USERFILENAME), INCOMES_FILENAME(incomesFileName), EXPENSES_FILENAME(expensesFileName)
    {
        userFinancesManager = NULL;
    };
    ~FinancialManager()
    {
        delete userFinancesManager;
        userFinancesManager = NULL;
    };

    //////////// MENU ////////////
    char getMainMenuChoice();
    char getFinanceMenuChoice();
    //////////// USER /////////////
    void userLogin();
    void showUsers();
    void userRegister();
    int getLoggedUserId();
    //////////// FINANCES /////////
    void addIncome();
    void addExpense();
    void userLogout();
    void currentMonth();
    void previousMonth();
    void choosePeriod();
    void changePass();

    /// TMP ///
    void showIncomes();
    void showExpenses();
    //int getLastIncomeId();
    /// TMP ///

};

#endif
