#include <stdio.h>
#include <stdlib.h>
#include "subj.h"

int DoMenu(char* s[], int max) {
    int i = 0;
    for (i = 1; i <= max; i++) {
        printf("%i. %s", i, s[i]);
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
        printf("1 - add\n2 - count\n3 - print list\n4 - delete\n5 - insert\n6 - clear\n0 - exit\n");
        fflush(stdin);
        if (scanf_s("%i", &key)) {
            switch (key) {
            case 1:
                while (1) {
                    fflush(stdin);
                    printf("\n1 - Plant\t2 - Fish\n3 - Bird\t4 - Animal\n\n");
                    printf("Enter number of type entity: ");
                    if (scanf_s("%i", &typ) && typ > 0 && typ < 5) break;
                };
                switch (typ) {
                case 1:
                    item = Create(Plant);
                    break;
                case 2:
                    item = Create(Fish);
                    break;
                case 3:
                    item = Create(Bird);
                    break;
                case 4:
                    item = Create(Animal);
                    break;
                };
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
                        while (1) {
                            fflush(stdin);
                            printf("\n1 - Plant\t2 - Fish\n3 - Bird\t4 - Animal\n\n");
                            printf("Enter number of type entity: ");
                            if (scanf_s("%i", &typ) && typ > 0 && typ < 5) break;
                        };
                        switch (typ) {
                        case 1:
                            item = Create(Plant);
                            break;
                        case 2:
                            item = Create(Fish);
                            break;
                        case 3:
                            item = Create(Bird);
                            break;
                        case 4:
                            item = Create(Animal);
                            break;
                        };
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
                }
                SearchYears(&list, lborder, rborder);
                break;
            case 0:
                return 0;
            default:
                printf("Wrong opinion\n");
                break;
            }
        }
    }
}