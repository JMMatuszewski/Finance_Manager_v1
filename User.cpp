#include "User.h"

///////////////////// GETTERS //////////////////////////
void User::setId(int newId)
{
    if (newId > 0)
    {
        id = newId;
    }
}

void User::setName(string newName)
{
    if (newName != "")
    {
        name = newName;
    }
}

void User::setSurname(string newSurname)
{
    if (newSurname != "")
    {
        surname = newSurname;
    }
}

void User::setLogin(string newLogin)
{
    if (newLogin != "")
    {
        login = newLogin;
    }
}

void User::setPass(string newPass)
{
    if (newPass != "")
    {
        pass = newPass;
    }
}
///////////////////// SETTERS //////////////////////////
int User::getId()
{
    return id;
}

string User::getName()
{
    return name;
}

string User::getSurname()
{
    return surname;
}

string User::getLogin()
{
    return login;
}

string User::getPass()
{
    return pass;
}

