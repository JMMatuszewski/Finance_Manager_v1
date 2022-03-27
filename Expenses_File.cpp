#include "Expenses_File.h"

vector<Amount> Expenses_File::loadUserExpense(int loggedUserId)
{
    CMarkup xml;
    Amount amount;
    vector<Amount> expenses;
    int current_id;
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
            current_id = atoi(xml.GetElemContent().c_str());
            if (loggedUserId == current_id)
            {
                status = amount.setId(current_id);

                xml.FindElem("DATE");
                status = amount.setDate(xml.GetElemContent());

                xml.FindElem("EXPENSE_ID");
                int expense_id = atoi(xml.GetElemContent().c_str());
                status = amount.setAmountId(expense_id);
                lastExpenseId = expense_id;

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
            }
            xml.OutOfElem();
            /// EOF: GET DATA FROM XML ///
        }
    }
    return expenses;
}

int Expenses_File::getLastExpenseId()
{
    return lastExpenseId;
}
