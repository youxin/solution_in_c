#ifndef _MY_SORT_H_
#define _MY_SORT_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int input_type;

void insertion_sort(input_type a[], unsigned int n);

void shellsort(input_type a[], unsigned int n);

void heapsort(input_type a[], unsigned int n);




#ifdef __cplusplus
}
#endif

#endif //_MY_SORT_H_