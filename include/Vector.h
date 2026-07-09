#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib>
#include <new>
#include <stdexcept>

template<typename T>
class Vector {
private:
    int capacity;
    int size;
    T* ptr;

    void resizing();

public:
    Vector();
    ~Vector();

    Vector(const Vector<T>& v);
    Vector<T>& operator=(const Vector<T>& v);

    void push_back(const T& x);
    void pop_back();

    int Size() const;
    bool isempty() const;

    T& operator[](int idx);
    const T& operator[](int idx) const;
};

#include "Vector.tpp"

#endif