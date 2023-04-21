#pragma once
#include <iostream>
#include <string>

using namespace std;

class Product {
    string name;
    int day, month, year; // дата выпуска
    int exp_day, exp_month, exp_year; // срок годности
public:

    bool isValidDate(int d, int m, int y);

    Product(); // пустой конструктор
    
    Product(string productname, string productionDate, string expiryDate);

    bool isExpired(string currentDate);
   
};

void checkExpiredProducts(int n, Product products[]);
