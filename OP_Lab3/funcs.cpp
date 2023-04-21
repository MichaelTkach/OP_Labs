#include "funcs.h"
#include <iostream>
#include <string>

using namespace std;

bool Product::isValidDate(int d, int m, int y) {
    if (m < 1 || m > 12 || d < 1 || d > 31 || y < 1) {
        return false;
    }
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d == 31) {
        return false;
    }
    if (m == 2) {
        if (d > 29) {
            return false;
        }
        if (d == 29 && (y % 400 != 0 && (y % 4 != 0 || y % 100 == 0))) {
            return false;
        }
    }
    return true;
}

Product::Product() {}; // пустой конструктор

Product::Product(string productname, string productionDate, string expiryDate) {
    name = productname;

    month = stoi(productionDate.substr(0, 2)); 
    day = stoi(productionDate.substr(3, 2)); 
    year = stoi(productionDate.substr(6, 4)); 

    exp_month = stoi(expiryDate.substr(0, 2)); 
    exp_day = stoi(expiryDate.substr(3, 2)); 
    exp_year = stoi(expiryDate.substr(6, 4)); 

    // валидация дат
    do {
        if (!isValidDate(day, month, year)) {
            cout << "Manufacture date of the product '" << name << "' is incorrect. Enter the manufacture date again: ";
            cin >> productionDate;
            cout << endl;
        }

        month = stoi(productionDate.substr(0, 2)); 
        day = stoi(productionDate.substr(3, 2)); 
        year = stoi(productionDate.substr(6, 4)); 
    } while (!isValidDate(day, month, year));
    
    do {
        if (!isValidDate(exp_day, exp_month, exp_year)) {
            cout << "Expiration date of the product '" << name << "' is incorrect. Enter the expiration date again: ";
            cin >> expiryDate;
            cout << endl;
        }

        exp_month = stoi(expiryDate.substr(0, 2)); 
        exp_day = stoi(expiryDate.substr(3, 2)); 
        exp_year = stoi(expiryDate.substr(6, 4)); 
    } while (!isValidDate(exp_day, exp_month, exp_year));

}

bool Product::isExpired(string currentDate) {
    int curr_day, curr_month, curr_year;

    curr_month = stoi(currentDate.substr(0, 2)); 
    curr_day = stoi(currentDate.substr(3, 2)); 
    curr_year = stoi(currentDate.substr(6, 4)); 

    do {
        if (!isValidDate(curr_day, curr_month, curr_year)) {
            cout << "Current date is incoorect. Enter the current date again (MM-DD-YYYY): ";
            cin >> currentDate;
            cout << endl;
        }

        curr_month = stoi(currentDate.substr(0, 2)); 
        curr_day = stoi(currentDate.substr(3, 2)); 
        curr_year = stoi(currentDate.substr(6, 4)); 
    } while (!isValidDate(curr_day, curr_month, curr_year));

    if ((curr_year > exp_year) || (curr_year == exp_year && curr_month > exp_month)) {
        cout << "The product '" << name << "' is expired!" << endl;
    } else if (curr_year == exp_year && curr_month == exp_month && curr_day > exp_day) {
        cout << "The product '" << name << "' is expired!" << endl;
    }
    return 0;
}

void checkExpiredProducts(int n, Product products[]) {
    string currentDate;

    cout << "Enter the current date (MM-DD-YYYY): ";
    cin >> currentDate;
    cout << endl;

    for (int i = 0; i < n; i++) {
        products[i].isExpired(currentDate);
    }
}
