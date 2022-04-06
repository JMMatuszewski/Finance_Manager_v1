#include "Expenses_File.h"

/// Method to load expenses of logged user ///
vector<Amount> Expenses_File::loadUserExpense(int loggedUserId)
{
    CMarkup xml;
    Amount amount;
    vector<Amount> expenses;
    int current_id;
    int expense_id ;
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
                status = amount.setDate(atoi(xml.GetElemContent().c_str()));

                xml.FindElem("EXPENSE_ID");
                expense_id = atoi(xml.GetElemContent().c_str());
                status = amount.setAmountId(expense_id);
                if (lastExpenseId < expense_id)
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
                if (lastExpenseId < expense_id)
                    lastExpenseId = expense_id;
            }
            xml.OutOfElem();
            /// EOF: GET DATA FROM XML ///
        }
    }
    sort(expenses.begin(), expenses.end());
    return expenses;
}

/// Method to write new expenses of logged user ///
void Expenses_File::writeExpenses(Amount amount, int LOGGED_USER_ID)
{
    CMarkup xml_in;
    xml_in.Load(getFileName());
    xml_in.ResetPos();
    if(!xml_in.FindElem("EXPENSES"))
    {
        xml_in.AddElem("EXPENSES");
    }
    xml_in.IntoElem();
    xml_in.AddElem("EXPENSE");
    xml_in.IntoElem();
    xml_in.AddElem("USER_ID", LOGGED_USER_ID);
    xml_in.AddElem("DATE", amount.getDate());
    xml_in.AddElem("EXPENSE_ID", amount.getAmountId());
    xml_in.AddElem("ITEM", amount.getItem());
    xml_in.AddElem("AMOUNT", Minor_Methods::toStringWithPrecision(amount.getAmount()));
    lastExpenseId++;
    xml_in.Save(getFileName());
}

/// Method to extract Id of the last expense ///
int Expenses_File::getLastExpenseId()
{
    return lastExpenseId;
}
