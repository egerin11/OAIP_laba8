#include"Header.h"
#include<stdio.h>

void task(int argc, char **argv) {
    if (argc == 1) {
        printf("\n not enough arguments\n");
        return;
    }
    char **arr2 = memory(argc);
    int *size = memory1(argc);
    fillAndCopyArrays(argc, arr2, argv, &size);
    mergeSort(&arr2, &size, 0, argc - 2);
    print(argc, arr2);
    freeMemory(arr2, size, argc);

}


