char *subString(char s[], int x, int n) {
    char *tmp = (char*)malloc((n+1) * sizeof(char));
    
    for(int i = 0; i < n; i++) {
        tmp[i] = s[i+x];
    }
    return tmp;
}