void Insert(char c, int x, char s[]) {
    //lập từ cuối đến vị trí cần chèn.
    //mỗi lần lập đẩy ra phía sau 1 ô để chừa ô trống cho giá trị mới.
    for(int i = strlen(s); i >= x; i--) {
        s[i+1] = s[i];
    }
    //thêm giá trị mới vô chổ trống.
    s[x] = c;
}