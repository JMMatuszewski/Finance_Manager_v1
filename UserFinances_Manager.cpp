#include "UserFinances_Manager.h"

/// Method to add new income ///
void UserFinances_Manager::addIncome()
{
    Amount amount;

    bool status = get_NewIncome(&amount);
    if (status)
    {
        incomes.push_back(amount);
        sort(incomes.begin(), incomes.end());
        incomes_File.writeIncomes(amount,LOGGED_USER_ID);
    }
    else
    {
        cout << "ERROR occured during adding new Income: " << status << endl;
        system("pause");
    }
}

/// Method to get data about new income ///
bool UserFinances_Manager::get_NewIncome(Amount* pIncome)
{
    bool status;
    int attempts = 3;
    system("cls");

    status = pIncome -> setId(LOGGED_USER_ID);
    if(status){}
    else return status;

    status = pIncome -> setDate(Minor_Methods::getCurDate());
    if(status){}
    else return status;

    status = pIncome -> setAmountId(incomes_File.getLastIncomeId() + 1);
    if (status){}
    else return status;

    cout << "Podaj Item:" << endl;
    status = pIncome -> setItem(Minor_Methods::minor_ReadLine());
    if(status){}
    else return status;

    cout << "Podaj Kwote:" << endl;
    string strAmount = Minor_Methods::minor_ReadLine();
    replace(strAmount.begin(),strAmount.end(),',','.');
    if(status = Minor_Methods::checkIfNumber(strAmount)){}
    else return status;
    if(pIncome -> setAmount(stod(strAmount))){}
    else return status;

    cout << "1. Current date." << endl;
    cout << "2. Custom date." << endl;
    int option = Minor_Methods::minor_ReadChar();
    while(true)
    {
        if (option == '1')
        {
            status = pIncome -> setDate(Minor_Methods::getCurDate());
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
            return status;// = 0;
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
void UserFinances_Manager::addExpense()
{
    Amount amount;

    bool status = get_NewExpense(&amount);
    if (status)
    {
        expenses.push_back(amount);
        sort(expenses.begin(), expenses.end());
        expenses_File.writeExpenses(amount,LOGGED_USER_ID);
    }
    else
    {
        cout << "ERROR occured during adding new Item: " << status << endl;
        system("pause");
    }
}

/// Method to get data about new expense ///
bool UserFinances_Manager::get_NewExpense(Amount* pExpense)
{
    bool status;
    int attempts = 3;
    system("cls");

    status = pExpense -> setId(LOGGED_USER_ID);
    if(status){}
    else return status;

    status = pExpense -> setDate(Minor_Methods::getCurDate());
    if(status){}
    else return status;

    status = pExpense -> setAmountId(expenses_File.getLastExpenseId() + 1);
    if (status){}
    else return status;

    cout << "Podaj Item:" << endl;
    status = pExpense -> setItem(Minor_Methods::minor_ReadLine());
    if(status){}
    else return status;

    cout << "Podaj Kwote:" << endl;
    string strAmount = Minor_Methods::minor_ReadLine();
    replace(strAmount.begin(),strAmount.end(),',','.');
    if(status = Minor_Methods::checkIfNumber(strAmount)){}
    else return status;
    if(pExpense -> setAmount(stod(strAmount))){}
    else return status;

    cout << "1. Current date." << endl;
    cout << "2. Custom date." << endl;
    int option = Minor_Methods::minor_ReadChar();
    while(true)
    {
        if (option == '1')
        {
            status = pExpense -> setDate(Minor_Methods::getCurDate());
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
            return status;// = 0;
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
    system("pause");
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
    system("pause");
}
/// TMP ///

/// Method to handle all the operations ///
/// to show bilans from current month   ///
void UserFinances_Manager::currentMonth()
{
    int date = Minor_Methods::getCurDate();
    showBilans(Minor_Methods::extractMonth(date), Minor_Methods::extractMonth(date),1);
}

/// Method to show bilans ///
/// option = 1 | month
/// option = 2 | full date
void UserFinances_Manager::showBilans(int startDate, int endDate, int option)
{
    if (option == 1)
    {
        //cout << "opcja 1\n";
        //cout << "start: " << startDate << endl;
        //cout << "end: " << endDate << endl;
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
double UserFinances_Manager::calcMonthSum(vector<Amount> vectorName, int startDate, int endDate)
{
    //vector<Amount> bilans;
    double sum = 0;

    for (vector<Amount>::iterator itr = vectorName.begin() ; itr != vectorName.end() ; itr++)
    {
        if ((Minor_Methods::extractMonth(itr->getDate()) <= endDate) && (Minor_Methods::extractMonth(itr->getDate()) >= startDate))
        {
            sum += itr->getAmount();
            cout << "---------------------" << endl;
            cout << "Date:"; Minor_Methods::printDate(itr->getDate());
            cout << "Item: " << itr->getItem() << endl;
            cout << "Amount: " << itr->getAmount() << endl;
            cout << endl;
            //bilans.push_back(itr);
        }
    }
    //showBilansParts(bilans);
    return sum;
}

/// Method to calculate precise bilans ///
/// in certain period.                 ///
double UserFinances_Manager::calcPreciseSum(vector<Amount> vectorName, int startDate, int endDate)
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
void UserFinances_Manager::previousMonth()
{
    int date = Minor_Methods::getCurDate();
    int month = Minor_Methods::extractMonth(date) - 1;
    if (month == 0)
        month = 12;
    showBilans(month, month, 1);
}

/// Method to choose perion in which ///
/// will be calculated bilans.       ///
void UserFinances_Manager::choosePeriod()
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
int UserFinances_Manager::chooseDate()
{
    cout << "Please pass date in rrrr-mm-dd format:" << endl;
    string date = Minor_Methods::minor_ReadLine();

    if (!(Minor_Methods::checkDate(date)))
    {
        cout << "ERROR: pls hold to the right format and past or current date." << endl;
        system("pause");
        return 0;
    }

    return Minor_Methods::mergeDate(date);
}

/// TMP ///
/*
int UserFinances_Manager::getLastIncomeId()
{
    return incomes_File.getLastIncomeId();
}*/
/// TMP ///
