#ifndef _MY_BINARY_TREE_EXPRESSION_H_
#define _MY_BINARY_TREE_EXPRESSION_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tree_node *tree_ptr;

typedef unsigned char element_type;

struct tree_node
{
	element_type element;
	tree_ptr left;
	tree_ptr right;
}
typedef tree_ptr TREE;

void print_expression_infix(TREE T);
void print_expression_postfix(TREE T);
TREE construct_expression_tree_from_postfix(unsigned char* expression, unsigned int length);

#ifdef __cplusplus
}
#endif

#endif //_MY_BINARY_TREE_EXPRESSION_H_