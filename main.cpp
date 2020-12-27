#include <iostream>
#include "CMatrix.h"
#include <string>
using namespace std;
#include <fstream>


int main() {


    /*WEKTOROWA
    CMatrix matrix_wiektorowa_1(1,5);
    CMatrix matrix_wiektorowa_2(1,5);

    matrix_wiektorowa_1.printMatrix();

    cout << matrix_wiektorowa_1.getValueAt(0, 5);

    //int res = matrix_wiektorowa_1.scalarOfVectors(matrix_wiektorowa_2);

    //cout << res;


    //matrix_wiektorowa_1.printMatrix();
    */

    CMatrix matrix1(5,3);
    //CMatrix matrix2(2,4);
    CMatrix matrix2(3,2);

    CMatrix vectorX = matrix1.getVectorFromRow(3);
    CMatrix vectorY = matrix1.getVectorFromCol(1);


    matrix1.printMatrix();

    vectorX.printMatrix();
    vectorY.printMatrix();

    //matrix1.setValueAt(10, 2, 2);

    //CMatrix res = matrix1.substract(matrix2);

    CMatrix res = matrix1.transpose();

    //res.printMatrix();

    return 0;
}
