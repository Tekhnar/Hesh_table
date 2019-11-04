//
// Created by texnar on 04/11/2019.
//

#include "HeshList.h"

template <typename T>
List<T>::List() {
    head_ = 0;
    tail_ = 0;
    size_ = 0;
    length_ = 100;
    size_calloc = 0;

//    point_from_calloc[size_calloc++] = (T*) calloc (length_, sizeof(struct element<T>));

    /*for (list_t i = 1; i < length_; i++){
        ((element<T>*)point_from_calloc[0])[i].data_ = 0;
        printf("%d\n", ((element<T>*)point_from_calloc[0])[i].data_);

        ((element<T>*)point_from_calloc[0])[i].next_ = (T*)&(((element<T>*)point_from_calloc[0])[i + 1]);
        printf("%p\n", &((element<T>*)point_from_calloc[0])[i]);
    }*/

    fillingFreePoints();

    free_ = (T*)&(((element<T>*)point_from_calloc[0])[1]);
//    printf("First free %p\n", free_);

    ((element<T>*)point_from_calloc[0])[length_ - 1].next_ = (T*)&(((element<T>*)point_from_calloc[0])[0]);
    ((element<T>*)point_from_calloc[0])[0].next_ = (T*)&(((element<T>*)point_from_calloc[0])[0]);

//    length_*= MULTIPLICATION_FACTOR;
}

template <typename T>
List<T>::~List()
{
    for (list_t i = 0; i < size_calloc; i++) {
        free(point_from_calloc[i]);
    }
}

template <typename T>
void List<T>::autoIncreaseLength(list_t MULTIPLICATION_FACTOR)
{
//    point_from_calloc[size_calloc++] = (T*) calloc (length_, sizeof(struct element<T>));
    if (size_ + 1 >= length_ - 1) {
        list_t last_length = length_;
        length_ *= MULTIPLICATION_FACTOR;

        fillingFreePoints();

        ((element<T> *) point_from_calloc[size_calloc - 1])[length_ - 1].next_ =
                (T *) &(((element<T> *) point_from_calloc[0])[0]);

        ((element<T> *) point_from_calloc[size_calloc - 1])[last_length - 1].next_ =
                (T *) &(((element<T> *) point_from_calloc[size_calloc - 1])[0]);
    }
}

template <typename T>
void List<T>::fillingFreePoints()
{
    point_from_calloc[size_calloc++] = (T*) calloc (length_, sizeof(struct element<T>));

    if (point_from_calloc[size_calloc - 1] == nullptr) {
        printf("Error, in calloc\n");
        abort();
    }

    for (list_t i = 0; i < length_; i++){
        ((element<T>*)point_from_calloc[size_calloc - 1])[i].data_ = 0;
//        printf("%d\n", ((element<T>*)point_from_calloc[size_calloc - 1])[i].data_);

        ((element<T>*)point_from_calloc[0])[i].next_ = (T*)&(((element<T>*)point_from_calloc[size_calloc - 1])[i + 1]);
//        printf("%p\n", &((element<T>*)point_from_calloc[size_calloc - 1])[i]);
    }
}

template <typename T>
T* List<T>::insertInEnd (T value) {
    autoIncreaseLength();

    T* new_point = free_;
//    printf("Free %p\n", free_);
    free_ = ((element<T>*)free_)->next_;
//    printf("new Free %p\n", free_);

    if (size_ == 0) {
        head_ = new_point;
        tail_ = new_point;
        ((element<T>*)new_point)->data_ = value;
    }
    else if (size_ > 0) {
        ((element<T>*)tail_)->next_ = new_point;
        tail_ = new_point;
        ((element<T>*)new_point)->data_ = value;
    }

    size_++;
}
/*
template <typename T>
T* List<T>::insertAfterIndex(list_t index, T value)
{
//    check_OK();
//    if (index < 0 || index >length_) printError(6);
//    autoIncreaseLength();
//    if (index != tail_) list_is_sort = false;
    T* new_index = free_;
    free_ = ;

    if (size_ == 0){
        if (index == tail_){
            prev_[new_index] = 0;
            next_[new_index] = 0;

            tail_ = new_index;
            head_ = new_index;
        } else printError (4);
    }
    else if (size_ > 0) {
        if (tail_ == index){
            prev_[new_index] = tail_;
            next_[new_index] = 0;
            next_[tail_] = new_index;

            tail_ = new_index;
        } else {
            prev_[new_index] = index;
            next_[new_index] = next_[index];
            prev_[next_[index]] = new_index;
            next_[index] = new_index;
        }
    }

    data_ [new_index] = value;
    size_++;
    return new_index;
}*/
/*
template <typename T>
element<T>::element() :
data_ (nullptr),
next_ (nullptr),
{}*/
