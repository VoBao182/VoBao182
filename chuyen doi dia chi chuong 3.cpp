// Chuyển đổi địa chỉ chương 3
#include<iostream>

using namespace std;

void Logic_VatLy() {
	int n, sizeframe;
	cout << "Nhap so Page: ";
	cin >> n;
	
	// Nhập dữ liệu
	int* page = new int[n];
	for (int i = 0; i < n; ++i) {
		cout << "Nhap so Frame cua Page " << i << ": "; // Page đầu tiên luôn là 0
		cin >> page[i];
	}

	cout << "Nhap kich thuoc moi Frame (don vi KB) ";
	cin >> sizeframe;
	sizeframe *= 1024; // Chuyển đổi KB sang Byte


	int logic = -1;
	while (logic != 0) {
		cout << "----------------------------------------------------------\n";
		cout << "Nhap dia chi logic muon chuyen doi (nhap 0 de thoat): ";
		cin >> logic;
		if (logic == 0) {
			break;
		}
		int page_logic = logic / sizeframe;
		if (page_logic >= 0 && page_logic <= n - 1) {
			cout << "Dia chi logic ban muon chuyen doi thuoc page: " << page_logic << endl;
			cout << "Dia chi logic ban muon chuyen doi co frame = " << page[page_logic] << endl;
			int vatly = (page[page_logic] * sizeframe) + (logic % sizeframe);
			cout << "=>> Vay dia chi vat ly la: " << vatly << endl;
			}
		else {
			cout << "Khong tim thay page cho dia chi logic nay!" << endl;
		}
	}
	delete[] page;
}

void VatLy_Logic() {
	int n, sizeframe;
	cout << "Nhap so Page: ";
	cin >> n;
	
	// Nhập dữ liệu
	int* page = new int[n];
	for (int i = 0; i < n; ++i) {
		cout << "Nhap Table cua Page " << i << ": "; // Page đầu tiên luôn là 0
		cin >> page[i];
	}
	cout << "Nhap kich thuoc moi Frame (don vi KB): ";
	cin >> sizeframe;
	sizeframe *= 1024; // Chuyển đổi KB sang Byte

	int vatly = -1;
	while (vatly != 0) {
		cout << "----------------------------------------------------------\n";
		cout << "Nhap dia chi vat ly muon chuyen doi (nhap 0 de thoat): ";
		cin >> vatly;
		if (vatly == 0) {
			break;
		}
		int page_vatly = vatly / sizeframe;
		int vitri = -1;
		for (int i = 0; i < n; ++i) {
			if (page[i] == page_vatly) {
				cout << "Dia chi vat ly ban muon chuyen doi thuoc page: " << i << endl;
				vitri = i;
			}
		}
		if (vitri != -1) {
			int logic = (vitri * sizeframe) + (vatly - (page_vatly * sizeframe));
			cout << "=>> Vay dia chi logic la: " << logic << endl;
		}
		else {
			cout << "Khong tim thay page cho dia chi vat ly nay!" << endl;
		}
	}
	delete[] page;
}

int main() {
	int select = -1;
	while (select != 0) {
		cout << "-----------------------------------------------------------------------------------------------------\n";
		cout << "1/ Chuyen doi dia chi logic sang dia chi vat ly\n";
		cout << "2/ Chuyen doi dia chi vat ly sang dia chi logic\n";
		cout << "0/ Ket thuc\n";
		cout << "Chon truong hop: ";
		cin >> select;
		if (select == 1) {
			Logic_VatLy();
		}
		else if (select == 2) {
			VatLy_Logic();
		}
		else
			break;
	}
	return 0;
}