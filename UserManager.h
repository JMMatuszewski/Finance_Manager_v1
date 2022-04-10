#ifndef USERMANAGER_H
#define USERMANAGER_H
#define NULL 0

#include <iostream>
#include <vector>

#include "User.h"
#include "MinorMethods.h"
#include "UserFile.h"

using namespace std;

class UserManager
{
    int loggedUserId;
    UserFile userFile;
    vector <User> users;
    ///////// private methods /////////
    bool getNewUser(User *pUser);
    int getLastId();
    bool checkLogin(User *pUser);
    ///////////////////////////////////

public:
    UserManager(string userFileName) : userFile(userFileName){
    loggedUserId = 0;
    users = userFile.loadUsersFromFile();
    };
    void userLogin();
    void showUsers();
    void userRegister();
    int getLoggedUserId();
    char getFinanceMenuChoice();
    bool checkIfUserLogged();
    void changePass();
    void userLogout();

};

#endif
