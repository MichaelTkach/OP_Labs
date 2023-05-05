#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class TQuadrangle {
protected:
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
public:
    TQuadrangle();

    TQuadrangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

    double distance(int x1, int y1, int x2, int y2);

    double perimeter();

    bool valid_check();

    virtual double area();
};

class TRectangle : public TQuadrangle {
public:
    TRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

    double pyth_theorem(int x1, int y1, int x2, int y2, int x3, int y3);

    bool rectangle_check();

    virtual double area();
};

class TSquare : public TRectangle {
public:
    TSquare(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

    virtual double area();

    bool square_check();
};

class TParallelogram : public TQuadrangle {
public:
    TParallelogram(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

    bool parallelogram_check();
};

double make_rectangles(int n, TQuadrangle *Figures[]);

double make_squares(int n, TQuadrangle *Figures[]);

double make_parallelograms(int n, TQuadrangle *Figures[]);
