#include "Financial_Manager.h"

char Financial_Manager::getMainMenuChoice()
{
    char choice;
    system("cls");
    cout << ">>> Menadzer prywatnych finansow <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Logowanie" << endl;
    cout << "2. Rejestracja" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = Minor_Methods::minor_ReadChar();

    return choice;
}

void Financial_Manager::user_Login()
{
    user_Manager.user_Login();

    if(user_Manager.check_IfUserLogged())
    {
        userFinances_Manager = new UserFinances_Manager(INCOMES_FILENAME, user_Manager.getLoggedUserId());
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

/*// TMP ///
int Financial_Manager::getLastIncomeId()
{
    return userFinances_Manager -> getLastIncomeId();
}
*/// TMP ///
