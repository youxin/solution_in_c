#ifndef _MY_QUEUE_ARRAY_H_
#define _MY_QUEUE_ARRAY_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int element_type;
struct queue_record;
typedef struct queue_record *QUEUE;

QUEUE create_queue(unsigned int max_elements);
int is_empty(QUEUE Q);
int is_full(QUEUE Q);
void make_null(QUEUE Q); 
unsigned int succ(unsigned int value, QUEUE Q);
void enqueue(element_type x, QUEUE Q);
element_type dequeue(QUEUE Q);

#ifdef __cplusplus
}
#endif

#endif //_MY_QUEUE_ARRAY_H_