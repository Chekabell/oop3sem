#ifndef SUBJ_H
#define SUBJ_M

#include "list.h"

enum class ItemType { None, Plant, Fish, Bird, Animal };
enum class TypePlant { None, Herbage, Shrub, Tree };
enum class TypeReprod { None, Vegetation, Spores, Seeds };
enum class TypeFood { None, Herbivore, Aft, Meat };


class Base: public Item {
    ItemType type;
    std::string name;
    std::string area;
    int temperature;
    int wetness;
    int max_age;
    int repr_age;
public:
    Base();
    ~Base();
    Base* Create(int);
    void Input();
    void Print(void);
    std::string GetName(void);
    int GetMax_age(void);
};

class Plant: public Base {
    TypePlant type_plant;
    TypeReprod metod_repr;
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
    TypeFood type_food;
public:
    void Input(void);
    void Print(void);
};

class SubjList: public List {
    friend class Base;
public:
    SubjList();
    ~SubjList();
    void Print(void);
    void SortName();
    void Switch(int);
    void SearchYears(int, int);
};




#endif
#pragma once
