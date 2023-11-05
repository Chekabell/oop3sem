#include <stdlib.h>
#include <stdio.h>
#include "item.h"

Item::Item(Item* n, Item* p) {
	SetNext(n);
	SetPrev(p);
}

Item::Item(Item* no) {
	SetNext(NULL);
	SetPrev(NULL);
}

Item::Item() {
	SetNext(NULL);
	SetPrev(NULL);
}

Item::~Item() {
	if (next == NULL && prev == NULL);
	else if (prev == NULL) {
		next->prev = NULL;
		next = NULL;
	}
	else if (next == NULL) {
		prev->next = NULL;
		prev = NULL;
	}
	else {
		next->prev = prev;
		prev->next = next;
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

