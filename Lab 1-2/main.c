#include <stdio.h>
#include <stdlib.h>
#include "subj.h"

const char* Menu[10] = {"(none)", "add","count","print list","delete","insert","clear","sort","search years on intervals","exit" };
const char* Type[5] = {"(unknown)", "Plant","Fish","Bird","Animal" };

int DoMenu(char* s[], int max) {
    int i = 0;
    for (i = 1; i <= max; i++) {
        printf("%i - %s\n", i, s[i]);
    }
    printf(">");
    fflush(stdin);
    scanf_s("%i", &i);
    return i<1 || i>max ? 0 : i;
}

int main(void) {
    struct List list;
    list.head = NULL;
    list.tail = NULL;
    struct Base* item = NULL;
    int key = 0, index = 0, typ = 0;
    int lborder, rborder;
    while (1) {
        key = DoMenu(Menu, 9);
        if (key) {
            switch (key) {
            case 1:
                typ = DoMenu(Type, 4);
                item = Create(typ);
                Add(&list, (struct Item*)item);
                InputObject(item);
                break;
            case 2:
                printf("%i\n", Count(&list));
                break;
            case 3:
                PrintListObj(&list);
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
                        typ = DoMenu(Type, 4);
                        item = Create(typ);
                        Insert(&list, (struct Item*)item, index);
                        InputObject(item);
                        break;
                    }
                }
                break;
            case 6:
                Clear(&list);
                break;
            case 7:
                SortName(&list);
                PrintListObj(&list);
                break;
            case 8:
                while (1) {
                    printf("Enter interval age : ");
                    scanf_s("%i %i", &lborder, &rborder);
                    break;
                }
                SearchYears(&list, lborder, rborder);
                break;
            case 9:
                return 0;
            default:
                printf("Wrong opinion\n");
                break;
            }
        }
    }
    return 0;
}