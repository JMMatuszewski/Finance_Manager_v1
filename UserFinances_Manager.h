#ifndef USERFINANCESMANAGER_H
#define USERFINANCESMANAGER_H_H

#include <iostream>
#include <string>

#include "Minor_Methods.h"
#include "Incomes_File.h"
#include "Income.h"

using namespace std;


class UserFinances_Manager
{
    Incomes_File incomes_File;
    const int LOGGED_USER_ID;
    vector<Income> incomes;
    /// Private Methods ///
    bool get_NewIncome(Income* pIncome);
    ///////////////////////

public:
    UserFinances_Manager(string incomes_FileName, int loggedUserId)
    : incomes_File(incomes_FileName), LOGGED_USER_ID(loggedUserId)
    {
        incomes = incomes_File.loadUserIncome(LOGGED_USER_ID);
    }
    ////////////// METHODS ///////////////
    void addIncome();

    //int getLastIncomeId();
};

#endif
