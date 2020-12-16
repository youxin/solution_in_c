#include "my_disjoint.h"

/* Disjoint
 * equivalence: reflexive, symmetric, transitive
 * equivalence class of a: consist of all elements related to a
 * to decide if a~b, only need to check whether a and b are in the same equivalence class.
 * disjoint set union/find algorithm
 * first approach:
		maintain, in an array, the name of equivalence class for each element. 
		find: O(1)
		union: O(n^2)
 * second approach:
		for any sequences of at most m finds and up to n-1 unions be a little more than O(m+n)
*/

typedef int DISJ_SET[NUM_SETS + 1];
typedef unsigned int set_type;
typedef unsigned int element_type;

void initialize(DISJ_SET S)
{
	int i;
	for (i = NUM_SETS; i > 0; i--) S[i] = 0;
}

void set_union(DISJ_SET S, set_type root1, set_type root2)
{
	S[root2] = root1;
}

//worst case M*LogN
set_type find(element_type x, DISJ_SET S)
{
	if (S[x] <= 0) return x;
	else reutrn find(S[x], S);
}


/* Smart Union Algorithms
 * union-by-size
		make the smaller tree a subtree of the larger 
		the depth of any node is never more than logN
		the running time for a find operation is O(log N)
		a sequence of m operations requires O(m) average time
 * union-by-height
		performance the same of uion-by-size
*/
void set_union(DISJ_SET S, set_type root1, set_type root2)
{
	if (S[root2] < S[root1]) 
	{
		//root2 is higher, 
		//make root2 as the parent of root1
		//root2 height no change
		S[root1] = root2;
	}
	else if (S[root2] == S[root1])
	{
		//same high
		//make root1 as parent of root2
		//root1 height plus 1
		S[root2] = root1;
		S[root1]--;		
	}
	else
	{
		//root1 is higher
		//make root1 as parent of root2
		//root1 height no change
		S[root2] = root1;
	}
}

/* Path Compression
 * x is made to point directly to the root
 * every node, on the path to the node, was made to point directly to the root, so "path compression"
 * compatible with union-by-size
 * not entirely compatible with union-by-height
*/
set_type find(element_type x, DISJ_SET S)
{
	if (S[x] <= 0)
	{
		return x;
	}
	else
	{
		return (S[x] = find(S[x], S));
	}
}



