#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class UserFile : public XMLFile
{

public:
    UserFile(string userFileName) : XMLFile(userFileName){};
    vector<User> loadUsersFromFile();
    void addUserToFile(User user);
    void editUserPass(int loggedUserId, string newPass);
};

#endif
