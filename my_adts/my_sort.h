#ifndef _MY_SORT_H_
#define _MY_SORT_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int input_type;

void insertion_sort(input_type a[], unsigned int n);

void selection_sort(input_type a[], unsigned int n);

void shellsort(input_type a[], unsigned int n);

void heapsort(input_type a[], unsigned int n);

void mergesort(input_type a[], unsigned int n);

void radix_sort(input_type a[], unsigned int n);

void quick_sort(input_type a[], unsigned int n);

void quick_select(input_type a[], unsigned int k, unsigned int n);


#ifdef __cplusplus
}
#endif

#endif //_MY_SORT_H_