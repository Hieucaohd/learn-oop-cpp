#include <iostream>
#include <string>
using namespace std;

template <class typeOfItem,class typeOfKey>
struct item
{
    typeOfItem item;
    typeOfKey key;
};

template <class typeOfItem,class typeOfKey>
class Dset
{
public:
    Dset(int m)
    {
        size = m;
        element = new item<typeOfItem, typeOfKey>[m];
    }
    ~Dset()
    {
        delete [] element;
    }

    void inputElements(int numberOfElements)
    {
        size = numberOfElements;
        cout << "\n\n\t\t NHAP DANH SACH: \n";
        for (int i = 0; i < numberOfElements; i++)
        {
            cout << "Nhap phan tu thu " << i << ": ";
            cin >> element[i].item >> element[i].key;
        }
    }

    void outputElements()
    {
        if (size != 0)
        {
            cout << "\n\n\t\t XUAT DANH SACH: ";
            for (int i = 0; i < size; i++)
            {
                cout << element[i].item << "(" << element[i].key << ")" << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "mang rong" << endl;
        }
        
    }


    item<typeOfItem, typeOfKey> *element;
    int size;
};

int main(int argc, char const *argv[])
{
    system("cls");
    Dset<int, int> list1(10);
    list1.inputElements(10);
    list1.outputElements();
    system("pause");
    return 0;
}
