#ifndef _MY_HEAP_H_
#define _MY_HEAP_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int element_type;
struct heap_struct;
typedef struct heap_struct *PRIORITY_QUEUE;

PRIORITY_QUEUE create_pq(unsigned int max_elements);
int is_empty(PRIORITY_QUEUE H);
int is_full(PRIORITY_QUEUE H);
void insert(element_type x, PRIORITY_QUEUE H);
element_type delete_min(PRIORITY_QUEUE H);

void decrease_key(int position, int steps, PRIORITY_QUEUE H);
void increase_key(int position, int steps, PRIORITY_QUEUE H);
element_type delete_element(int position, PRIORITY_QUEUE H);
PRIORITY_QUEUE create_pq2(element_type* elements, int size, unsigned int max_elements);


#ifdef __cplusplus
}
#endif

#endif //_MY_HEAP_H_