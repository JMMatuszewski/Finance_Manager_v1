#include "UserFinancesManager.h"

/// Method to add new income ///
void UserFinancesManager::addIncome()
{
    Amount amount;

    bool status = getNewIncome(&amount);
    if (status)
    {
        incomes.push_back(amount);
        sort(incomes.begin(), incomes.end());
        incomesFile.writeIncomes(amount,LOGGED_USER_ID);
    }
    else
    {
        cout << "ERROR occured during adding new Income: " << status << endl;
        system("pause");
    }
}

/// Method to get data about new income ///
bool UserFinancesManager::getNewIncome(Amount* pIncome)
{
    bool status;
    int attempts = 3;
    system("cls");

    status = pIncome -> setId(LOGGED_USER_ID);
    if(status){}
    else return status;

    status = pIncome -> setDate(MinorMethods::getCurDate());
    if(status){}
    else return status;

    status = pIncome -> setAmountId(incomesFile.getLastIncomeId() + 1);
    if (status){}
    else return status;

    cout << "Podaj Item:" << endl;
    status = pIncome -> setItem(MinorMethods::minorReadLine());
    if(status){}
    else return status;

    cout << "Podaj Kwote:" << endl;
    string strAmount = MinorMethods::minorReadLine();
    replace(strAmount.begin(),strAmount.end(),',','.');
    if(status = MinorMethods::checkIfNumber(strAmount)){}
    else return status;
    if(pIncome -> setAmount(stod(strAmount))){}
    else return status;

    cout << "1. Current date." << endl;
    cout << "2. Custom date." << endl;
    int option = MinorMethods::minorReadChar();
    while(true)
    {
        if (option == '1')
        {
            status = pIncome -> setDate(MinorMethods::getCurDate());
            if(status){return status;}
            else
            {
                cout << "ERROR: during getting current date." << endl;
                return status;
            }
        }
        else if (attempts == 0)
        {
            cout << "ERROR: no attempts left." << endl;
            return status;
        }
        else if (option == '2')
        {
            status = pIncome -> setDate(chooseDate());
            if(status){return status;}
            else
            {
                //cout << "ERROR: during getting custom date." << endl;
                attempts--;
                cout << "Attempts left: " << attempts << endl;
                cout << endl;
                //return status;
            }
        }
        else
        {
            cout << "ERROR: wrong option." << endl;
            attempts--;
            cout << "Attempts left: " << attempts << endl;
            cout << endl;
        }
    }
}

/// Method to add new expense ///
void UserFinancesManager::addExpense()
{
    Amount amount;

    bool status = getNewExpense(&amount);
    if (status)
    {
        expenses.push_back(amount);
        sort(expenses.begin(), expenses.end());
        expensesFile.writeExpenses(amount,LOGGED_USER_ID);
    }
    else
    {
        cout << "ERROR occured during adding new Item: " << status << endl;
        system("pause");
    }
}

/// Method to get data about new expense ///
bool UserFinancesManager::getNewExpense(Amount* pExpense)
{
    bool status;
    int attempts = 3;
    system("cls");

    status = pExpense -> setId(LOGGED_USER_ID);
    if(status){}
    else return status;

    status = pExpense -> setDate(MinorMethods::getCurDate());
    if(status){}
    else return status;

    status = pExpense -> setAmountId(expensesFile.getLastExpenseId() + 1);
    if (status){}
    else return status;

    cout << "Podaj Item:" << endl;
    status = pExpense -> setItem(MinorMethods::minorReadLine());
    if(status){}
    else return status;

    cout << "Podaj Kwote:" << endl;
    string strAmount = MinorMethods::minorReadLine();
    replace(strAmount.begin(),strAmount.end(),',','.');
    if(status = MinorMethods::checkIfNumber(strAmount)){}
    else return status;
    if(pExpense -> setAmount(stod(strAmount))){}
    else return status;

    cout << "1. Current date." << endl;
    cout << "2. Custom date." << endl;
    int option = MinorMethods::minorReadChar();
    while(true)
    {
        if (option == '1')
        {
            status = pExpense -> setDate(MinorMethods::getCurDate());
            if(status){return status;}
            else
            {
                cout << "ERROR: during getting current date." << endl;
                return status;
            }
        }
        else if (attempts == 0)
        {
            cout << "ERROR: no attempts left." << endl;
            return status;
        }
        else if (option == '2')
        {
            status = pExpense -> setDate(chooseDate());
            if(status){return status;}
            else
            {
                //cout << "ERROR: during getting custom date." << endl;
                attempts--;
                cout << "Attempts left: " << attempts << endl;
                cout << endl;
                //return status;
            }
        }
        else
        {
            cout << "ERROR: wrong option." << endl;
            attempts--;
            cout << "Attempts left: " << attempts << endl;
            cout << endl;
        }
    }
}

