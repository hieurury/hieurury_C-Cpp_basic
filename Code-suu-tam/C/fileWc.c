#include <stdio.h>

int main() {
	FILE *file = fopen("new_file.txt", "w"); // Thay đổi chế độ thành "w+"
    if (file == NULL) {
        printf("Khong the tao hoac mo tep!\n");
        return 1;
    }
    
    
    file = fopen("new_file.txt", "a+"); // Thay đổi chế độ thành "w+"
    if (file == NULL) {
        printf("Khong the tao hoac mo tep!\n");
        return 1;
    }
    
    
    char value[100];
    fprintf(file, "hello hieurury");
    fseek(file, 0, SEEK_SET); // Di chuyển con trỏ đọc/ghi về đầu tệp
    fgets(value, sizeof(value), file);
    printf("trong file: %s", value);
    fclose(file); // Đóng tệp

    return 0;
}
