#include "MinorMethods.h"

/// Method to read the line from input ///
string MinorMethods::minorReadLine()
{
    string line="";
    getline(cin,line);
    return line;
}

/// Method to read the character from input ///
char MinorMethods::minorReadChar()
{
    char chrInput = {0};
    string strInput;

    while (true)
    {
        cout << "Choice: ";
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

/// Method to get current date ///
int MinorMethods::getCurDate()
{
    /////////// TIME VARIABLES ////////////
    time_t rawtime;
    struct tm * timeinfo;
    char dateChar[80];
    string date;
    int intDate;
    /////////// TIME OPERATIONS ///////////
    time (&rawtime);
    timeinfo = localtime(&rawtime);
    strftime (dateChar,80,"%Y%m%d",timeinfo);
    date = dateChar;
    intDate = atoi(date.c_str());
    return intDate;
}

/// Method to delete "-" from date ///
int MinorMethods::mergeDate(string date)
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

/// Method to check if date is correct ///
bool MinorMethods::checkDate(string date)
{
    bool status = false;
    string mergedDate;

    if (!(date.length() == 10))
        return false;

    for (int position = 0; position < date.length(); position++)
    {
        if ((position == 4) || (position == 7)){}// || (position+1 == date.length())){}
        else
        {
            mergedDate += date[position];
        }
    }

    if(!checkIfNumber(mergedDate))
        return false;

    int intMergedDate = atoi(mergedDate.c_str());
    if(!checkMonth(extractMonth(intMergedDate)))
        return false;

    if( !(getDays(extractMonth(intMergedDate), extractYear(intMergedDate)) >= extractDay(intMergedDate)) )
        return false;
        else { cout << "Date is fine \n";}

    if (!(getCurDate() >= atoi(mergedDate.c_str())))
        return false;

    return true;
}

/// Method if string has only numbers ///
/// before converting it to int.      ///
bool MinorMethods::checkIfNumber(string& num)
{
    bool point = false;
    string::iterator itr;
    for (itr = num.begin() ; itr != num.end() ; itr++)
    {
        if (*itr == '.' && point == false)
            point = true;
        else if (*itr != '.' && isdigit(*itr)){}
        else return false;
    }
    //string::iterator itr = num.begin();
    //while(itr != num.end() && isdigit(*itr)) ++itr;
    return !num.empty() && itr == num.end();
}

/// Method to extract year from date ///
int MinorMethods::extractYear(int date)
{
    string strDate = to_string(date);
    return atoi((strDate.substr(0,4)).c_str());
}

/// Method to extract month from date ///
int MinorMethods::extractMonth(int date)
{
    string strDate = to_string(date);
    return atoi((strDate.substr(4,2)).c_str());
}

/// Method to extract day from date ///
int MinorMethods::extractDay(int date)
{
    string strDate = to_string(date);
    return atoi((strDate.substr(6,2)).c_str());
}
/// Method to check if year is correct ///
bool MinorMethods::checkYear(int year)
{
    if ( (year >= 2000) && (year <= extractYear(getCurDate())))
        return true;
    else return false;
}
/// Method to check if month is correct ///
bool MinorMethods::checkMonth(int month)
{
    if ( (month >= 1) && (month <= 12) )    /// WAZNE /// ZASTISIWAC "if (expr) return true; return false;! Just write return expr;"
        return true;
    else return false;
}

/// Function returning number of days of the given month. ///
/// Will help in operations on counting days from one date to another. ///
int MinorMethods::getDays(int m, int y)
{
    if (m==2)
    {
        if((y%100 == 0 && y%400==0) || (y%100!= 0 && y%4==0))
        {
            cout << "02 = 29 \n";
            return 29;
        }
        else
        {
            cout << "02 = 28 \n";
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

/// Method dedicated to printing Date in rrrr-dd-mm format ///
void MinorMethods::printDate(int date)
{
    string strDate = to_string(date);
    cout << "Date: " << strDate.substr(0,4) << "-" << strDate.substr(4,2) << "-" << strDate.substr(6,2) << endl;
}

/// Function to convert float data to string, ///
/// with certain precision - in this case 2 numbers. ///
string MinorMethods::toStringWithPrecision(double fAmount)
{
    string strAmount;
    stringstream stream;
    stream << fixed << setprecision(2) << fAmount;
    strAmount = stream.str();
    return strAmount;
}
