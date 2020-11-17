#ifndef _MY_TREE_TRAVERSALS_DIRECTORY_H_
#define _MY_TREE_TRAVERSALS_DIRECTORY_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tree_node *tree_ptr;

typedef struct
{
	unsigned char[255] name;
	unsigned char is_folder;
	unsigned int size;
}element_type;

struct tree_node
{
	element_type element;
	tree_ptr first_child;
	tree_ptr next_sibling;
}

void list_directory(tree_ptr D);

unsigned int size_directory(tree_ptr D);


#ifdef __cplusplus
}
#endif

#endif //_MY_TREE_TRAVERSALS_DIRECTORY_H_