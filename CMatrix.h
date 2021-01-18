//
// Created by Тарас Бульба on 26.12.2020.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#ifndef LISTA6_CMATRIX_H
#define LISTA6_CMATRIX_H

#endif //LISTA6_CMATRIX_H

template < typename T > class CMatrix{
private:
    T **matrix;
    int sizeX;
    int sizeY;
public:

    CMatrix(int i, int j);
    ~CMatrix();

    //GetValues
    //Sizes
    int getX();
    int getY();

    T getValueAt(int x, int y);
    CMatrix getVectorFromRow(int x);
    CMatrix getVectorFromCol(int y);

    //Setters
    //Set value at (x;y)
    bool setValueAt(T value, int x, int y);
    bool setRowAt(int* row , int row_size, int x);



    //OPERATIONS
    CMatrix<T> add(CMatrix<T> &matrix);
    CMatrix<T> substract(CMatrix<T> &matrix);
    CMatrix<T> multiply(CMatrix<T> &matrix);
    CMatrix<T> multiplyByNumber(T number);
    CMatrix<T> transpose();
    T scalarOfVectors(CMatrix<T> &matrix);

    //OVERLOADED OPERATORS
    CMatrix<T> operator+(CMatrix<T> &otherMatrix);
    CMatrix<T> operator-(CMatrix<T> &otherMatrix);
    CMatrix<T> operator*(CMatrix<T> &otherMatrix);
    CMatrix<T> operator*(T number);
    void operator=(CMatrix<T> otherMatrix);

    //Print matrix
    void printMatrix();


    //Get Matrix From File
    static CMatrix<T> readFromFile(const string &filePath)
    {
        if(filePath.empty())
        {
            throw "Empty file path";
        }

        fstream handle;
        int numberOfRows = 0;
        int numberOfColumns = 0;
        handle.open(filePath);

        if (!handle.is_open()){
            throw "File with matrix was not opened !";
        }

        string line;
        getline(handle, line);
        istringstream stm(line);

        T word;

        while (stm >> word) {
            numberOfColumns++;
        }
        numberOfRows++;
        while (getline(handle, line)) {
            if(!line.empty()){
                numberOfRows++;
            }
        }
        handle.close();


        CMatrix<T> result(numberOfRows, numberOfColumns);


        handle.open(filePath);
        int i = 0;


        while (getline(handle, line)) {
            if(!line.empty()){
                std::istringstream stm(line);
                T word;
                int j = 0;
                while (stm >> word) {
                    result.setValueAt(word ,i, j);
                    j++;
                }
                i++;
            }
        }
        handle.close();

        return result;
    }


};


//IMPLEMENTATION


template <typename T>
CMatrix<T>::CMatrix(int x, int y)
        : sizeX(x),
          sizeY(y)
{
    if( (sizeX>0) && (sizeY>0) ){
        matrix=new T*[sizeX];
        for(int i = 0; i < sizeX; i++){
            //Create line
            matrix[i] = new T[sizeY];

            //fill matrix with values
            for(int ii = 0; ii < sizeY; ii++){
                matrix[i][ii] = i+ii;
            }
        }
    }else{
        matrix = NULL;
    }
}

template <typename T>
CMatrix<T>::~CMatrix(){
    if( (sizeX!=0) && (sizeX!=0) ){
        for (int i = 0; i < sizeX; i++) {
            delete matrix[i];
        }
        delete [] matrix;
    }
}

template <typename T>
void CMatrix<T>::printMatrix()
{
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
        CMatrix<T> res(1, this->sizeY);
        for(int i = 0; i < sizeY; i++)
        {
            res.matrix[0][i] = matrix[x][i];
        }
        return res;
    }
    CMatrix<T> nullable(0, 0);
    return nullable;
}

template <typename T>
CMatrix<T> CMatrix<T>::getVectorFromCol(int y)
{
    if( y < sizeY )
    {
        CMatrix<T> res(1, this->sizeX);
        for(int i = 0; i < sizeX; i++)
        {
            res.matrix[0][i] = this->matrix[i][y];
        }
        return res;
    }
    CMatrix<T> nullable(0, 0);
    return nullable;
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
}

//OVERLOADED OPERATORS

//ADDITION
template <typename T>
CMatrix<T> CMatrix<T>::operator+(CMatrix<T>& otherMatrix){
    if( (sizeX == otherMatrix.getX()) && (sizeY == otherMatrix.getY()) ) {
        //Result matrix
        CMatrix<T> res(sizeX,sizeY);

        for (int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY ; j++){
                (res.matrix)[i][j] = (this->matrix[i][j])+otherMatrix.matrix[i][j];
            }
        }
        return res;
    }
    CMatrix<T> nullable(0,0);
    return nullable;
}

//SUBSTRACTION
template <typename T>
CMatrix<T> CMatrix<T>::operator-(CMatrix<T> &otherMatrix)
{
    if( (sizeX == otherMatrix.getX()) && (sizeY == otherMatrix.getY()) ) {
        //Result matrix
        CMatrix<T> res(sizeX,sizeY);

        for (int i = 0; i < sizeX; i++){
            for(int j = 0; j < sizeY ; j++){
                (res.matrix)[i][j] = (this->matrix[i][j])-otherMatrix.matrix[i][j];
            }
        }
        return res;
    }
    CMatrix<T> nullable(0,0);
    return nullable;
}
//MULTIPLICATION
template <typename T>
CMatrix<T> CMatrix<T>::operator*(CMatrix<T> &otherMatrix)
{
    if( sizeY == otherMatrix.sizeX ) {
        //Result matrix
        CMatrix<T> res(sizeX,otherMatrix.sizeY);
        //Naive algorithm O(n^3)
        for (int i = 0; i < sizeX; i++){
            for(int j = 0; j < otherMatrix.sizeY ; j++){
                (res.matrix)[i][j] = 0;
                for(int k = 0; k < otherMatrix.sizeX; k++){
                    (res.matrix)[i][j] =
                            (this->matrix[i][k])*otherMatrix.matrix[k][j];
                }
            }
        }
        return res;
    }
    CMatrix<T> nullable(0,0);
    return nullable;
}

//MULTIPLICATION BY NUMBER
template <typename T>
CMatrix<T> CMatrix<T>::operator*(T number)
{
    //Result matrix
    CMatrix<T> res(sizeX,sizeY);
    for(int i = 0; i < sizeX; i++){
        for(int ii = 0; ii < sizeY; ii++){
            matrix[i][ii]*=number;
        }
    }
    return res;
}

//MS
template <typename T>
void CMatrix<T>::operator=(CMatrix<T> otherMatrix){
    if( (sizeX!=0) && (sizeX!=0) ){
        for (int i = 0; i < sizeX; i++) {
            delete[] matrix[i];
        }
        delete [] matrix;
    }

    sizeX = otherMatrix.sizeX;
    sizeY = otherMatrix.sizeY;

    otherMatrix.sizeX = 0;
    otherMatrix.sizeY = 0;

    matrix = otherMatrix.matrix;
    otherMatrix.matrix = NULL;

}