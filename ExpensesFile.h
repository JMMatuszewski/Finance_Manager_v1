#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>

#include "MinorMethods.h"
#include "Amount.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class ExpensesFile : public XMLFile
{
    int lastExpenseId;
public:
    ExpensesFile(string expensesFileName) : XMLFile(expensesFileName)
    {
        lastExpenseId = 0;
    };
    /// PUBLIC METHODS ///
    vector<Amount> loadUserExpense(int loggedUserId);
    void writeExpenses(Amount amount,int LOGGED_USER_ID);

    int getLastExpenseId();
};

#endif
