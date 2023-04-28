#include "mylib.h"
#include <iostream>
#include <string>

using namespace std;

Numeral_16::Numeral_16() {}

Numeral_16::Numeral_16(string str) {
    value = str;
}

Numeral_16::Numeral_16(const Numeral_16& n) {
    value = n.value;
}

Numeral_16::Numeral_16(int num) {
    string hex = "";
    while (num > 0) {
        int rem = num % 16;
        char hex_digit;
        if (rem < 10) {
            hex_digit = '0' + rem;
        } else {
            hex_digit = 'A' + (rem - 10);
        }
        hex = hex_digit + hex;
        num /= 16;
    }
    if (hex == "") { hex = "0"; }
    value = hex;
}

string Numeral_16::get_value() {
    return value;
}

string Numeral_16::to_binary() {
    string binary_str = "";
    for (int i = 0; i < value.length(); i++) {
        switch (value[i]) {
            case '0': binary_str += "0000"; break;
            case '1': binary_str += "0001"; break;
            case '2': binary_str += "0010"; break;
            case '3': binary_str += "0011"; break;
            case '4': binary_str += "0100"; break;
            case '5': binary_str += "0101"; break;
            case '6': binary_str += "0110"; break;
            case '7': binary_str += "0111"; break;
            case '8': binary_str += "1000"; break;
            case '9': binary_str += "1001"; break;
            case 'A': case 'a': binary_str += "1010"; break;
            case 'B': case 'b': binary_str += "1011"; break;
            case 'C': case 'c': binary_str += "1100"; break;
            case 'D': case 'd': binary_str += "1101"; break;
            case 'E': case 'e': binary_str += "1110"; break;
            case 'F': case 'f': binary_str += "1111"; break;
        }
    }
    return binary_str;
}

string Numeral_16::to_short_binary() {
    string binary_str = to_binary();
    // Видаляємо нулі на початку
    binary_str.erase(0, min(binary_str.find_first_not_of('0'), binary_str.size()-1));
    // Якщо число нульове, повертаємо один нуль
    if (binary_str.empty()) {
        binary_str = "0";
    }
    return binary_str;
}

int Numeral_16::hex_to_decimal() {
    int decimal = 0;
    int power = 1; // начальная степень числа 16

    // перебираем символы числа справа налево
    for (int i = value.length() - 1; i >= 0; i--) {
        // получаем значение символа
        int digit;
        if (value[i] >= '0' && value[i] <= '9') {
            digit = value[i] - '0';
        }
        else if (value[i] >= 'A' && value[i] <= 'F') {
            digit = value[i] - 'A' + 10;
        }
        else if (value[i] >= 'a' && value[i] <= 'f') {
            digit = value[i] - 'a' + 10;
        }

        // добавляем в общее значение число, равное текущему разряду
        decimal += digit * power;

        // увеличиваем степень числа 16
        power *= 16;
    }

    return decimal;
}

Numeral_16 Numeral_16::operator+(Numeral_16& num2) {
    // переводимо поточний об'єкт та переданий об'єкт до десяткової системи числення
    int num1_dec = this->hex_to_decimal();
    int num2_dec = num2.hex_to_decimal();
    return Numeral_16(num1_dec + num2_dec);
}

Numeral_16& Numeral_16::operator+=(int num) {
    int num1_dec = this->hex_to_decimal();
    *this = Numeral_16(num1_dec + num);
    return *this;
}

Numeral_16& Numeral_16::operator++() {
    int num1_dec = this->hex_to_decimal();
    *this = Numeral_16(++num1_dec);
    return *this;
}
