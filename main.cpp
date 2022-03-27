#include <iostream>

#include "Financial_Manager.h"

using namespace std;

int main()
{
    Financial_Manager financial_Manager("xml_files/users.xml", "xml_files/incomes.xml");
    char choice;

    while(true)
    {
        if(financial_Manager.getLoggedUserId() == 0)
        {

            choice = financial_Manager.getMainMenuChoice();
            switch(choice)
            {
            case '1':
                financial_Manager.user_Login();
                break;
            case '2':
                financial_Manager.user_Register();
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
            //cout << "Last Id: " << financial_Manager.getLastIncomeId() << endl;
            //system("pause");
            choice = financial_Manager.getFinanceMenuChoice();

            switch(choice)
            {
            case '1':
                financial_Manager.addIncome();
                break;

            }
        }
    }
    //financial_Manager.user_Login(); DONE
    //financial_Manager.show_Users(); DONE
    //financial_Manager.user_Register();


    return 0;
}
