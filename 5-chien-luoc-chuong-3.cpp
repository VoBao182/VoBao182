// 5 Chiến lược chương 3
#include<iostream>

using namespace std;

void First_fit(int* tientrinh, int* phanvung, int a, int b) {
	cout << "----------------------------------------------------------------------------\n";
	cout << "CHIEN LUOC FIRST-FIT\n";
	
	// Lưu trữ các tiến trình thỏa phân vùng
	int** arr = new int*[b]; 
	for (int i = 0; i < b; ++i) {
		arr[i] = new int[a];
	}
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			arr[i][j] = 0;
		}
	}

	// Sao chép mảng phân vùng 
	int* brr = new int [b];
	for (int i = 0; i < b; ++i) {
		brr[i] = phanvung[i];
	}

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			if (tientrinh[i] <= brr[j]) {
				arr[j][i] = 1;
				brr[j] -= tientrinh[i];
				break;
			}
		}
	}


	// Xuất kết quả
	for (int i = 0; i < b; ++i) {
		cout << phanvung[i] << " =>> ";
		for (int j = 0; j < a; ++j) {
			if(arr[i][j] == 1){
				cout << tientrinh[j] << "\t";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < a; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] brr;
}

void Best_fit(int* tientrinh, int* phanvung, int a, int b) {
	cout << "----------------------------------------------------------------------------\n";
	cout << "CHIEN LUOC BEST-FIT\n";

	// Lưu trữ các tiến trình thỏa phân vùng
	int** arr = new int* [b];
	for (int i = 0; i < b; ++i) {
		arr[i] = new int[a];
	}
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			arr[i][j] = 0;
		}
	}
	
	// Sao chép mảng phân vùng 
	int* brr = new int[b];
	for (int i = 0; i < b; ++i) {
		brr[i] = phanvung[i];
	}

	for (int i = 0; i < a; ++i) {
		int index = -1;
		int min = INT_MAX;
		for (int j = 0; j < b; ++j) {
			if (brr[j] >= tientrinh[i] && brr[j] < min) { // Tìm phân vùng phù hợp 
				index = j;
				min = brr[j];
			}
		}
		if (index != -1) {
			arr[index][i] = 1;
			brr[index] -= tientrinh[i];
		}
	}

	// Xuất kết quả 
	for (int i = 0; i < b; ++i) {
		cout << phanvung[i] << " =>> ";
		for (int j = 0; j < a; ++j) {
			if (arr[i][j] == 1) {
				cout << tientrinh[j] << "\t";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < a; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] brr;
}

void Worst_fit(int* tientrinh, int* phanvung, int a, int b) {
	cout << "----------------------------------------------------------------------------\n";
	cout << "CHIEN LUOC WORST-FIT\n";

	// Lưu trữ các tiến trình thỏa phân vùng
	int** arr = new int* [b];
	for (int i = 0; i < b; ++i) {
		arr[i] = new int[a];
	}
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			arr[i][j] = 0;
		}
	}

	// Sao chép mảng phân vùng 
	int* brr = new int[b];
	for (int i = 0; i < b; ++i) {
		brr[i] = phanvung[i];
	}

	for (int i = 0; i < a; ++i) {
		int index = -1;
		int max = INT_MIN;
		for (int j = 0; j < b; ++j) { // Tìm phân vùng thỏa
			if (brr[j] > max && brr[j] > tientrinh[i]) {
				index = j;
				max = brr[j];
			}
		}

		if (index != -1) {
			brr[index] -= tientrinh[i];
			arr[index][i] = 1;
		}
	}

	// Xuất kết quả 
	for (int i = 0; i < b; ++i) {
		cout << phanvung[i] << " =>> ";
		for (int j = 0; j < a; ++j) {
			if (arr[i][j] == 1) {
				cout << tientrinh[j] << "\t";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < a; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] brr;
}

void Next_fit(int* tientrinh, int* phanvung, int a, int b) {
	cout << "----------------------------------------------------------------------------\n";
	cout << "CHIEN LUOC NEXT-FIT\n";

	// Lưu trữ các tiến trình thỏa phân vùng
	int** arr = new int* [b];
	for (int i = 0; i < b; ++i) {
		arr[i] = new int[a];
	}
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			arr[i][j] = 0;
		}
	}

	// Sao chép mảng phân vùng 
	int* brr = new int[b];
	for (int i = 0; i < b; ++i) {
		brr[i] = phanvung[i];
	}

	int count = 0;
	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < b; ++j) {
			j += count;
			if (j >= b)
				j = 0; count = 0;
			if (tientrinh[i] <= brr[j]) {
				arr[j][i] = 1;
				brr[j] -= tientrinh[i];
				++count;
				break;
			}
		}
	}


	// Xuất kết quả 
	for (int i = 0; i < b; ++i) {
		cout << phanvung[i] << " =>> ";
		for (int j = 0; j < a; ++j) {
			if (arr[i][j] == 1) {
				cout << tientrinh[j] << "\t";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < a; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] brr;
}

void Last_fit(int* tientrinh, int* phanvung, int a, int b) {
	cout << "----------------------------------------------------------------------------\n";
	cout << "CHIEN LUOC LAST-FIT\n";

	// Lưu trữ các tiến trình thỏa phân vùng
	int** arr = new int* [b];
	for (int i = 0; i < b; ++i) {
		arr[i] = new int[a];
	}
	for (int i = 0; i < b; ++i) {
		for (int j = 0; j < a; ++j) {
			arr[i][j] = 0;
		}
	}

	// Sao chép mảng phân vùng 
	int* brr = new int[b];
	for (int i = 0; i < b; ++i) {
		brr[i] = phanvung[i];
	}

	for (int i = 0; i < a; ++i) {
		for (int j = b - 1; j >= 0; --j) {
			if (tientrinh[i] <= brr[j]) {
				arr[j][i] = 1;
				brr[j] -= tientrinh[i];
				break;
			}
		}
	}

	// Xuất kết quả 
	for (int i = 0; i < b; ++i) {
		cout << phanvung[i] << " =>> ";
		for (int j = 0; j < a; ++j) {
			if (arr[i][j] == 1) {
				cout << tientrinh[j] << "\t";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < a; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	delete[] brr;
}

int main() {
	int a,b;
	
	cout << "so phan vung cua bo nho chinh: ";
	cin >> b;
	int* phanvung = new int[b];
	for (int i = 0; i < b; ++i) {
		cout << "nhap phan vung " << i + 1 << ": ";
		cin >> phanvung[i];
	}

	cout << "so luong tien trinh: ";
	cin >> a;
	int* tientrinh = new int[a];
	for (int i = 0; i < a; ++i) {
		cout << "nhap du lieu tien trinh " << i + 1 << ": ";
		cin >> tientrinh[i];
	}

	int select = -1;
	while (select != 0) {
		cout << "1. First-fit\n";
		cout << "2. Best-fit\n";
		cout << "3. Worst_fit\n";
		cout << "4. Next_fit\n";
		cout << "5. Last_fit\n";
		cout << "0. Ket Thuc\n";
		cout << "Chon chien luoc muon thuc hien: ";
		cin >> select;
		if (select == 1) {
			First_fit(tientrinh, phanvung, a, b);
		}
		if (select == 2) {
			Best_fit(tientrinh, phanvung, a, b);
		}
		if (select == 3) {
			Worst_fit(tientrinh, phanvung, a, b);
		}
		if (select == 4) {
			Next_fit(tientrinh, phanvung, a, b);
		}
		if (select == 5) {
			Last_fit(tientrinh, phanvung, a, b);
		}
	}

	delete[] tientrinh;
	delete[] phanvung;
	return 0;
}