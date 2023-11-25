#include <string.h>
#include "subj.h"

Base* Base::Create(ItemType t) {
	Base* p = NULL;
	switch (t) {
		case Plant:
			p = (Base*)new class Plant;
			break;
		case Fish:
			p = (Base*)new class Fish;
			break;
		case Bird:
			p = (Base*)new class Bird;
			break;
		case Animal:
			p = (Base*)new class Animal;
			break;
	}
	if (p) p->type = t;
	return p;
}

void Base::Input(int typ) {
	cin >> this->name;
	cin >> this->area;
	cin >> this->temperature;
	cin >> this->wetness;
	cin >> this->max_age;
	cin >> this->repr_age;
	switch (p->type) {
	case Plant:
		((class Plant*)p)->Input();
		break;
	case Fish:
		((class Fish*)p)->Input();
		break;
	case Bird:
		((class Bird*)p)->Input();
		break;
	case Animal:
		((class Animal*)p)->Input();
		break;
	}
}

void Plant::Print(void) {
	cout << 
}

void SubjList::Print(void) {
	for (Base* p = (Base*)GetHead(); p; p = (Base*)p->GetNext()) {
		p->Print();
	}
}

void Plant::Input(void) {
	int i;
	cout << "Enter type plant (1 - Herbage, 2 - Shrub, 3 - Tree): " << endl;
	cin >> i;
	switch (i) {
	case 1:
		type_plant = Herbage;
		break;
	case 2:
		type_plant = Shrub;
		break;
	case 3:
		type_plant = Tree;
		break;
	}
	cout << "Enter type metod reproduction (1 - Vegetation, 2 - Spores, 3 - Zygote): " << endl;
	cin >> i;
	switch (i) {
	case 1:
		metod_repr = Vegetation;
		break;
	case 2:
		metod_repr = Spores;
		break;
	case 3:
		metod_repr = Zygote;
		break;
	}
	cout << "Enter presence of fruits (0 - no, 1 - yes):" << endl;
	cin >> i;
	if (i) fruits = true;
	else fruits = false;
}

void Base::Print(void) {

	cout << name << endl << area << endl;
	cout << temperature << endl << wetness << endl;
	cout << max_age << endl << repr_age << endl;
	switch (type) {
	case Plant:
		((class Plant*)this) -> Print();
		break;
	case Fish:
		((class Fish*)this)->Print();
		break;
	case Bird:
		((class Bird*)this)->Print();
		break;
	case Animal:
		((class Animal*)this)->Print();
		break;
	default:
		cout << "Unknown type" << endl;
		break;
	}
}

