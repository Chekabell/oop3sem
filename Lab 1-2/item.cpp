#include <stdlib.h>
#include <stdio.h>
#include "item.h"

Item::~Item() {
	Item* item = list->head;
	while (1) {
		if ()
	}
}

void Item::SetNext(Item* n) {
	next = n;
}

void Item::SetPrev(Item* p) {
	prev = p;
}

Item* Item::GetNext() const{
	return next;
}

Item* Item::GetPrev() const {
	return prev;
}

