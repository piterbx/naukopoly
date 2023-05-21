#ifndef FIELDCARD_H
#define FIELDCARD_H
#include "field.h"
#include <string>
class FieldCard: public Field{
private:
    string cardName;

public:
    FieldCard();
    virtual void setCard() = 0; // which card is the chosen one
    virtual void setCardText() = 0; // what the card says

};

#endif // FIELDCARD_H
