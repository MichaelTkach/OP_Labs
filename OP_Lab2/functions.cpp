#include "functions.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void createFile(string filename) {
    ofstream outfile(filename, ios::binary); // открываем файл для записи

    cout << "File '" << filename << "' has been successfully created!" << endl << endl;
    outfile.close(); // закрываем файл
}

void displayCustomers(string filename) {
    ifstream file(filename, ios::binary);

    Customer customer;
    cout << endl << "---------------------------" << filename << "---------------------------" << endl;
    cout << "Surname           Gender  Year of Birth  Number of Purchases\n";
    while (file.read((char*)&customer, sizeof(Customer))) {
        cout << left << setw(20) << customer.surname
                     << setw(10) << customer.gender
                     << setw(17) << customer.yearOfBirth
                     << setw(5) << customer.numPurchases << endl;
    }
    cout << endl;
    file.close();
}

void addCustomer(string filename) {
    ofstream outfile(filename, ios::binary | ios::app);
    char answer1, answer2, answer3;
    bool trigger;
    
    cout << "Do you want to add new customer? (If you do then enter y or else any other symbol): ";
    cin >> answer1;
    if (answer1 == 'y') {
        do {
            // Ask for customer details
            Customer customer;
            cout << "Enter customer surname: ";
            cin >> customer.surname;

            do {
                cin.ignore();
                trigger = true;

                cout << "Enter customer gender (m/f): ";
                cin >> customer.gender;

                if (customer.gender != 'm' && customer.gender != 'f') {
                    cout << "Error. Please try again." << endl;
                    trigger = false;
                }

            } while (trigger == false);

            do {
                cin.ignore();
                trigger = true;

                cout << "Enter customer year of birth: ";
                cin >> customer.yearOfBirth;

                if (customer.yearOfBirth < 1900 || customer.yearOfBirth > 2023) {
                    cout << "Error. Please try again." << endl;
                    trigger = false;
                }

            } while (trigger == false);
            
            do {
                cin.ignore();
                trigger = true;

                cout << "Enter number of purchases: ";
                cin >> customer.numPurchases;

                if (customer.numPurchases < 0) {
                    cout << "Error. Please try again." << endl;
                    trigger = false;
                }

            } while (trigger == false);

            outfile.write((char*)&customer, sizeof(Customer));

            cout << endl << "Do you want to add ane more customer? (If you do then enter y or else any other symbol): ";
            cin >> answer2;
            cout << endl;
        } while (answer2 == 'y');
        
        outfile.close();

        cout << "Customer data has been successfully added to the file." << endl << endl;

        cout << "Do you want to check the changes in the file? (If you do then enter y or else any other symbol): ";
        cin >> answer3;

        if (answer3 == 'y') {
            displayCustomers(filename);
        } else {
            cout << endl;
        }

    } else {
        cout << endl;
    }
}

void count_profit(string filename) {
    ifstream infile(filename, ios::binary);
    int total_revenue = 0;
    int discount = 0;

    Customer customer;
    while (infile.read((char*)&customer, sizeof(Customer))) {
        int age = 2023 - customer.yearOfBirth;
        if (age >= 60) {
            discount = 5;
        }
        int price_per_purchase = 100 - age - discount;
        if (price_per_purchase < 0) {
            price_per_purchase = 0;
        }
        int revenue = price_per_purchase * customer.numPurchases;
        total_revenue += revenue;
    }

    infile.close();
    cout << "Total revenue: " << total_revenue << endl;
}

void processCustomers(string inputFile, string outputFile) {
    ifstream infile(inputFile, ios::binary);
    ofstream outfile(outputFile, ios::binary);
    int discount = 0;

    Customer customer;
    while (infile.read((char*)&customer, sizeof(Customer))) {
        int age = 2023 - customer.yearOfBirth;
        if (age >= 60) {
            discount = 5;
        }
        int salePrice = 100 - age - discount;

        if (salePrice * customer.numPurchases > 250.0) {
            outfile.write((char*)&customer, sizeof(Customer));
        }
    }

    infile.close();
    outfile.close();
}

void file_processing() {
    string filename, answer1, answer2;
    string outputFileName = "output";

    cout << "Enter filename: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        createFile(filename);
        addCustomer(filename);
        count_profit(filename);
        processCustomers(filename, outputFileName);
        displayCustomers(outputFileName);
    } else {
        cout << "File '" << filename << "' already exists." << endl;
        displayCustomers(filename);
        addCustomer(filename);
        count_profit(filename);
        processCustomers(filename, outputFileName);
        displayCustomers(outputFileName);
    }
}