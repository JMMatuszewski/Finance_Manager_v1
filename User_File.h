#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "XML_File.h"
#include "Markup.h"

using namespace std;

class User_File : public XML_File
{

public:
    User_File(string userFileName) : XML_File(userFileName){};
    vector<User> loadUsersFromFile();
    void add_UserToFile(User user);

    //////////////////////////////////////
    //vector<User> loadUserFinances();

};

#endif
