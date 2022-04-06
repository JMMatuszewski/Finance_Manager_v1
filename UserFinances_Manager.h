#ifndef USERFINANCESMANAGER_H
#define USERFINANCESMANAGER_H_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "Minor_Methods.h"
#include "Incomes_File.h"
#include "Expenses_File.h"
#include "Amount.h"
//#include "DateParts.h"

using namespace std;


class UserFinances_Manager
{
    Incomes_File incomes_File;
    Expenses_File expenses_File;
    const int LOGGED_USER_ID;
    vector<Amount> incomes;
    vector<Amount> expenses;
    /// Private Methods ///
    bool get_NewIncome(Amount* pIncome);
    bool get_NewExpense(Amount* pExpense);
    void showBilans(int startDate, int endDate, int option);
    double calcMonthSum(vector<Amount> vectorName, int startDate, int endDate);
    double calcPreciseSum(vector<Amount> vectorName, int startDate, int endDate);
    int chooseDate();
    //void showBilansParts(vector<Amount> bilans);

    ///////////////////////

public:
    UserFinances_Manager(string incomes_FileName, string expenses_FileName, int loggedUserId)
    : incomes_File(incomes_FileName), expenses_File(expenses_FileName), LOGGED_USER_ID(loggedUserId)
    {
        incomes = incomes_File.loadUserIncome(LOGGED_USER_ID);
        expenses = expenses_File.loadUserExpense(LOGGED_USER_ID);
    }
    ////////////// METHODS ///////////////
    void addIncome();
    void addExpense();
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
