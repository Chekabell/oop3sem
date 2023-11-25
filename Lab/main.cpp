#include "stdio.h"
#include "stdlib.h"
#include "subj.h"

const char* const Menu[10] = {"(none)", "add","count","print list","delete","insert","clear","exit" };
const char* const TypeObject[5] = { "(none)", "Plant","Fish","Bird","Animal" };


int DoMenu(const char* const* s, int max) {
    int i = 0;
    for (i = 1; i <= max; i++) {
        cout << i << " - " << s[i] << endl;
    }
    cout << ">";
    fflush(stdin);
    cin >> i;
    return i<1 || i>max ? 0 : i;
}

int main(void) {
    List list{};
    Base* item = NULL;
    int key = 0, index = 0, typ = 0;
    int lborder = 0, rborder = 0;
    while (1) {
        typ = 0; 
        key = DoMenu(Menu, 7);
        if (key) {
            switch (key) {
            case 1:
                typ = DoMenu(TypeObject, 4);
                item =  (*item).Create(typ);
                list.Add((Item*)item);
                break;
            case 2:
                cout << endl << "Count" << list.Count();
                break;
            case 3:
                list.PrintList();
                break;
            case 4:
                cout << endl << "Enter index: ";
                cin >> index;
                list.Delete(index);
                break;
            case 5:
                cout << "Enter index: ";
                cin >> index;
                item = new Item;
                list.Insert(item, index);
                break;
            case 6:
                list.Clear();
                break;
            case 7:
                return 0;
            default:
                cout << "Wrong opinion\n" << endl;
                break;
            }
        }
        cout << "\n" << endl;
    }
}