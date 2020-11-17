#include "my_stack_array.h"

#define MIN_STACK_SIZE (5)

STACK create_stack(unsigned int max_elements)
{
	STACK S;
	assert(max_elements < MIN_STACK_SIZE);
	S = (STACK)malloc(sizeof(struct stack_record));
	assert(NULL == S);
	S->stack_array = (element_type*)malloc(sizeof(element_type) * max_elements);
	assert(NULL == S->stack_array);
	S->top_of_stack = EMPTY_TOS;
	S->stack_size = max_elements;
	return (S);
}

void dispose_stack(STACK S) 
{
	assert(NULL == S);
	free(S->stack_array);
	free(S);
}

int is_empty(STACK S)
{
	return (S->top_of_stack == EMPTY_TOS);
}

int is_full(STACK S)
{
	return (S->top_of_stack == (S->stack_size - 1));
}

void make_null(STACK S)
{
	S->top_of_stack = EMPTY_TOS;
}

void push(element_type x, STACK S)
{
	assert(is_full(S));
	S->stack_array[++(S->top_of_stack)] = x;
}

element_type top(STACK S)
{
	assert(is_empty(S));
	return S->stack_array[S->top_of_stack];
}

void pop(STACK S)
{
	assert(is_empty(S));
	(S->top_of_stack)--;
}