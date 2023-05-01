#include "field.h"
#include <iostream>

Field::Field()
{
    owner = 5; //bank or none
    houses = 0;
}

void Field::setFieldName(string inputName)
{
    fieldName = inputName;
}

void Field::setPropertyPrice(int inputPrice)
{
    price = inputPrice;
}

void Field::setHouses(int inputHouses)
{
    houses = inputHouses;
}

bool Field::canIUpgradeHouses()
{
    if(houses < 3){
        totalValue = rent * ((houses + 2) * 0.5);
        houses++;
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

int Field::getHouses()
{
    return houses;
}

string Field::getFieldName()
{
    return fieldName;
}




