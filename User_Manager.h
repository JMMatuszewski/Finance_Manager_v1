#ifndef USERMANAGER_H
#define USERMANAGER_H
#define NULL 0

#include <iostream>
#include <vector>
//#include <windows.h>

#include "User.h"
#include "Minor_Methods.h"
#include "User_File.h"

using namespace std;

class User_Manager
{
    int loggedUserId;
    User_File user_File;
    vector <User> users;
    ///////// private methods /////////
    bool get_NewUser(User *pUser);
    int get_LastId();
    bool check_Login(User *pUser);
    ///////////////////////////////////

public:
    User_Manager(string userFileName) : user_File(userFileName){
    loggedUserId = 0;
    users = user_File.loadUsersFromFile();
    };
    void user_Login();
    void show_Users();
    void user_Register();
    int getLoggedUserId();
    char getFinanceMenuChoice();
    bool check_IfUserLogged();
    void userLogout();

};

#endif
