#include <iostream>
#include <stdexcept>
#include "Matrix.h"

Matrix::Matrix(int rs, int cs, TableLayoutPanel^ tableLayoutPanel) {

    this->rows = rs;
    this->cols = cs;

    data = gcnew array<array<double>^>(rows);
    for (int i = 0; i < rows; i++) {
        data[i] = gcnew array<double>(cols);
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            TextBox^ textBox = dynamic_cast<TextBox^>(tableLayoutPanel->GetControlFromPosition(col, row));

            double value;
            if (!System::Double::TryParse(textBox->Text, value))
                throw gcnew System::Exception("Invalid input in the text boxes.");

            data[row][col] = value;
        }
    }
}

double Matrix::CalculateTrace() {
    if (rows != cols)
        throw gcnew System::Exception("Trace can be calculated only for square matrices.");

    double trace = 0.0;
    for (int i = 0; i < rows; i++) {
        trace += data[i][i];
    }

    if (trace == 0.0)
        throw gcnew System::Exception("The trace of the matrix is zero.");

    return trace;
}
