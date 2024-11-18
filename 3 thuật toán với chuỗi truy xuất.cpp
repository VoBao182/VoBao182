// Thuật toán thay thế trang FIFO
#include<iostream>

using namespace std;

void FIFO(int** page,int n,int kt, int* ctx) {
	int* loitrang = new int[n]; // Mảng lưu trữ lỗi trang (khởi tạo tất cả bằng 0 tức không có lỗi)
	for (int i = 0; i < n; ++i) {
		loitrang[i] = 0;
	}

	int index = 0; // Con trỏ cho việc thay thế theo kiểu FIFO

	for (int i = 0; i < n; ++i) {
		// Xét xem số đang truy xuất có trùng với dữ liệu đã có trong khung hay không ( có lỗi trang hay không )
		for (int j = 0; j < kt; ++j) {
			if (i == 0) {
				loitrang[i] = 1;
				break;
			}
			else {
				if (page[j][i - 1] == ctx[i]) {
					loitrang[i] = 0;
					break;
				}
				else
					loitrang[i] = 1;
			}
		}

		if (loitrang[i] == 0) { // Nếu không xảy ra lỗi trang
			for (int z = 0; z < kt; ++z) {
				page[z][i] = page[z][i - 1];
			}
			continue;
		}
		else { // Nếu xảy ra lỗi trang
			for (int z = 0; z < kt; ++z) {
				if (i == 0) {
					page[z][i] = -1;
				}
				else
					page[z][i] = page[z][i - 1];
			}

			page[index][i] = ctx[i];
			index = (index + 1) % kt; // Đảm bảo index luôn nằm trong (kt - 1)
		}
	}

	// Xuất kết quả
	for (int i = 0; i < n; ++i) {
		cout << ctx[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < kt; ++i) {
		for (int j = 0; j < n; ++j) {
			if (page[i][j] == -1)
				cout << "  ";
			else
				cout << page[i][j] << " ";
		}
		cout << endl;
	}
	// Xuất lỗi trang
	int count = 0; // Biến dùng để đếm số lỗi trang
	for (int i = 0; i < n; ++i) {
		if (loitrang[i] == 0)
			cout << "  ";
		else {
			cout << "* ";
			++count;
		}
	}
	cout << "\nCo " << count << " loi trang\n";
}

// Hàm tìm khung trang sẽ lâu được sử dụng nhất
int Find(int** page,int n, int index, int kt, int* ctx) {

	int max = -1; // Khoảng cách xa nhất đến lần xuất hiện tiếp theo
	int kq = -1; // Chỉ số của trang cần thay thế

	for (int i = 0; i < kt; ++i) {
		int temp = page[i][index - 1];
		// Tìm lần xuất hiện tiếp theo của trang hiện tại
		int next = index + 1;
		while (next < n && ctx[next] != temp) {
			next++;
		}																																	
	
		if (next > max) {
			max = next;
			kq = i;
		}
	}

	return kq;
}

void TOIUU(int** page,int n, int kt, int* ctx) {
	int* loitrang = new int[n]; // Mảng lưu trữ lỗi trang (khởi tạo tất cả bằng 0 tức không có lỗi)
	for (int i = 0; i < n; ++i) {
		loitrang[i] = 0;
	}

	for (int i = 0; i < n; ++i) {
		// Xét xem số đang truy xuất có trùng với dữ liệu đã có trong khung hay không ( có lỗi trang hay không )
		for (int j = 0; j < kt; ++j) {
			if (i == 0) {
				loitrang[i] = 1;
				break;
			}
			else {
				if (page[j][i - 1] == ctx[i]) {
					loitrang[i] = 0;
					break;
				}
				else
					loitrang[i] = 1;
			}
		}

		if (loitrang[i] == 0) { // Nếu không xảy ra lỗi trang
			for (int z = 0; z < kt; ++z) {
				page[z][i] = page[z][i - 1];
			}
		}
		else { // Nếu xảy ra lỗi trang
			for (int z = 0; z < kt; ++z) {
				if (i == 0) {
					page[z][i] = -1;
					page[0][0] = ctx[0];
				}
				else
					page[z][i] = page[z][i - 1];
			}
			if (i >= kt )
				page[Find(page, n, i, kt, ctx)][i] = ctx[i];
			else
				page[i][i] = ctx[i];
		}
	}

	// Xuất kết quả
	for (int i = 0; i < n; ++i) {
		cout << ctx[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < kt; ++i) {
		for (int j = 0; j < n; ++j) {
			if (page[i][j] == -1)
				cout << "  ";
			else
				cout << page[i][j] << " ";
		}
		cout << endl;
	}
	// Xuất lỗi trang
	int count = 0; // Biến dùng để đếm số lỗi trang
	for (int i = 0; i < n; ++i) {
		if (loitrang[i] == 0)
			cout << "  ";
		else {
			cout << "* ";
			++count;
		}
	}
	cout << "\nCo " << count << " loi trang\n";
}

// Hàm tìm số lớn nhất trong mảng phục vụ thuật toán LRU
int Max(int*& index, int kt) { 
	int max = 0;
	for (int i = 1; i < kt; ++i) {
		if (index[i] > index[max]) {
			max = i;
		}
	}	
	return max;
}

// Tăng thời gian chưa được sử dụng của khung trang
void reload(int*& index, int kt) { 
	for (int i = 0; i < kt; ++i) {
		++index[i];
	}
}

void LRU(int** page,int n, int kt, int* ctx) {
	int* loitrang = new int[n]; // Mảng lưu trữ lỗi trang (khởi tạo tất cả bằng 0 tức không có lỗi)
	for (int i = 0; i < n; ++i) {
		loitrang[i] = 0;
	}

	int* index = new int[kt]; // Con trỏ cho việc thay thế theo kiểu LRU
	for (int i = 0; i < kt; ++i) { // index càng lớn => càng lâu chưa sử dụng
		index[i] = kt - 1 - i;
	}

	for (int i = 0; i < n; ++i) {
		int temp;
		// Xét xem số đang truy xuất có trùng với dữ liệu đã có trong khung hay không ( có lỗi trang hay không )
		for (int j = 0; j < kt; ++j) {
			if (i == 0) {
				loitrang[i] = 1;
				break;
			}
			else {
				if (page[j][i - 1] == ctx[i]) {
					loitrang[i] = 0;
					temp = j;
					break;
				}
				else
					loitrang[i] = 1;
			}
		}
		/*int max = Max(index, kt);*/
		if (loitrang[i] == 0) { // Nếu không xảy ra lỗi trang
			for (int z = 0; z < kt; ++z) {
				page[z][i] = page[z][i - 1];
			}
			reload(index, kt);
			index[temp] = 0;
		}
		else { // Nếu xảy ra lỗi trang
			
			for (int z = 0; z < kt; ++z) {
				if (i == 0) {
					page[z][i] = -1;
				}
				else
					page[z][i] = page[z][i - 1];
			}
			page[Max(index, kt)][i] = ctx[i];
			reload(index, kt);
			index[Max(index, kt)] = 0;
		}
	}

	// Xuất kết quả
	for (int i = 0; i < n; ++i) {
		cout << ctx[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < kt; ++i) {
		for (int j = 0; j < n; ++j) {
			if (page[i][j] == -1)
				cout << "  ";
			else
				cout << page[i][j] << " ";
		}
		cout << endl;
	}
	// Xuất lỗi trang
	int count = 0; // Biến dùng để đếm số lỗi trang
	for (int i = 0; i < n; ++i) {
		if (loitrang[i] == 0)
			cout << "  ";
		else {
			cout << "* ";
			++count;
		}
	}
	cout << "\nCo " << count << " loi trang\n";

	delete[] loitrang;
	delete[] index;
}

int main() {
	int n, kt;
	cout << " Nhap so khung trang: ";
	cin >> kt;
	cout << " Nhap so luong chuoi truy xuat: ";
	cin >> n;

	int* ctx = new int[n];
	// Nhập chuỗi truy xuất	
	for (int i = 0; i < n; ++i) {
		cout << "Nhap chuoi truy xuat " << i + 1 <<": ";
		cin >> ctx[i];
	}

	// Tạo mảng chứa dữ liệu khung trang (khởi tạo tất cả bằng -1)
	int** page = new int*[kt]; // Dòng
	for (int i = 0; i < kt; ++i) { // Cột
		page[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			page[i][j] = -1;
		}
	}

	int select = -1;
	while (select != 0) {
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "1/ Thuat toan FIFO\n";
		cout << "2/ Thuat toan toi uu\n";
		cout << "3/ Thuat toan Least Recently Used - LRU\n";
		cout << "0/ Ket thuc\n";
		cout << "Chon truong hop: ";
		cin >> select;
		if (select == 1) {
			FIFO(page, n, kt, ctx);
		}
		else if (select == 2) {
			TOIUU(page, n, kt, ctx);
		}
		else if (select == 3) {
			LRU(page, n, kt, ctx);
		}
		else
			break;
	}


	// Xóa dữ liệu 
	for (int i = 0; i < kt; ++i) {
		delete[] page[i];
	}
	delete[] page;
	delete[] ctx;
	return 0;
}