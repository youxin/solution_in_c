#ifndef _MY_LIST_H_
#define _MY_LIST_H_

#include "my_common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef int ElementType;
struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);

int IsEmpty(List L);

int IsLast(Position P, List L);

Position Find(ElementType X, List L);

void Delete(ElementType X, List L);

Position FindPrevious(ElementType X, List L);

void Insert(ElementType X, List L, Position P);

void DeleteList(List L);

Position Header(List L);

Position First(List L);

Position Advance(Position P);

ElementType Retrieve(Position P);


#ifdef __cplusplus
}
#endif

#endif //_MY_LIST_H_