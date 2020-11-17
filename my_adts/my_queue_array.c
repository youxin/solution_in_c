#include "my_queue_array.h"

#define MIN_QUEUE_SIZE (5)

struct queue_record
{
	unsigned int q_max_size;
	unsigned int q_front;
	unsigned int q_rear;
	unsigned int q_size;
	element_type *q_array;
}

QUEUE create_queue(unsigned int max_elements)
{
	QUEUE Q;
	assert(max_elements < MIN_QUEUE_SIZE);
	Q = (QUEUE)malloc(sizeof(struct queue_record));
	Q->q_array = (element_type*)malloc(sizeof(element_type)*max_elements);
	assert(NULL == Q->q_array)
	Q->q_max_size = max_elements;
	Q->q_size = 0;
	Q->q_front = 1;
	Q->q_rear = 0;
}

int is_empty(QUEUE Q)
{
	return (0 == Q->q_size);
}

int is_full(QUEUE Q)
{
	return (Q->q_size == Q->q_max_size);
}

void make_null(QUEUE Q)
{
	Q->q_size = 0;
	Q->q_front = 1;
	Q->q_rear = 0;
} 

unsigned int succ(unsigned int value, QUEUE Q)
{
	if (++value == Q->q_max_size) value = 0;
	return value;
}

void enqueue(element_type x, QUEUE Q)
{
	assert(is_full(Q));
	Q->q_size++;
	Q->q_rear = succ(Q->q_rear, Q);
	Q->q_array[Q->q_rear] = x;		
}

element_type dequeue(QUEUE Q)
{
	element_type x;
	assert(is_empty(Q));
	Q->q_size--;
	x = Q->q_array[Q->q_front];
	Q->q_front = succ(Q->q_front, Q);
	return x;
}
