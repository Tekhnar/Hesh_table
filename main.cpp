#include <stdio.h>

typedef unsigned int type_list;

#include "HeshList.h"

int main() {
    int size_array_list = 50;
    List<type_list> a[size_array_list];

    WordProcessing(a, size_array_list);
    return 0;
}
