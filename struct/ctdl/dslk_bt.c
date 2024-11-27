#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


typedef struct Node Node;
typedef struct Node* Position;
typedef Position List;
typedef int ElementType;
struct Node {
    ElementType Element;
    Position Next;
};
void insertList(ElementType x, Position p, List *L) {
    Position t = (Position)malloc(sizeof(struct Node));
    t->Element = x;
    t->Next = p->Next;
    p->Next = t;
}
Position endList(List L) {
    Position i = L;
    while(i->Next != NULL) {
        i = i->Next;
    }
    return i;
}
List getList() {
    List L = (Position)malloc(sizeof(struct Node));
    L->Next = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insertList(x, endList(L), &L);
    }
    return L;
}

void printList(List L) {
    Position i = L;
    while(i->Next != NULL) {
        printf("%d ", i->Next->Element);
        i = i->Next;
    }
    printf("\n");
}

void sort(List *L) {
    Position i = *L;
    while(i->Next != NULL) {
        Position j = i->Next;
        while(j->Next != NULL) {
            if(i->Next->Element < j->Next->Element) {
                int t = i->Next->Element;
                i->Next->Element = j->Next->Element;
                j->Next->Element = t;
            }
            j = j->Next;
        }
        i = i->Next;
    }
}
Position find(ElementType x, List L) {
    Position i = L;
    while(i->Next != NULL) {
        if(x > i->Next->Element) return i;
        i = i->Next;
    }
    return i;
}

List merge(List L1, List L2) {
    List L = (Position)malloc(sizeof(struct Node));
    L->Next = NULL;
    Position i = L1;
    while(i->Next != NULL) {
        insertList(i->Next->Element, endList(L), &L);
        i = i->Next;
    }
    i = L2;
    while(i->Next != NULL) {
        Position j = find(i->Next->Element, L);
        if(j->Next != NULL) insertList(i->Next->Element, j, &L);
        else insertList(i->Next->Element, endList(L), &L);
        i = i->Next;
    }
    return L;
}


int main() {
    List L1 = getList();
    printList(L1);
    sort(&L1);
    List L2 = getList();
    printList(L2);
    sort(&L2);
    List L = merge(L1, L2);
    printList(L);
}