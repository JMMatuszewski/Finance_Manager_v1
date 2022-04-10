#ifndef USERFINANCESMANAGER_H
#define USERFINANCESMANAGER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "MinorMethods.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "Amount.h"

using namespace std;


class UserFinancesManager
{
    IncomesFile incomesFile;
    ExpensesFile expensesFile;
    const int LOGGED_USER_ID;
    vector<Amount> incomes;
    vector<Amount> expenses;
    /// Private Methods ///
    bool getNewIncome(Amount* pIncome);
    bool getNewExpense(Amount* pExpense);
    void showBilans(int startDate, int endDate, int option);
    double calcMonthSum(vector<Amount> vectorName, int startDate, int endDate);
    double calcPreciseSum(vector<Amount> vectorName, int startDate, int endDate);
    int chooseDate();

    ///////////////////////

public:
    UserFinancesManager(string incomesFileName, string expensesFileName, int loggedUserId)
    : incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId)
    {
        incomes = incomesFile.loadUserIncome(LOGGED_USER_ID);
        expenses = expensesFile.loadUserExpense(LOGGED_USER_ID);
    }
    ////////////// METHODS ///////////////
    void addIncome();
    void addExpense();
    void currentMonth();
    void previousMonth();
    void choosePeriod();

    /// TMP ///
    void showIncomes();
    void showExpenses();
    //int getLastIncomeId();
    /// TMP ///

};

#endif
