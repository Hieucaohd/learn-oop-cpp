#pragma once
#include <iostream>
#include <string>
#include "DocGia.cpp"

class DocGiaTreEm: public DocGia
{
private:
    string hoTenNguoiDaiDien;
public:
    DocGiaTreEm();
    ~DocGiaTreEm();

    void input();
    void output();
    int tinhTienLamThe();
};







// phương thức nhập thông tin độc giả trẻ em
void DocGiaTreEm::input()
{
    DocGia::input(); 
    
    cin.ignore(); //xóa bộ nhớ đệm bên c++
    cout << "\n Nhap thong tin nguoi dai dien: ";
    getline(cin, hoTenNguoiDaiDien);
}

// phương thức xuất thông tin độc giả trẻ em
void DocGiaTreEm::output()
{
    DocGia::output();
    cout << "\n Ho ten nguoi dai dien: " << hoTenNguoiDaiDien << endl;
}

// tính tiền làm thẻ của độc giả trẻ em
int DocGiaTreEm::tinhTienLamThe()
{
    return soThangCoHieuLuc * 5000;
}

DocGiaTreEm::DocGiaTreEm()
{

}

DocGiaTreEm::~DocGiaTreEm()
{
    
}