#ifndef FIELD_H
#define FIELD_H
#include <string>
using namespace std;

class Field{
private:
        string schoolName[2];

        int price;
        //int owner;
        int houses; // are we doing hotels?
        int totalValue; // price of house +
        // tax = 0.1 * totalValue
public:
    Field();
    // set values
    void setSchoolName(string inputName);
    void setPropertyPrice(int inputPrice);
    void setHouses(int inputHouses);
    bool HouseUpdate();
    // get values
    // getname? index?
    int getPropertyPrice();
    int getHouses();
};

#endif // FIELD_H
