#include <iostream>
#include "CMatrix.h"
#include <string>
using namespace std;


void multiplyMatrices(){
    CMatrix<int> matrix1(5,3);
    CMatrix<int> matrix2(3,2);

    CMatrix<int> res(1,1);

    res=(matrix1*matrix2);
    res.printMatrix();
}

void substractMatrices(){
    CMatrix<int> matrix1(5,3);
    CMatrix<int> matrix2(5,3);

    matrix1.setValueAt(-100,2,2);
    matrix2.setValueAt(-120,2,2);

    CMatrix<int> res(1,1);

    //res=(matrix1-matrix2);
    res.printMatrix();
}

void transposeMatrix(){
    CMatrix<int> matrix1(5,3);
    matrix1.printMatrix();
    matrix1.transpose().printMatrix();
}

void scalar(){
    CMatrix<int> vector_1(1,5);
    CMatrix<int> vector_2(1,5);

    cout << vector_1.scalarOfVectors(vector_2);
}

void vectorsFromMatrix(){
    CMatrix<int> matrix1(5,3);

    CMatrix<int> vectorX = matrix1.getVectorFromRow(3);
    CMatrix<int> vectorY = matrix1.getVectorFromCol(1);

    vectorX.printMatrix();
    vectorY.printMatrix();
}

void readFromFile(){
    CMatrix<float> matrix = CMatrix<float>::readFromFile("../floatMatrix.txt");
    matrix.printMatrix();
}

int main() {
    //multiplyMatrices();

    readFromFile();
    return 0;
}
