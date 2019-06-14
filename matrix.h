#ifndef SPARSE_MATRIX_MATRIX_H
#define SPARSE_MATRIX_MATRIX_H

#include "node.h"
#include <stdexcept>

using namespace std;

template <typename T>
class Matrix {
private:
    Node<T> *root;
    unsigned rows, columns;

public:
    Matrix(unsigned rows, unsigned columns){
        if(rows == 0 && columns == 0) throw out_of_range("Valor de filas y columnas inválido!");
        else {
            root = new Node <T>();
            this->rows = rows;
            this->columns = columns;
            createRowsHeaders();
            createColumHeaders();
        }
    };

    void set(unsigned _posR, unsigned _posC, T value){
        auto newNodeIn = new Node<T>(value, _posR, _posC);
        auto tempC = new Node<T>(); //columna
        auto tempR = new Node<T>(); //fila


        findPosR(_posR, _posC, tempR);

        if(tempR->down){
            auto temp = tempR->down;
            if(tempR->down->posR == _posR){ //Si es que ya existe un valor en dicha posición
                if(newNodeIn->data != 0){ //controla si se inserta un cero
                    tempR->down = newNodeIn;
                    newNodeIn->down = temp->down;
                }else{
                    tempR->down = temp->down;
                    delete newNodeIn;
                }
            }
            else{
                tempR->down = newNodeIn;
                newNodeIn->down = temp;
            }
        }else
            tempR->down = newNodeIn;

        //Link en columna
        findPosC(_posR, _posC, tempC);
        if(tempC->next){
            auto temp = tempC->next;
            if (tempC->next->posC == _posC){ //Si es que ya existe un valor en dicha posición
                if(newNodeIn->data != 0) {//controla si se inserta un cero
                    tempC->next = newNodeIn;
                    newNodeIn->next = temp->next;
                }else{
                    tempC->next = temp->next;
                }
                delete temp;
            }else {
                tempC->next = newNodeIn;
                newNodeIn->next = temp;
            }
        }else
            tempC->next = newNodeIn;

    };

    T operator()(unsigned _posR, unsigned _posC) const{
        auto temp = root;
        for(int i = 0 ; i <= _posC; i++)
            temp = temp->next;
        while(temp->down){
            temp = temp->down;
            if(temp->posR == _posR)
                return temp->data;
        }
       throw out_of_range ("No se encontró el valor solicitado!");
    };

    Matrix<T> operator*(T scalar) const{
        auto newMatriz = new Matrix <T>(rows, columns);
        auto temp = root;
        while(temp->down){
            temp = temp->down;
            auto temp2 = temp;
            while(temp->next){
                temp = temp->next;
                newMatriz->set(temp->posR, temp->posC, temp->data*scalar);
            }
            temp = temp2;
        }
        return *newMatriz;
    };
    Matrix<T> operator*(Matrix<T> other) const{
        if(columns == other.rows) { //colA = rowB
            auto newMatriz = new Matrix<T>(rows, other.columns);
            auto tempA = root;
            auto tempB = other.root;
            while(tempB->next){
                tempB = tempB->next;
                    while (tempA->down) {
                    tempA = tempA->down;
                    auto tempA2 = tempA;
                    auto tempB2 = tempB;
                    T suma=0;
                    while (tempA->next) {
                        tempA = tempA->next;
                        auto tempB3 = tempB;
                        while (tempB->down) {
                            tempB = tempB->down;
                            if (tempA->posC == tempB->posR) {
                                suma += tempA->data * tempB->data;
                                break;
                            }
                        }
                        tempB = tempB3;
                    }
                    newMatriz->set(tempA->posR, tempB->posC, suma);
                    tempA = tempA2;
                    tempB = tempB2;
                }
            }
            return *newMatriz;
        }else
            throw out_of_range ("Las matrices no tienen las mismas dimensiones");



    };
    Matrix<T> operator+(Matrix<T> other) const{
        if(rows == other.rows && columns == other.columns) {
            auto newMatriz = new Matrix<T>(rows, columns);
            auto tempOther = other.root;
            auto temp = root;
            while (temp->down) {
                temp = temp->down;
                tempOther = tempOther->down;
                auto temp2 = temp;
                auto tempOther2 = tempOther;
                while (temp->next) {
                    temp = temp->next;
                    tempOther = tempOther->next;
                    newMatriz->set(temp->posR, temp->posC, temp->data + tempOther->data);
                }
                temp = temp2;
                tempOther = tempOther2;
            }
            return *newMatriz;
        }else
            throw out_of_range ("Las matrices no tienen las mismas dimensiones");
    };
    Matrix<T> operator-(Matrix<T> other) const{
        if(rows == other.rows && columns == other.columns) {
            auto newMatriz = new Matrix<T>(rows, columns);
            auto tempOther = other.root;
            auto temp = root;
            while (temp->down) {
                temp = temp->down;
                tempOther = tempOther->down;
                auto temp2 = temp;
                auto tempOther2 = tempOther;
                while (temp->next) {
                    temp = temp->next;
                    tempOther = tempOther->next;
                    newMatriz->set(temp->posR, temp->posC, temp->data - tempOther->data);
                }
                temp = temp2;
                tempOther = tempOther2;
            }
            return *newMatriz;
        }else
            throw out_of_range ("Las matrices no tienen las mismas dimensiones");

    };
    Matrix<T> transpose() const{
        auto newMatriz = new Matrix <T>(columns, rows);
        auto temp = root;
        while(temp->down){
            temp = temp->down;
            auto temp2 = temp;
            while(temp->next){
                temp = temp->next;
                newMatriz->set(temp->posC, temp->posR, temp->data);
            }
            temp = temp2;
        }
        return *newMatriz;
    };
    void print() const {
        auto temp = root;
        for(int i = 0; i < rows; i++){
            temp = temp->down;
            auto temp2 = temp;
            for(int j = 0; j < columns; j++ ){
                if(temp->next && temp->next->posC==j){
                    temp = temp->next;
                    cout << temp->data << " ";
                }else{
                    cout << "0" << " ";
                }
            }
            cout << endl;
            temp = temp2;
        }
        cout << endl;
    };

    ~Matrix(){

    };

protected:

    bool createRowsHeaders(){
        auto temp = root;
        for (int i = 0; i < rows; i++){
            Node<T>* newNode = new Node<T>(i, 0);
            temp->down = newNode;
            temp = newNode;
        }
        return true;
    }
    bool createColumHeaders(){
        auto temp = root;
        for (int i = 0; i < columns; i++){
            Node <T>* newNode = new Node<T>(0, i);
            temp->next = newNode;
            temp = newNode;
        }
        return true;
    }
    bool findPosR (unsigned _posR, unsigned _posC, Node<T>* &_tempR){
        _tempR = root;
        for(int i = 0; i <= _posC; i++) //Moverse en C
            _tempR = _tempR->next;

        while(_tempR->down && (_tempR->down->posR < _posR)) //buscar R
            _tempR = _tempR->down;

        return true;
    };

    bool findPosC (unsigned _posR, unsigned _posC,  Node<T> * &_tempC){
        _tempC = root;
        for(int i = 0; i <= _posR; i++) //Bajar en R
            _tempC = _tempC->down;

        while(_tempC->next && (_tempC->next->posC < _posC)) //buscar C
            _tempC = _tempC->next;

        return true;
    };


};

#endif //SPARSE_MATRIX_MATRIX_H