#include <iostream>
#include <string>
using namespace std;

// Khai báo cấu trúc nhân viên
class NhanVien
{
protected:
    string ho_ten;
    int tuoi;
    string gioi_tinh;
    string dia_chi;
    string sdt;
    double chieu_cao;
    double can_nang;
public:
    void Nhap();
    void Xuat();

    NhanVien();
    ~NhanVien();
};

// Hàm nhập thông tin nhân viên  
void NhanVien::Nhap()
{
    fflush(stdin);
    cout << "\n Nhap ho ten: ";
    getline(cin, ho_ten);
    cout << "\n Nhap tuoi: ";
    cin >> tuoi;
    fflush(stdin);
    cout << "\n Nhap gioi tinh: ";
    getline(cin, gioi_tinh);
    cout << "\n Nhap dia chi: ";
    getline(cin, dia_chi);
    cout << "\n Nhap sdt: ";
    getline(cin, sdt);
    cout << "\n Nhap chieu_cao: ";
    cin >> chieu_cao;
    cout << "\n Nhap can nang: ";
    cin >> can_nang;
}

//Hàm xuất thông tin nhân viên 
void NhanVien::Xuat()
{
    cout << "\n Ho ten: " << ho_ten;
    cout << "\n Tuoi: " << tuoi;
    cout << "\n Gioi tinh: " << gioi_tinh;
    cout << "\n Dia chi: " << dia_chi;
    cout << "\n Sdt: " << sdt;
    cout << "\n Chieu_cao: " << chieu_cao;
    cout << "\n Can nang: " << can_nang;
}

//Hàm tạo nhân viên sủa ống nước 
NhanVien::NhanVien()
{

}

//Hàm hủy nhân viên sửa ống nước 
NhanVien::~NhanVien()
{

}
// Khai báo cấu trúc nhân viên sửa sống nước 
class NhanVienSuaOngNuoc: public NhanVien
{
private:
    double so_h_sua;
public:
    void Nhap();
    void Xuat();
    double Tinh_Tien_Luong();
    
    NhanVienSuaOngNuoc();
    ~NhanVienSuaOngNuoc();
};

// Hàm nhập thông tin nhân viên sửa ống nước 
void NhanVienSuaOngNuoc::Nhap()
{
    NhanVien::Nhap();
    cout << "\n Nhap so gio sua: ";
    cin >> so_h_sua;
}

//Hàm xuất thông tin nhân viên sửa ống nước 
void NhanVienSuaOngNuoc::Xuat()
{
    NhanVien::Xuat();
    cout << "\n So gio sua: " << so_h_sua << endl;
}

//Hàm tính tiền lương nhân viên sủa ống nước 
double NhanVienSuaOngNuoc::Tinh_Tien_Luong()
{
    return so_h_sua * 50000;
}

//Hàm tạo nhân viên sủa ống nước 
NhanVienSuaOngNuoc::NhanVienSuaOngNuoc()
{

}

//Hàm hủy nhân viên sửa ống nước 
NhanVienSuaOngNuoc::~NhanVienSuaOngNuoc()
{

}

// Khai báo cấu trúc nhân viên giao hàng
class NhanVienGiaoHang: public NhanVien
{
private:
    int so_hang_giao;
public:
    void Nhap();
    void Xuat();
    double Tinh_Tien_Luong();
    
    NhanVienGiaoHang();
    ~NhanVienGiaoHang();
};

// Hàm nhập thông tin nhân viên giao hàng
void NhanVienGiaoHang::Nhap()
{
    NhanVien::Nhap();
    cout << "\n Nhap so hang giao: ";
    cin >> so_hang_giao;
}

//Hàm xuất thông tin nhân viên giao hàng
void NhanVienGiaoHang::Xuat()
{
    NhanVien::Xuat();
    cout << "\n So hang giao: " << so_hang_giao << endl;
}

//Hàm tính tiền lương nhân viên giao hàng
double NhanVienGiaoHang::Tinh_Tien_Luong()
{
    return so_hang_giao * 33500;
}

