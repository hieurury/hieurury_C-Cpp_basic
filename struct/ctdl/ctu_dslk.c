#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/**
 * TODO: khởi tạo danh sách liên kết
 * danh sách liên kết là một kiểu dữ liệu dùng để lưu trữ.
 * các phần tử trong danh sách liên kết là một đối tượng.
 * các phần tử được liên kết với nhau thành một dãy bằng con trỏ.
 * 
 * @param Node - là một đối tượng trong danh sách
 * @param ElementType - là dạng dữ liệu đang làm việc
 * @param Element - là biến chứa giá trị quy định bởi @param ElementType
 * @param Next - là con trỏ quy định @param Node tiếp theo trong danh sách
 * @param Position - là vị trí của một đối tượng có dạng tự định nghĩa
 * @param List - là kiểu danh sách
 * 
 * @attention { @param Position, @param List, @param Next} - là các con trỏ kiểu @param Node
 * @author: hieurury
 */

//TODOD: khởi tạo danh sách
typedef int ElementType;
typedef struct Node Node;
struct Node {
    ElementType Element;
    Node *Next;
};
typedef Node* Position;
typedef Position List;



//TODO: khởi tạo hàm
//tạo Node sách mới
Node *createNode(ElementType x);
//khởi tạo danh sách rỗng
void MakeNull(List *L);
//kiểm tra rỗng
int EmptyList(List L);
//hàm nhập danh sách
List ReadSet();
//trả về vị trí đầu danh sách;
Position FirstList(List L);
//trả về vị trí cuối danh sách;
Position EndList(List L);
//trả về giá trị tại vị trí p (phần tử sau p)
ElementType Retrieve(Position p, List L);
//trả về vị trí tiếp theo
Position Next(Position p, List L);
//trả về vi trí trước đó
Position Previous(Position p, List L);
//xoá phần tử ở vị trí p (phần tử sau p)
void DeleteList(Position p, List *L);
//thêm phần tử vào vị trí p
void InsertList(Position p, ElementType x, List *L);
//trả vè vị trí đầu tiên của x
Position Locate(ElementType x, List L);
//in danh sách
void PrintList(List L);
//đếm số lượng x có trong danh sách
int Count(ElementType x, List L);
//chuẩn hoá danh sách
void Normalize(List *L);
//sắp xếp tăng dần
void Sort(List *L);
//tính giá trị trung bình của các phần tử
float GetAvg(List L);
//kiểm tra x có trong danh sách không
int Member(ElementType x, List L);
//lọc ra phần tử riêng biệt của 2 danh sách
List Difference(List L1, List L2);


//=============================================
int main() {
    List L;
    MakeNull(&L);
    for(int i = 1; i <= 5; i++) {
        InsertList(EndList(L), i, &L);
    }
    PrintList(L);
    Position t = Locate(4, L);
    Position e = Next(t, L);
    Position f = Previous(t, L);
    printf("%d\n", Retrieve(t, L));
    printf("%d\n", Retrieve(e, L));
    printf("%d\n", Retrieve(f, L));
}
//=============================================

//TODO: xây dựng hàm
// hàm tạo Node mới
Node *createNode(ElementType x) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Element = x;
    newNode->Next = NULL;
}

//tạo rỗng
void MakeNull(List *L) {
    (*L) = (Node*)malloc(sizeof(Node));
    (*L)->Next = NULL;
}

//kiểm tra rỗng
int EmptyList(List L) {
    return (L->Next == NULL);
}
//hàm nhập danh sách
List ReadSet() {
    List newList;
    MakeNull(&newList);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        ElementType x;
        scanf("%d", &x);
        if(!Member(x, newList)) addFirst(x, &newList);
    }
    return newList;
}
//trả về vị trí đầu tiên của danh sách (header)
Position FirstList(List L) {
    return L;
}
//trả về vị trí cuối
Position EndList(List L) {
    Position t = FirstList(L);
    while(t->Next != NULL) {
        t = t->Next;
    }
    return t;
}
//trả về giá trị của ô tiếp theo ở vị trí p(p->Next->Element)
ElementType Retrieve(Position p, List L) {
    if(p->Next != NULL)
        return p->Next->Element;
}

