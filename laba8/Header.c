#include<stdlib.h>
#include<stdio.h>
int strLen(const char *arr) {
    int i = 0;
    while (arr[i] != '\0')
        i++;
    return i;
}

void strCopy(char *arr1, char **arr2) {
    int strlen = strLen(arr1), i = 0;
    (*arr2) = (char *) calloc(strlen + 1, sizeof(char));
    while (arr1[i] != '\0') {
        (*arr2)[i] = arr1[i];
        i++;
    }
    (*arr2)[i] = '\0';
}

int ifLetter(char arr1) {

    if ((arr1 >= 'a' && arr1 <= 'z') || (arr1 >= 'A' && arr1 <= 'Z'))
        return 1;

    return 0;

}

void erase(char **arr, int *size, int pos) {
    for (int i = pos; i < *size - 1; i++)
        (*arr)[i] = (*arr)[i + 1];
    (*size) -= 1;
    *arr = (char *) realloc(*arr, (*size + 1) * sizeof(char));
    (*arr)[*size] = '\0';
}

void remove1(char **arr) {
    int i = 0;
    int size = strLen(arr[i]);
    while ((*arr)[i] == ' ') {
        erase(arr, &size, i);
    }

    i = size - 2;
    while ((*arr)[i] == ' ') {
        erase(arr, &size, i);
        i--;
    }

    i = 1;
    while (i < size) {
        i++;

        if ((*arr)[i] == ' ') {
            i++;
            while ((*arr)[i] == ' ') {
                erase(arr, &size, i);
            }
        }
    }
}

int findWord(char **arr2) {

    remove1(arr2);

    int i = 0, cnt = 0, cnt1 = 0;
    while ((*arr2)[i] != '\0') {
        if (!ifLetter((*arr2)[i])) {
            if (cnt % 2 == 0) {
                cnt1++;

            }
            cnt = 0;
        } else {

            cnt++;
        }
        i++;
    }
    if (cnt % 2 == 0) {
        cnt1++;
    }

    return cnt1;

}

void merge(char ***arr, int **size, int left, int mid, int right) {
    int l = left, r = mid + 1;
    int len = right - left + 1;
    int *tempSize = (int *) calloc(len, sizeof(int));
    char **tempArr = (char **) calloc(len, sizeof(char *));
    int index = 0;
    while ((l <= mid) && (r <= right)) {
        if ((*size)[l] > (*size)[r]) {
            tempSize[index] = (*size)[l];
            tempArr[index] = (*arr)[l];
            l++;
        } else {
            tempSize[index] = (*size)[r];
            tempArr[index] = (*arr)[r];
            r++;

        }
        index++;
    }
    for (int i = l; i <= mid; i++) {
        tempSize[index] = (*size)[i];
        tempArr[index] = (*arr)[i];
        index++;
    }
    for (int i = r; i <= right; i++) {
        tempArr[index] = (*arr)[i];
        tempSize[index] = (*size)[i];
        index++;
    }

    for (int i = 0; i < len; i++) {
        (*size)[left + i] = tempSize[i];
        (*arr)[left + i] = tempArr[i];
    }
    free(tempSize);
    free(tempArr);

}

void mergeSort(char ***arr, int **size, int left, int right) {

    if (left < right) {
        int mid = ( right+left) / 2;
        mergeSort(arr, size, left, mid);
        mergeSort(arr, size, mid + 1, right);
        merge(arr, size, left, mid, right);
       /* printf("\n");*/
    }
}
void printString(char *arr) {
    int i = 0;
    while (arr[i] != '\0') {
        printf("%c", arr[i]);
        i++;
    }
    printf("\n");
}

void freeMemory(char **arr2, int *size, int argc) {
    for (int i = 0; i < argc - 1; i++) {
        free(arr2[i]);
    }
    free(size);
    free(arr2);
}
 char**  memory(int argc)
{
    char **arr2 = (char **) calloc((argc - 1), sizeof(char *));
    return arr2;
}
 int* memory1(int argc)
{
    int *size = (int *) calloc((argc - 1), sizeof(int));
    return size;
}
void fillAndCopyArrays(int argc,char **arr2,char **argv,int*size)
{
    for (int i = 1; i < argc; i++) {
        strCopy(argv[i], &arr2[i - 1]);
        size[i - 1] = findWord(&argv[i]);
        printf("%d\n%s\n", size[i - 1], argv[i]);
    }
    printf("\n\n");

}

void print(int argc, char **arr2)
{
    for (int i = 0; i < argc - 1; i++) {
        printString(arr2[i]);

    }
}