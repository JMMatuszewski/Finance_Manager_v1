#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>

#include "MinorMethods.h"
#include "Amount.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class IncomesFile : public XMLFile
{
    int lastIncomeId;
public:
    IncomesFile(string incomesFileName) : XMLFile(incomesFileName)
    {
        lastIncomeId = 0;
    };
    /// PUBLIC METHODS ///
    vector<Amount> loadUserIncome(int loggedUserId);
    void writeIncomes(Amount amount,int LOGGED_USER_ID);
    int getLastIncomeId();
};

#endif
