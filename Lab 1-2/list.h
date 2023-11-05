#ifndef LIST_H
#define LIST_M

class List {
    friend class Item;
    private:
        Item* head;
        Item* tail;
    public:
        List(Item*, Item*);
        ~List();
        Item* GetHead();
        Item* GetTail();
        void SetHead(Item*);
        void SetTail(Item*);
        void Add(List*, Item*);
        int Count(List*);
        void PrintList(List*);
        Item* GetItem(List*, int);
        int GetIndex(List*, Item*);
        Item* Remove(List*, int);
        void Delete(List*, int);
        void Clear(List*);
        void Insert(List*, Item*, int);
};

#endif
#pragma once
