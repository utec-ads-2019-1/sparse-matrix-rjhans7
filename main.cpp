#include <iostream>
#include "matrix.h"
#include "tester/tester.cpp"

int main() {
   // Tester::execute();

       int n=5, c=5;

       //indices inician desde 1 (FILA, COLUMNA)
       auto myMatrix = new Matrix<int>(n, c);
       auto myMatri2 = new Matrix<int>(n, c);
       myMatrix->set(0,1,3);
       myMatrix->set(1,0,2);
       myMatrix->set(1,2,2);
       myMatrix->set(2,1,1);
       myMatri2->set(0,0,1);
       myMatri2->set(1,0,2);

       auto resultado = (*myMatrix)*(*myMatri2);

    return EXIT_SUCCESS;
}

