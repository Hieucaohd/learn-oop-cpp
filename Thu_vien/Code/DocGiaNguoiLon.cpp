#pragma once
#include <iostream>
#include <string>
#include "DocGia.cpp"
using namespace std;

class DocGiaNguoiLon: public DocGia
{
private:
    string chungMinhNhanDan;
public:
    DocGiaNguoiLon();
    ~DocGiaNguoiLon();

    void input();
    void output();
    int tinhTienLamThe();
};











// phương thức nhập đọc giả người lớn
void DocGiaNguoiLon::input()
{
    DocGia::input();

    cin.ignore(); // xóa bộ nhớ đệm
    cout << "\n Nhap CMND: ";
    cin >> chungMinhNhanDan;
}

// phương thức xuất đọc giả người lớn
void DocGiaNguoiLon::output()
{
    DocGia::output();
    cout << "\n Chung minh thu nhan dan: " << chungMinhNhanDan << endl;
}

// phương thức tính tiền làm thẻ
int DocGiaNguoiLon::tinhTienLamThe()
{
    return soThangCoHieuLuc * 10000;
}

DocGiaNguoiLon::DocGiaNguoiLon()
{

}

DocGiaNguoiLon::~DocGiaNguoiLon()
{
    
}