#include <iostream>
#include "matrix.h"
#include "tester/tester.cpp"

int main() {
    //Tester::execute();

        //indices inician desde 1 (FILA, COLUMNA)
        auto myMatrix = new Matrix<int>(3, 3);
        auto myMatri2 = new Matrix<int>(3, 1);
        myMatrix->set(0, 0, 3);
        myMatrix->set(0, 1, 2);
        myMatrix->set(0, 2, 4);
        myMatrix->set(1, 0, 2);
        myMatrix->set(1, 1, 4);
        myMatrix->set(1, 2, 3);
        myMatrix->set(2, 0, 1);
        myMatrix->set(2, 1, 8);
        myMatrix->set(2, 2, 15);

        myMatri2->set(0, 0, 1);
        myMatri2->set(1, 0, 2);

        /*
        int *myPointer = new int;
        *myPointer = 7;
        delete myPointer; //freed memory
        myPointer = nullptr; //pointed dangling ptr to NULL
*/

        myMatri2->print();
        //auto resultado = (*myMatrix) * (*myMatri2);
        //resultado.print();
        delete myMatrix;
        delete myMatri2;

    return EXIT_SUCCESS;
}

