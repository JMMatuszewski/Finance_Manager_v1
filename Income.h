#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int id;
    string date;
    int incomeId;
    string item;
    double amount;
public:
    bool setId(int newId);
    bool setDate(string newDate);
    bool setIncomeId(int newIncomeId);
    bool setItem(string newItem);
    bool setAmount(double newAmount);

    int getId();
    string getDate();
    int getIncomeId();
    string getItem();
    double getAmount();
};

#endif
