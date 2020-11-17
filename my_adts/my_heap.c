#include "my_heap.h"

const int MIN_DATA = -1;

struct heap_struct
{
	unsigned int max_heap_size;
	unsigned int size;
	element_type *elements;
};

PRIORITY_QUEUE create_pq(unsigned int max_elements)
{
	PRIORITY_QUEUE H;
	H = (PRIORITY_QUEUE)malloc(sizeof(struct heap_struct));
	H->elements = (element_type*)malloc((max_elements + 1) * sizeof(element_type));
	H->size = 0;
	H->max_heap_size = max_elements;
	H->elements[0] = MIN_DATA;
}

int is_empty(PRIORITY_QUEUE H)
{
	return (H->size == 0);
}

int is_full(PRIORITY_QUEUE H)
{
	return (H->size == H->max_heap_size);
}

void percolate_up(int position, PRIORITY_QUEUE H)
{
	int i;
	i = position;
	while (H->elements[i/2] > x)
	{
		H->elements[i] = H->elements[i/2];
		i = i/2;
	}
	H->elements[i] = x;
}

//each insertion: average O(1) ~2.607, worst O(logN)
//insertion of N elements: average O(N), worst O(N logN)
void insert(element_type x, PRIORITY_QUEUE H)
{
	unsigned int i;
	if (is_full(H))
	{
		//error
	}
	else
	{
		i = ++(H->size);
		percolate_up(i, H);
	}
}

void percolate_down(int position, PRIORITY_QUEUE H)
{
	int i, child;
	element_type key;
	i = position;
	key = H->elements[i];
	while (i*2 <= H->size)
	{
		//node i have child
		child = i*2;
		if (child < H->size)
		{
			if (H->elements[child + 1] < H->elements[child])
			{
				//find the smaller child
				child++;
			}
		}
		if (H->elements[i] > H->elements[child])
		{
			//node i bigger than child
			//'shift' value of child node to this(i) node
			H->elements[i] = H->elements[child];
			i = child;
		}
		else
		{
			//node i not bigger child
			break;
		}
	}
	H->elements[i] = key;
}

//average O(logN)
//worst O(logN)
element_type delete_min(PRIORITY_QUEUE H)
{
	int i; 
	element_type min_element;
	
	if (is_empty(H))
	{
		//error
		return H->element_type[0];
	}
	
	min_element = H->elements[1];
	H->elements[1] = H->elements[H->size--];
	percolate_down(1, H);
	return min_element;
}

void decrease_key(int position, int steps, PRIORITY_QUEUE H)
{
	H->elements[position] -= steps;
	percolate_up(position, H);
}

void increase_key(int position, int steps, PRIORITY_QUEUE H)
{
	H->elements[position] += steps;
	percolate_down(position, H);	
}

element_type delete_element(int position, PRIORITY_QUEUE H)
{
	decrease_key(position, H->elements[position] + 1, H);
	delete_min(H);
}

//O(N) average, O(N LogN) worst
//for a perfect tree with h height, nodes number: {2^(h+1) - 1}, the sum of the heights is {2^(h+1) - 1 - (h+1)}
void build_queue(PRIORITY_QUEUE H)
{
	int i;
	i = H->size/2;
	while (i > 0)
	{
		percolate_up(i--);
	}
}

PRIORITY_QUEUE create_pq2(element_type* elements, int size, unsigned int max_elements)
{
	PRIORITY_QUEUE H;
	H = (PRIORITY_QUEUE)malloc(sizeof(struct heap_struct));
	H->elements = (element_type*)malloc((max_elements + 1) * sizeof(element_type));
	H->max_heap_size = max_elements;
	H->elements[0] = MIN_DATA;		
	memcpy(&(H->elements[1]), elements, size*sizeof(element_type));
	H->size = size;
	build_queue(H);
}











