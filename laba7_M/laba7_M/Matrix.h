#pragma once

#include <iostream>
#include <stdexcept>
using namespace System::Windows::Forms;
ref class Matrix {
private:
    int rows;
    int cols;
    array<array<double>^>^ data;

public:
    Matrix(int rows, int cols, TableLayoutPanel^ tableLayoutPanel);

    double CalculateTrace();
};