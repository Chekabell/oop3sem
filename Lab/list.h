#include <iostream>

class Item {
    friend class List;
protected:
    List* list;
    Item* next;
    Item* prev;
public:
    Item(const Item*);
    Item();
    ~Item();
    void SetList(List*);
    void SetNext(Item*);
    void SetPrev(Item*);
    Item* GetNext() const;
    Item* GetPrev() const;
    List* GetList() const;
};


class List {
private:
    Item* head;
    Item* tail;
public:
    List(const List*);
    List();
    ~List();
    void SetHead(Item*);
    void SetTail(Item*);
    Item* GetHead() const;
    Item* GetTail() const;
    void Add(Item*);
    int Count();
    void PrintList();
    Item* GetItem(int);
    int GetIndex(Item*);
    Item* Remove(int);
    void Delete(int);
    void Clear();
    void Insert(Item*, int);
};

