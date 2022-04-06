#include "User_File.h"

/// Method to load accessible users from xml file ///
vector<User> User_File::loadUsersFromFile()
{
    CMarkup xml;
    User user;
    vector<User> users;

    xml.Load(getFileName());
    xml.ResetPos();
    if(xml.FindElem("USERS"))
    {
        xml.IntoElem();
        while(xml.FindElem("USER"))
        {
            xml.IntoElem();
            /// GET DATA FROM XML ///
            xml.FindElem("LOGIN");
            user.setLogin(xml.GetElemContent());

            xml.FindElem("PASS");
            user.setPass(xml.GetElemContent());

            xml.FindElem("ID");
            user.setId(atoi(xml.GetElemContent().c_str()));

            xml.FindElem("NAME");
            user.setName(xml.GetElemContent());

            xml.FindElem("SURNAME");
            user.setSurname(xml.GetElemContent());
            //////////////////////////
            xml.OutOfElem();
            users.push_back(user);
        }
    }
    return users;
}

/// Method to add new user to file ///
void User_File::add_UserToFile(User user)
{
    CMarkup xml;

    cout << "addint to file\n";
    xml.Load( getFileName() );
    xml.ResetPos();
    if(xml.FindElem("USERS")){}
    else
    {
        xml.AddElem("USERS");
    }

    xml.IntoElem();
    xml.AddElem("USER");
    xml.IntoElem();

    xml.AddElem("LOGIN",user.getLogin());
    xml.AddElem( "PASS", user.getPass());
    xml.AddElem( "ID", user.getId());
    xml.AddElem( "NAME", user.getName());
    xml.AddElem( "SURNAME", user.getSurname());

	xml.Save( getFileName() );
}
