#include "Minor_Methods.h"

// Method to read the line from input
string Minor_Methods::minor_ReadLine()
{
    string line="";
    getline(cin,line);
    return line;
}

char Minor_Methods::minor_ReadChar()
{
    char chrInput = {0};
    string strInput = "";

    while (true)
    {
        getline(cin, strInput);

        if (strInput.length() == 1)
        {
            chrInput = strInput[0];
            break;
        }
        cout << "Blad na wejsciu" << endl;
    }
    return chrInput;
}

string Minor_Methods::getDate()
{
    /////////// TIME VARIABLES ////////////
    time_t rawtime;// = time(0);
    struct tm * timeinfo;
    char date_char[80];
    string date;
    /////////// TIME OPERATIONS ///////////
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    //cout << timeinfo << endl;
    strftime (date_char,80,"%Y-%m-%d",timeinfo);
    //cout << date_char << endl;
    date = date_char;
    //cout << date << endl;
    return date;
}

