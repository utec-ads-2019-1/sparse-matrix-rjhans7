#include <iostream>
#include "matrix.h"
#include "tester/tester.cpp"

int main() {
    Tester::execute();


        auto myMatrix = new Matrix<int>(3, 3);
        auto myMatri2 = new Matrix<int>(3, 3);
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

        myMatri2->print();
        myMatrix->print();
        auto m = myMatri2->operator*(3);
        m.print();




    return EXIT_SUCCESS;
}

