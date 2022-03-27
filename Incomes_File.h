#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>

#include "Minor_Methods.h"
#include "Amount.h"
#include "XML_File.h"
#include "Markup.h"

using namespace std;

class Incomes_File : public XML_File
{
    int lastIncomeId;
public:
    Incomes_File(string incomes_FileName) : XML_File(incomes_FileName)
    {
        lastIncomeId = 0;
    };
    /// PUBLIC METHODS ///
    vector<Amount> loadUserIncome(int loggedUserId);

    int getLastIncomeId();
};

#endif
