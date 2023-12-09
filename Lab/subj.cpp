#include "subj.h"


Base::Base()
	: Item()
	, name("unknown")
	, area("unknown")
	, temperature(0)
	, wetness(0)
	, max_age(0)
	, repr_age(0)
{
}

Base::~Base() { ((Item*)this)->~Item(); };


Plant::Plant()
	: Base()
	, type_plant(TypePlant::None)
	, metod_repr(TypeReprod::None)
	, fruits(false)
{
}

Fish::Fish()
	: Base()
	, type_water(false)
{
}

Bird::Bird()
	: Base()
	, quan_eggs(0)
	, can_fly(false)
	, can_swim_on(false)
	, can_swim_under(false)
{
}

Animal::Animal()
	: Base()
	, type_food(TypeFood::None)
{
}

ItemType Plant::GetType() {
	return ItemType::Plant;
}

ItemType Fish::GetType() {
	return ItemType::Fish;
}

ItemType Bird::GetType() {
	return ItemType::Bird;
}

ItemType Animal::GetType() {
	return ItemType::Animal;
}

Base* Base::Create(int t) {
	Base* p = NULL;
	switch (t) {
	case 1:
		p = new Plant();
		break;
	case 2:
		p = new Fish();
		break;
	case 3:
		p = new Bird();
		break;
	case 4:
		p = new Animal();
		break;
	}
	return p;
}

void Base::Input(void) {
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter area: ";
	std::cin >> area;
	std::cout << "Enter temperature (-200 - +100): ";
	std::cin >> temperature;
	while (temperature < -200 || temperature > 100) {
		temperature = 0;
		fflush(stdin);
		std::cout << "Immposible temperature for life!!\n Enter again:";
		std::cin >> temperature;
	}
	std::cout << "Enter wetness (0 - 100): ";
	std::cin >> wetness;
	while (wetness < 0 || wetness > 100) {
		wetness = 0;
		fflush(stdin);
		std::cout << "Immposible wetness!!\n Enter again:";
		std::cin >> wetness;
	}
	std::cout << "Enter maximal age: ";
	std::cin >> max_age;
	while (max_age < 0) {
		max_age = 0;
		fflush(stdin);
		std::cout << "Immposible maximal age!!\n Enter again:";
		std::cin >> max_age;
	}
	std::cout << "Enter reproductive age: ";
	std::cin >> repr_age;
	while (repr_age <= 0) {
		repr_age = 0;
		fflush(stdin);
		std::cout << "Immposible reproductive age!!\n Enter again:";
		std::cin >> repr_age;
	}
}

void Plant::Input(void) {
	Base::Input();
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
	Base::Input();
	int i;
	std::cout << "Enter type water (0 - marine, 1 - fresh):" << std::endl;
	std::cin >> i;
	if (i) type_water = true;
	else type_water = false;
}

void Bird::Input(void) {
	Base::Input();
	int i;
	std::cout << "Enter quantity of eggs in laying" << std::endl;
	std::cin >> quan_eggs;
	while (quan_eggs < 0) {
		quan_eggs = 0;
		fflush(stdin);
		std::cout << "Immposible quantity eggs!!\n Enter again:";
		std::cin >> quan_eggs;
	}
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
	Base::Input();
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

void SubjList::Print(void) {
	for (Base* p = (Base*)GetHead(); p; p = (Base*)p->GetNext()) {
		p->Print();
		std::cout << std::endl;
	}
}

void Base::Print(void) {
	switch (GetType()) {
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
	std::cout << "\tName: " << name << std::endl << "\tArea: " << area << std::endl;
	std::cout << "\tTemperature: " << temperature << std::endl << "\tWetness: " << wetness << std::endl;
	std::cout << "\tMaximal age: " << max_age << std::endl << "\tReproductive age: " << repr_age << std::endl;
}

void Plant::Print(void) {
	Base::Print();
	std::cout << "\tType plant: ";
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
	std::cout << "\tMetor reproduction: ";
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
	std::cout << "\tAvailable fruits: ";
	if (fruits) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
}

void Fish::Print(void) {
	Base::Print();
	std::cout << "\tType water: ";
	if (type_water) std::cout << "fresh" << std::endl;
	else std::cout << "marine" << std::endl;
}

void Bird::Print(void) {
	Base::Print();
	std::cout << "\tQuantity of eggs in laying: ";
	std::cout << quan_eggs << std::endl;
	std::cout << "\tAbility fly: ";
	if (can_fly) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	std::cout << "\tAbility swim on water: ";
	if (can_swim_on) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
	std::cout << "\tAbility swim under water: ";
	if (can_swim_under) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;
}

void Animal::Print(void) {
	Base::Print();
	std::cout << "\tType food: ";
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

void SubjList::Switch(int j) {
	Item* a = this->Remove(j);
	this->Insert(a, j + 1);
}

bool Base::operator > (const Base& p)
{
	if (name.compare(p.name) > 0) return true;
	else return false;
}

Base& SubjList::operator [](const int i) {
	return *(Base*)GetItem(i);
}

void SubjList::SortName() {
	int i, j, len = this->Count();
	for (i = 0; i <= len; i++) {
		for (j = 0; j < len - 1; j++) {
			if ((*this)[j] > (*this)[j+1]) {
				this->Switch(j);
			};
		}
	}
}

bool Base::operator>= (const int i) {
	if (max_age >= i) return true;
	else return false;
}

bool Base::operator<= (const int i) {
	if (max_age <= i) return true;
	else return false;
}

void SubjList::SearchYears(int lborder, int rborder) {
	int i, len = this->Count();
	for (i = 0; i <= len; i++) {
		if ((*this)[i] >= lborder && (*this)[i] <= rborder) {
			((*this)[i]).Print();
		}
	}
}