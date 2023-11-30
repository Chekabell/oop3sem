#include <string.h>
#include "subj.h"

Base* Base::Create(int t) {
	Base* p = NULL;
	switch (t) {
	case 1:
			p = (Base*)new class Plant;
			p->type = ItemType::Plant;
			break;
	case 2:
			p = (Base*)new class Fish;
			p->type = ItemType::Fish;
			break;
	case 3:
			p = (Base*)new class Bird;
			p->type = ItemType::Bird;
			break;
	case 4:
			p = (Base*)new class Animal;
			p->type = ItemType::Animal;
			break;
	}
	if (!p) p->type = ItemType::None;
	return p;
}

void Plant::Input(void) {
	int i;
	std::cout << "Enter type plant (1 - Herbage, 2 - Shrub, 3 - Tree): " << std::endl;
	std::cin >> i;
	switch (i) {
	case 1:
		type_plant = TypePlant::Herbage;
		break;
	case 2:
		type_plant = TypePlant::Shrub;
		break;
	case 3:
		type_plant = TypePlant::Tree;
		break;
	default:
		type_plant = TypePlant::None;
		break;
	}
	std::cout << "Enter type metod reproduction (1 - Vegetation, 2 - Spores, 3 - Seeds): " << std::endl;
	std::cin >> i;
	switch (i) {
	case 1:
		metod_repr = TypeReprod::Vegetation;
		break;
	case 2:
		metod_repr = TypeReprod::Spores;
		break;
	case 3:
		metod_repr = TypeReprod::Seeds;
		break;
	default:
		metod_repr = TypeReprod::None;
		break;
	}
	std::cout << "Enter presence of fruits (0 - no, 1 - yes):" << std::endl;
	std::cin >> i;
	if (i) fruits = true;
	else fruits = false;
}

void Fish::Input(void) {
	int i;
	std::cout << "Enter type water (0 - marine, 1 - fresh):" << std::endl;
	std::cin >> i;
	if (i) type_water = true;
	else type_water = false;
}

void Bird::Input(void) {
	int i;
	std::cout << "Enter quantity of eggs in laying" << std::endl;
	std::cin >> quan_eggs;
	std::cout << "Enter ability fly (0 - no, 1 - yes):" << std::endl;
	std::cin >> i;
	if (i) can_fly = true;
	else can_fly = false;
	std::cout << "Enter ability swim on water (0 - no, 1 - yes):" << std::endl;
	std::cin >> i;
	if (i) can_swim_on = true;
	else can_swim_on = false;
	std::cout << "Enter ability swim under water (0 - no, 1 - yes):" << std::endl;
	std::cin >> i;
	if (i) can_swim_under = true;
	else can_swim_under = false;
}

void Animal::Input(void) {
	int i;
	std::cout << "Enter type food (1 - Herbivore, 2 - Aft, 3 - Meat): " << std::endl;
	std::cin >> i;
	switch (i) {
	case 1:
		type_food = TypeFood::Herbivore;
		break;
	case 2:
		type_food = TypeFood::Aft;
		break;
	case 3:
		type_food = TypeFood::Meat;
		break;
	default:
		type_food = TypeFood::None;
		break;
	}
}

void Base::Input() {
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter area: ";
	std::cin >> area;
	std::cout << "Enter temperature: ";
	std::cin >> temperature;
	std::cout << "Enter wetness: ";
	std::cin >> wetness;
	std::cout << "Enter maximal age: ";
	std::cin >> max_age;
	std::cout << "Enter reproductive age: ";
	std::cin >> repr_age;
	switch (type) {
	case ItemType::Plant:
		((class Plant*)this)->Input();
		break;
	case ItemType::Fish:
		((class Fish*)this)->Input();
		break;
	case ItemType::Bird:
		((class Bird*)this)->Input();
		break;
	case ItemType::Animal:
		((class Animal*)this)->Input();
		break;
	default:
		std::cout << "Unknown type object" << std::endl;
	}
}


