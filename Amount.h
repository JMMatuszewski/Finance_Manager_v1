#ifndef AMOUNT_H
#define AMOUNT_H

#include <iostream>

using namespace std;

class Amount
{
    int id;
    int date;
    int amountId;
    string item;
    double amount;
public:
    bool setId(int newId);
    bool setDate(int newDate);
    bool setAmountId(int newAmountId);
    bool setItem(string newItem);
    bool setAmount(double newAmount);

    int getId();
    int getDate();
    int getAmountId();
    string getItem();
    double getAmount();
};

#endif
