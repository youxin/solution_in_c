#ifndef _MY_QUEUE_LIST_H_
#define _MY_QUEUE_LIST_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

struct queue_node;
typedef struct queue_node* queue_node_ptr;
typedef queue_node_ptr queue_position;
typedef void* queue_element;

struct queue_recored;
typedef struct queue_recored* QUEUE;

QUEUE create_queue();
void delete_queue(QUEUE queue);
int is_empty(QUEUE queue);
queue_element dequeue(QUEUE queue);
void enqueue(QUEUE queue, queue_element element);

#ifdef __cplusplus
}
#endif

#endif //_MY_QUEUE_LIST_H_