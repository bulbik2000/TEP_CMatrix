//
// Created by Тарас Бульба on 26.12.2020.
//
#include "CMatrix.h"
#include <string>
using namespace std;


//const int CMatrix::DEF_VAL=2;
/*
template <typename T>
CMatrix<T>::CMatrix(int x, int y)
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

template <typename T>
CMatrix<T>::~CMatrix(){
    for (int i = 0; i < sizeX; i++)
        delete [] matrix[i];
    delete [] matrix;
}

template <typename T>
void CMatrix<T>::printMatrix(){
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
template <typename T>
bool CMatrix<T>::setValueAt(T value, int x, int y){

    if( x<0 || x>=sizeX){
        return false;
    }
    if( y<0 || y>=sizeY){
        return false;
    }

    matrix[x][y] = value;
    return true;
}

template <typename T>
bool CMatrix<T>::setRowAt(int* row , int row_size ,int x){
    if( x<sizeX && (row_size<sizeY) ){
        return true;
    }
    return false;
}

//GETTERS
//GetSize
template <typename T>
int CMatrix<T>::getX(){
    return this->sizeX;
}

template <typename T>
int CMatrix<T>::getY(){
    return this->sizeY;
}

//Val at Pos
template <typename T>
T CMatrix<T>::getValueAt(int x, int y){
    if( x<0 || x>=sizeX){
        return -100;
    }
    if( y<0 || y>=sizeY){
        return -100;
    }

    return matrix[x][y] ;
}

//Get Vectors From Matrix

template <typename T>
CMatrix<T> CMatrix<T>::getVectorFromRow(int x)
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

template <typename T>
CMatrix<T> CMatrix<T>::getVectorFromCol(int y)
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
template <typename T>
CMatrix<T> CMatrix<T>::multiply(CMatrix<T> &matrix){
    if( sizeY == matrix.sizeX ) {
        //Result matrix
        CMatrix<T> res(sizeX,matrix.sizeY);
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
template <typename T>
CMatrix<T> CMatrix<T>::multiplyByNumber(T number){
        //Result matrix
        CMatrix<T> res(sizeX,sizeY);
        for(int i = 0; i < sizeX; i++){
            for(int ii = 0; ii < sizeY; ii++){
                matrix[i][ii]*=number;
            }
        }
        return res;
}

//ADDITION
template <typename T>
CMatrix<T> CMatrix<T>::add(CMatrix<T> &matrix){
    if( (sizeX == matrix.sizeX) && (sizeY == matrix.sizeY) ) {
        //Result matrix
        CMatrix<T> res(sizeX,sizeY);

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
template <typename T>
CMatrix<T> CMatrix<T>::substract(CMatrix<T> &matrix){
    if( (sizeX == matrix.sizeX) && (sizeY == matrix.sizeY) ) {
        //Result matrix
        CMatrix<T> res(sizeX,sizeY);

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
template <typename T>
CMatrix<T> CMatrix<T>::transpose(){
    CMatrix res(sizeY,sizeX);
    for(int i = 0; i < sizeX; i++ ){
        for(int j = 0; j < sizeY; j++ ) {
            res.matrix[j][i] = matrix[i][j];
        }
    }
    return res;
}

//SCALAR
template <typename T>
T CMatrix<T>::scalarOfVectors(CMatrix<T> &matrix){
    if( (sizeX==1) && (sizeX==matrix.sizeX) && (sizeY==matrix.sizeY)){
        T sum = 0;
        for(int i = 0; i < sizeY; i++){
            sum += (this->matrix[0][i] * matrix.matrix[0][i]);
        }
        return sum;
    }else{
        return 0;
    }
}*/




