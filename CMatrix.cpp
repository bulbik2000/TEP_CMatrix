//
// Created by Тарас Бульба on 26.12.2020.
//
#include "CMatrix.h"
#include <string>
using namespace std;
#include <cmath>;

//const int CMatrix::DEF_VAL=2;

CMatrix::CMatrix(int x, int y)
        : sizeX(x),
          sizeY(y)
{
    if( (sizeX>0) || (sizeY>0) ){
        matrix=new int*[sizeX];
        for(int i = 0; i < sizeX; i++){
            //Create line
            matrix[i] = new int[sizeY];

            //fill matrix with values
            for(int ii = 0; ii < sizeY; ii++){
                matrix[i][ii] = i+ii;
            }

        }
    }
}

CMatrix::~CMatrix(){
    for (int i = 0; i < sizeX; i++)
        delete [] matrix[i];
    delete [] matrix;
}

void CMatrix::printMatrix(){
    for(int i = 0; i < sizeX; i++){
        cout << "\n";
        for(int ii = 0; ii < sizeY; ii++){
            cout << " ";
            cout << matrix[i][ii];
        }
    }
    cout << "\n";
}

//SETTERS
bool CMatrix::setValueAt(int value, int x, int y){

    if( x<0 || x>=sizeX){
        return false;
    }
    if( y<0 || y>=sizeY){
        return false;
    }

    matrix[x][y] = value;
    return true;
}

bool CMatrix::setRowAt(int* row , int row_size ,int x){
    if( x<sizeX && (row_size<sizeY) ){
        return true;
    }
    return false;
}

//GETTERS
//GetSize
int CMatrix::getX(){
    return this->sizeX;
}

int CMatrix::getY(){
    return this->sizeY;
}

//Val at Pos
int CMatrix::getValueAt(int x, int y){
    if( x<0 || x>=sizeX){
        return -100;
    }
    if( y<0 || y>=sizeY){
        return -100;
    }

    return matrix[x][y] ;
}

//Get Vectors From Matrix

CMatrix CMatrix::getVectorFromRow(int x)
{
    if( x < sizeX )
    {
        CMatrix res(1, this->sizeY);
        for(int i = 0; i < sizeY; i++)
        {
            res.matrix[0][i] = this->matrix[x][i];
        }
        return res;
    }
}

CMatrix CMatrix::getVectorFromCol(int y)
{
    if( y < sizeY )
    {
        CMatrix res(1, this->sizeX);
        for(int i = 0; i < sizeX; i++)
        {
            res.matrix[0][i] = this->matrix[i][y];
        }
        return res;
    }
}

//OPERATIONS

//MULTIPLICATION
CMatrix CMatrix::multiply(CMatrix &matrix){
    if( sizeY == matrix.sizeX ) {
        //Result matrix
        CMatrix res(sizeX,matrix.sizeY);
        //Naive algorithm O(n^3)
        for (int i = 0; i < sizeX; i++){
            for(int j = 0; j < matrix.sizeY ; j++){
                (res.matrix)[i][j] = 0;
                for(int k = 0; k < matrix.sizeX; k++){
                    (res.matrix)[i][j] =
                            (this->matrix[i][k])*matrix.matrix[k][j];
                }
            }
        }

        return res;
    }
}

//MULTIPLICATION BY NUMBER
CMatrix CMatrix::multiplyByNumber(int number){
        //Result matrix
        CMatrix res(sizeX,sizeY);
        for(int i = 0; i < sizeX; i++){
            for(int ii = 0; ii < sizeY; ii++){
                matrix[i][ii]*=number;
            }
        }
        return res;
}

//ADDITION
CMatrix CMatrix::add(CMatrix &matrix){
    if( (sizeX == matrix.sizeX) && (sizeY == matrix.sizeY) ) {
        //Result matrix
        CMatrix res(sizeX,sizeY);

        for (int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY ; j++){
                (res.matrix)[i][j] =
                        (this->matrix[i][j])+matrix.matrix[i][j];
            }
        }
        return res;
    }
}

//SUBSTRACTION
CMatrix CMatrix::substract(CMatrix &matrix){
    if( (sizeX == matrix.sizeX) && (sizeY == matrix.sizeY) ) {
        //Result matrix
        CMatrix res(sizeX,sizeY);

        for (int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY ; j++){
                (res.matrix)[i][j] =
                        (this->matrix[i][j])-matrix.matrix[i][j];
            }
        }

        return res;
    }
}

//TRANSPOSITION
CMatrix CMatrix::transpose(){
    CMatrix res(sizeY,sizeX);
    for(int i = 0; i < sizeX; i++ ){
        for(int j = 0; j < sizeY; j++ ) {
            res.matrix[j][i] = matrix[i][j];
        }
    }
    return res;
}

//SCALAR
int CMatrix::scalarOfVectors(CMatrix &matrix){
    if( (sizeX==1) && (sizeX==matrix.sizeX) && (sizeY==matrix.sizeY)){
        int sum = 0;
        for(int i = 0; i < sizeY; i++){
            sum += (this->matrix[0][i] * matrix.matrix[0][i]);
        }
        return sum;
    }else{
        return 0;
    }
}




