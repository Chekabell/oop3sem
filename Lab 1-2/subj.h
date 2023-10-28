#ifndef SUBJ_H
#define SUBJ_M

#include "list.h"

enum ItemType { None, Plant, Fish, Bird, Animal };

struct Base {
    struct Item* next;
    struct Item* prev;
    enum ItemType type;
    char name[20];
    char area[20];
    int temperature;
    int wetness;
    int max_age;
    int repr_age;
};

struct Plant {
    struct Item* next;
    struct Item* prev;
    enum ItemType type;
    char name[20];
    char area[20];
    int temperature;
    int wetness;
    int max_age;
    int repr_age;
    char type_plant[15];
    char metod_repr[15];
    char fruits[4];
};

struct Fish {
    struct Item* next;
    struct Item* prev;
    enum ItemType type;
    char name[20];
    char area[20];
    int temperature;
    int wetness;
    int max_age;
    int repr_age;
    char type_water[15];
};

struct Bird {
    struct Item* next;
    struct Item* prev;
    enum ItemType type;
    char name[20];
    char area[20];
    int temperature;
    int wetness;
    int max_age;
    int repr_age;
    int quan_eggs;
    char can_fly[4];
    char can_swim_on[4];
    char can_swim_under[4];
};

struct Animal {
    struct Item* next;
    struct Item* prev;
    enum ItemType type;
    char name[20];
    char area[20];
    int temperature;
    int wetness;
    int max_age;
    int repr_age;
    char type_food[10];
};

struct Base* Create(enum ItemType);

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

#endif
#pragma once
