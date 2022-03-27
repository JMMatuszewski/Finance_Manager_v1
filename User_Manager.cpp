#include "User_Manager.h"

char User_Manager::getFinanceMenuChoice()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesi¹ca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = Minor_Methods::minor_ReadChar();

    return choice;
}

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

void User_Manager::user_Register()
{
    User user;
    bool status = get_NewUser(&user);

    users.push_back(user);



    user_File.add_UserToFile(user);


}

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

bool User_Manager::check_Login(User *pUser)
{
    for (vector<User>::iterator itr = users.begin(); itr != users.end() ; itr++)
    {
        if (itr -> getLogin() == pUser -> getLogin())
            return false;
    }
    return true;
}

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

int User_Manager::get_LastId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

int User_Manager::getLoggedUserId()
{
    return loggedUserId;
}

bool User_Manager::check_IfUserLogged()
{
    if (loggedUserId > 0)
        return true;
    else
        return false;
}
