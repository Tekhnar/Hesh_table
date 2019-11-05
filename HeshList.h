//
// Created by texnar on 04/11/2019.
//

#ifndef HESH_TABLE_HESHLIST_H
#define HESH_TABLE_HESHLIST_H

#include <stdlib.h>
#include "assert.h"
#include <string.h>

typedef long long list_t;
template <typename T>
struct element {
    T data_;
    T* next_;
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

    T* searchByValue (T value);
    void fillingFreePoints (list_t last_length);
    void autoIncreaseLength (list_t MULTIPLICATION_FACTOR = 2);
    T* insertInEnd (T value);
};

type_list HeshingAlwaysOne(const char* str);
type_list HeshingFirstSymbol(const char* str);
type_list HeshingStringLength(const char* str);
type_list HeshingSumSymbol(const char* str);
type_list HeshingRol(const char* str);
type_list HeshingGNU(const char* str);
#include "HeshList.cpp"

#endif //HESH_TABLE_HESHLIST_H
