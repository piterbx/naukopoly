#ifndef FIELD_H
#define FIELD_H
#include <string>
using namespace std;

class Field{
private:
        string fieldName; // "Politechnika" "Lubelska"
        int price;
        int owner;
        int rent;
        int houses; // are we doing hotels?
        int totalValue; // price of house +
        // tax = 0.1 * totalValue
public:
    Field();
    // set values
    void setFieldName(string inputName);
    void setPropertyPrice(int inputPrice);
    void setOwner(int owner);
    void setHouses(int inputHouses);
    bool canIUpgradeHouses();
    // get values
    // getname? index?
    int getPropertyPrice();
    int getOwner();
    int getHouses();
    string getFieldName();
};

#endif // FIELD_H
