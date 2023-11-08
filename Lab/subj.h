#ifndef SUBJ_H
#define SUBJ_M

#include "list.h"
class Item;

enum ItemType { None, Plant, Fish, Bird, Animal };
enum TypePlant { None, Herbage, Shrub, Tree };
enum TypeReprod { None, Vegetation, Spores, Zygote };
enum TypeFood { None, Herbivore, Aft, Meat};

class Base: protected Item {
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

class SubjList {
public:
    Base* Create(enum ItemType);
    void InputPlant(struct Plant*);
    void InputFish(struct Fish*);
    void InputBird(struct Bird*);
    void InputAnimal(struct Animal*);
    void InputObject(struct Base*);
    void PrintPlant(struct Plant*);
    void PrintFish(struct Fish*);
    void PrintBird(struct Bird*);
    void PrintAnimal(struct Animal*);
    void PrintObject(struct Base*);
    void PrintListObj(struct List*);
    void SortName(struct List*);
    void Switch(struct List*, int);
    void SearchYears(struct List*, int, int);
};


#endif
#pragma once
