#include <iostream>
#include "matrix.h"
//#include "tester/tester.cpp"

int main() {
    //Tester::execute();
    int n=10, c=10;

    //indices inician desde 1 (FILA, COLUMNA)
    auto myMatrix = new Matrix<int>(n, c);

    for (int i = 1; i <= n; i=i+3) {
        for (int j = 1; j <=c; j = j+2){
            myMatrix->set(i, j, rand()%100+1);
            cout << (*myMatrix)(i,j) << " ";
        }
        cout << endl;
    }


    for (int i = 1; i <= n; i=i+3) {
        for (int j = 1; j <=c; j = j+2){
            cout << ((*myMatrix)*(-1))(i,j)  << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= c; i=i+2) {
        for (int j = 1; j <=n; j = j+3){
            cout << myMatrix->transpose()(i,j) << " ";
        }
        cout << endl;
    }



    return EXIT_SUCCESS;
}

