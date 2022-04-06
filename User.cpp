#include "User.h"

///////////////////// Setters //////////////////////////
/// Setter of Id in User object ///
void User::setId(int newId)
{
    if (newId > 0)
    {
        id = newId;
    }
}
/// Setter of Name in User object ///
void User::setName(string newName)
{
    if (newName != "")
    {
        name = newName;
    }
}
/// Setter of Surname in User object ///
void User::setSurname(string newSurname)
{
    if (newSurname != "")
    {
        surname = newSurname;
    }
}
/// Setter of Login in User object ///
void User::setLogin(string newLogin)
{
    if (newLogin != "")
    {
        login = newLogin;
    }
}
/// Setter of Password in User object ///
void User::setPass(string newPass)
{
    if (newPass != "")
    {
        pass = newPass;
    }
}
///////////////////// Getters //////////////////////////
/// Getter of Id in User object ///
int User::getId()
{
    return id;
}
/// Getter of Name in User object ///
string User::getName()
{
    return name;
}
/// Getter of Surname in User object ///
string User::getSurname()
{
    return surname;
}
/// Getter of Login in User object ///
string User::getLogin()
{
    return login;
}
/// Getter of Password in User object ///
string User::getPass()
{
    return pass;
}

