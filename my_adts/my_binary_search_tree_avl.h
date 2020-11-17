#ifndef _MY_BINARY_SEARCH_TREE_AVL_H_
#define _MY_BINARY_SEARCH_TREE_AVL_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct avl_node *avl_ptr;
typedef int element_type;
struct avl_node
{
	element_type element;
	avl_ptr left;
	avl_ptr right;
	int height;
}
typedef avl_ptr SEARCH_TREE;

void make_null(SEARCH_TREE T);
avl_ptr find(element_type x, SEARCH_TREE T);
avl_ptr find_min(SEARCH_TREE T);
avl_ptr find_max(SEARCH_TREE T);
avl_ptr insert(element_type x, SEARCH_TREE T);
avl_ptr delete_element(element_type, x, SEARCH_TREE T);

#ifdef __cplusplus
}
#endif

#endif //_MY_BINARY_SEARCH_TREE_AVL_H_