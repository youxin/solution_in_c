#include "my_binary_search_tree_avl.h"

/*
* average O(logN), but after N*N insert/delete operation, tree become left incline
*/

//caller should check NULL
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

avl_ptr find(element_type x, SEARCH_TREE T)
{
	if (NULL == T) return NULL;
	else if (x == T->element) return T;
	else if (x < T->element) return find(x, T->left);
	else (x > T->element) return find(x, T->right);
}

avl_ptr find_min_internal(SEARCH_TREE T)
{
	if (NULL == T->left) return T;
	else return find_min_internal(T->left);
}

avl_ptr find_min(SEARCH_TREE T)
{
	if (NULL == T) return NULL;
	else return find_min_internal(T);
}

avl_ptr find_max(SEARCH_TREE T)
{
	if (T == NULL) return NULL;
	while (T->right != NULL) T = T->right;
	return T;
}

int height(avl_ptr p)
{
	if (p == NULL) return -1;
	else return p->height;
}

avl_ptr s_rotate_left(avl_ptr k2)
{
	avl_ptr k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->left), k2->height) + 1;
	return k1;
}

avl_ptr s_rotate_right(avl_ptr k2)
{
	avl_ptr k1;
	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->right), k2->height) + 1;
	return k1;
}

avl_ptr d_rotate_left(avl_ptr k3)
{
	k3->left = s_rotate_right(k3->left);
	return (s_rotate_left(k3));
}

avl_ptr d_rotate_right(avl_ptr k3)
{
	k3->right = s_rotate_left(k3->right);
	return s_rotate_right(k3);
}

avl_ptr insert_internal(element_type x, SEARCH_TREE T, avl_ptr parent)
{
	avl_ptr rotated_tree;
	if (T== NULL)
	{
		T = (SEARCH_TREE)malloc(sizeof(struct avl_node));
		T->element = x; 
		T->height = 0;
		T->left = T->right = NULL;
	}
	else if (x == T->element)
	{
		//found, no need to insert
	}
	else if (x < T->element)
	{
		//insert to the left
		T->left = insert_internal(x, T->left, T);
		if (height(T->left) - height(T->right) == 2)
		{
			//T is imbalance caused by insert a node to its left
			if (x < T->left->element) 
			{
				rotated_tree = s_rotate_left(T);
			}
			else
			{			
				rotated_tree = d_rotate_left(T);
			}
			/*
			if (parent == NULL)
			{
				//no need to update parent
			}
			if (parent->left == T)
			{
				//previously, T is left child of the parent
				parent->left = rotated_tree;
			}
			else if (parent->right == T)
			{
				//previously, T is right child of the parent
				parent->right = rotated_tree;
			}
			*/
			T = rotated_tree;
		}
		else
		{
			//T is still balance, height(T->left) - height(T-right) <= 1
			T->height = max(height(T->left), height(T->right)) + 1;
		}
	}
	else
	{
		//insert to the right
		T->right = insert_internal(x, T->right, T);
		if (height(T->right) - height(T->left) == 2)
		{
			if (x > T->right->element) 
			{
				rotated_tree = s_rotate_right(T);
			}
			else
			{
				rotated_tree = d_rotate_right(T);
			}
			T = rotated_tree;
		}
		else
		{
			T->height = max(height(T->left), height(T->right)) + 1;
		}
	}

	return T;
}

avl_ptr insert(element_type x, SEARCH_TREE T)
{
	return insert_internal(x, T, NULL);
}

//to be done
avl_ptr delete_element(element_type x, SEARCH_TREE T)
{
	if (T == NULL)
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
		
	}
	
	
	return T;
}

















