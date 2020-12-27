//
// Created by Тарас Бульба on 26.12.2020.
//

#include <iostream>

#ifndef LISTA6_CMATRIX_H
#define LISTA6_CMATRIX_H

#endif //LISTA6_CMATRIX_H

class CMatrix{
private:
    int **matrix;
    int sizeX;
    int sizeY;
public:

    CMatrix(int i, int j);
    ~CMatrix();

    //GetValues
    //Sizes
    int getX();
    int getY();

    int getValueAt(int x, int y);
    CMatrix getVectorFromRow(int x);
    CMatrix getVectorFromCol(int y);

    //Setters
    //Set value at (x;y)
    bool setValueAt(int value, int x, int y);
    bool setRowAt(int* row , int row_size, int x);



    //OPERATIONS
    CMatrix add(CMatrix &matrix);
    CMatrix substract(CMatrix &matrix);
    CMatrix multiply(CMatrix &matrix);
    CMatrix multiplyByNumber(int number);
    CMatrix transpose();
    int scalarOfVectors(CMatrix &matrix);

    //Print matrix
    void printMatrix();
};