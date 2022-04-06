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
        cout << "ERROR: wrong char." << endl;
    }
    return chrInput;
}

int Minor_Methods::getCurDate()
{
    /////////// TIME VARIABLES ////////////
    time_t rawtime;// = time(0);
    struct tm * timeinfo;
    char date_char[80];
    string date;
    int intDate;
    /////////// TIME OPERATIONS ///////////
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    //cout << timeinfo << endl;
    strftime (date_char,80,"%Y%m%d",timeinfo);
    //cout << date_char << endl;
    date = date_char;
    intDate = atoi(date.c_str());
    //cout << date << endl;
    //mergedDate = mergeDate(date);
    //cout << "cur date: " << mergedDate << endl;
    return intDate;
}

int Minor_Methods::mergeDate(string date)
{
    string mergedDate;
    int intMergedDate;

    for (int position = 0; position < date.length(); position++)
    {
        if ((date[position] == '-')){}// || (position+1 == date.length())){}
        else
        {
            mergedDate += date[position];
        }
    }

    intMergedDate = atoi(mergedDate.c_str());
    return intMergedDate;
}

bool Minor_Methods::checkDate(string date)
{
    bool status = false;
    string mergedDate;

    if (!(date.length() == 10))
        return false;

    for (int position = 0; position < date.length(); position++)
    {
        if ((position == 4) || (position == 7) || (position+1 == date.length())){}
        else
        {
            mergedDate += date[position];
        }
    }

    if(!checkIfNumber(mergedDate))
        return false;

    int intMergedDate = atoi(mergedDate.c_str());
    /// SPRAWDZIC MIESIAC I DNI ///
    if(!checkMonth(extractMonth(intMergedDate)))
        return false;

    if( !(getDays(extractMonth(intMergedDate), extractYear(intMergedDate)) >= extractDay(intMergedDate)) )
        return false;
    /// SPRAWDZIC MIESIAC I DNI ///

    if (!(getCurDate() >= atoi(mergedDate.c_str())))
        return false;

    return true;


    //if(checkIfNumber(mergedDate))
        //return status = true;
}

// troche eksperyment ale dziala, zwraca 0/1
bool Minor_Methods::checkIfNumber(string& num)
{
    string::iterator itr = num.begin();
    while (itr != num.end() && isdigit(*itr)) ++itr;
    return !num.empty() && itr == num.end();
}
//PRV
int Minor_Methods::extractYear(int date)
{
    string strDate = to_string(date);
    return atoi((strDate.substr(0,4)).c_str());
}

int Minor_Methods::extractMonth(int date)
{
    string strDate = to_string(date);
    return atoi((strDate.substr(4,2)).c_str());
}

//PRV
int Minor_Methods::extractDay(int date)
{
    string strDate = to_string(date);
    return atoi((strDate.substr(6,2)).c_str());
}
//PRV
bool Minor_Methods::checkYear(int year)
{
    if ( (year >= 2000) && (year <= extractYear(getCurDate())))
        return true;
    else return false;
}
//PRV
bool Minor_Methods::checkMonth(int month)
{
    if ( (month >= 0) && (month <= 12) )    /// WAZNE /// ZASTISIWAC "if (expr) return true; return false;! Just write return expr;"
        return true;
    else return false;
}

// Function returning number of days of the given month.
// Will help in operations on counting days from one date to another.
int Minor_Methods::getDays(int m, int y)
{
    if (m==2)
    {
        if((y%100 == 0 && y%400==0) || (y%100!= 0 && y%4==0))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    switch(m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    }
}

void Minor_Methods::printDate(int date)
{
    string strDate = to_string(date);
    cout << "Date: " << strDate.substr(0,4) << "-" << strDate.substr(4,2) << "-" << strDate.substr(6,2) << endl;
}

// Function to convert float data to string,
// with certain precision - in this case 2 numbers.
string Minor_Methods::toStringWithPrecision(double fAmount)
{
    string strAmount;
    stringstream stream;
    stream << fixed << setprecision(2) << fAmount;
    strAmount = stream.str();
    return strAmount;
}


// Function to convert from string (Loaded from xml)
// to class year,month,day, for easier operations on date later.
/*
DateParts Minor_Methods::getDateParts(string date)
{
    DateParts dateparts;
    string datepart = "";
    int part=0;
    for (int position = 0; position < date.length(); position++)
    {
        if ((date[position] == '-') || (position+1 == date.length()))
        {
            part++;
            switch(part)
            {
            case 1:
                dateparts.year = atoi(datepart.c_str());
                break;
            case 2:
                dateparts.month = atoi(datepart.c_str());
                break;
            case 3:
                datepart += date[position];
                dateparts.day = atoi(datepart.c_str());
                break;
            }
            datepart = "";
        }
        else
        {
            datepart += date[position];
        }
    }
    return dateparts;
}
*/
