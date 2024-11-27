#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

/**
 * TODO: Kiến thức cần biết
 * *Khái niệm cây
 * một cây có 1 và chỉ một nút góc
 * nút gốc là nút không có nút cha
 * nút lá là nút không có nút con
 * nút mà không phải nút gốc cũng không phải nút lá là nút trung gian
 * một nút chỉ có tối đa 1 cha
 * một nút có thể có nhiều nút con
 * *bậc của cây
 * bậc của nút: là số nút con của nút
 * bậc của cây: là số nút con nhiều nhất của một nút
 * nút lá có bậc bằng 0
 * cây bậc n được gọi là n phân
 * *lưu ý
 * nút lá có thể là nút gốc
 * nút trung gian không thể là nút lá
 * *đường đi của cây
 * cây chỉ đi từ nút cha đến cút con. không đi ngược lại
 * độ dài đường đi: là số cạnh hoặc số nút - 1
 * A được gọi là tiền bối của B khi có đường đi từ A -> B
 * *chiều cao của cây
 * chiều cao của cây là chiều cao của nút gốc
 * chiều cao của nút là độ dài đường đi từ nút đó đến nút lá xa nhất
 * chiều cao của cây chính là mức của cây
 * chiều cao của cây là độ dài nút lá xa nhất
 * *khái niệm rừng
 * từ 2 cây trở lên được gọi là rừng
 * nhãn: là giá trị lưu trữ trên cây
 * cây có giá trị: cây có nhãn
 * cây biểu thức: có nhãn là các toán tử, toán hạng
 * *họ cây
 * cây có thứ tự: đổi thứ tự -> thay đổi cây
 * cây không thứ tự: đổi thứ tự -> không làm thay đổi cây
 * nút anh em: nút có cùng cha
 * anh em ruột phải: nút nằm bên phải nút đó
 * *cây nhị phân
 * khái niệm: là cây có tối đa 2 nút con
 * các nút con được quy định là nút trái và nút phải
 * 2 cây dù có cùng thứ tự nhưng khác vị trí nút con thì cũng là 2 cây khác nhau.
 * 
 * 
 */

/**
*   TODO: khai báo dữ liệu
*   *Khai báo kiểu binary-trees
*   @param Node - một nút của cây, chứa dữ liệu và liên kết các nút con trái, phải
*   @param Data - dữ liệu trên mỗi @param Node của cây
*   @param Left - @param Right là các nút con trái phải của một @param Node
*   @attention { @param Tree } - là con trỏ kiểu @param Node
*   *cây tìm kiếm nhị phân
    

*   @author {hieurury}
*
*/
typedef struct Node Node;
typedef struct Node* Tree;
typedef int DataType; 
struct Node {
    DataType Data;
    Node *Left;
    Node *Right;
};




//TODO: khởi tạo hàm
void makenullTree(Tree *T); //tạo cây rỗng
int emptyTree(Tree T); //kiểm tra cây rỗng
Tree leftChild(Tree N); //Node bên trái
Tree rightChild(Tree N); //Node bên phải
int isLeaf(Tree N); //Kiểm tra Node lá
int countNode(Tree T); //Đếm tất cả các nút
int countNodeLeaf(Tree T); //Đếm nút lá
int countNodeIntermedate(Tree T); //Đếm nút trung gian
int countSkipRoot(Tree T); //hỗ trợ đếm bỏ gốc cho hàm intermedate
int treeHeight(Tree T); //tính chiều cao của cây
int supTreeHeight(Tree T);
Tree createBTree(DataType x, Tree L, Tree R); //tạo cây nhị phân
void preOrder(Tree T); //Duyệt tiền tự
void inOrder(Tree T); //Duyệt trung tự
void posOrder(Tree T); //Duyệt hậu tự


//TODO: làm việc tại đây
int main() {
    //Khởi tạo cây
    Tree T;
    makenullTree(&T);
    // T = createBTree(1, createBTree(2, createBTree(4, NULL, NULL), createBTree(5, NULL, createBTree(6, NULL, NULL))), createBTree(3, createBTree(7, NULL, createBTree(8, NULL, NULL)), createBTree(9, NULL, NULL)));
    T = createBTree(1, NULL, NULL);

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
    int height = treeHeight(T);
    printf("height: %d", height);
    printf("\n");
}


//TODO: cài đặt hàm
void makenullTree(Tree *T) {
    *T = NULL;
}
int emptyTree(Tree T) {
    return T == NULL;
}
Tree leftChild(Tree N) {
    if(N == NULL) return NULL;
    return N->Left;
}
Tree rightChild(Tree N) {
    if(N == NULL) return NULL;
    return N->Right;
}
int isLeaf(Tree N) {
    if(N == NULL) return 0;
    return (rightChild(N) == NULL) && (leftChild(N) == NULL);
}
int countNode(Tree T) {
    if(T == NULL) return 0;
    return 1 + countNode(leftChild(T)) + countNode(rightChild(T));
}

int countNodeLeaf(Tree T) {
    if(T == NULL) return 0;
    if(isLeaf(T)) {
        return 1;
    }
    return countNodeLeaf(leftChild(T)) + countNodeLeaf(rightChild(T));
}

int countNodeIntermedate(Tree T) {
    if(T == NULL) return 0;
    return countSkipRoot(leftChild(T)) + countSkipRoot(rightChild(T));
}
int countSkipRoot(Tree T) {
    if(T == NULL) return 0;
    if(isLeaf(T)) return 0;
    return 1 + countSkipRoot(leftChild(T)) + countSkipRoot(rightChild(T));
}

int treeHeight(Tree T) {
    if(T == 0) return 0;
    int leftHeigth = treeHeight(leftChild(T));
    int rightHeight = treeHeight(rightChild(T));

    if(leftHeigth > rightHeight) return leftHeigth;
    return rightHeight;
}
int supTreeHeight(Tree T) {
    if(T == 0) return 0;
    int leftHeigth = treeHeight(leftChild(T));
    int rightHeight = treeHeight(rightChild(T));

    if(leftHeigth > rightHeight) return 1 + leftHeigth;
    return 1 + rightHeight;
}

Tree createBTree(DataType x, Tree L, Tree R) {
    Tree T = (Node*)malloc(sizeof(Node));
    T->Data = x;
    T->Left = L;
    T->Right = R;
    return T;
}
void preOrder(Tree T) {
    if(T == NULL) return;
    printf("%d ", T->Data);
    preOrder(leftChild(T));
    preOrder(rightChild(T));
}
void inOrder(Tree T) {
    if(T == NULL) return;
    inOrder(leftChild(T));
    printf("%d ", T->Data);
    inOrder(rightChild(T));
}
void posOrder(Tree T) {
    if(T == NULL) return;
    posOrder(leftChild(T));
    posOrder(rightChild(T));
    printf("%d ", T->Data);
}