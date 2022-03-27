#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>

#include "Minor_Methods.h"
#include "Amount.h"
#include "XML_File.h"
#include "Markup.h"

using namespace std;

class Expenses_File : public XML_File
{
    int lastExpenseId;
public:
    Expenses_File(string expenses_FileName) : XML_File(expenses_FileName)
    {
        lastExpenseId = 0;
    };
    /// PUBLIC METHODS ///
    vector<Amount> loadUserExpense(int loggedUserId);

    int getLastExpenseId();
};

#endif
