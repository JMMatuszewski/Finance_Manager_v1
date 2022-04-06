#ifndef MINOR_METHODS_H
#define MINOR_METHODS_H

#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <iomanip>
//#include "DateParts.h"

using namespace std;

// Class with all the additional methods
class Minor_Methods
{

    //static int extractMonth(string date);
    static int extractYear(int date);
    static int extractDay(int date);
    static bool checkYear(int year);
    static bool checkMonth(int month);
public:
    static string minor_ReadLine();
    static char minor_ReadChar();
    static int getCurDate();
    static int getDays(int m, int y);
    static int mergeDate(string date); //prv?
    static bool checkDate(string date);
    static int extractMonth(int date);
    static void printDate(int date);
    static string toStringWithPrecision(double fAmount);
    static bool checkIfNumber(string& num);
    /// PRV? ///
    //static int extractMonth(int date);

    //static bool checkIfNumber(string& num);

    //static DateParts getDateParts(string date);
};

#endif
