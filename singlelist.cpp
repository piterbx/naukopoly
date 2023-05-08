
#include "singlelist.h"

SingleList::SingleList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

SingleList::~SingleList()
{
    listElement* tmp;

    while(head){
        tmp = head->next;
        delete head;
        head = tmp;
    }
}

void SingleList::setHeadAndTailToNull()
{
    head = nullptr;
    tail = nullptr;
}

int SingleList::getSize()
{
    return size;
}

listElement *SingleList::pushOnHead(listElement *el)
{
    el->next = head;
    head = el;
    if(!tail) tail = head;
    size++;
    return head;
}

listElement *SingleList::pushOnTail(listElement *el)
{
    if(tail) tail->next = el;
    el->next = nullptr;
    tail = el;
    if(!head) head = tail;
    size++;
    return tail;
}

listElement *SingleList::popHead()
{
    listElement *tmp;
    if(head){
        tmp = head;
        head = head->next;
        if(!head) tail = nullptr;
        size--;
        return tmp;
    } else return nullptr;
}

listElement *SingleList::pushTail()
{
    listElement *tmp;
    if(tail){
        tmp = tail;
        if(tmp == head) head = tail = nullptr;
        else {
            tail = head;
            while(tail->next!=tmp) tail = tail->next;
            tail->next = nullptr;
        }
        size--;
        return tmp;
    } else return nullptr;
}

listElement *SingleList::erase(listElement *el)
{
    listElement *tmp;

    if(el==head) return popHead();
    else {
        tmp = head;
        while(tmp->next != tmp) el = el->next;
        tmp->next = el->next;
        if(!tmp->next) tail = tmp;
        size--;
        return el;
    }

}

listElement *SingleList::findElement(int value)
{
    listElement *tmp;
    int found = 0;
    tmp = head;
    while(tmp){
        if(tmp->propertyFieldIndex==value){
            found = 1;
        } else {
            tmp = tmp->next;
        }
        if(found) break;
    }
    return tmp;

}

QListWidget *SingleList::display()
{
    QListWidget *tmpList = new QListWidget();
    QString str;
    listElement *tmp;

    if(!head) return tmpList;//empty list
    else {
        tmp = head;
        while(tmp){
            str = QString::fromStdString(std::to_string(tmp->propertyFieldIndex)+" "+tmp->propertyName+" domy: "+std::to_string(tmp->boughtHouses));
            QListWidgetItem *el = new QListWidgetItem(str);
            tmpList->addItem(el);
            delete el;
        }
    }
    return tmpList;
}
