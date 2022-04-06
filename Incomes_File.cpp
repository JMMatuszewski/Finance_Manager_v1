#include "Incomes_File.h"

vector<Amount> Incomes_File::loadUserIncome(int loggedUserId)
{
    CMarkup xml;
    Amount amount;
    vector<Amount> incomes;
    int current_id;
    int income_id;
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
                status = amount.setDate(atoi(xml.GetElemContent().c_str()));

                xml.FindElem("INCOME_ID");
                income_id = atoi(xml.GetElemContent().c_str());
                status = amount.setAmountId(income_id);
                if (lastIncomeId < income_id)
                    lastIncomeId = income_id;
                //cout << "lastIncomeId: " << lastIncomeId << endl;
                //system("pause");

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
                income_id = atoi(xml.GetElemContent().c_str());
                if (lastIncomeId < income_id)
                    lastIncomeId = income_id;
            }
            xml.OutOfElem();
            /// EOF: GET DATA FROM XML ///
        }
    }
    sort(incomes.begin(), incomes.end());
    return incomes;
}

void Incomes_File::writeIncomes(Amount amount, int LOGGED_USER_ID)
{
    CMarkup xml_in;
    xml_in.Load(getFileName());
    xml_in.ResetPos();
    if(!xml_in.FindElem("INCOMES"))
    {
        //cout << "empty file\n";
        xml_in.AddElem("INCOMES");
    }
    else
    {
        //cout << "file exist\n";
    }
    xml_in.IntoElem();
    xml_in.AddElem("INCOME");
    xml_in.IntoElem();
    xml_in.AddElem("USER_ID", LOGGED_USER_ID);
    xml_in.AddElem("DATE", amount.getDate());
    xml_in.AddElem("INCOME_ID", amount.getAmountId());
    xml_in.AddElem("ITEM", amount.getItem());
    xml_in.AddElem("AMOUNT", Minor_Methods::toStringWithPrecision(amount.getAmount()));
    lastIncomeId++;
    xml_in.Save(getFileName());
}

int Incomes_File::getLastIncomeId()
{
    //cout << "LastEIncomeId to return: " << lastIncomeId << endl;
    //system("pause");
    return lastIncomeId;
}
/*
void Incomes_File::setLastIncomeId(int newLastIncomeId)
{
    lastIncomeId = newLastIncomeId;
}*/
