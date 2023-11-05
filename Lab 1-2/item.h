#ifndef ITEM_H
#define ITEM_M

class Item {
private:
    List* list;
    Item* next;
    Item* prev;
public:
    List* GetList() const;
    Item* GetNext() const;
    Item* GetPrev() const;
    void SetList(List*);
    void SetNext(Item*);
    void SetPrev(Item*);
    ~Item()

};

#endif
#pragma once
