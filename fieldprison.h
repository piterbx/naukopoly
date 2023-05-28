#ifndef FIELDPRISON_H
#define FIELDPRISON_H
#include "field.h"

class FieldPrison: public Field
{
private:
public:
    FieldPrison();
    void isPlayerPrisoner(); // for display todo
    void setPrison();
    // setPrisonTime(use different name) for current player
};

#endif // FIELDPRISON_H
