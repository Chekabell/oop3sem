#ifndef SUBJ_H
#define SUBJ_M

#include "list.h"
class Item;

enum ItemType { None, Plant, Fish, Bird, Animal };
enum TypePlant { None, Herbage, Shrub, Tree };
enum TypeReprod { None, Vegetation, Spores, Zygote };
enum TypeFood { None, Herbivore, Aft, Meat};

class Base: public Item {
    friend class SubjList;
protected:
    enum ItemType type;
    char name[20];
    char area[20];
    int temperature;
    int wetness;
    int max_age;
    int repr_age;
};

class Plant: protected Base {
private:
    enum TypePlant type_plant;
    enum TypeReprod metod_repr;
    bool fruits;
};

class Fish: protected Base {
private:
    bool type_water;
};

class Bird: protected Base {
private:
    int quan_eggs;
    bool can_fly;
    bool can_swim_on;
    bool can_swim_under;
};

class Animal: protected Base {
private:
    enum TypeFood type_food;
};


class SubjList: public List {
public:
    Base* Create(enum ItemType);
    void InputPlant(class Plant*);
    void InputFish(class Fish*);
    void InputBird(class Bird*);
    void InputAnimal(class Animal*);
    void InputObject(class Base*);
    void PrintPlant(class Plant*);
    void PrintFish(class Fish*);
    void PrintBird(class Bird*);
    void PrintAnimal(class Animal*);
    void PrintObject(Base*);
    void PrintListObj(List*);
    void SortName(List*);
    void Switch(List*, int);
    void SearchYears(List*, int, int);
};


#endif
#pragma once
