#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void Add(struct List* list, struct Item* item) {
	if (list->head == NULL) {
		list->head = item;
		list->tail = item;
		item->next = NULL;
		item->prev = NULL;
	}
	else {
		list->tail->next = item;
		item->prev = list->tail;
		list->tail = item;
		item->next = NULL;
	}
}

int Count(struct List* list) {
	int i;
	struct Item* curr = list->head;
	for (i = 0; curr != NULL; i++) {
		curr = curr->next;
	}
	return i;
}

void PrintList(struct List* list) {
	struct Item* curr;
	if (Count(list)) {
		for (curr = list->head; curr != NULL; curr = curr->next) {
			if (curr == list->head) {
				printf("HEAD:\nCurr: %p\nNext: %p\n\n", curr, curr->next);
			}
			else if (curr == list->tail) {
				printf("TAIL:\nPrev: %p\nCurr: %p\n\n", curr->prev, curr);
			}
			else {
				printf("ITEM:\nPrev: %p\nCurr: %p\nNext: %p\n\n", curr->prev, curr, curr->next);
			}
		}
	}
	else printf("List empty\n\n");
}

struct Item* GetItem(struct List* list, int index) {
	struct Item* curr = list->head;
	int k = 0;
	for (curr; curr != NULL; curr = curr->next) {
		if (k == index) {
			break;
		}
		k++;
	}
	return curr;
}

int GetIndex(struct List* list, struct Item* item) {
	int i;
	struct Item* curr = list->head;
	for (i = 0; curr != item; curr = curr->next, i++) {
	}
	return i;
}

struct Item* Remove(struct List* list, int i) {
	struct Item* item = GetItem(list, i);
	if (item == NULL) {
		return NULL;
	}
	else if (item == list->head) {
		if (item->next == NULL) {
			list->head = NULL;
			return item;
		}
		list->head = item->next;
		item->next->prev = NULL;
	}
	else if (item == list->tail) {
		list->tail = item->prev;
		item->prev->next = NULL;
	}
	else {
		item->next->prev = item->prev;
		item->prev->next = item->next;
		item->prev = NULL;
		item->next = NULL;
	}
	return item;
}

void Delete(struct List* list, int i) {
	struct Item* item = Remove(list, i);
	if (item)
		free(item);
}

void Clear(struct List* list) {
	struct Item* curr = list->head;
	for (curr; list->head != NULL; curr = list->head) {
		Delete(list, 0);
	}
}

void Insert(struct List* list, struct Item* item, int index) {
	struct Item* curr = GetItem(list, index);
	if (curr == NULL) {
		Add(list, item);
	}
	else if (index == 0) {
		list->head->prev = item;
		item->next = list->head;
		list->head = item;
		item->prev = NULL;
	}
	else {
		item->next = curr;
		item->prev = curr->prev;
		curr->prev->next = item;
		curr->prev = item;
	}
}