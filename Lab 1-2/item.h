#ifndef ITEM_H
#define ITEM_M
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Item {
private:
    Item* next;
    Item* prev;
public:
    ~Item();
    void SetNext(Item*);
    void SetPrev(Item*);
    Item* GetNext() const;
    Item* GetPrev() const;
};

#endif
#pragma once
