#include "list.h"

enum class ItemType { None, Plant, Fish, Bird, Animal };
enum class TypePlant { None, Herbage, Shrub, Tree };
enum class TypeReprod { None, Vegetation, Spores, Seeds };
enum class TypeFood { None, Herbivore, Aft, Meat };


class Base: public Item {
private:
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
private:
    TypePlant type_plant;
    TypeReprod metod_repr;
    bool fruits;
public:
    Plant();
    void Input(void);
    void Print(void);
};

class Fish: public Base {
private:
    bool type_water;
public:
    Fish();
    void Input(void);
    void Print(void);
};

class Bird: public Base {
private:
    int quan_eggs;
    bool can_fly;
    bool can_swim_on;
    bool can_swim_under;
public:
    Bird();
    void Input(void);
    void Print(void);
};

class Animal: public Base {
private:
    TypeFood type_food;
public:
    Animal();
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