//Hàm tạo nhân viên giao hàng
NhanVienGiaoHang::NhanVienGiaoHang()
{

}

//Hàm hủy nhân viên giao hàng
NhanVienGiaoHang::~NhanVienGiaoHang()
{

}

// Khai báo cấu trúc nhân viên xe ôm 4.0
class NhanVienXeOm: public NhanVien
{
private:
    int so_km;
public:
    void Nhap();
    void Xuat();
    double Tinh_Tien_Luong();
    
    NhanVienXeOm();
    ~NhanVienXeOm();
};

// Hàm nhập thông tin nhân viên xe ôm 4.0
void NhanVienXeOm::Nhap()
{
    NhanVien::Nhap();
    cout << "\n Nhap so km: ";
    cin >> so_km;
}

//Hàm xuất thông tin nhân viên xe ôm 4.0
void NhanVienXeOm::Xuat()
{
    NhanVien::Xuat();
    cout << "\n So km: " << so_km << endl;
}

//Hàm tính tiền lương nhân viên xe ôm 4.0
double NhanVienXeOm::Tinh_Tien_Luong()
{
    return so_km * 10000;
}

//Hàm tạo nhân viên xe ôm 4.0
NhanVienXeOm::NhanVienXeOm()
{

}

//Hàm hủy nhân viên xe ôm 4.0
NhanVienXeOm::~NhanVienXeOm()
{

}

//Tính tổng tiền các nhân viên sửa ống nước 
double Tong_Tien_Nhan_Vien_Sua_Ong_Nuoc(NhanVienSuaOngNuoc  ds[], int n)
{
    double sum  = 0;
    for (int  i = 0; i < n; i++)
    {
        sum += ds[i].Tinh_Tien_Luong();
    }
    return sum;
}

//Tính tổng tiền các nhân viên giao hàng
double Tong_Tien_Nhan_Vien_Giao_Hang(NhanVienGiaoHang  ds[], int n)
{
    double sum  = 0;
    for (int  i = 0; i < n; i++)
    {
        sum += ds[i].Tinh_Tien_Luong();
    }
    return sum;
}

//Tính tổng tiền các nhân viên xe ôm công nghệ
double Tong_Tien_Nhan_Vien_Xe_Om(NhanVienXeOm  ds[], int n)
{
    double sum  = 0;
    for (int  i = 0; i < n; i++)
    {
        sum += ds[i].Tinh_Tien_Luong();
    }
    return sum;
}

//Hoán vị nhân viên sủa ống nước 
void Hoan_Vi_Nhan_Vien_Sua_Ong_Nuoc(NhanVienSuaOngNuoc &nv1, NhanVienSuaOngNuoc &nv2)
{
    NhanVienSuaOngNuoc tam = nv1;
    nv1 = nv2;
    nv2 = tam;
}

//Hoán vị nhân viên sủa ống nước 
void Hoan_Vi_Nhan_Vien_Giao_Hang(NhanVienGiaoHang &nv1, NhanVienGiaoHang &nv2)
{
    NhanVienGiaoHang tam = nv1;
    nv1 = nv2;
    nv2 = tam;
}

//Hoán vị nhân viên xe ôm công nghệ 
void Hoan_Vi_Nhan_Vien_Xe_Om( NhanVienXeOm &nv1, NhanVienXeOm &nv2)
{
    NhanVienXeOm tam = nv1;
    nv1 = nv2;
    nv2 = tam;
}

//Sắp xếp danh sách nhân viên SỬA ỐNG NƯỚC giảm dần
void Sap_Xep_Danh_Sach_Nhan_Vien_Sua_Ong_Nuoc_Giam_Dan(NhanVienSuaOngNuoc ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[j].Tinh_Tien_Luong() > ds[i].Tinh_Tien_Luong()) {
                Hoan_Vi_Nhan_Vien_Sua_Ong_Nuoc(ds[j], ds[i]);
            }
        }
    }
}

