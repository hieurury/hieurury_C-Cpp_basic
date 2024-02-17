using namespace std;
#include <iostream>
int main()
{
	int n{ 0 };
	cout << "enter n: ";
	cin >> n;

	

	{
		float mauSo = 1;
		float bienSo;
		float dapAn = 0;
		while (mauSo <= n)
		{
			bienSo = ( 1 / (mauSo));
			++mauSo;
			dapAn = dapAn + bienSo;

		}
		cout << "Sum: " << dapAn;
		
		
	}
}
