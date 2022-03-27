#ifndef AMOUNT_H
#define AMOUNT_H

#include <iostream>

using namespace std;

class Amount
{
    int id;
    string date;
    int amountId;
    string item;
    double amount;
public:
    bool setId(int newId);
    bool setDate(string newDate);
    bool setAmountId(int newAmountId);
    bool setItem(string newItem);
    bool setAmount(double newAmount);

    int getId();
    string getDate();
    int getAmountId();
    string getItem();
    double getAmount();
};

#endif
