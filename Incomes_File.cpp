#include "Incomes_File.h"

vector<Amount> Incomes_File::loadUserIncome(int loggedUserId)
{
    CMarkup xml;
    Amount amount;
    vector<Amount> incomes;
    int current_id;
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
            current_id = atoi(xml.GetElemContent().c_str());
            if (loggedUserId == current_id)
            {
                status = amount.setId(current_id);

                xml.FindElem("DATE");
                status = amount.setDate(xml.GetElemContent());

                xml.FindElem("INCOME_ID");
                int income_id = atoi(xml.GetElemContent().c_str());
                status = amount.setAmountId(income_id);
                lastIncomeId = income_id;

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
                lastIncomeId = atoi(xml.GetElemContent().c_str());
            }
            xml.OutOfElem();
            /// EOF: GET DATA FROM XML ///
        }
    }
    return incomes;
}

int Incomes_File::getLastIncomeId()
{
    return lastIncomeId;
}
