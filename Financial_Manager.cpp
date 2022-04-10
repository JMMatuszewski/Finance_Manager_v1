#include "Financial_Manager.h"

/// Method that plays a role of GUI ///
char Financial_Manager::getMainMenuChoice()
{
    char choice;
    system("cls");
    cout << ">>> Private Finances <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "9. End of Work" << endl;
    cout << "---------------------------" << endl;
    //cout << "Choice: ";
    choice = Minor_Methods::minor_ReadChar();

    return choice;
}

/// Method to login a user ///
/// Created object to work on the data. ///
void Financial_Manager::user_Login()
{
    user_Manager.user_Login();

    if(user_Manager.check_IfUserLogged())
    {
        userFinances_Manager = new UserFinances_Manager(INCOMES_FILENAME, EXPENSES_FILENAME, user_Manager.getLoggedUserId());
    }
}

void Financial_Manager::show_Users()
{
    user_Manager.show_Users();
}

void Financial_Manager::user_Register()
{
    user_Manager.user_Register();
}

int Financial_Manager::getLoggedUserId()
{
    user_Manager.getLoggedUserId();
}

char Financial_Manager::getFinanceMenuChoice()
{
    user_Manager.getFinanceMenuChoice();
}

/////////////// FINANCES ////////////////

void Financial_Manager::addIncome()
{
    userFinances_Manager -> addIncome();
}

void Financial_Manager::addExpense()
{
    userFinances_Manager -> addExpense();
}

void Financial_Manager::userLogout()
{
    user_Manager.userLogout();
    delete userFinances_Manager;
    userFinances_Manager = NULL;
}

void Financial_Manager::show_Incomes()
{
    userFinances_Manager -> show_Incomes();
}

void Financial_Manager::show_Expenses()
{
    userFinances_Manager -> show_Expenses();
}

void Financial_Manager::currentMonth()
{
    userFinances_Manager -> currentMonth();
}

void Financial_Manager::previousMonth()
{
    userFinances_Manager -> previousMonth();
}

void Financial_Manager::choosePeriod()
{
    userFinances_Manager -> choosePeriod();
}

void Financial_Manager::changePass()
{
    user_Manager.changePass();
}
/// TMP ///
/*
int Financial_Manager::getLastIncomeId()
{
    return userFinances_Manager -> getLastIncomeId();
}*/
/// TMP ///
