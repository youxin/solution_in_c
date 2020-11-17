#ifndef _MY_STACK_H_
#define _MY_STACK_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef int element_type;
	typedef struct node* node_ptr;

	struct node {
		element_type element;
		node_ptr next;
	};

	typedef node_ptr STACK;




#ifdef __cplusplus
}
#endif

#endif //_MY_STACK_H_