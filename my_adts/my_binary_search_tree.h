#ifndef _MY_BINARY_SEARCH_TREE_H_
#define _MY_BINARY_SEARCH_TREE_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tree_node *tree_ptr;
typedef int element_type;
struct tree_node
{
	element_type element;
	tree_ptr left;
	tree_ptr right;
	
	int height;
	int depth;
}
typedef tree_ptr SEARCH_TREE;

void print_tree(SEARCH_TREE T);
void print_tree_level_order(SEARCH_TREE T);
int label_height(SEARCH_TREE T);
void label_depth(SEARCH_TREE T);
void make_null(SEARCH_TREE T);
tree_ptr find(element_type x, SEARCH_TREE T);
tree_ptr find_min(SEARCH_TREE T);
tree_ptr find_max(SEARCH_TREE T);
tree_ptr insert(element_type x, SEARCH_TREE T);
tree_ptr delete_element(element_type, x, SEARCH_TREE T);

#ifdef __cplusplus
}
#endif

#endif //_MY_BINARY_SEARCH_TREE_H_