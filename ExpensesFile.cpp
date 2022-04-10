#include "ExpensesFile.h"

/// Method to load expenses of logged user ///
vector<Amount> ExpensesFile::loadUserExpense(int loggedUserId)
{
    CMarkup xml;
    Amount amount;
    vector<Amount> expenses;
    int currentId;
    int expenseId ;
    ////// TMP STATUS //////////
    bool status;
    ///////////////////////////
    xml.Load(getFileName());
    xml.ResetPos();
    if(xml.FindElem("EXPENSES"))
    {
        xml.IntoElem();
        while(xml.FindElem("EXPENSE"))
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

                xml.FindElem("EXPENSE_ID");
                expenseId = atoi(xml.GetElemContent().c_str());
                status = amount.setAmountId(expenseId);
                if (lastExpenseId < expenseId)
                    lastExpenseId = expenseId;

                xml.FindElem("ITEM");
                status = amount.setItem(xml.GetElemContent());

                xml.FindElem("AMOUNT");
                status = amount.setAmount(atof(xml.GetElemContent().c_str()));
                //////////////////////////
                expenses.push_back(amount);
            }
            else
            {
                xml.FindElem("EXPENSE_ID");
                lastExpenseId = atoi(xml.GetElemContent().c_str());
                if (lastExpenseId < expenseId)
                    lastExpenseId = expenseId;
            }
            xml.OutOfElem();
            /// EOF: GET DATA FROM XML ///
        }
    }
    sort(expenses.begin(), expenses.end());
    return expenses;
}

/// Method to write new expenses of logged user ///
void ExpensesFile::writeExpenses(Amount amount, int LOGGED_USER_ID)
{
    CMarkup xml;
    xml.Load(getFileName());
    xml.ResetPos();
    if(!xml.FindElem("EXPENSES"))
    {
        xml.AddElem("EXPENSES");
    }
    xml.IntoElem();
    xml.AddElem("EXPENSE");
    xml.IntoElem();
    xml.AddElem("USER_ID", LOGGED_USER_ID);
    xml.AddElem("DATE", amount.getDate());
    xml.AddElem("EXPENSE_ID", amount.getAmountId());
    xml.AddElem("ITEM", amount.getItem());
    xml.AddElem("AMOUNT", MinorMethods::toStringWithPrecision(amount.getAmount()));
    lastExpenseId++;
    xml.Save(getFileName());
}

/// Method to extract Id of the last expense ///
int ExpensesFile::getLastExpenseId()
{
    return lastExpenseId;
}