/// TMP ///
void UserFinancesManager::showIncomes()
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
    system("pause");
}

void UserFinancesManager::showExpenses()
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
    system("pause");
}
/// TMP ///

/// Method to handle all the operations ///
/// to show bilans from current month   ///
void UserFinancesManager::currentMonth()
{
    int date = MinorMethods::getCurDate();
    showBilans(MinorMethods::extractMonth(date), MinorMethods::extractMonth(date),1);
}

/// Method to show bilans ///
/// option = 1 | month
/// option = 2 | full date
void UserFinancesManager::showBilans(int startDate, int endDate, int option)
{
    if (option == 1)
    {
        system("cls");
        cout << ">>> Your incomes <<<" << endl;
        double incomesSum = calcMonthSum(incomes, startDate, endDate);
        cout << ">>> Your expenses <<<" << endl;
        double expensesSum = calcMonthSum(expenses, startDate, endDate);

        //system("cls");
        cout << "Incomes sum: " << incomesSum << endl;
        cout << "Expenses sum: " << expensesSum << endl;
        cout << "Bilans: " << incomesSum - expensesSum << endl;
        system("pause");
    }
    else if(option == 2)
    {
        cout << ">>> Your incomes <<<" << endl;
        double incomesSum = calcPreciseSum(incomes, startDate, endDate);
        cout << ">>> Your expenses <<<" << endl;
        double expensesSum = calcPreciseSum(expenses, startDate, endDate);

        //system("cls");
        cout << "Incomes sum: " << incomesSum << endl;
        cout << "Expenses sum: " << expensesSum << endl;
        cout << "Bilans: " << incomesSum - expensesSum << endl;
        system("pause");
    }

}

/// Method to calculate bilans from few months. ///
double UserFinancesManager::calcMonthSum(vector<Amount> vectorName, int startDate, int endDate)
{
    double sum = 0;

    for (vector<Amount>::iterator itr = vectorName.begin() ; itr != vectorName.end() ; itr++)
    {
        if ((MinorMethods::extractMonth(itr->getDate()) <= endDate) && (MinorMethods::extractMonth(itr->getDate()) >= startDate))
        {
            sum += itr->getAmount();
            cout << "---------------------" << endl;
            cout << "Date:"; MinorMethods::printDate(itr->getDate());
            cout << "Item: " << itr->getItem() << endl;
            cout << "Amount: " << itr->getAmount() << endl;
            cout << endl;
        }
    }
    return sum;
}

/// Method to calculate precise bilans ///
/// in certain period.                 ///
double UserFinancesManager::calcPreciseSum(vector<Amount> vectorName, int startDate, int endDate)
{
    double sum = 0;
    for (vector<Amount>::iterator itr = vectorName.begin() ; itr != vectorName.end() ; itr++)
    {
        if ((itr->getDate() <= endDate) && (itr->getDate() >= startDate))
        {
            sum += itr->getAmount();
            cout << "---------------------" << endl;
            cout << "Item: " << itr->getItem() << endl;
            cout << "Amount: " << itr->getAmount() << endl;
            cout << endl;
        }
    }
    return sum;
}

/// Method to extract month earlier ///
/// than the present one.           ///
void UserFinancesManager::previousMonth()
{
    int date = MinorMethods::getCurDate();
    int month = MinorMethods::extractMonth(date) - 1;
    if (month == 0)
        month = 12;
    showBilans(month, month, 1);
}

/// Method to choose perion in which ///
/// will be calculated bilans.       ///
void UserFinancesManager::choosePeriod()
{
    system("cls");

    cout << "> FROM <" << endl;
    int startDate = chooseDate();
    if (!startDate)
        return;
    cout << "> TO <" << endl;
    int endDate = chooseDate();
    if (!endDate)
        return;
    else if(startDate > endDate)
    {
        cout << "ERROR: Last date is earlier than starting date." << endl;
        system("pause");
        return;
    }
    showBilans(startDate,endDate,2);
}

/// Method to get date from user. ///
int UserFinancesManager::chooseDate()
{
    cout << "Please pass date in rrrr-mm-dd format:" << endl;
    string date = MinorMethods::minorReadLine();

    if (!(MinorMethods::checkDate(date)))
    {
        cout << "ERROR: pls hold to the right format and past or current date." << endl;
        system("pause");
        return 0;
    }

    return MinorMethods::mergeDate(date);
}

/// TMP ///
/*
int UserFinances_Manager::getLastIncomeId()
{
    return incomes_File.getLastIncomeId();
}*/
/// TMP ///
