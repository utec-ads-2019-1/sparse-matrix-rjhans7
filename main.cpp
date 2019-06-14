#include <iostream>
#include "matrix.h"
#include "tester/tester.cpp"

int main() {
    //Tester::execute();


       //indices inician desde 1 (FILA, COLUMNA)
       auto myMatrix = new Matrix<int>(3, 3);
       auto myMatri2 = new Matrix<int>(3, 1);
       myMatrix->set(0,0,3);
       myMatrix->set(0,1,2);
       myMatrix->set(0,2,4);
       myMatrix->set(1,2,2);
       myMatrix->set(2,0,1);
       myMatrix->set (2,2,3);
       myMatrix->print();

       myMatrix->set(0,1,0);
       myMatrix->print();

       myMatri2->set(0,0,1);
       myMatri2->set(1,0,2);


       myMatri2->print();
       auto resultado = (*myMatrix)*(*myMatri2);
       resultado.print();


    return EXIT_SUCCESS;
}

