#pragma once
#include <iostream>
#include <string>

using namespace std;

class Numeral_16 {
private:
    string value;  // шістнадцяткове число у вигляді рядка
public:
    Numeral_16();

    Numeral_16(string str);

    Numeral_16(const Numeral_16& n);

    Numeral_16(int num);

    string get_value();

    string to_binary();

    string to_short_binary();

    int hex_to_decimal();

    Numeral_16 operator+(Numeral_16& num2);
    
    Numeral_16& operator+=(int num);

    Numeral_16& operator++();
};