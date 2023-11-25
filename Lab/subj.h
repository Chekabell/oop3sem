#ifndef SUBJ_H
#define SUBJ_M

#include "list.h"

enum ItemType { Plant = 1, Fish, Bird, Animal };
enum TypePlant { Herbage = 1, Shrub, Tree };
enum TypeReprod { Vegetation = 1, Spores, Zygote };
enum TypeFood { Herbivore = 1, Aft, Meat };

class Base: public Item {
    friend class SubjList;
    ItemType type;
    char name[20];
    char area[20];
    int temperature;
    int wetness;
    int max_age;
    int repr_age;
public:
    void Input(Base*);
    void Print(void);
};

class Plant: public Base {
    enum TypePlant type_plant;
    enum TypeReprod metod_repr;
    bool fruits;
public:
    void Input(void);
    void Print(void);
};

class Fish: public Base {
    bool type_water;
public:
    void Input(void);
    void Print(void);
};

class Bird: public Base {
    int quan_eggs;
    bool can_fly;
    bool can_swim_on;
    bool can_swim_under;
public:
    void Input(void);
    void Print(void);
};

class Animal: public Base {
    enum TypeFood type_food;
public:
    void Input(void);
    void Print(void);
};


class SubjList: public List {
private :
    Base* Create(enum ItemType);
    void InputPlant(class Plant*);
    void InputFish(class Fish*);
    void InputBird(class Bird*);
    void InputAnimal(class Animal*);
    void Input(class Base*);
    void Print(void);
    void PrintListObj(List*);
    void SortName(List*);
    void Switch(List*, int);
    void SearchYears(List*, int, int);
};


#endif
#pragma once
