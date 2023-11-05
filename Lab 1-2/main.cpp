#include "stdio.h"
#include "stdlib.h"
#include "list.h"


const char* const Menu[10] = {"(none)", "add","count","print list","delete","insert","clear","sort","search years on intervals","exit" };
const char* const Type[5] = {"(unknown)", "Plant","Fish","Bird","Animal" };

int DoMenu(const char* const* s, int max) {
    int i = 0;
    cout << "\n" << endl;
    for (i = 1; i <= max; i++) {
        cout << i << " - " << s[i] << endl;
    }
    cout << "\n" << endl;
    fflush(stdin);
    scanf_s(">%i", &i);
    return i<1 || i>max ? 0 : i;
}

int main(void) {
    List list(NULL,NULL);
    Item* item = NULL;
    int key = 0, index = 0, typ = 0;
    int lborder = 0, rborder = 0;
    while (1) {
        typ = 0; 
        key = DoMenu(Menu, 9);
        if (key) {
            switch (key) {
            case 1:
                //while (1) {
                    //if (typ = DoMenu(Type, 4)) {
                        //item = Create(typ);
                        item = new Item;
                        list.Add(&list, item);
                        //InputObject(item);
                        break;
                    //}
                    //printf("Unknown type object\n");
                //}
                break;
            case 2:
                cout << list.Count(&list) << "\n" << endl;
                break;
            case 3:
                list.PrintList(&list);
                break;
            case 4:
                cout << "Enter index: " << endl;
                while (1) {
                    if (scanf_s("%i", &index)) {
                        list.Delete(&list, index-1);
                        break;
                    }
                }
                break;
            case 5:
                cout << "Enter index: " << endl;
                while (1) {
                    if (scanf_s("%i", &index)) {
                       // while (1) {
                            //if (typ = DoMenu(Type, 4)) {
                                //item = Create(typ);
                                item = new Item;
                                list.Insert(&list, (Item*)item, index-1);
                                //InputObject(item);
                                //break;
                            //}
                            //printf("Unknown type object\n");
                        //}
                        break;
                    }
                }
                break;
            case 6:
                list.Clear(&list);
                break;
            case 7:
                //SortName(&list);
                //PrintListObj(&list);
                break;
            case 8:
                /*while (1) {
                    printf("Enter interval age with space: ");
                    scanf_s("%i %i", &lborder, &rborder);
                    break;
                }
                SearchYears(&list, lborder, rborder);
                break;*/
            case 9:
                return 0;
            default:
                cout << "Wrong opinion\n" << endl;
                break;
            }
        }
    }
}