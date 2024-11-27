#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


/**
 * *cây tìm kiếm nhị phân
 * nhãn của mỗi nút thì lớn hơn con trái và nhỏ hơn con phải
 * cây con của cây tìm kiếm nhị phân vẫn là cây tìm kiếm nhị phân
 * danh sách duyệt trung tự của cây tìm kiếm nhị phân thì tăng dần
 */

typedef int keyType;
typedef struct Node Node;
typedef struct Node* FTree;
struct Node {
    keyType Key;
    Node* Left;
    Node* Right;
};

//TODO: khởi tạo hàm
void makenullFTree(FTree *T); //tạo cây rỗng
int emptyFTree(FTree T); //kiểm tra cây rỗng
FTree leftChild(FTree N); //Node bên trái
FTree rightChild(FTree N); //Node bên phải
int isLeaf(FTree N); //Kiểm tra Node lá
int countNode(FTree T); //Đếm tất cả các nút
int countNodeLeaf(FTree T); //Đếm nút lá
int countNodeIntermedate(FTree T); //Đếm nút trung gian
int countSkipRoot(FTree T); //hỗ trợ đếm bỏ gốc cho hàm intermedate
int heightTree(FTree T); //tính chiều cao của cây
int heightNode(int x, FTree T); // tính chiều cao của Node x trên cây
FTree deleteMin(); //xoá nút x trên cây và trả về nút nhỏ nhất
// FTree createBFTree(keyType x, FTree L, FTree R); //tạo cây nhị phân
FTree searchNode(keyType x, FTree T); //tìm nút trên cây
FTree rightSibling(int x, Tree T);//anh em ruột phải
FTree getPrevious(int x, FTree T); //lấy nút trước nút x;
void addNode(keyType x, FTree *T);
void preOrder(FTree T); //Duyệt tiền tự
void inOrder(FTree T); //Duyệt trung tự
void posOrder(FTree T); //Duyệt hậu tự


//TODO: làm việc tại đây
int main() {
    //Khởi tạo cây
    FTree T;
    makenullFTree(&T);
    addNode(1, &T);
    addNode(3, &T);
    addNode(5, &T);
    addNode(2, &T);
    addNode(11, &T);
    addNode(13, &T);
    addNode(4, &T);
    addNode(7, &T);
    addNode(9, &T);
    addNode(4, &T);

    //các lệnh duyệt cây
    printf("pre order: ");
    preOrder(T); //duyệt tiền tự
    printf("\n");
    printf("in order: ");
    inOrder(T); //duyệt trung tự
    printf("\n");
    printf("pos order: ");
    posOrder(T); //duyệt hậu tự
    printf("\n");

    //đếm số nút
    int node = countNode(T);
    printf("node: %d", node);
    printf("\n");
    
    //đếm số nút
    int intermedate = countNodeIntermedate(T);
    printf("intermedate: %d", intermedate);
    printf("\n");

    //đếm nút lá
    int leaf = countNodeLeaf(T);
    printf("leaf: %d", leaf);
    printf("\n");

    //xác định chiều cao cây
    int height = FtreeHeight(T);
    printf("height: %d", height);
    printf("\n");
}


//TODO: cài đặt hàm
void makenullFTree(FTree *T) {
    *T = NULL;
}
int emptyFTree(FTree T) {
    return T == NULL;
}
FTree leftChild(FTree N) {
    if(N == NULL) return NULL;
    return N->Left;
}
FTree rightChild(FTree N) {
    if(N == NULL) return NULL;
    return N->Right;
}
int isLeaf(FTree N) {
    if(N == NULL) return 0;
    return (rightChild(N) == NULL) && (leftChild(N) == NULL);
}
int countNode(FTree T) {
    if(T == NULL) return 0;
    return 1 + countNode(leftChild(T)) + countNode(rightChild(T));
}

int countNodeLeaf(FTree T) {
    if(T == NULL) return 0;
    if(isLeaf(T)) {
        return 1;
    }
    return countNodeLeaf(leftChild(T)) + countNodeLeaf(rightChild(T));
}

int countNodeIntermedate(FTree T) {
    if(T == NULL) return 0;
    return countSkipRoot(leftChild(T)) + countSkipRoot(rightChild(T));
}
int countSkipRoot(FTree T) {
    if(T == NULL) return 0;
    if(isLeaf(T)) return 0;
    return 1 + countSkipRoot(leftChild(T)) + countSkipRoot(rightChild(T));
}

