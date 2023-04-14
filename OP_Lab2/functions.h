#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

struct Customer {
    char surname[30];
    char gender;
    int yearOfBirth;
    int numPurchases;
};

void createFile(string filename);

void displayCustomers(string filename);

void addCustomer(string filename);

void count_profit(string filename);

void processCustomers(string inputFile, string outputFile);

void file_processing();