void Plant::Print(void) {
	std::cout << "Type plant: ";
	switch (type_plant) {
	case TypePlant::Herbage:
		std::cout << "Herbage" << std::endl;
		break;
	case TypePlant::Shrub:
		std::cout << "Shrub" << std::endl;
		break;
	case TypePlant::Tree:
		std::cout << "Tree" << std::endl;
		break;
	}
	std::cout << "Metor reproduction: ";
	switch (metod_repr) {
	case TypeReprod::Vegetation:
		std::cout << "Vegetation" << std::endl;
		break;
	case TypeReprod::Spores:
		std::cout << "Spores" << std::endl;
		break;
	case TypeReprod::Seeds:
		std::cout << "Seeds" << std::endl;
		break;
	}
	std::cout << "Available fruits: ";
	if (fruits) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
}

void Fish::Print(void) {
	std::cout << "Type water: ";
	if (type_water) std::cout << "fresh" << std::endl;
	else std::cout << "marine" << std::endl;
}

void Bird::Print(void) {
	std::cout << "Quantity of eggs in laying: ";
	std::cout << quan_eggs << std::endl;
	std::cout << "Ability fly: ";
	if (can_fly) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	std::cout << "Ability swim on water: ";
	if (can_swim_on) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	std::cout << "Ability swim under water: ";
	if (can_swim_under) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
}

void Animal::Print(void) {
	std::cout << "Type food: ";
	switch (type_food) {
	case TypeFood::Herbivore:
		std::cout << "Herbivore" << std::endl;
		break;
	case TypeFood::Aft:
		std::cout << "Aft" << std::endl;
		break;
	case TypeFood::Meat:
		std::cout << "Meat" << std::endl;
		break;
	}
}

void SubjList::Print(void) {
	for (Base* p = (Base*)GetHead(); p; p = (Base*)p->GetNext()){
		p->Print();
		std::cout << std::endl;
	}
}

void Base::Print(void) {
	if (type != ItemType::None) {
		switch (type) {
		case ItemType::Plant:
			std::cout << "------------Plant------------" << std::endl;
			break;
		case ItemType::Fish:
			std::cout << "------------Fish------------" << std::endl;
			break;
		case ItemType::Bird:
			std::cout << "------------Bird------------" << std::endl;
			break;
		case ItemType::Animal:
			std::cout << "------------Animal------------" << std::endl;
			break;
		}
		std::cout << "Name: " << name << std::endl << "Area: " << area << std::endl;
		std::cout << "Temperature: " << temperature << std::endl << "Wetness: " << wetness << std::endl;
		std::cout << "Maximal age: " << max_age << std::endl << "Reproductive age: " << repr_age << std::endl;
		switch (type) {
		case ItemType::Plant:
			((class Plant*)this)->Print();
			break;
		case ItemType::Fish:
			((class Fish*)this)->Print();
			break;
		case ItemType::Bird:
			((class Bird*)this)->Print();
			break;
		case ItemType::Animal:
			((class Animal*)this)->Print();
			break;
		}
	}
}

int Base::GetMax_age(void) {
	return this->max_age;
}

char* Base::GetName(void) {
	return this->name;
}

void SubjList::Switch(int j) {
	Item* a = this->Remove(j);
	this->Insert(a, j + 1);
}

void SubjList::SortName() {
	int i, j, len = this->Count();
	Base *p1, *p2;
	for (i = 0; i <= len; i++) {
		for (j = 0; j < len - 1; j++) {
			p1 = (Base*)this->GetItem(j);
			p2 = (Base*)this->GetItem(j + 1);
			if (strcmp(p1->GetName(), p2->GetName()) > 0) {
				this->Switch(j);
			};
		}
	}
}

void SubjList::SearchYears(int lborder, int rborder) {
	Item* curr;
	Base* tmp = NULL;
	for (curr = this->GetHead(); curr; curr = curr->GetNext()) {
		tmp = (Base*)curr;
		if (tmp->GetMax_age() >= lborder && tmp->GetMax_age() <= rborder) {
			tmp->Print();
		}
	}
}