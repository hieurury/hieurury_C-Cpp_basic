#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//TODO: Danh sách đặc
#define maxLength 100
typedef struct List List; // Kiểu dữ liệu
typedef int ElementType; // kiểu phần tử
typedef int Position; // kiểu vị trí
struct List {
    ElementType Elements[maxLength];
    Position Last;
};


//TODO: khai báo hàm
void MakeNull(List *L); //tạo danh sách rỗng
int EmptyList(List L); //kiểm tra rỗng
Position FirstList(List L); //trả về vị trí đầu tiên
Position EndList(List L); //trả về vị trí cuối cùng;
ElementType Retrieve(Position p, List L); //trả về giá trị phần tử ở p
Position Next(Position p, List L); //trả về vị trí tiếp theo của p
Position Previous(Position p, List L); //trả về vị trí trước p
void InsertList(Position p, ElementType x, List *L); //thêm phần tử x vào vị trí p
void DeleteList(Position p, List *L); //xoá phần tử ở vị trí p
Position Locate(ElementType x, List L); //vị trí xuất hiện đầu tiên của x
void sort(List *L); //sắp xếp danh sách;
void PrintList(List L); //in danh sách L


int main() {
    List L;
    MakeNull(&L);
    for (int i = 0; i <= 5; i++)
    {
        InsertList(EndList(L), i, &L);
    }
    // Position n = Locate(3, L);
    // DeleteList(n, &L);
    PrintList(L);
    
    
}

//TODO: khởi tạo hàm
void MakeNull(List *L) {
    L->Last = 0;
}
int EmptyList(List L) {
    return L.Last == 0;
}
Position FirstList(List L) {
    return 1;
}
Position EndList(List L) {
    return L.Last + 1;
}
ElementType Retrieve(Position p, List L) {
    return L.Elements[p-1];
}
Position Next(Position p, List L) {
    return p + 1;
}
Position Previous(Position p, List L) {
    return p - 1;
}
void InsertList(Position p, ElementType x, List *L) {
    if(p < FirstList(*L) || p > EndList(*L)) {
        printf("Position invalid\n");
        return;
    }
    Position i = EndList(*L);
    while(i != p) {
        L->Elements[i] = Retrieve(Previous(i, *L), *L);
        i = Previous(i, *L);
    }
    L->Elements[p] = x;
    L->Last++;
}
void DeleteList(Position p, List *L) {
    if(EmptyList(*L)) {
        printf("List of NULL\n");
        return;
    }
    Position i = p;
    while(i != EndList(*L)) {
        L->Elements[i] = Retrieve(Next(i, *L), *L);
        i = Next(i, *L);
    }
    L->Last--;
}
Position Locate(ElementType x, List L) {
    Position i = FirstList(L);
    while(i != EndList(L)) {
        if(Retrieve(i, L) == x) return i;
        i = Next(i, L);
    }
    return EndList(L);
}
void PrintList(List L) {
    if(EmptyList(L)) {
        printf("List of NULL\n");
        return;
    }
    Position i = FirstList(L);
    while(i != EndList(L)) {
        printf("%d ", Retrieve(i, L));
        i = Next(i, L);
    }
    printf("\n");
}

// sắp xếp danh sách tăng dần
void sort(List *L) {
    for(int i = 0; i < L->Last; i++) {
        for(int j = i + 1; j < L->Last; j++) {
            if(L->Elements[i] > L->Elements[j]) {
                ElementType t = L->Elements[i];
                L->Elements[i] = L->Elements[j];
                L->Elements[j] = t;
            }
        }
    }
}
void insertTrue(ElementType x, List *L) {
    if(x <= Retrieve(FirstList(*L), *L)) {
        InsertList(FirstList(*L), x, L);
        return;
    }
    if(x >= Retrieve(EndList(*L), *L)) {
        InsertList(EndList(*L), x, L);
        return;
    }

    for(int i = 1; i <= L->Last; i++) {
        if(Retrieve(i, *L) >= x) {
            InsertList(i, x, L);
        }
        return;
    }
}