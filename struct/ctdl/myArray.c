#include <D:\programs\C_C++_Programing_languages\struct\ctdl\ArrayLib.h>



int main() {
    List newList;
    MakeNull(&newList);
    ReadList(&newList);
    PrintList(newList);
    ReadList(&newList);
    PrintList(newList);
    int e;
    printf("nhap doi tuong can dem: ");
    scanf("%d", &e);
    int counted = CountElement(e, newList);
    printf("xuat hien: %d", counted);
    int find;
    printf("\ndoi tuong can tim: ");
    scanf("%d", &find);
    int position = Locate(find, newList);
    if(position != EndList(newList)) printf("tim thay o vi tri: %d", position);
    else printf("khong tim thay");
}



