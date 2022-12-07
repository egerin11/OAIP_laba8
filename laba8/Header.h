#ifndef HEADER_H
#define HEADER_H
void strLen(const char *arr);
void strCopy(char *arr1,char ** arr2);
int ifLetter( char arr1);
int findWord(char** arr2);
void remove1(char **arr);
void erase(char **arr, int *size, int pos);
void merge(char ***arr,int ** size,int left,int mid,int right);
void mergeSort(char ***arr,int ** size,int left,int right);
void printString(char* arr);
void freeMemory(char **arr2,int *size,int argc);
char** memory(int argc);
 int* memory1(int argc);
void fillAndCopyArrays(int argc,char **arr2,char **argv,int **size);
void print(int argc,char**arr2);
#endif
