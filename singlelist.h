
#ifndef LISTONEWAY_H
#define LISTONEWAY_H

#include "qlistwidget.h"
#include <string>

struct listElement {
    listElement * next;
    int propertyFieldIndex;
    std::string propertyName; //to display on screen name; = fields[propertyFieldIndex].fieldName
    int boughtHouses; //=fields[propertyFieldIndex].houses; to display on screen how many houses
};


class SingleList
{
    listElement *head;
    listElement *tail;
    int size;
public:
    SingleList();
    ~SingleList();

    void setHeadAndTailToNull();

    int getSize();
    //adding element
    listElement *pushOnHead(listElement *el);
    listElement *pushOnTail(listElement *el);
    //removing element
    listElement *popHead();
    listElement *pushTail();
    listElement *erase(listElement *el);
    //custom function -> find specific element and return this listElement
    listElement *findElement(int value);
    QListWidget *display();
};

#endif // LISTONEWAY_H
