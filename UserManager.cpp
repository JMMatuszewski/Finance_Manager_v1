#include "UserManager.h"

/// Method that plays the role of GUI ///
char UserManager::getFinanceMenuChoice()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = MinorMethods::minorReadChar();

    return choice;
}

/// Method to login as certain user ///
void UserManager::userLogin()
{
    string login = "";
    string pass = "";
    //system("cls");
    cout << "Podaj login:" << endl;
    login = MinorMethods::minorReadLine();

    vector<User>::iterator itr = users.begin();
    while(itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attempt = 0; attempt < 3 ; attempt++)
            {
                cout << "Podaj haslo:" << endl;
                pass = MinorMethods::minorReadLine();

                if(itr -> getPass() == pass)
                {
                    cout << endl << "Welcome " << itr -> getName() << endl;
                    system("pause");
                    loggedUserId = itr -> getId();
                    return;
                }
                //int attempts_left
                cout << "Wrong login or password" << endl;
                system("pause");
            }
            cout << "No attempts left" << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "No such login found" << endl;
    system("pause");
    return;
}

/// Method to register new user ///
void UserManager::userRegister()
{
    User user;
    bool status = getNewUser(&user);

    users.push_back(user);



    userFile.addUserToFile(user);


}

/// Method to get information about ///
/// new user from user input.       ///
bool UserManager::getNewUser(User * pUser)
{
    //User user;

    pUser -> setId(getLastId());
    cout << "Podaj login" << endl;
    pUser -> setLogin(MinorMethods::minorReadLine());
    if (checkLogin(pUser)){}
    else
    {
        cout << "Login zajety" << endl;
        return false;// user=nullptr;
    }
    cout << "Podaj haslo" << endl;
    pUser -> setPass(MinorMethods::minorReadLine());
    cout << "Podaj imie" << endl;
    pUser ->setName(MinorMethods::minorReadLine());
    cout << "Podaj nazwisko" << endl;
    pUser -> setSurname(MinorMethods::minorReadLine());

    return true;
}

/// Method to check if user already exists ///
bool UserManager::checkLogin(User *pUser)
{
    for (vector<User>::iterator itr = users.begin(); itr != users.end() ; itr++)
    {
        if (itr -> getLogin() == pUser -> getLogin())
            return false;
    }
    return true;
}

/// Method to show all the accessible users ///
void UserManager::showUsers()
{
    for (int i=0; i<users.size();i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPass() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << endl;
    }
}

/// Method to extract id of the last accessible user ///
int UserManager::getLastId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

/// Method to extract id of logged user ///
int UserManager::getLoggedUserId()
{
    return loggedUserId;
}

/// Method to check if there is logged any user ///
bool UserManager::checkIfUserLogged()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

void UserManager::changePass()
{
    string newPass = "";
    cout << "Print new password: ";
    newPass = MinorMethods::minorReadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == loggedUserId)
        {
            itr -> setPass(newPass);
            cout << "Password changed." << endl;
            system("pause");
            userFile.editUserPass(loggedUserId, newPass);
            break;
        }
    }
}

/// Method to logout user ///
void UserManager::userLogout()
{
    loggedUserId = 0;
}
