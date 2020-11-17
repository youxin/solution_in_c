#ifndef _MY_STACK_ARRAY_H_
#define _MY_STACK_ARRAY_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef int element_type;
	struct stack_record {
		unsigned int stack_size;
		int top_of_stack;
		element_type* stack_array;
	};

	typedef struct stack_record* STACK;

#define EMPTY_TOS (-1)



#ifdef __cplusplus
}
#endif

#endif //_MY_STACK_ARRAY_H_