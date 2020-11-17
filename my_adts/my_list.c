#include "my_list.h"

struct Node
{
	ElementType Element;
	Position Next;
};

//O(1)
int IsEmpty(List L)
{
	return L->Next == NULL;
}

//O(1)
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}

//O(N)
Position Find(ElementType X, List L)
{
	Position P;
	
	P = First(L);
	while (P != NULL && P->Element != X)
	{
		P = P->Next;
	}
	return P;
}

//O(N)
//return header if list is empty
//reutrn header if the element hit first node
//return node previous to the element node if the element node is at the second to the last one
//return last node if element not found
Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = Header(L);
	while (P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}

	return P;
}

//O(1)
void Delete(ElementType X, List L)
{
	Position P, TmpCell; 

	P = FindPrevious(X, L);

	if (!IsLast(P, L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}

//O(1)
void Insert(ElementType X, List L, Position P)
{
	PtrToNode TmpCell;
	
	TmpCell = (PtrToNode)malloc(sizeof(struct Node));
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

//O(1)
Position Header(List L)
{
	return L;
}

//O(1)
Position First(List L)
{
	return L->Next;
}

//O(N)
List MakeEmpty(List L)
{
	Position P = L->Next;
	Position TmpCell;

	while (P != NULL)
	{
		TmpCell = P->Next;
		free(P);
		P = TmpCell;
	}
	L->Next = NULL;
	return L;
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

void DeleteList(List L)
{
	MakeEmpty(L);
	free(L);
}

Position Advance(Position P)
{
	return P->Next;
}
