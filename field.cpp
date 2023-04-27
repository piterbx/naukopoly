#include "field.h"
#include <iostream>

Field::Field()
{

}

void Field::setSchoolName(string inputName)
{
    schoolName[0] = inputName;
}

void Field::setPropertyPrice(int inputPrice)
{
    price = inputPrice;
}

void Field::setHouses(int inputHouses)
{
    houses = inputHouses;
}

bool Field::HouseUpdate()
{
    if(houses < 3){
        totalValue = totalValue * 2;
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

int Field::getHouses()
{
    return houses;
}


