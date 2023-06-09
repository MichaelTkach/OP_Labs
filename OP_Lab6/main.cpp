#include <iostream>
#include <string>
#include "mylib.h"
using namespace std;

int main() {

    while (1) {
        int choice;
        cout << "Select the data type for the set: " << endl;
        cout << "1. int" << endl;
        cout << "2. double" << endl;
        cout << "3. string" << endl;
        cout << "Enter the number of the selected data type: ";
        cin >> choice;

        if (choice == 1) {
            processHashSet<int>();
            break;
        } else if (choice == 2) {
            processHashSet<double>();
            break;
        } else if (choice == 3) {
            processHashSet<string>();
            break;
        } else {
            cout << "Wrong choice of data type.\n" << endl;
        }
    }

    return 0;
}
