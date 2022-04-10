#include <iostream>

#include "FinancialManager.h"

using namespace std;

int main()
{
    FinancialManager financialManager("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while(true)
    {
        if(financialManager.getLoggedUserId() == 0)
        {
            choice = financialManager.getMainMenuChoice();
            switch(choice)
            {
            case '1':
                financialManager.userLogin();
                break;
            case '2':
                financialManager.userRegister();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << "Nie ma takiego wyboru" << endl;
                system("pause");
                break;
            }
        }
        else
        {
            //financial_Manager.show_Incomes();
            //financial_Manager.show_Expenses();
            //system("pause");
            choice = financialManager.getFinanceMenuChoice();

            switch(choice)
            {
            case '1':
                financialManager.addIncome();
                break;
            case '2':
                financialManager.addExpense();
                break;
            case '3':
                financialManager.currentMonth();
                break;
            case '4':
                financialManager.previousMonth();
                break;
            case '5':
                financialManager.choosePeriod();
                break;
            case '6':
                financialManager.changePass();
                break;
            case '7':
                financialManager.userLogout();
                break;
            }
        }
    }
    return 0;
}
