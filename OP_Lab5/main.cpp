#include "mylib.h"

int main() {
    int n, n1, n2, n3;
    double Area_Rec, Area_Squa, Peri_Para, Total_Area;

    cout << "Enter number of the figures: ";
    cin >> n;
    cout << endl;
    
    TQuadrangle* Figures[n];

    n2 = n/3;
    n3 = n/3;

    if (n % 3 == 0) {
        n1 = n/3;
    } else if (n % 3 == 1) {
        n1 = n/3 + 1;
    } else {
        n1 = n/3 + 1;
        n2 = n1;
    }

    Area_Rec = make_rectangles(n1, &Figures[n]);
    cout << "Total area of the rectangles: " << Area_Rec << endl << endl;

    Area_Squa = make_squares(n2, &Figures[n]);
    cout << "Total area of the squares: " << Area_Squa << endl << endl;

    Total_Area = Area_Rec + Area_Squa;
    cout << "Total area of the rectangles and squares: " << Total_Area << endl << endl;

    Peri_Para = make_parallelograms(n3, &Figures[n]);
    cout << "Total perimetr of the parallelograms: " << Peri_Para << endl << endl;
    
    return 0;
}