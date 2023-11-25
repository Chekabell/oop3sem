#include <stdlib.h>
#include <stdio.h>


Item::Item(const Item* no) {
	SetNext(no->GetNext());
	SetPrev(no->GetPrev());
}

Item::Item() {
	SetNext(NULL);
	SetPrev(NULL);
}

Item::~Item() {
	if (list->GetIndex(this) != -1) list->Remove(list->GetIndex(this));
}

void Item::SetList(List* l) {
	list = l;
}

void Item::SetNext(Item* n) {
	next = n;
}

void Item::SetPrev(Item* p) {
	prev = p;
}

List* Item::GetList() const {
	return list;
}

Item* Item::GetNext() const{
	return next;
}

Item* Item::GetPrev() const {
	return prev;
}

