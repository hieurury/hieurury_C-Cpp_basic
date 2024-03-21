int Length(char s[]) {
    int count = 0;
    while(s[count] != '\0') {
        count++;
    }
    return count;
}