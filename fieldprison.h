#ifndef FIELDPRISON_H
#define FIELDPRISON_H
#include "field.h"

class FieldPrison: public Field
{
private:
    bool Prisoner;
public:
    FieldPrison();
    void isPlayerPrisoner(bool Prisoner);

};

#endif // FIELDPRISON_H