//Trả về vị trí tiếp theo
Position Next(Position p, List L) {
    if(p->Next != NULL) {
        return p->Next;
    }
}
//trả về vị trí trước đó
Position Previous(Position p, List L) {
    Position i = FirstList(L);
    while(i->Next != NULL) {
        if(i->Next->Next->Element == Retrieve(p, L)) return i;
        i = Next(i, L);
    }
    return EndList(L);
}

//xoá phần tử ở vị trí p trong danh sách (p->Next)
void DeleteList(Position p, List *L) {
    /**
     * ! chú ý vị trí cần xoá là sau vị trí ô p (p->Next)
     * gán p->Next thành địa chỉ ô tiếp theo p->Next->Next
     * thực hiện giải phóng bộ nhớ
     */

    //kiểm tra danh sách rỗng
    if(p->Next == NULL) return;
    //nếu danh sách không rỗng thì tiếng hành xử lí logic
    Position temp = p->Next;
    p->Next = temp->Next;
    free(temp);
    return;

    //*hoặc có thể làm như sau:
    Position t = p->Next;
    p->Next = p->Next->Next;
    free(t);
    return;
}

//thêm phần tử x ở vị trí p
void InsertList(Position p, ElementType x, List *L) {

    //Kiểm trả vị trí hợp lệ hay không
    if(p == NULL) {
        printf("Position invalid!\n");
        return;
    }
    Position newNode = createNode(x);
    newNode->Next = p->Next;
    p->Next = newNode;
    return;
}

//in danh sách
void PrintList(List L) {
    //kiểm tra danh sách rỗng
    if(EmptyList(L)) {
        printf("List of NULL!\n");
        return;
    }
    Position t = FirstList(L);
    while(t->Next != NULL) {
        printf("%d ", Retrieve(t, L));
        t = t->Next;
    }
    printf("\n");
    return;
}
//trả về vịt trí xuất hiện đầu tiên của x trong L
Position Locate(ElementType x, List L) {
    Position t = FirstList(L);
    while(t->Next != NULL) {
        if(Retrieve(t, L) == x) return t;
        t = t->Next;
    }
}
//đếm số lượng phần tử x
int Count(ElementType x, List L) {
    int count = 0;
    Position i = FirstList(L);
    while(i->Next != NULL) {
        if(Retrieve(i, L) == x) count++;
        i = i->Next;
    }
    return count;
}
//chuẩn hoá danh sách
void Normalize(List *L) {
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
//?cần chỉnh sửa lại cho phù hợp
//sắp xếp tăng dần
void Sort(List *L) {
    Position p = *L;
    while(p->Next != NULL) {
        Position temp = p->Next;
        while(temp->Next != NULL) {
            if(p->Next->Element > temp->Next->Element) {
                ElementType tmp = temp->Next->Element;
                temp->Next->Element = p->Next->Element;
                p->Next->Element = tmp;
            }
            temp = temp->Next;
        }
        p = p->Next;
    }
}
//tính giá trị trung bình của các phần tử
float GetAvg(List L) {
    if(L->Next == NULL) return -10000.0f;
    float avg = 0;
    int count = 0;
    Position i = L;
    while(i->Next != NULL) {
        avg += i->Next->Element;
        count++;
        i = i->Next;
    }
    return avg/count;
}
//kiểm tra x có trong L không
int Member(ElementType x, List L) {
    Position i = L;
    while(i->Next != NULL) {
        if(i->Next->Element == x) return 1;
        i = i->Next;
    }
    return 0;
}
//hàm chọn ra phần tử riêng của 2 danh sách
List Difference(List L1, List L2) {
    List newList;
    MakeNull(&newList);
    Position i = L1;
    while(i->Next != NULL) {
        if(!member(i->Next->Element, L2)) append(i->Next->Element, &newList);
        i = i->Next;
    }
    return newList;
}
