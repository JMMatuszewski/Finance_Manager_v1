#include "FinancialManager.h"

/// Method that plays a role of GUI ///
char FinancialManager::getMainMenuChoice()
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
    choice = MinorMethods::minorReadChar();

    return choice;
}

/// Method to login a user ///
/// Created object to work on the data. ///
void FinancialManager::userLogin()
{
    userManager.userLogin();

    if(userManager.checkIfUserLogged())
    {
        userFinancesManager = new UserFinancesManager(INCOMES_FILENAME, EXPENSES_FILENAME, userManager.getLoggedUserId());
    }
}

void FinancialManager::showUsers()
{
    userManager.showUsers();
}

void FinancialManager::userRegister()
{
    userManager.userRegister();
}

int FinancialManager::getLoggedUserId()
{
    userManager.getLoggedUserId();
}

char FinancialManager::getFinanceMenuChoice()
{
    userManager.getFinanceMenuChoice();
}

/////////////// FINANCES ////////////////

void FinancialManager::addIncome()
{
    userFinancesManager -> addIncome();
}

void FinancialManager::addExpense()
{
    userFinancesManager -> addExpense();
}

void FinancialManager::userLogout()
{
    userManager.userLogout();
    delete userFinancesManager;
    userFinancesManager = NULL;
}

void FinancialManager::showIncomes()
{
    userFinancesManager -> showIncomes();
}

void FinancialManager::showExpenses()
{
    userFinancesManager -> showExpenses();
}

void FinancialManager::currentMonth()
{
    userFinancesManager -> currentMonth();
}

void FinancialManager::previousMonth()
{
    userFinancesManager -> previousMonth();
}

void FinancialManager::choosePeriod()
{
    userFinancesManager -> choosePeriod();
}

void FinancialManager::changePass()
{
    userManager.changePass();
}
/// TMP ///
/*
int Financial_Manager::getLastIncomeId()
{
    return userFinances_Manager -> getLastIncomeId();
}*/
/// TMP ///
