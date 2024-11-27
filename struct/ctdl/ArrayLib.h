#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define maxLength 100
typedef int Position;
typedef int elementType;
typedef struct List List;
struct List
{
    elementType Elements[maxLength];
    Position last;
};

void MakeNull(List *list) {
    list->last = 0;
}
Position FirstList(List list) {
    return 1;
}
Position EndList(List list) {
    return list.last + 1;
}
int EmptyList(List list) {
    return list.last == 0;
}
int FullList(List list) {
    return list.last == maxLength;
}
Position Next(Position i, List list) {
    return i + 1;
}
Position Revious(Position i, List list) {
    return i - 1;
}
elementType Retrive(Position i, List list) {
    if(EmptyList(list)) return list.last + 1;
    return list.Elements[i - 1];
}
Position Locate(elementType element, List list) {
    Position index = FirstList(list);
    while(index != EndList(list)) {
        if(Retrive(index, list) == element) return index;
        index = Next(index, list);
    }
    return EndList(list);
}
void PrintList(List list) {
    Position index = FirstList(list);
    while(index != EndList(list)) {
        printf("%d ",Retrive(index, list));
        index = Next(index, list);
    }
    printf("\nda in xong\n");
}
void InsertList(Position index, elementType element, List *list) {
    if(FullList(*list)) {
        printf("danh sach day!\n");
        return;
    }
    if(index < FirstList(*list) || index > EndList(*list)) {
        printf("vi tri khong phu hop!\n");
        return;
    }
    for(int i = list->last; i >= index; i--) {
        printf("%d\n", i);
        list->Elements[i + 1] = list->Elements[i];
    }
    list->last++;
    list->Elements[index-1] = element;
}
void ReadList(List *list) {
    printf("so phan tu can them: ");
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        int tmp;
        printf("phan tu thu %d: ", i+1);
        scanf("%d", &tmp);
        getchar();
        InsertList(EndList(*list), tmp, list);
    }
    
}

int CountElement(elementType element, List list) {
    int count = 0;
    Position index = FirstList(list);

    while (index != EndList(list))
    {
        if(Retrive(index, list) == element) count++;
        index = Next(index, list);
    }
    return count;
    
}