#include "User_Manager.h"

/// Method that plays the role of GUI ///
char User_Manager::getFinanceMenuChoice()
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
    choice = Minor_Methods::minor_ReadChar();

    return choice;
}

/// Method to login as certain user ///
void User_Manager::user_Login()
{
    string login = "";
    string pass = "";
    //system("cls");
    cout << "Podaj login:" << endl;
    login = Minor_Methods::minor_ReadLine();

    vector<User>::iterator itr = users.begin();
    while(itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int attempt = 0; attempt < 3 ; attempt++)
            {
                cout << "Podaj haslo:" << endl;
                pass = Minor_Methods::minor_ReadLine();

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
void User_Manager::user_Register()
{
    User user;
    bool status = get_NewUser(&user);

    users.push_back(user);



    user_File.add_UserToFile(user);


}

/// Method to get information about ///
/// new user from user input.       ///
bool User_Manager::get_NewUser(User * pUser)
{
    //User user;

    pUser -> setId(get_LastId());
    cout << "Podaj login" << endl;
    pUser -> setLogin(Minor_Methods::minor_ReadLine());
    if (check_Login(pUser)){}
    else
    {
        cout << "Login zajety" << endl;
        return false;// user=nullptr;
    }
    cout << "Podaj haslo" << endl;
    pUser -> setPass(Minor_Methods::minor_ReadLine());
    cout << "Podaj imie" << endl;
    pUser ->setName(Minor_Methods::minor_ReadLine());
    cout << "Podaj nazwisko" << endl;
    pUser -> setSurname(Minor_Methods::minor_ReadLine());

    /*
    cout << "ID: " << puser -> getId() << endl;
    cout << "Login: " << puser -> getLogin() << endl;
    cout << "Pas: " << puser -> getPass() << endl;
    cout << "Name: " << puser -> getName() << endl;
    cout << "Surname: " << puser -> getSurname() << endl;
    */
    return true;
}

/// Method to check if user already exists ///
bool User_Manager::check_Login(User *pUser)
{
    for (vector<User>::iterator itr = users.begin(); itr != users.end() ; itr++)
    {
        if (itr -> getLogin() == pUser -> getLogin())
            return false;
    }
    return true;
}

/// Method to show all the accessible users ///
void User_Manager::show_Users()
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
int User_Manager::get_LastId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

/// Method to extract id of logged user ///
int User_Manager::getLoggedUserId()
{
    return loggedUserId;
}

/// Method to check if there is logged any user ///
bool User_Manager::check_IfUserLogged()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}

void User_Manager::changePass()
{
    string newPass = "";
    cout << "Print new password: ";
    newPass = Minor_Methods::minor_ReadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == loggedUserId)
        {
            itr -> setPass(newPass);
            cout << "Password changed." << endl;
            system("pause");
            user_File.editUserPass(loggedUserId, newPass);
            break;
        }
    }
}

/// Method to logout user ///
void User_Manager::userLogout()
{
    loggedUserId = 0;
}
