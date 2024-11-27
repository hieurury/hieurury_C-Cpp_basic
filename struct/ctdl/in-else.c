#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//*các phép toán trên danh sách đặc
#define maxLength 100
typedef int ElementType;
typedef int Position;
typedef struct List List;
struct List {
    ElementType Elements[maxLength];
    Position Last;
};



// hàm sắp xếp;
void sort(List *L) {
    int i = 1;
    while(i < L->Last) {
        int j = i + 1;
        while(j <= L->Last) {
            
            if(L->Elements[i-1] > L->Elements[j-1]) {
                int tmp = L->Elements[i-1];
                L->Elements[i-1] = L->Elements[j-1];
                L->Elements[j-1] = tmp;
            }
            j++;
        }
        i++;
    }
}

// gọp 2 danh sách
void unionSet(List L1, List L2, List *L) {
    makenullList(&*L);
    //thêm danh sách đầu tiên vào;
    int i = 1;
    while(i <= L1.Last) {
        insertSet(L1.Elements[i-1], &*L);
        i++;
    }
    //gan lai i cho lan them tiep theo
    i = 1;
    while(i <= L2.Last) {
        if(!member(L2.Elements[i-1], *L)) {
            insertSet(L2.Elements[i-1], &*L);
        }
        i++;
    }
}

// hàm chuẩn hoá danh sách
void normalize(List *L) {
    int i = 1;
    while(i != L->Last + 1) {
        int j = i + 1;
        while(j != L->Last + 1) {
            if(L->Elements[i-1] == L->Elements[j-1]) {
                deleteList(j, &*L);
            } else j++;
        }
        i++;
    }
}

// hàm chọn phần tử trùng nhau
int checkList(int x, List L) {
    if(emptyList(L)) return 1;
    int i = 1;
    while(i != endList(L)) {
        if(retrieve(i, L) == x) return 0;
        i++;
    }
    return 1;
}

void findSame(List L1, List L2, List *L) {
    int i = 1;
    while(i != endList(L1)) {
        int j = 1;
        while(j != endList(L2)) {
            if(retrieve(i, L1) == retrieve(j, L2)) {
                insertList(retrieve(i, L1), endList(*L), L);
            }
            j++;
        }
        i++;
    }
    
}


//các hàm tách số chẳn và kiểm tra số lẻ

void soLe(List L) {
    int i = first(L);
    while(i != endList(L)) {
        if(retrieve(i, L) % 2 != 0) printf("%d ", retrieve(i, L));
        i++;
    }
}
List getSoChan(List L) {
    List newList;
    makenullList(&newList);
    int i = first(L);
    while(i != endList(L)) {
        if(retrieve(i, L) % 2 == 0) 
            insertList(retrieve(i, L), endList(newList), &newList);
        i++;
    }
    return newList;
}

//đọc và in
void readList(List *L) {
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insertList(x, endList(*L), L);
    }
}
void printList(List L) {
    int i = first(L);
    while(i != endList(L)) {
        printf("%d ", retrieve(i, L));
        i++;
    }
}

//hàm xoá pt trùng đầu tiên
void firstDel(int x, List *L) {
    int i = first(*L);
    while(i != endList(*L)) {
        if(retrieve(i, *L) == x) {
            deleteList(i, L);
            return;
        }
        i++;
    }
}

//xoá phần tử xuất hiện cuối cùng
void delLast(int x, List *L) {
    int i = L->Last;
    while(i >= first(*L)) {
        if(retrieve(i, *L) == x) {
            deleteList(i, L);
            return;
        }
        i--;
    }
    printf("Khong co phan tu x\n");
    
}


//* đến phần danh sách sinh viên
#define maxSV 40
struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};
struct DanhSach {
    SinhVien A[maxSV];
    int n;
};
typedef struct SinhVien SinhVien;
typedef struct DanhSach DanhSach;

//chép một đối tượng không đạt vào danh sách
DanhSach chepKhongDat(DanhSach L) {
    DanhSach newL;
    dsRong(&newL);
    for(int i = 0; i < L.n; i++) {
        float sum = L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2;
        if(sum < 4) chenCuoi(L.A[i], &newL);
    }
    return newL;
}
//xoá sinh viên có mã số x tại vị trí được tìm thấy
void xoaSinhVien(char *x, DanhSach *L) {
    int num = tim(x, *L);
    xoaTai(num, L);
}

//nhập vào danh sách
#include <stdlib.h>
#include <string.h>
DanhSach nhap() {
    DanhSach newL;
    newL = dsRong();
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++) {
        struct SinhVien newSV;
        fgets(newSV.MSSV, sizeof(newSV.MSSV), stdin);
        newSV.MSSV[strcspn(newSV.MSSV, "\n")] = 0;
        fgets(newSV.HoTen, sizeof(newSV.HoTen), stdin);
        newSV.HoTen[strcspn(newSV.HoTen, "\n")] = 0;
        scanf("%f%f%f", &newSV.DiemLT, &newSV.DiemTH1, &newSV.DiemTH2);
        getchar();
        int find = tim(newSV.MSSV, newL);
        
        if(!(find < i)) chenCuoi(newSV, &newL);
        
    }
    return newL;
}

//kiểm tra sinh viên có đạt điều kiện không
void checkSV(int mark, DanhSach L) {
    printf("Sinh vien DAT\n");
    for(int i = 0; i < L.n; i++) {
        float avg = L.A[i].LT + L.A[i].TH1 + L.A[i].TH2;
        if(avg >= mark) printf("%s - %s - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].LT, L.A[i].TH1, L.A[i].TH2);
    }
}




// *DANH SÁCH LIÊN KẾT

//*xoá tất cả phần tử x trong danh sách
void removeAll(int x, List *L) {
    Position p = locate(x, *L);
    while(p->Next != NULL) {
        p = locate(x, *L);
        deleteList(p, L);
    }
}
//*sắp xếp
void sort(List *L) {
    Position p = *L;
    while(p->Next != NULL) {
        Position temp = p;
        while(temp->Next != NULL) {
            if(p->Next->Element > temp->Next->Element) {
                ElementType tmp = temp->Next->Element;;
                temp->Next->Element = p->Next->Element;
                p->Next->Element = tmp;
            }
            temp = temp->Next;
        }
        p = p->Next;
    }
}

//chuẩn hoá danh sách
void normalize(List *L) {
    Position i = *L;
    while(i->Next != NULL) {
        Position j = i->Next;
        while(j->Next != NULL) {
            if(j->Next->Element == i->Next->Element) {
                deleteList(j, L);
            } else j = j->Next;
        }
        i = i->Next;
    }
}
