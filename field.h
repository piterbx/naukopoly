#ifndef FIELD_H
#define FIELD_H
#include <string>
using namespace std;

class Field{
private:
        string schoolName[2];
        int price;
        int owner;
        int houses; // are we doing hotels?
        int totalValue; // price of house +

public:
    Field();
};

#endif // FIELD_H
