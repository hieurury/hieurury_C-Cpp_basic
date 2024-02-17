#include <stdio.h>


//VIET HAM TIM GIA TRI LON NHAT TRONG MANG INT. NEU TRUNG LAP THI IN RA SO LAN LAP LAI;

//void findMax(int array[], int length) {
//	int numberMax = array[0];
//	int core = 1;
//	for(int i = 1; i < length; i++) {
//		if(array[i] > numberMax) {
//			numberMax = array[i];
//			core = 1;
//		} else if(numberMax == array[i]) {
//			core++;
//		}
//	}
//	
//		printf("gia tri lon nhat trong mang la: %d\n", numberMax);
//		if(core > 1) printf("lap lai: %d", core);
//		else printf("khong lap lai!");
//	
//}

//VIET HAM XAC DINH XEM SO DO CO TON TAI TRONG MANG HAY KHONG. NEU CO THI IN RA CAC VI TRI CU THE.

//void findIndex(int array[], int length, int number) {
//	int tmpLength = 1;
//	int tmpArray[tmpLength];
//	for(int i = 0; i < length; i++) {
//		if(array[i] == number) {
//			tmpArray[tmpLength - 1] = i;
//			tmpLength++;
//		}
//	}
//	
//	if(tmpLength != 1) {
//		printf("vi tri tim thay: ");
//		for(int i = 0; i < tmpLength - 1; i++) {
//			printf("%d ", tmpArray[i]);
//		}
//	} else {
//		printf("khong tim thay");
//	}
//	
//}

void insert(int array[], int length) {
	for(int i = 0; i < length; i++) {
		scanf("%d", &array[i]);
	}
}

int main() {
	
	
	return 1;
}