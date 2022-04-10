#ifndef MINORMETHODS_H
#define MINORMETHODS_H

#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Class with all the additional methods
class MinorMethods
{

    //static int extractMonth(string date);
    static int extractYear(int date);
    static int extractDay(int date);
    static bool checkYear(int year);
    static bool checkMonth(int month);
public:
    static string minorReadLine();
    static char minorReadChar();
    static int getCurDate();
    static int getDays(int m, int y);
    static int mergeDate(string date);
    static bool checkDate(string date);
    static int extractMonth(int date);
    static void printDate(int date);
    static string toStringWithPrecision(double fAmount);
    static bool checkIfNumber(string& num);
};

#endif
