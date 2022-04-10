#include "IncomesFile.h"

/// Method to load encomes of logged user ///
vector<Amount> IncomesFile::loadUserIncome(int loggedUserId)
{
    CMarkup xml;
    Amount amount;
    vector<Amount> incomes;
    int currentId;
    int incomeId;
    ////// TMP STATUS //////////
    bool status;
    ///////////////////////////
    xml.Load(getFileName());
    xml.ResetPos();
    if(xml.FindElem("INCOMES"))
    {
        xml.IntoElem();
        while(xml.FindElem("INCOME"))
        {
            xml.IntoElem();
            /// GET DATA FROM XML ///
            xml.FindElem("USER_ID");
            currentId = atoi(xml.GetElemContent().c_str());
            if (loggedUserId == currentId)
            {
                status = amount.setId(currentId);

                xml.FindElem("DATE");
                status = amount.setDate(atoi(xml.GetElemContent().c_str()));

                xml.FindElem("INCOME_ID");
                incomeId = atoi(xml.GetElemContent().c_str());
                status = amount.setAmountId(incomeId);
                if (lastIncomeId < incomeId)
                    lastIncomeId = incomeId;

                xml.FindElem("ITEM");
                status = amount.setItem(xml.GetElemContent());

                xml.FindElem("AMOUNT");
                status = amount.setAmount(atof(xml.GetElemContent().c_str()));
                //////////////////////////
                incomes.push_back(amount);
            }
            else
            {
                xml.FindElem("INCOME_ID");
                incomeId = atoi(xml.GetElemContent().c_str());
                if (lastIncomeId < incomeId)
                    lastIncomeId = incomeId;
            }
            xml.OutOfElem();
            /// EOF: GET DATA FROM XML ///
        }
    }
    sort(incomes.begin(), incomes.end());
    return incomes;
}

/// Method to write new expenses of logged user ///
void IncomesFile::writeIncomes(Amount amount, int LOGGED_USER_ID)
{
    CMarkup xml;
    xml.Load(getFileName());
    xml.ResetPos();
    if(!xml.FindElem("INCOMES"))
    {
        xml.AddElem("INCOMES");
    }
    xml.IntoElem();
    xml.AddElem("INCOME");
    xml.IntoElem();
    xml.AddElem("USER_ID", LOGGED_USER_ID);
    xml.AddElem("DATE", amount.getDate());
    xml.AddElem("INCOME_ID", amount.getAmountId());
    xml.AddElem("ITEM", amount.getItem());
    xml.AddElem("AMOUNT", MinorMethods::toStringWithPrecision(amount.getAmount()));
    lastIncomeId++;
    xml.Save(getFileName());
}

/// Method to extract Id of the last income ///
int IncomesFile::getLastIncomeId()
{
    return lastIncomeId;
}
/*
void Incomes_File::setLastIncomeId(int newLastIncomeId)
{
    lastIncomeId = newLastIncomeId;
}*/
