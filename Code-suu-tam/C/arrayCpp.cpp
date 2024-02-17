#include <iostream>

int main()
{
    int m, n, arr1[10][10], arr2[10][10],arr3[10][10];
    std::cout << "nhap m: ";
    std::cin >> m;
    std::cout << "nhap n: ";
    std::cin >> n;
    std::cout << "ma tra 1: ";
    for(int i = 0; i < m; i++) {
    	for(int j = 0; j < n; j++) {
    		std::cin >> arr1[i][j];
		}
	}
	std::cout << "ma tran 2: ";
	for(int i = 0; i < m; i++) {
    	for(int j = 0; j < n; j++) {
    		std::cin >> arr2[i][j];
		}
	}
	std::cout << "ma tran tong: \n";
	for(int i = 0; i < m; i++) {
    	for(int j = 0; j < n; j++) {
    		arr3[i][j] = arr1[i][j] + arr2[i][j];
    		std::cout << arr3[i][j] << " ";
		}
		std::cout << "\n";
	}
	
    return 0;
}

