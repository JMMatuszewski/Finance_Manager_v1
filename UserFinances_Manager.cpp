#include "UserFinances_Manager.h"

void UserFinances_Manager::addIncome()
{
    Amount amount;

    bool status = get_NewIncome(&amount);
    if (status)
    {
        incomes.push_back(amount);
        incomes_File.writeIncomes(amount,LOGGED_USER_ID);
    }
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

    status = pIncome -> setDate(Minor_Methods::getCurDate());
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
    {
        expenses.push_back(amount);
        expenses_File.writeExpenses(amount,LOGGED_USER_ID);
    }
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

    status = pExpense -> setDate(Minor_Methods::getCurDate());
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
void UserFinances_Manager::showBilansParts(vector<Amount> bilans)
{
    for (int i=0; i<bilans.size();i++)
    {
        cout << "////////////////////////" << endl;
        cout << bilans[i].getId() << endl;
        cout << bilans[i].getDate() << endl;
        cout << bilans[i].getAmountId() << endl;
        cout << bilans[i].getItem() << endl;
        cout << bilans[i].getAmount() << endl;
        cout << "////////////////////////" << endl;
        cout << endl;
    }
}
*/
void UserFinances_Manager::currentMonth()
{
    int date = Minor_Methods::getCurDate();
    cout << "date: " << date << endl;
    Minor_Methods::printDate(date);
    cout << "extract start: " << Minor_Methods::extractMonth(date) << endl;
    showBilans(Minor_Methods::extractMonth(date), Minor_Methods::extractMonth(date),1);
}

// option = 1 | month
// option = 2 | full
void UserFinances_Manager::showBilans(int startDate, int endDate, int option)
{
    if (option == 1)
    {
        cout << "opcja 1\n";
        cout << "start: " << startDate << endl;
        cout << "end: " << endDate << endl;
        double incomesSum = calcMonthSum(incomes, startDate, endDate);
        double expensesSum = calcMonthSum(expenses, startDate, endDate);

        //system("cls");
        cout << "Incomes sum: " << incomesSum << endl;
        cout << "Expenses sum: " << expensesSum << endl;
        cout << "Bilans: " << incomesSum - expensesSum << endl;
        system("pause");
    }
    else if(option == 2)
    {
        double incomesSum = calcPreciseSum(incomes, startDate, endDate);
        double expensesSum = calcPreciseSum(expenses, startDate, endDate);

        system("cls");
        cout << "Incomes sum: " << incomesSum << endl;
        cout << "Expenses sum: " << expensesSum << endl;
        cout << "Bilans: " << incomesSum - expensesSum << endl;
        system("pause");
    }

}

double UserFinances_Manager::calcMonthSum(vector<Amount> vectorName, int startDate, int endDate)
{
    //vector<Amount> bilans;
    double sum = 0;
    for (vector<Amount>::iterator itr = vectorName.begin() ; itr != vectorName.end() ; itr++)
    {
        if ((Minor_Methods::extractMonth(itr->getDate()) <= endDate) && (Minor_Methods::extractMonth(itr->getDate()) >= startDate))
        {
            sum += itr->getAmount();
            //bilans.push_back(itr);
        }
    }
    //showBilansParts(bilans);
    return sum;
}

double UserFinances_Manager::calcPreciseSum(vector<Amount> vectorName, int startDate, int endDate)
{
    double sum = 0;
    for (vector<Amount>::iterator itr = vectorName.begin() ; itr != vectorName.end() ; itr++)
    {
        if ((itr->getDate() <= endDate) && (itr->getDate() >= startDate))
        {
            sum += itr->getAmount();
        }
    }
    return sum;
}

void UserFinances_Manager::previousMonth()
{
    int date = Minor_Methods::getCurDate();
    int month = Minor_Methods::extractMonth(date) - 1;
    if (month == 0)
        month = 12;
    showBilans(month, month, 1);
}

void UserFinances_Manager::choosePeriod()
{
    system("cls");

    cout << "Daty prosze podac w formacie rrrr-mm-dd" << endl;
    cout << "> OD <" << endl;
    int startDate = chooseDate();
    if (!startDate)
        return;
    cout << "> DO <" << endl;
    int endDate = chooseDate();
    if (!endDate)
        return;

    showBilans(startDate,endDate,2);

    //cout << "Podaj poczatek okresu: " << endl;
    //int startDate = atoi((Minor_Methods::minor_ReadLine()).c_str());
    //cout << "Podaj koniec okresu: " << endl;
    //int endDate = atoi((Minor_Methods::minor_ReadLine()).c_str());

    //cout << "start: " << startDate << endl;
    //cout << "end: " << endDate << endl;
}

int UserFinances_Manager::chooseDate()
{
    string date = Minor_Methods::minor_ReadLine();

    if (!(Minor_Methods::checkDate(date)))
    {
        cout << "ERROR: Podano bledna date, prosze trzymac sie formatu oraz dzisiejszej lub przeszlej daty." << endl;
        return 0;
    }

    return atoi(date.c_str());
}
/// TMP ///
/*
int UserFinances_Manager::getLastIncomeId()
{
    return incomes_File.getLastIncomeId();
}*/
/// TMP ///
