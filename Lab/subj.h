#include "list.h"

enum class ItemType { None, Plant, Fish, Bird, Animal };
enum class TypePlant { None, Herbage, Shrub, Tree };
enum class TypeReprod { None, Vegetation, Spores, Seeds };
enum class TypeFood { None, Herbivore, Aft, Meat };


class Base : public Item {
    friend class SubjList;
private:
    std::string name;
    std::string area;
    int temperature;
    int wetness;
    int max_age;
    int repr_age;
public:
    Base();
    virtual ~Base();
    virtual ItemType GetType() { return ItemType::None; };
    static Base* Create(int);
    virtual void Input(void);
    virtual void Print(void);
    bool operator > (const Base&);
    bool operator >= (const int);
    bool operator <= (const int);
};

class Plant : public Base {
private:
    TypePlant type_plant;
    TypeReprod metod_repr;
    bool fruits;
public:
    Plant();
    ~Plant();
    void Input(void) override;
    void Print(void) override;
    ItemType GetType() override;
};

class Fish : public Base {
private:
    bool type_water;
public:
    Fish();
    ~Fish();
    void Input(void) override;
    void Print(void) override;
    ItemType GetType() override;
};

class Bird : public Base {
private:
    int quan_eggs;
    bool can_fly;
    bool can_swim_on;
    bool can_swim_under;
public:
    Bird();
    ~Bird();
    void Input(void) override;
    void Print(void) override;
    ItemType GetType() override;
};

class Animal : public Base {
private:
    TypeFood type_food;
public:
    Animal();
    ~Animal();
    void Input(void) override;
    void Print(void) override;
    ItemType GetType() override;
};

class SubjList : public List {
public:
    SubjList() : List() {};
    ~SubjList();
    void Print(void);
    void SortName();
    void Switch(int);
    void SearchYears(int, int);
    Base& operator [](const int);
};

