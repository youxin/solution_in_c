#include "my_queue_list.h"

struct queue_node{
	queue_element element;
	queue_position next;
};

struct queue_recored
{
	int size;
	queue_position front;
	queue_position rear;
};

QUEUE create_queue()
{
	QUEUE queue;
	queue = (QUEUE)malloc(sizeof(queue_recored));	
	queue.size = 0;
	queue.front = NULL;
	queue.rear = NULL;
}

void delete_queue(QUEUE queue)
{
	queue_position p;
	queue_position tmp_cell;
	if (queue != NULL)
	{
		p = queue->front;
		while (p != NULL)
		{
			tmp_cell = p->next;
			free(p);
			p = tmp_cell;
		}
		free(queue);
	}
}

int is_empty(QUEUE queue)
{
	return ((queue == NULL) || (queue->size <= 0));
}

queue_element dequeue(QUEUE queue)
{
	queue_element element;
	queue_node_ptr tmp_cell;
	tmp_cell = queue->front;
	queue->front = tmp_cell->next;
	queue->size -= 1;
	element = tmp_cell->element;
	free(tmp_cell);
	return element;
}

void enqueue(QUEUE queue, queue_element element)
{
	queue_node_ptr tmp_cell;
	tmp_cell = (queue_node_ptr)malloc(sizeof(struct queue_node));
	tmp_cell->element = element;
	tmp_cell->next = NULL;
	if (queue->rear == NULL)
	{
		queue->rear = tmp_cell;
	}
	else
	{
		queue->rear->next = tmp_cell;
	}
	queue->size += 1;
}
