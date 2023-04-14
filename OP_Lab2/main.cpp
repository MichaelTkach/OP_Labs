#include "functions.h"

int main() {
    char answer;
    do {
        file_processing();

        cout << "Do you want to continue session? (If you do then enter y or else any other symbol): ";
        cin.ignore();
        cin >> answer;

    } while (answer == 'y');

   return 0;
}