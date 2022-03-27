#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User
{
    int id;
    string name;
    string surname;
    string login;
    string pass;
public:
    void setId(int newId);
    void setName(string newName);
    void setSurname(string newSurname);
    void setLogin(string newLogin);
    void setPass(string newPass);

    int getId();
    string getName();
    string getSurname();
    string getLogin();
    string getPass();
};

#endif
