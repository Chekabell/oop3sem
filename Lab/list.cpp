#include <stdlib.h>
#include <stdio.h>
#include "list.h"

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

Item* Item::GetNext() const {
	return next;
}

Item* Item::GetPrev() const {
	return prev;
}

List::List(const List* l) {
	SetHead(l->GetHead());
	SetTail(l->GetTail());
}

List::List() {
	SetHead(NULL);
	SetTail(NULL);
}

List::~List() {
	Clear();
}

void List::SetHead(Item* item) {
	head = item;
}

void List::SetTail(Item* item) {
	tail = item;
}

Item* List::GetHead() const{
	return head;
}

Item* List::GetTail() const {
	return tail;
}

void List::Add(Item* item) {
	if (GetHead() == NULL) {
		SetHead(item);
		SetTail(item);
		item->SetNext(NULL);
		item->SetPrev(NULL);
	}
	else {
		tail->SetNext(item);
		item->SetPrev(tail);
		SetTail(item);
		item->SetNext(NULL);
	}
}

int List::Count() {
	int i;
	Item* curr;
	for (curr = head, i = 0; curr; curr = curr->GetNext()) {
		i++;
	}
	return i;
}

void List::PrintList() {
	int k = 1, len = Count();
	Item* curr = head;
	if(len) cout << "\n\t\tPREV\t\t CURR\t\t NEXT" << endl;
	if (len > 1) {
		cout << "0 - HEAD: " << curr->GetPrev() << " " << curr << " " << curr->GetNext() << endl;
		curr = curr->GetNext();
		while (curr->GetNext()) {
			cout << k << " - ITEM: " << curr->GetPrev() << " " << curr << " " << curr->GetNext() << endl;
			curr = curr->GetNext();
			k++;
		}
		cout << k << " - TAIL: " << curr->GetPrev() << " " << curr << " " << curr->GetNext();
	}
	else if (len == 1) {
		cout << "0 - HEAD: " << curr->GetPrev() << " " << curr << " " << curr->GetNext();
	}
	else cout << "\nList empty";
}

Item* List::GetItem(int index) {
	Item* curr;
	int k = 0;
	for (curr = head; curr ; curr = curr->GetNext()){
		if (k == index) {
			break;
		}
		k++;
	}
	return curr;
}

int List::GetIndex(Item* item) {
	int i;
	Item* curr;
	for (curr = head, i = 0; curr != item || curr!= NULL; curr = curr->GetNext()) {
		i++;
	}
	return curr ? i : -1;
}

Item* List::Remove(int i) {
	Item* item = GetItem(i);
	if (item == NULL) {
		return NULL;
	}
	else if (item == head) {
		if (item->GetNext() == NULL) {
			head = NULL;
			return item;
		}
		head = item->GetNext();
		item->GetNext()->SetPrev(NULL) ;
	}
	else if (item == tail) {
		tail = item->GetPrev();
		item->GetPrev()->SetNext(NULL);
	}
	else {
		item->GetNext()->SetPrev(item->GetPrev());
		item->GetPrev()->SetNext(item->GetNext());
		item->SetPrev(NULL);
		item->SetNext(NULL);
	}
	return item;
}

void List::Delete(int i) {
	Item* item = Remove(i);
	if (item) {
		delete item;
		item = NULL;
	}
}

void List::Clear() {
	while (head){
		Delete(0);
	}
}

void List::Insert(Item* item, int index) {
	Item* curr = GetItem(index);
	if (curr == NULL) {
		Add(item);
	}
	else if (index == 0) {
		head->SetPrev(item);
		item->SetNext(head);
		head = item;
		item->SetPrev(NULL);
	}
	else {
		item->SetNext(curr);
		item->SetPrev(curr->GetPrev());
		curr->GetPrev()->SetNext(item);
		curr->SetPrev(item);
	}
}