void Insert(int x, int p, int A[], int *len) {
    //tạo một vùng nhớ mới rộng hơn 1.
    int *B = (int*)malloc((*len + 1) * sizeof(int));
    //cho con trỏ B quản lí vùng nhớ của mảng A
    B = A;

    //đẩy các phần tử ra sau chừa chổ cho vị trí cần chèn.
    for(int i = *len; i > p; i--) {
        B[i] = B[i-1];
    }
    //chèn giá trị vào vị trí.
    B[p] = x;
    //tăng độ dài lên 1.
    *len = *len + 1;
}