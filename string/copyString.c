void mystrcpy(char s1[], char s2[]) {
    for(int i = 0; i < strlen(s1); i++) {
        s2[i] = s1[i];;
    }

    //kết thúc chuỗi ban đầu ngay lập tức.
    s2[strlen(s1)] = '\0';


}