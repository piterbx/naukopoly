#include "field.h"
#include <iostream>

int Field::getTotalValue() const
{
    return totalValue;
}

int Field::getHousePrice()
{
    return housePrice;
}

Field::Field()
{
    rent = 20;
    owner = -1; //bank
    houses = 0;
    housePrice = 10;
    totalValue = rent;
}

void Field::setFieldName(string inputName)
{
    fieldName = inputName;
}

void Field::setPropertyPrice(int inputPrice)
{
    price = inputPrice;
}

void Field::setOwner(int owner)
{
    this->owner = owner;
}

void Field::setCanBePurchased(bool canBePurchased)
{
    this->canBePurchased = canBePurchased;
}

void Field::setHouses(int inputHouses)
{
    houses = inputHouses;
    totalValue = rent * ((houses + 2) * 0.5);
}

void Field::setHousePrice(int housePrice)
{
    this->housePrice = housePrice;
}

bool Field::canIUpgradeHouses()
{
    if(houses < 3){
        houses++;
        totalValue = rent * ((houses + 2) * 0.5);
        return true;
    }
    else{
        return false;
    }
}

int Field::getPropertyPrice()
{
    return price;
}

int Field::getOwner()
{
    return owner;
}

bool Field::getCanBePurchased()
{
    return canBePurchased;
}

int Field::getHouses()
{
    return houses;
}

string Field::getFieldName()
{
    return fieldName;
}




