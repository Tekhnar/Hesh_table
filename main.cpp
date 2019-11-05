#include <stdio.h>

typedef unsigned int type_list;

#include "HeshList.h"

int main() {
    int size_array_list = 50;
    List<type_list> a[size_array_list];

    WordProcessing(a, size_array_list);
//    printf("Free a[1] %p", a[2].free_);
//    a[2].insertInEnd(10);
//    a[2].insertInEnd(20);
//    a[2].insertInEnd(30);
//    a[2].insertInEnd(40);
//    a[2].insertInEnd(50);

//    printf("Address %p\n", a[2].searchByValue(20));
//    printf("Address %p\n", a[2].searchByValue(30));
//    printf("aaaa[1] num %lld", a[1].size_);
/*    FILE* table = fopen("table.csv", "wb");
    fprintf(table, "No,");
    for (int i = 0; i < size_array_list; i++){
        fprintf(table, "%d," ,i);
    }
    fprintf(table, "\b\n First");


    for (int i = 0; i < size_array_list; i++){
        fprintf(table, "%u," ,a[i].size_);
    }
    fprintf(table, "\b\n");
    fclose(table);*/
    return 0;
}
