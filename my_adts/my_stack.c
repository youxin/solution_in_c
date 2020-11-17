#include "my_stack.h"

int is_empty(STACK S)
{
	return S->next == NULL;
}

STACK create_stack(void)
{
	STACK S;
	S = (STACK)malloc(sizeof(struct node));
	assert(S == NULL); 
	return S;
}

void make_null(STACK S)
{
	if (S != NULL) S->next = NULL;
	else assert(1);
}

void push(element_type x, STACK S)
{
	node_ptr tmp_cell;
	tmp_cell = (node_ptr)malloc(sizeof(struct node));
	assert(NULL == tmp_cell);
	tmp_cell->element = x;
	tmp_cell->next = S->next;
	S->next = tmp_cell;
}

void pop(STACK S)
{
	node_ptr first_cell;
	assert(is_empty(S));
	first_cell = S->next;
	S->next = first_cell->next;
	free(first_cell);
}

element_type top(STACK S)
{
	assert(is_empty(S));
	return S->next->element;
}