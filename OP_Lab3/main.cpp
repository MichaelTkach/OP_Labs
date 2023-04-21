#include "funcs.h"

int main() {
    int n;

    cout << "Enter number of the products: ";
    cin >> n;
    cout << endl;

    Product products[n]; // создание массива объектов класса
    
    for (int i = 0; i < n; i++) {
        string productname, date_man, date_exp;
        
        cout << "Enter the name of the " << i + 1 << " product: ";
        cin >> productname;

        cout << "Enter the manufacture date of this product (MM-DD-YYYY): ";
        cin >> date_man;

        cout << "Enter the expiration date of this product (MM-DD-YYYY): ";
        cin >> date_exp;
        cout << endl;
        
        products[i] = Product(productname, date_man, date_exp);
    }

    checkExpiredProducts(n, products);
    return 0;
}
