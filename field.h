#ifndef FIELD_H
#define FIELD_H
#include <string>
#include <vector>
using namespace std;

struct Card{
    string info;
    int money;
};

class Field{
private:
        string fieldName; // "Politechnika" "Lubelska"
        int price;
        int owner;
        bool canBePurchased;
        int rent;
        int houses; // are we doing hotels?
        int housePrice;
        int totalValue; // price of house +
        // tax = 0.1 * totalValue
        vector<Card> cards;
public:
    Field();
    // set values
    void setFieldName(string inputName);
    void setPropertyPrice(int inputPrice);
    void setOwner(int owner);
    void setCanBePurchased(bool canBePurchased);
    void setHouses(int inputHouses);
    void setHousePrice(int housePrice);
    bool canIUpgradeHouses();
    // get values
    // getname? index?
    int getPropertyPrice();
    int getOwner();
    bool getCanBePurchased();
    int getHouses();
    string getFieldName();
    int getTotalValue() const;
    int getHousePrice();
    void makeAction();
};

#endif // FIELD_H
