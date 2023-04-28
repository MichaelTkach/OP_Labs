#include "mylib.h"

int main () {
    int hex_f, add;
    string hex_s;

    cout << "Enter the decimal number to be converted to the first hexadecimal number: ";
    cin >> hex_f;
    Numeral_16 N1(hex_f);
    cout << "The first hexadecimal number is: " << N1.get_value() << endl;
    ++N1;
    cout << "The first modified hexadecimal number is: " << N1.get_value() << endl << endl;

    cout << "Enter the second hexadecimal number: ";
    cin >> hex_s;
    Numeral_16 N2(hex_s);
    cout << "The second hexadecimal number is: " << N2.get_value() << endl;
    cout << "Enter the decimal number to be added to the second number: ";
    cin >> add;
    N2 += add;
    cout << "The second modified hexadecimal number is: " << N2.get_value() << endl << endl;

    cout << "The third hexadecimal number will be initialized automatically." << endl;
    Numeral_16 N3;
    N3 = N1 + N2;
    cout << "The third modified hexadecimal number is: " << N3.get_value() << endl << endl;
    cout << "The third hexadecimal number in binary: " << N3.to_short_binary() << endl;
    return 0;
}