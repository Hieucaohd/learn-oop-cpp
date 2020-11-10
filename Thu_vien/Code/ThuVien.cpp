#pragma once
#include "DocGiaTreEm.cpp"
#include "DocGiaNguoiLon.cpp"
#include <vector>

class ThuVien
{
private:
    vector<DocGia *> ds_DocGia;
public:
    ThuVien();
    ~ThuVien();

    void input();
    void output();
    int tinhTongTienLamThe();
};













// phương thức nhập thông tin các loại độc giả
void ThuVien::input()
{
    int luaChon;
    while (true)
    {
        system("cls"); //xóa màn hình trước đó
        cout << "\n 1. Doc gia tre em";
        cout << "\n 2. Doc gia nguoi lon";
        cout << "\n 0. Thoat";
        cout << "\n Nhap lua chon: ";
        cin >> luaChon;
        DocGia *x;
        if (luaChon == 1)
        {
            x = new DocGiaTreEm;
            cout << "\n\n\t\t NHAP THONG TIN DOC GIA TRE EM \n";
            x->input();
            ds_DocGia.push_back(x); // thêm đối tượng độc giả trẻ em vào danh sách ds_DocGia
        } 
        else if (luaChon == 2)
        {
            x = new DocGiaNguoiLon;
            cout << "\n\n\t\t NHAP THONG TIN DOC GIA NGUOI LON \n";
            x->input();
            ds_DocGia.push_back(x); // thêm đối tượng độc giả người lớn vào danh sách ds_DocGia
        } 
        else if (luaChon == 0)
        {
            break;  
        } 
        else
        {
            cout << "\n Lua chon khong hop le. Xin kiem tra lai";
            system("pause");
        }    
    }
}

// phương thức xuất thông tin độc giả
void ThuVien::output()
{
    cout << "\n\n\t\t DANH SACH DOC GIA \n";
    for (int i = 0; i < ds_DocGia.size(); i++)
    {
        cout << "\n\n\t\t DOC GIA THU " << i;
        ds_DocGia[i]->output(); 
    }
    system("pause");
}

// phương thức tính tổng tiền làm thẻ
int ThuVien::tinhTongTienLamThe()
{
    int sum = 0;
    for (int i = 0; i < ds_DocGia.size(); i++)
    {
        sum += ds_DocGia[i]->tinhTienLamThe();
    }
    return sum;
}

ThuVien::ThuVien()
{

}
ThuVien::~ThuVien()
{

}


