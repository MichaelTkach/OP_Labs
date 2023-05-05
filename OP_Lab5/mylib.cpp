#include "mylib.h"
#include <iostream>
#include <cmath>

using namespace std;

TQuadrangle::TQuadrangle() {};

TQuadrangle::TQuadrangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->x3 = x3;
    this->y3 = y3;
    this->x4 = x4;
    this->y4 = y4;
}

double TQuadrangle::distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double TQuadrangle::perimeter() {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x4, y4);
    double d = distance(x4, y4, x1, y1);
    return a + b + c + d;
}

bool TQuadrangle::valid_check() {
    double d12 = distance(x1, y1, x2, y2);
    double d13 = distance(x1, y1, x3, y3);
    double d14 = distance(x1, y1, x4, y4);
    double d23 = distance(x2, y2, x3, y3);
    double d24 = distance(x2, y2, x4, y4);
    double d34 = distance(x3, y3, x4, y4);

    if (d12 == 0 || d13 == 0 || d14 == 0 || d23 == 0 || d24 == 0 || d34 == 0) {
        cout << "Invalid quadrangle verification!" << endl;
        return false;
    }
    return true;
}

double TQuadrangle::area() {
    double a = distance(x1, y1, x2, y2);
    double b = distance(x1, y1, x3, y3);
    double c = distance(x2, y2, x3, y3);
    double p = (a + b + c)/2; 
    double S = 2*sqrt(p*(p-a)*(p-b)*(p-c));
    return S;
}

TRectangle::TRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
    : TQuadrangle(x1, y1, x2, y2, x3, y3, x4, y4) {}

double TRectangle::pyth_theorem(int x1, int y1, int x2, int y2, int x3, int y3) {
    double a = pow(distance(x1, y1, x2, y2), 2);
    double b = pow(distance(x2, y2, x3, y3), 2);
    double c = pow(distance(x1, y1, x3, y3), 2);
    return abs(a + b - c);
}

bool TRectangle::rectangle_check() {
    double angle1 = pyth_theorem(x1, y1, x2, y2, x3, y3);
    double angle2 = pyth_theorem(x2, y2, x3, y3, x4, y4);
    double angle3 = pyth_theorem(x3, y3, x4, y4, x1, y1);
    if (angle1 > 0.01 || angle2 > 0.01 || angle3 > 0.01) {
        cout << "Invalid rectangle verification!" << endl;
        return false;
    }
    return true;
} 

double TRectangle::area() {
    return distance(x1, y1, x2, y2) * distance(x2, y2, x3, y3);
}

TSquare::TSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
    : TRectangle(x1, y1, x2, y2, x3, y3, x4, y4) {}

double TSquare::area() {
    return pow(distance(x1, y1, x2, y2), 2);
} 

bool TSquare::square_check() {
    if (distance(x1, y1, x2, y2) != distance(x2, y2, x3, y3) || distance(x1, y1, x2, y2) != distance(x3, y3, x4, y4) || 
        distance(x1, y1, x2, y2) != distance(x4, y4, x1, y1)) {
        cout << "Invalid square verification!" << endl;
        return false;
    }
    return true;
}

TParallelogram::TParallelogram(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
    : TQuadrangle(x1, y1, x2, y2, x3, y3, x4, y4) {}

bool TParallelogram::parallelogram_check() {
    if ((distance(x1, y1, x2, y2) != distance(x3, y3, x4, y4)) || (distance(x2, y2, x3, y3) != distance(x1, y1, x4, y4))) {
        cout << "Invalid parallelogram verification!" << endl;
        return false;
    }
    return true;
}

double make_rectangles(int n, TQuadrangle *Figures[]) {
int x1, y1, x2, y2, x3, y3, x4, y4;
bool trigger1, trigger2;
double Area = 0;

for(int i = 0; i < n; i++) {

    do {
        cout << "Enter first vertex of the " << i+1 << " rectangle: ";
        cin >> x1 >> y1;

        cout << "Enter second vertex of the " << i+1 << " rectangle: ";
        cin >> x2 >> y2;

        cout << "Enter third vertex of the " << i+1 << " rectangle: ";
        cin >> x3 >> y3;

        cout << "Enter fourth vertex of the " << i+1 << " rectangle: ";
        cin >> x4 >> y4;
        cout << endl;

        TRectangle rect(x1, y1, x2, y2, x3, y3, x4, y4);
        Figures[i] = &rect;

        trigger1 = Figures[i]->valid_check();
        trigger2 = static_cast<TRectangle*>(Figures[i])->rectangle_check();

        if (trigger1 && trigger2) {
            Area += Figures[i]->area();
        } else {
            cout << "The coordinates of this rectangle are invalid." << endl << endl;
        }
    } while (!trigger1 || !trigger2);
}

return Area;
}

double make_squares(int n, TQuadrangle *Figures[]) {
int x1, y1, x2, y2, x3, y3, x4, y4;
bool trigger1, trigger2, trigger3;
double Area = 0;

for(int i = 0; i < n; i++) {

    do {
        cout << "Enter first vertex of the " << i+1 << " square: ";
        cin >> x1 >> y1;

        cout << "Enter second vertex of the " << i+1 << " square: ";
        cin >> x2 >> y2;

        cout << "Enter third vertex of the " << i+1 << " square: ";
        cin >> x3 >> y3;

        cout << "Enter fourth vertex of the " << i+1 << " square: ";
        cin >> x4 >> y4;
        cout << endl;

        TSquare squa(x1, y1, x2, y2, x3, y3, x4, y4);
        Figures[i] = &squa;

        trigger1 = Figures[i]->valid_check();
        trigger2 = static_cast<TRectangle*>(Figures[i])->rectangle_check();
        trigger3 = static_cast<TSquare*>(Figures[i])->square_check();

        if (trigger1 && trigger2 && trigger3) {
            Area += Figures[i]->area();
        } else {
            cout << "The coordinates of this square are invalid." << endl << endl;
        }
    } while (!trigger1 || !trigger2 || !trigger3);
}

return Area;
}

double make_parallelograms(int n, TQuadrangle *Figures[]) {
int x1, y1, x2, y2, x3, y3, x4, y4;
bool trigger1, trigger2;
double Perimetr = 0;

for(int i = 0; i < n; i++) {

    do {
        cout << "Enter first vertex of the " << i+1 << " parallelogram: ";
        cin >> x1 >> y1;

        cout << "Enter second vertex of the " << i+1 << " parallelogram: ";
        cin >> x2 >> y2;

        cout << "Enter third vertex of the " << i+1 << " parallelogram: ";
        cin >> x3 >> y3;

        cout << "Enter fourth vertex of the " << i+1 << " parallelogram: ";
        cin >> x4 >> y4;
        cout << endl;

        TParallelogram para(x1, y1, x2, y2, x3, y3, x4, y4);
        Figures[i] = &para;
        
        trigger1 = Figures[i]->valid_check();
        trigger2 = static_cast<TParallelogram*>(Figures[i])->parallelogram_check();

        if (trigger1 && trigger2) {
            Perimetr += Figures[i]->perimeter();
        } else {
            cout << "The coordinates of this parallelogram are invalid." << endl << endl;
        }
    } while (!trigger1 || !trigger2);
}

return Perimetr;
}
