#include "MyDCLL.h"
int main() {
    MyDCLL list;

   
    cout << "Inserting elements recursively: 10, 20, 30, 40, 50" << endl;
    list.insertRecursive(nullptr, 10);
    list.insertRecursive(list.getHead(), 20);
    list.insertRecursive(list.getHead(), 30);
    list.insertRecursive(list.getHead(), 40);
    list.insertRecursive(list.getHead(), 50);

    cout << "List after insertion: ";
    list.printlist();


    cout << "Recursive print (entire list): ";
    list.printlistrecursive();

    cout << "Recursive print (range 1 to 3): ";
    list.printlistrecursive(1, 3);

    cout << "Recursive print (range 2 to 4): ";
    list.printlistrecursive(2, 4);

    cout << "Recursive print (invalid range, 4 to 2): ";
    list.printlistrecursive(4, 2);

    return 0;
}
