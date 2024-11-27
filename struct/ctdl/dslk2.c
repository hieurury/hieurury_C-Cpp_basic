#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef Node* Position;
typedef Position List;
typedef int ElementType;
struct Node {
  ElementType Element;
  Position Next;
};
void makenullList(List *L) {
    (*L) = (Node*)malloc(sizeof(Node));
    (*L)->Next = NULL;
}
void append(ElementType x, List *L) {
    Position newNode;
    makenullList(&newNode);
    newNode->Next = (*L)->Next;
    (*L)->Next = newNode;
    newNode->Element = x;
    
}
Position firstList(List L) {
    return L;
}
void insertList(Position p, ElementType x, List *L) {
    Position newNode;
    makenullList(&newNode);
    newNode->Next = p->Next;
    p->Next = newNode;
    newNode->Element = x;
}
int member(ElementType x, List L) {
    Position i = L;
    while(i->Next != NULL) {
        if(i->Next->Element == x) return 1;
        i = i->Next;
    }
    return 0;
}
List same(List L1, List L2) {
    List newList;
    makenullList(&newList);
    Position i = L1;
    while(i->Next != NULL) {
        if(member(i->Next->Element, L2)) append(i->Next->Element, &newList);
        i = i->Next;
    }
    return newList;
}
void printList(List L) {
    Position i = L;
    while(i->Next != NULL) {
        printf("%d ", i->Next->Element);
        i = i->Next;
    }
    printf("\n");
}
List readList() {
    List newList;
    makenullList(&newList);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(!member(x, newList)) append(x, &newList);
    }
    return newList;
}

int main() {
    List L1, L2;
    makenullList(&L1);
    L1 = readList();
    printList(L1);
    makenullList(&L2);
    readList(&L2);
    printList(L2);
    List L;
    makenullList(&L);
    L = same(L1, L2);
    printList(L);
    
    
}