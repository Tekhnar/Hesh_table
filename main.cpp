#include <stdio.h>
#include "HeshList.h"
int main() {
    List<unsigned int> a[50];

//    printf("Free a[1] %p", a[2].free_);
    a[2].insertInEnd(10);
    return 0;
}