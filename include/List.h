#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>

template<typename T>
class Node{
public:
    Node<T>* next;
    T value;

    Node(T val);
    ~Node();
};

template<typename T>
class Linkedlist{
public:
    Node<T>* head;
    Node<T>* tail;
    int count;

    Linkedlist();
    Linkedlist(const Linkedlist& ls);
    Linkedlist& operator=(const Linkedlist& ls);
    ~Linkedlist();

    void push(T& val);
    void pop();
    void delete_any(T& val);

    Node<T>* begin()const;
    Node<T>* end()const;

    int Size();
    bool isempty();

    T& operator[](int idx);
};

#include "../src/List.tpp"

#endif