//
// Created by texnar on 04/11/2019.
//

#ifndef HESH_TABLE_HESHLIST_H
#define HESH_TABLE_HESHLIST_H

#include <stdlib.h>

typedef long list_t;

template <typename T>
struct element {
    T data_;
    T* next_;
    /*element ();
    ~element();
    element (const element& that) = delete;*/
};

template <typename T>
struct List {
//    T* data_;
//    element<T> arrays;
    T* head_;
    T* tail_;
    T* free_;
    list_t size_;
    list_t length_;

    T* point_from_calloc[100];
    list_t size_calloc;

    explicit List (); // MULTIPLICATION can be only integer number
    ~List ();
    List (const List& that) = delete;

    void fillingFreePoints ();
    void autoIncreaseLength (list_t MULTIPLICATION_FACTOR = 2);

//    T* insertAfterIndex(list_t index, T value);
    T* insertInEnd (T value);
};

#include "HeshList.cpp"

#endif //HESH_TABLE_HESHLIST_H
