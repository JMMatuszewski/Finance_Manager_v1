#include "UserFinances_Manager.h"

void UserFinances_Manager::addIncome()
{
    Income income;

    bool status = get_NewIncome(&income);
    if (status)
        incomes.push_back(income);
    else
    {
        cout << "ERROR occured during adding new Item: " << status << endl;
        system("pause");
    }
}

bool UserFinances_Manager::get_NewIncome(Income* pIncome)
{
    bool status;
    system("cls");

    status = pIncome -> setId(LOGGED_USER_ID);
    if(status){}
    else return status;

    status = pIncome -> setDate(Minor_Methods::getDate());
    if(status){}
    else return status;

    status = pIncome -> setIncomeId(incomes_File.getLastIncomeId() + 1);
    if (status){}
    else return status;

    cout << "Podaj Towar:" << endl;
    status = pIncome -> setItem(Minor_Methods::minor_ReadLine());
    if(status){}
    else return status;

    cout << "Podaj Kwote:" << endl;
    if(pIncome -> setAmount(stod(Minor_Methods::minor_ReadLine()))){}
    else return status;

    return status;
}
/*// TMP ///
int UserFinances_Manager::getLastIncomeId()
{
    return incomes_File.getLastIncomeId();
}
*/// TMP ///