void SubjList::InputPlant(class Plant* p) {
	while (1) {
		fflush(stdin);
		printf("Enter name: ");
		if (scanf_s("%s", p->name, (unsigned)sizeof(p->name))) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter area: ");
		if (scanf_s("%s", p->area, (unsigned)sizeof(p->area))) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter temperature: ");
		if (scanf_s("%i", &p->temperature)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter wetness: ");
		if (scanf_s("%i", &p->wetness)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter maximal age: ");
		if (scanf_s("%i", &p->max_age)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter reprodactive age: ");
		if (scanf_s("%i", &p->repr_age)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter type plant (1 - Herbage, 2 - Shrub, 3 - Tree): ");
		if (scanf_s("%i", p->type_plant)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter metod reprodaction (1 - Vegetation, 2 - Spores, 3 - Zygote): ");
		if (scanf_s("%i", p->metod_repr)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter presence of fruits (0 - no, 1 - yes): ");
		if (scanf_s("%i", p->fruits)) break;
	};
}

void SubjList::InputFish(class Fish* p) {
	while (1) {
		fflush(stdin);
		printf("Enter name: ");
		if (scanf_s("%s", p->name, (unsigned)sizeof(p->name))) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter area: ");
		if (scanf_s("%s", p->area, (unsigned)sizeof(p->area))) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter temperature: ");
		if (scanf_s("%i", &p->temperature)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter wetness: ");
		if (scanf_s("%i", &p->wetness)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter maximal age: ");
		if (scanf_s("%i", &p->max_age)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter reprodactive age: ");
		if (scanf_s("%i", &p->repr_age)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter type water (0 - salt, 1 - not salt): ");
		if (scanf_s("%i", p->type_water)) break;
	};
}

void SubjList::InputBird(class Bird* p) {
	while (1) {
		fflush(stdin);
		printf("Enter name: ");
		if (scanf_s("%s", p->name, (unsigned)sizeof(p->name))) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter area: ");
		if (scanf_s("%s", p->area, (unsigned)sizeof(p->area))) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter temperature: ");
		if (scanf_s("%i", &p->temperature)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter wetness: ");
		if (scanf_s("%i", &p->wetness)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter maximal age: ");
		if (scanf_s("%i", &p->max_age)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter reprodactive age: ");
		if (scanf_s("%i", &p->repr_age)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter quantity eggs: ");
		if (scanf_s("%i", &p->quan_eggs)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter can fly: ");
		if (scanf_s("%s", p->can_fly, (unsigned)sizeof(p->can_fly))) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter can swim on water: ");
		if (scanf_s("%s", p->can_swim_on, (unsigned)sizeof(p->can_swim_on))) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter can swim under water: ");
		if (scanf_s("%s", p->can_swim_under, (unsigned)sizeof(p->can_swim_under))) break;
	};
}

void SubjList::InputAnimal(class Animal* p) {
	while (1) {
		fflush(stdin);
		printf("Enter name: ");
		if (scanf_s("%s", p->name, (unsigned)sizeof(p->name))) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter area: ");
		if (scanf_s("%s", p->area, (unsigned)sizeof(p->area))) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter temperature: ");
		if (scanf_s("%i", &p->temperature)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter wetness: ");
		if (scanf_s("%i", &p->wetness)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter maximal age: ");
		if (scanf_s("%i", &p->max_age)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter reprodactive age: ");
		if (scanf_s("%i", &p->repr_age)) break;
	};
	while (1) {
		fflush(stdin);
		printf("Enter type food: ");
		if (scanf_s("%s", p->type_food, (unsigned)sizeof(p->type_food))) break;
	};
}

void SubjList::InputObject(class Base* p) {
	if (p)
		switch (p->type) {
		case Plant:
			InputPlant((struct Plant*)p);
			break;
		case Fish:
			InputFish((struct Fish*)p);
			break;
		case Bird:
			InputBird((struct Bird*)p);
			break;
		case Animal:
			InputAnimal((struct Animal*)p);
			break;
		default:
			printf("Error: unknown object type!\n");
		}
	else printf("Error: null pointer!\n");
}

void SubjList::PrintFish(class Fish* p) {
	printf("\nName: %s\nArea: %s\n", p->name, p->area);
	printf("Temperature: %i\nWetness: %i\n", p->temperature, p->wetness);
	printf("Max age: %i\nReprodactive age: %i\n", p->max_age, p->repr_age);
	printf("Type water: %s\n", p->type_water);
}

void SubjList::PrintBird(class Bird* p) {
	printf("\nName: %s\nArea: %s\n", p->name, p->area);
	printf("Temperature: %i\nWetness: %i\n", p->temperature, p->wetness);
	printf("Max age: %i\nReprodactive age: %i\n", p->max_age, p->repr_age);
	printf("Quantity eggs: %i\nCan fly: %s\n", p->quan_eggs, p->can_fly);
	printf("Can swim on water: %s\nCan swim under water: %s\n", p->can_swim_on, p->can_swim_under);
}

void SubjList::PrintAnimal(class Animal* p) {
	printf("\nName: %s\nArea: %s\n", p->name, p->area);
	printf("Temperature: %i\nWetness: %i\n", p->temperature, p->wetness);
	printf("Max age: %i\nReprodactive age: %i\n", p->max_age, p->repr_age);
	printf("Type food: %s\n", p->type_food);
}

void SubjList::PrintObject(Base* p) {
	if (p)
		switch (p->type) {
		case Plant:
			printf("\n\n==------------------==\n\tPlant:\n==------------------==\n");
			PrintPlant((struct Plant*)p);
			break;
		case Fish:
			printf("\n\n==------------------==\n\tFish:\n==------------------==\n");
			PrintFish((struct Fish*)p);
			break;
		case Bird:
			printf("\n\n==------------------==\n\tBird:\n==------------------==\n");
			PrintBird((struct Bird*)p);
			break;
		case Animal:
			printf("\n\n==------------------==\n\tAnimal:\n==------------------==\n");
			PrintAnimal((struct Animal*)p);
			break;
		default:
			printf("Error: unknown object type!\n");
		}
	else printf("Error: null pointer!\n");
}

void SubjList::PrintListObj(List* list) {
	struct Item* p = list->head;
	if (list)
		if (p)
			for (; p; p = p->next)
				PrintObject((struct Base*)p);
		else printf("List is empty.\n");
	else printf("ERROR: wrong list!\n");
}

void SubjList::Switch(List* list, int j) {
	struct Item* a = Remove(list, j);
	Insert(list, a, j + 1);
}

void SubjList::SortName(List* list) {
	int i, j, len = Count(list);
	struct Base* p1, * p2;
	for (i = 0; i <= len; i++) {
		for (j = 0; j < len - 1; j++) {
			p1 = (struct Base*)GetItem(list, j);
			p2 = (struct Base*)GetItem(list, j + 1);
			if (strcmp(p1->name, p2->name) > 0) {
				Switch(list, j);
			};
		}
	}
}

void SubjList::SearchYears(List* list, int lborder, int rborder) {
	struct Item* curr;
	struct Base* tmp = NULL;
	for (curr = list->head; curr; curr = curr->next) {
		tmp = (struct Base*)curr;
		if (tmp->max_age >= lborder && tmp->max_age <= rborder) {
			PrintObject(tmp);
		}
	}
}