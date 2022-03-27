#include "UserFinances_Manager.h"

void UserFinances_Manager::addIncome()
{
    Amount amount;

    bool status = get_NewIncome(&amount);
    if (status)
        incomes.push_back(amount);
    else
    {
        cout << "ERROR occured during adding new Item: " << status << endl;
        system("pause");
    }
}

bool UserFinances_Manager::get_NewIncome(Amount* pIncome)
{
    bool status;
    system("cls");

    status = pIncome -> setId(LOGGED_USER_ID);
    if(status){}
    else return status;

    status = pIncome -> setDate(Minor_Methods::getDate());
    if(status){}
    else return status;

    status = pIncome -> setAmountId(incomes_File.getLastIncomeId() + 1);
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
//////////////////////////////////////////
void UserFinances_Manager::addExpense()
{
    Amount amount;

    bool status = get_NewExpense(&amount);
    if (status)
        expenses.push_back(amount);
    else
    {
        cout << "ERROR occured during adding new Item: " << status << endl;
        system("pause");
    }
}

bool UserFinances_Manager::get_NewExpense(Amount* pExpense)
{
    bool status;
    system("cls");

    status = pExpense -> setId(LOGGED_USER_ID);
    if(status){}
    else return status;

    status = pExpense -> setDate(Minor_Methods::getDate());
    if(status){}
    else return status;

    status = pExpense -> setAmountId(expenses_File.getLastExpenseId() + 1);
    if (status){}
    else return status;

    cout << "Podaj Towar:" << endl;
    status = pExpense -> setItem(Minor_Methods::minor_ReadLine());
    if(status){}
    else return status;

    cout << "Podaj Kwote:" << endl;
    if(pExpense -> setAmount(stod(Minor_Methods::minor_ReadLine()))){}
    else return status;

    return status;
}

/// TMP ///

void UserFinances_Manager::show_Incomes()
{
    for (int i=0; i<incomes.size();i++)
    {
        cout << incomes[i].getId() << endl;
        cout << incomes[i].getDate() << endl;
        cout << incomes[i].getAmountId() << endl;
        cout << incomes[i].getItem() << endl;
        cout << incomes[i].getAmount() << endl;
        cout << endl;
    }
}

void UserFinances_Manager::show_Expenses()
{
    for (int i=0; i<expenses.size();i++)
    {
        cout << expenses[i].getId() << endl;
        cout << expenses[i].getDate() << endl;
        cout << expenses[i].getAmountId() << endl;
        cout << expenses[i].getItem() << endl;
        cout << expenses[i].getAmount() << endl;
        cout << endl;
    }
}
/*
int UserFinances_Manager::getLastIncomeId()
{
    return incomes_File.getLastIncomeId();
}*/
/// TMP ///
