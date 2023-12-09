#include "stdio.h"
#include "stdlib.h"
#include "subj.h"

const char* const Menu[10] = {"(none)","add","count","print list object","delete","insert","clear","sort","Search on interval years","exit" };
const char* const TypeObject[5] = {"(none)","Plant","Fish","Bird","Animal" };

int DoMenu(const char* const* s, int max) {
    int i = 0;
    for (i = 1; i <= max; i++) {
        std::cout << i << " - " << s[i] << std::endl;
    }
    std::cout << ">";
    fflush(stdin);
    std::cin >> i;
    return i<1 || i>max ? 0 : i;
}

int main(void) {
    SubjList list{};
    Base* item = nullptr;
    int key = 0, index = 0, typ = 0;
    int lborder = 0, rborder = 0;
    while (1) {
        item = nullptr;
        typ = 0; 
        key = DoMenu(Menu, 9);
        if (key) {
            switch (key) {
            case 1:
                typ = DoMenu(TypeObject, 4);
                    if (typ) {
                        item = item->Create(typ);
                        item->Input();
                        list.Add((Item*)item);
                    }
                break;
            case 2:
                std::cout << std::endl << "Count: " << list.Count();
                break;
            case 3:
                list.Print();
                break;
            case 4:
                std::cout << std::endl << "Enter index: ";
                std::cin >> index;
                list.Delete(index);
                break;
            case 5:
                std::cout << "Enter index: ";
                std::cin >> index;
                typ = DoMenu(TypeObject, 4);
                if (typ) {
                    item = item->Create(typ);
                    item->Input();
                    list.Insert(item, index);
                }
                break;
            case 6:
                list.Clear();
                break;
            case 7:
                list.SortName();
                break;
            case 8:
                std::cout << "Ented left border and right border interval: ";
                std::cin >> lborder >> rborder;
                list.SearchYears(lborder, rborder);
                break;
            case 9:
                return 0;
            default:
                std::cout << "Wrong opinion\n" << std::endl;
                break;
            }
        }
        std::cout << "\n" << std::endl;
    }
}