#include "Income.h"

bool Income::setId(int newId)
{
    if (newId > 0)
    {
        id = newId;
        return true;
    }
    return false;
}

bool Income::setDate(string newDate)
{
    if (newDate != "")
    {
        date = newDate;
        return true;
    }
    return false;
}

bool Income::setIncomeId(int newIncomeId)
{
    if (newIncomeId > 0)
    {
        incomeId = newIncomeId;
        return true;
    }
    return false;
}

bool Income::setItem(string newItem)
{
    if (newItem != "")
    {
        item = newItem;
        return true;
    }
    return false;
}

bool Income::setAmount(double newAmount)
{
    if (newAmount > 0)
    {
        amount = newAmount;
        return true;
    }
    return false;
}
//////////////////////////////////////////////////////
int Income::getId()
{
    return id;
}

string Income::getDate()
{
    return date;
}

int Income::getIncomeId()
{
    return incomeId;
}

string Income::getItem()
{
    return item;
}

double Income::getAmount()
{
    return amount;
}