//Sắp xếp danh sách nhân viên GIAO HÀNG giảm dần
void Sap_Xep_Danh_Sach_Nhan_Vien_Giao_Hang_Giam_Dan(NhanVienGiaoHang ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[j].Tinh_Tien_Luong() > ds[i].Tinh_Tien_Luong()) {
                Hoan_Vi_Nhan_Vien_Giao_Hang(ds[j], ds[i]);
            }
        }
    }
}

//Sắp xếp danh sách nhân viên XE ÔM CÔNG NGHỆ giảm dần
void Sap_Xep_Danh_Sach_Nhan_Vien_Xe_Om_Giam_Dan(NhanVienXeOm ds[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ds[j].Tinh_Tien_Luong() > ds[i].Tinh_Tien_Luong()) {
                Hoan_Vi_Nhan_Vien_Xe_Om(ds[j], ds[i]);
            }
        }
    }
}
//Thiết kế menu quản lí
void Menu(NhanVienSuaOngNuoc ds_NhanVienSuaOngNuoc[], NhanVienGiaoHang ds_NhanVienGiaoHang[], NhanVienXeOm ds_NhanVienXeOm[], int n, int m, int l)
{
    int lua_chon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t ====== CHUONG TRINH QUAN LI ======";
        cout << "\n 1. Nhap thong tin nhan vien SUA ONG NUOC";
        cout << "\n 2. Nhap thong tin nhan vien GIAO HANG";
        cout << "\n 3. Nhap thong tin nhan vien XE OM CONG NGHE";
        cout << "\n 4. Xuat thong tin nhan vien SUA ONG NUOC";
        cout << "\n 5. Xuat thong tin nhan vien GIAO HANG";
        cout << "\n 6. Xuat thong tin nhan vien XE OM CONG NGHE";
        cout << "\n 7. Xuat tong tien luong CAC NHAN VIEN ";
        cout << "\n 8. Xuat danh sach nhan vien SUA ONG NUOC giam dan";
        cout << "\n 9. Xuat danh sach nhan vien GIAO HANG giam dan";
        cout << "\n 10.Xuat danh sach nhan vien XE OM CONG NGHE giam dan";
        cout << "\n 0. Thoat";

        cout << "\n Nhap lua chon: ";
        cin >> lua_chon;
        if (lua_chon < 0 || lua_chon > 10) {
            cout << "\n Lua chon khong hop le, xin nhap lai \n";
            system("pause");
        } else if (lua_chon ==  0) {
            break;
        } else if (lua_chon == 1) {
            NhanVienSuaOngNuoc nv_SuaOngNuoc;
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN SUA ONG NUOC\n";
            nv_SuaOngNuoc.Nhap();

            ds_NhanVienSuaOngNuoc[n] = nv_SuaOngNuoc;
            n++;
        } else if (lua_chon == 2) {
            NhanVienGiaoHang nv_GiaoHang;
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN GIAO HANG\n";
            nv_GiaoHang.Nhap();

            ds_NhanVienGiaoHang[m] = nv_GiaoHang;
            m++;
        } else if (lua_chon == 3) {
            NhanVienXeOm nv_XeOm;
            cout << "\n\n\t\t NHAP THONG TIN NHAN VIEN XE OM CONG NGHE\n";
            nv_XeOm.Nhap();

            ds_NhanVienXeOm[l] = nv_XeOm;
            l++;
        } else if (lua_chon == 4) {
            cout << "\n\n\t\t DANH SACH NHAN VIEN SUA ONG NUOC \n";
            for (int i = 0; i < n; i++)
            {
                cout << "\n\n\t\t THONG TIN NHAN VIEN SUA ONG NUOC THU " << i << endl;
                ds_NhanVienSuaOngNuoc[i].Xuat();
            }
            cout << "\n\n\t\t TONG TIEN LUONG CUA NHAN VIEN SUA ONG NUOC: " << (size_t)(Tong_Tien_Nhan_Vien_Sua_Ong_Nuoc(ds_NhanVienSuaOngNuoc, n)) << endl; 
            system("pause");   
        } else if (lua_chon == 5) {
            cout << "\n\n\t\t DANH SACH NHAN VIEN GIAO HANG \n";
            for (int i = 0; i < n; i++)
            {
                cout << "\n\n\t\t THONG TIN NHAN VIEN GIAO HANG THU " << i << endl;
                ds_NhanVienGiaoHang[i].Xuat();
            }
            cout << "\n\n\t\t TONG TIEN LUONG CUA NHAN VIEN SUA ONG NUOC: " << (size_t)(Tong_Tien_Nhan_Vien_Giao_Hang(ds_NhanVienGiaoHang, m)) << endl;
            system("pause");   
        } else if (lua_chon == 6) {
            cout << "\n\n\t\t DANH SACH NHAN VIEN XE OM CONG NGHE \n";
            for (int i = 0; i < n; i++)
            {
                cout << "\n\n\t\t THONG TIN NHAN VIEN XE OM CONG NGHE THU " << i << endl;
                ds_NhanVienXeOm[i].Xuat();
            }
            cout << "\n\n\t\t TONG TIEN LUONG CUA NHAN VIEN SUA ONG NUOC: " << (size_t)(Tong_Tien_Nhan_Vien_Xe_Om(ds_NhanVienXeOm, l)) << endl;
            system("pause");   
        } else if (lua_chon == 7) {
            cout << "\n\n\t\t TONG TIEN LUONG CUA CAC NHAN VIEN: " << (size_t)(Tong_Tien_Nhan_Vien_Sua_Ong_Nuoc(ds_NhanVienSuaOngNuoc, n) + Tong_Tien_Nhan_Vien_Giao_Hang(ds_NhanVienGiaoHang, m) + Tong_Tien_Nhan_Vien_Xe_Om(ds_NhanVienXeOm, l)) << endl;
            system("pause");
        } else if (lua_chon == 8) {
            cout << "\n\n\t\t DANH SACH NHAN VIEN SUA ONG NUOC GIAM DAN \n";
            Sap_Xep_Danh_Sach_Nhan_Vien_Sua_Ong_Nuoc_Giam_Dan(ds_NhanVienSuaOngNuoc, n);
            for (int i = 0; i < n; i++)
            {
                cout << "\n\n\t\t THONG TIN NHAN VIEN SUA ONG NUOC THU " << i << endl;
                ds_NhanVienSuaOngNuoc[i].Xuat();
            }
            system("pause");
        } else if (lua_chon == 9) {
            cout << "\n\n\t\t DANH SACH NHAN VIEN GIAO HANG GIAM DAN \n";
            Sap_Xep_Danh_Sach_Nhan_Vien_Giao_Hang_Giam_Dan(ds_NhanVienGiaoHang, m);
            for (int i = 0; i < m; i++)
            {
                cout << "\n\n\t\t THONG TIN NHAN VIEN GIAO HANG THU " << i << endl;
                ds_NhanVienGiaoHang[i].Xuat();
            }
            system("pause");
        } else if (lua_chon == 10) {
            cout << "\n\n\t\t DANH SACH NHAN VIEN XE OM CONG NGHE GIAM DAN \n";
            Sap_Xep_Danh_Sach_Nhan_Vien_Xe_Om_Giam_Dan(ds_NhanVienXeOm, l);
            for (int i = 0; i < l; i++)
            {
                cout << "\n\n\t\t THONG TIN NHAN VIEN XE OM CONG NGHE THU " << i << endl;
                ds_NhanVienXeOm[i].Xuat();
            }
            system("pause");
        }
    }  
}


int main(int argc, char const *argv[])
{
    NhanVienSuaOngNuoc *nv = new NhanVienSuaOngNuoc();
    nv->Nhap();
    nv->Xuat();
    delete nv;
    system("pause");
   
    return 0;
}