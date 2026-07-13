#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>

template<typename T>
class Vector{
private:
    int capacity;
    int size;
    T* ptr;

    void resizing(int cap = 2);

public:
    Vector();
    Vector(int cap);
    Vector(const Vector<T>& v);
    ~Vector();

    void push_back(const T& x);
    void pop_back();

    int Size() const;
    int Capacity() const;
    bool isempty() const;

    T& operator[](int idx);
    const T& operator[](int idx) const;

    Vector<T>& operator=(const Vector<T>& v);
};

#include "../src/Vector.tpp"

#endif