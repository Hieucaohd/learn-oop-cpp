#include "ThuVien.cpp"

int main(int argc, char const *argv[])
{
    system("cls");
    vector<DocGia *> ds_DocGia;

    // thêm docGia1 vào ds_DocGia
    DocGia *docGia1 = new DocGiaTreEm;
    docGia1->input();
    ds_DocGia.push_back(docGia1);

    cout << "\n\n\t\t";

    // thêm docGia2 vào ds_DocGia
    DocGia *docGia2 = new DocGiaNguoiLon;
    docGia2->input();
    ds_DocGia.push_back(docGia2);


    // in ra danh sách ds_DocGia
    system("cls");
    cout << "\n\n\t\t DANH SACH DOC GIA \n";
    for (int i = 0; i < ds_DocGia.size(); i++)
    {
        ds_DocGia[i]->output();
        cout << "\n\n\t\t";
    }
    
    system("pause");
    delete docGia1, docGia2;
    return 0;
}
