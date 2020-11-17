#include "my_binary_search_tree.h"
#include "my_queue_list.h"

/*
* average O(logN), but after N*N insert/delete operation, tree become left incline
*/

//O(N)
void print_tree(SEARCH_TREE T)
{
	if (T != NULL)
	{
		print_tree(T->left);
		printf("%d ", T->element);
		print_tree(T->right);
	}
}

void visit(tree_ptr node)
{
	printf("%d", node->element);
}

//O(N)
void visit_tree_level_order(SEARCH_TREE T)
{
	tree_ptr tmp_cell;
	QUEUE queue;
	queue = create_queue();	
	enqueue(queue, T);
	while (!is_empty(queue))
	{
		tmp_cell = dequeue(queue);
		visit(tmp_cell);
		if (tmp_cell->left != NULL) enqueue(queue, tmp_cell->left);
		if (tmp_cell->right != NULL) enqueue(queue, tmp_cell->right);
	}	
	delete_queue(queue);
}

//O(N)
int label_height(SEARCH_TREE T)
{
	int iLeft, iRight;
	if (T == NULL) 
	{
		return -1;
	}
	else 
	{
		iLeft = height(T->left);
		iRight = height(T->right);
		T->height = max(iLeft, iRight) + 1;
		return T->height;
	}
}

//O(N)
void label_depth_internal(SEARCH_TREE T, SEARCH_TREE parent)
{
	if (NULL == parent)
	{
		T->depth = 0;
	}
	else
	{
		T->depth = parent->depth + 1;
		if (T->left != NULL)
		{
			label_depth_internal(T->left, T);
		}
		if (T->right != NULL) 
		{
			label_depth_internal(T->right, T);
		}
	}		
}

void label_depth(SEARCH_TREE T)
{
	if (T != NULL)
	{
		label_depth_internal(T, NULL);
	}
}

//O(N)
void delete_tree(SEARCH_TREE T)
{
	if (T->left != NULL) delete_tree(T->left);
	if (T->left != NULL) delete_tree(T->right);
	free(T);
}

void make_null(SEARCH_TREE T)
{
	if (NULL != T) delete_tree(T);
}

//O(logN)
tree_ptr find(element_type x, SEARCH_TREE T)
{
	if (NULL == T) return NULL;
	else if (x == T->element) return T;
	else if (x < T->element) return find(x, T->left);
	else (x > T->element) return find(x, T->right);
}

//O(logN)
tree_ptr find_min_internal(SEARCH_TREE T)
{
	if (NULL == T->left) return T;
	else return find_min_internal(T->left);
}

//O(logN)
tree_ptr find_min(SEARCH_TREE T)
{
	if (NULL == T) return NULL;
	else return find_min_internal(T);
}

//O(logN)
tree_ptr find_max(SEARCH_TREE T)
{
	if (T == NULL) return NULL;
	while (T->right != NULL) T = T->right;
	return T;
}

//O(logN)
tree_ptr insert(element_type x, SEARCH_TREE T)
{
	if (NULL == T)
	{
		T = (tree_ptr)malloc(sizeof(struct tree_node));
		T-element = x;
		T->left = NULL:
		T-right = NULL;
	}
	else if (x < T->element)
	{
		T->left = insert(x, T->left);
	}
	else if (x > T->element)
	{
		T->right = insert(x, T->right);
	}
	else
	{
		//x is already in the tree, do nothing
	}
	return T;
}

//caller to check if T is NULL
//O(logN)
tree_ptr delete_min(SEARCH_TREE T, element_type* element)
{
	if (T->left == NULL)
	{
		*element = T->element;
		free(T);
		return T->right;
	}
	else
	{
		T->left =  delete_min(T->left, element);
	}
}

//O(logN)
tree_ptr delete_element(element_type x, SEARCH_TREE T)
{
	tree_ptr tmp_cell;
	element_type tmp_element;
	if (NULL == T) 
	{
		//element not found
	}
	else if (x < T->element)
	{
		T->left = delete_element(x, T->left);
	}
	else if (x > T->element)
	{
		T->right = delete_element(x, T->right);
	}
	else
	{
		//element found
		if (T->left == NULL && T->right == NULL)
		{
			//leaf
			free(T);
			T = NULL;
		}
		else if (T->left != NULL && T->right != NULL)
		{
			//have two child
			T->right = delete_min(T->right, &tmp_element);
			T->element = tmp_element;
		}
		else
		{
			//have one child
			tmp_cell = (NULL != T->left)?T->left:T->right;
			free(T);
			T = tmp_cell;
		}
	}
	return T;
}

















