#ifndef SPARSE_MATRIX_NODE_H
#define SPARSE_MATRIX_NODE_H

template <typename T>
class Matrix;

template <typename T>
class Node {
protected:
    T data;
    unsigned posR, posC;
    Node <T>* next;
    Node <T>* down;


public:
    Node() = default;

    Node(unsigned _posR, unsigned _posC){ //Para Headers
        posR = _posR;
        posC = _posC;
        this->next = this->down = nullptr;
    };

    Node(T _data, unsigned _posR, unsigned _posC){ //Para nodos
        data = _data;
        posR = _posR;
        posC = _posC;
        this->next = this->down = nullptr;
    };

    void operator delete(void* ptr, size_t sz){
        free (ptr);
    }

    void killSelf(){
        delete this;
    }


    friend class Matrix<T>;
};

#endif //SPARSE_MATRIX_NODE_H
