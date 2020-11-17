#ifndef _MY_LIST_CURSOR_H_
#define _MY_LIST_CURSOR_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int node_ptr; 
typedef unsigned int element_type;
struct node { element_type element; node_ptr next; }; 
typedef node_ptr LIST; 
typedef node_ptr position;


#ifdef __cplusplus
}
#endif

#endif //_MY_LIST_CURSOR_H_