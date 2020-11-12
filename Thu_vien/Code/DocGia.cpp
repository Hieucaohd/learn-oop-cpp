#pragma once
#include <iostream>
#include <string>
using namespace std;

class DocGia //lớp cha
{
protected:
    string hoTen;
    string ngayLapThe; // dd/mm/yyyy
    int soThangCoHieuLuc;

public:
    DocGia();
    ~DocGia();

    virtual void input(); // phương thức nhập thông tin độc giả
    virtual void output(); // phương thức xuất thông tin độc giả
    virtual int tinhTienLamThe() = 0;
};












// phương thức nhập thông  tin độc giả
void DocGia::input()
{
    fflush(stdin); // xóa bộ nhớ đệm
    cout << "\n Nhap ho ten doc gia: ";
    getline(cin, hoTen);

    fflush(stdin); // xóa bộ nhớ đệm
    cout << "\n Nhap ngay lap the(dd/mm/yyyy): ";
    getline(cin, ngayLapThe);

    cout << "\n Nhap so thang co hieu luc: ";
    cin >> soThangCoHieuLuc;
}

// phương thức xuất thông tin độc giả
void DocGia::output()
{
	cout << "\n Ho ten doc gia: " << hoTen;
	cout << "\n Ngay lap the(dd/mm/yyyy): " << ngayLapThe;
	cout << "\n So thang co hieu luc: " << soThangCoHieuLuc;
}

DocGia::DocGia()
{

}

DocGia::~DocGia()
{

}

