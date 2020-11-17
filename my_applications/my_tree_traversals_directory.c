#include "my_tree_traversals_directory.h"


void list_directory(tree_ptr D)
{
	list_dir(D, 0);
}

int is_folder(tree_ptr D)
{
	return (NULL != D && D->element.is_folder);
}

int is_file(tree_ptr D)
{
}

void print_name(unsigned int depth, D)
{
	while (depth--) printf(" ");
	printf("%s", D->element.name);
}

//O(N)
//preorder
void list_dir(tree_ptr D, unsigned int depth)
{
	tree_ptr child;
	print_name(depth, D);
	if (is_folder(D))
	{
		child = D->first_child;
		while(child)
		{
			list_dir(child, depth+1);
			child = child->next_sibling;
		}			
	}
}

//O(N)
//postorder
unsigned int size_directory(tree_ptr D)
{
	tree_ptr child;
	unsigned int total_size;
	total_size = 0;
	if (is_folder(D))
	{
		child = D->first_child;
		while (child)
		{
			total_size += D->element.size;
			child = child->next_sibling;
		}
	}
	return total_size;
}

