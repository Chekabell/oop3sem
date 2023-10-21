#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
    struct List list;
    list.head = NULL;
    list.tail = NULL;
    struct Item* item;
    int key = 0, index = 0;
    while (1) {
        printf("1 - add\n2 - count\n3 - print list\n4 - delete\n5 - insert\n6 - clear\n0 - exit\n");
        fflush(stdin);
        if (scanf_s("%i", &key)) {
            switch (key) {
            case 1:
                item = (struct Item*)calloc(1, sizeof(struct Item));
                Add(&list, item);
                break;
            case 2:
                printf("%i\n", Count(&list));
                break;
            case 3:
                PrintList(&list);
                break;
            case 4:
                printf("Enter index: ");
                while (1) {
                    if (scanf_s("%i", &index)) {
                        Delete(&list, index);
                        break;
                    }
                }
                break;
            case 5:
                printf("Enter index: ");
                while (1) {
                    if (scanf_s("%i", &index)) {
                        item = (struct Item*)calloc(1, sizeof(struct Item));
                        Insert(&list, item, index);
                        break;
                    }
                }
                break;
            case 6:
                Clear(&list);
                break;
            case 0:
                return 0;
            default:
                printf("Wrong opinion");
                break;
            }
        }
    }
}