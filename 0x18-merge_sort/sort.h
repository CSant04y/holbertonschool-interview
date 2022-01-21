#ifndef _SORT_H
#define _SORT_H
#define MAX 2000

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *L, int *R, size_t size);

#endif
