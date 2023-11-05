#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List::List(Item* h, Item* t) {
	SetHead(h);
	SetTail(t);
}

List::List(Item* ht) {
	SetHead(ht);
	SetTail(ht);
}

List::List() {
	SetHead(NULL);
	SetTail(NULL);
}

List::~List() {
	while (head) delete head;
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

void List::Add(List* list, Item* item) {
	if (GetHead() == NULL) {
		SetHead(item);
		SetTail(item);
		item->SetNext(NULL);
		item->SetPrev(NULL);
	}
	else {
		list->tail->SetNext(item);
		item->SetPrev(list->tail);
		SetTail(item);
		item->SetNext(NULL);
	}
}

int List::Count(List* list) {
	int i;
	Item* curr;
	for (curr = list->head, i = 0; curr; curr = curr->GetNext()) {
		i++;
	}
	return i;
}

void List::PrintList(List* list) {
	int k = 2, len = Count(list);
	Item* curr = list->head;
	if(len) cout << "\n\t\tPREV\t\t CURR\t\t NEXT" << endl;
	if (len > 1) {
		cout << "1 - HEAD: " << curr->GetPrev() << " " << curr << " " << curr->GetNext() << endl;
		curr = curr->GetNext();
		while (curr->GetNext()) {
			cout << k << " - ITEM: " << curr->GetPrev() << " " << curr << " " << curr->GetNext() << endl;
			curr = curr->GetNext();
			k++;
		}
		cout << k << " - TAIL: " << curr->GetPrev() << " " << curr << " " << curr->GetNext();
	}
	else if (len == 1) {
		cout << "1 - HEAD: " << curr->GetPrev() << " " << curr << " " << curr->GetNext();
	}
	else cout << "\nList empty";
}

Item* List::GetItem( List* list, int index) {
	Item* curr;
	int k = 0;
	for (curr = list->head; curr ; curr = curr->GetNext()){
		if (k == index) {
			break;
		}
		k++;
	}
	return curr;
}

int List::GetIndex(List* list, Item* item) {
	int i;
	Item* curr;
	for (curr = list->head, i = 0; curr != item; curr = curr->GetNext()) {
		i++;
	}
	return i;
}

Item* List::Remove(List* list, int i) {
	Item* item = GetItem(list, i);
	if (item == NULL) {
		return NULL;
	}
	else if (item == list->head) {
		if (item->GetNext() == NULL) {
			list->head = NULL;
			return item;
		}
		list->head = item->GetNext();
		item->GetNext()->SetPrev(NULL) ;
	}
	else if (item == list->tail) {
		list->tail = item->GetPrev();
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

void List::Delete(List* list, int i) {
	Item* item = Remove(list, i);
	if (item) {
		delete item;
		item = NULL;
	}
}

void List::Clear(List* list) {
	while (list->head){
		Delete(list, 0);
	}
}

void List::Insert(List* list, Item* item, int index) {
	Item* curr = GetItem(list, index);
	if (curr == NULL) {
		Add(list, item);
	}
	else if (index == 0) {
		list->head->SetPrev(item);
		item->SetNext(list->head);
		list->head = item;
		item->SetPrev(NULL);
	}
	else {
		item->SetNext(curr);
		item->SetPrev(curr->GetPrev());
		curr->GetPrev()->SetNext(item);
		curr->SetPrev(item);
	}
}