#include "Amount.h"

bool Amount::setId(int newId)
{
    if (newId > 0)
    {
        id = newId;
        return true;
    }
    return false;
}

bool Amount::setDate(int newDate)
{
    if (newDate > 0)
    {
        date = newDate;
        return true;
    }
    return false;
}

bool Amount::setAmountId(int newAmountId)
{
    if (newAmountId > 0)
    {
        amountId = newAmountId;
        return true;
    }
    return false;
}

bool Amount::setItem(string newItem)
{
    if (newItem != "")
    {
        item = newItem;
        return true;
    }
    return false;
}

bool Amount::setAmount(double newAmount)
{
    if (newAmount > 0)
    {
        amount = newAmount;
        return true;
    }
    return false;
}
//////////////////////////////////////////////////////
int Amount::getId()
{
    return id;
}

int Amount::getDate()
{
    return date;
}

int Amount::getAmountId()
{
    return amountId;
}

string Amount::getItem()
{
    return item;
}

double Amount::getAmount()
{
    return amount;
}