int heightTree(FTree T) {
    if(T == 0) return -1;
    int leftHeigth = heightTree(leftChild(T));
    int rightHeight = heightTree(rightChild(T));

    if(leftHeigth > rightHeight) return 1 + leftHeigth;
    return 1 + rightHeight;
}
int heightNode(int x, FTree T) {
    if(T == NULL) return -1;
    if(T->Key == x) {
        int leftHeight = heightTree(T->Left);
        int rightHeight = heightTree(T->Right);
        if(leftHeight > rightHeight) return 1 + leftHeight;
        return 1 + rightHeight;
    }
    if(x > T->Key) return heightNode(x, T->Right);
    return heightNode(x, T->Left);
}

// FTree createBFTree(keyType x, FTree L, FTree R) {
//     FTree T = (Node*)malloc(sizeof(Node));
//     T->Key = x;
//     T->Left = L;
//     T->Right = R;
//     return T;
// }
FTree searchNode(keyType x, FTree T) {
    if(T == NULL) return NULL;
    if(T->Key == x) return T;
    if(T->Key > x) return searchNode(x, leftChild(T));
    return searchNode(x, rightChild(T));
}
void addNode(keyType x, FTree *T) {
    if(*T == NULL) {
        FTree newT = (Node*)malloc(sizeof(Node));
        newT->Key = x;
        newT->Left = NULL;
        newT->Right = NULL;
        *T = newT;
        return;
    }
    if((*T)->Key == x) {
        printf("%d da ton tai roi cha oi cha, khong co them!\n", x);
        return;
    }
    if((*T)->Key > x) {
        addNode(x, &(*T)->Left);
    } else {
        addNode(x, &(*T)->Right);
    }
}
keyType deleteMin(FTree *T) {
    if(*T == NULL) return NULL;
    if((*T)->Left == NULL) {
        keyType min = (*T)->Key;
        (*T) = (*T)->Right;
        return min;
    }
    return deleteMin(&(*T)->Left);
}
void deleteNode(int x, FTree *T) {
    //nếu cây rỗng thì thôi
    if(*T == NULL) return;
    if((*T)->Key < x) {
        deleteNode(x, (*T)->Right);
        return;
    } //tịnh tiến sang phải
    if((*T)->Key > x) {
        deleteNode(x, (*T)->Left);
        return;
    } //tịnh tiến sang trái
    if((*T)->Key == x) {
        //nếu tìm thấy thì xử lí
        //nếu node lá
        if((*T)->Left == NULL && (*T)->Right == NULL) {
            *T = NULL;
            return;
        }
        if((*T)->Left == NULL) {
            *T = (*T)->Right;
            return;
        } //nếu chỉ có con phải
        if((*T)->Right == NULL) {
            *T = (*T)->Left;
            return;
        } //chỉ có con trái
        //xử lí xoá 2 con
        (*T)->Key = deleteMin(&(*T)->Right);
    }
}
FTree rightSibling(int x, FTree T) {
    if(T == NULL) return NULL;
    if(x == T->Left->Key) return T->Right;
    else return NULL;
    if(x > T->Key) return rightSibling(x, T->Right);
    return rightSibling(x, T->Left);
}
FTree getPrevious(int x, FTree T) {
    if (T == NULL) return NULL;
    FTree previous = NULL;
    while (T != NULL) {
        if (x > T->Key) {
            previous = T;
            T = T->Right;
        } else {
            T = T->Left;
        }
    }
    return previous;
}
FTree getParent(int x, FTree T) {
    if(T == NULL) return NULL;
    if(T->Key == x) return NULL;
    if(T->Left->Key == x || T->Right->Key == x) return T;
    if(x > T->Key) return getParent(x, T->Right);
    return getParent(x, T->Left);
}   
FTree getNext(int x, FTree T) {
    if (T == NULL) return NULL;
    FTree next = NULL;
    while (T != NULL) {
        if (x < T->Key) {
            next = T;
            T = T->Left;
        } else {
            T = T->Right;
        }
    }
    return next;
}
void preOrder(FTree T) {
    if(T == NULL) return;
    printf("%d ", T->Key);
    preOrder(leftChild(T));
    preOrder(rightChild(T));
}
void inOrder(FTree T) {
    if(T == NULL) return;
    inOrder(leftChild(T));
    printf("%d ", T->Key);
    inOrder(rightChild(T));
}
void posOrder(FTree T) {
    if(T == NULL) return;
    posOrder(leftChild(T));
    posOrder(rightChild(T));
    printf("%d ", T->Key);
}