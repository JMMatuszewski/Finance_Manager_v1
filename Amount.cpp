#include "Amount.h"

/// Setter of ID in Amount object ///
/// Id says to which user belongs ///
/// the object.                   ///
bool Amount::setId(int newId)
{
    if (newId > 0)
    {
        id = newId;
        return true;
    }
    return false;
}

/// Setter of Date in Amount object  ///
/// Date says when the flow of money ///
/// occured.                         ///
bool Amount::setDate(int newDate)
{
    if (newDate > 0)
    {
        date = newDate;
        return true;
    }
    return false;
}

/// Setter of Amount Id in Amount object   ///
/// Amount Id gives order in which objects ///
/// were added, helping in managing.       ///
bool Amount::setAmountId(int newAmountId)
{
    if (newAmountId > 0)
    {
        amountId = newAmountId;
        return true;
    }
    return false;
}

/// Setter of Item in Amount object   ///
/// Item is the name of the reason of ///
/// flow of money given by user       ///
bool Amount::setItem(string newItem)
{
    if (newItem != "")
    {
        item = newItem;
        return true;
    }
    return false;
}

/// Setter of Amount in Amount object  ///
/// Amount is the amount of money that ///
/// happens to flow.                   ///
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
/// Getter of ID in Amount object ///
int Amount::getId()
{
    return id;
}

/// Getter of Date in Amount object ///
int Amount::getDate()
{
    return date;
}

/// Getter of AmountId in Amount object ///
int Amount::getAmountId()
{
    return amountId;
}

/// Getter of Item in Amount object   ///
string Amount::getItem()
{
    return item;
}

/// Getter of Amount in Amount object   ///
double Amount::getAmount()
{
    return amount;
}
