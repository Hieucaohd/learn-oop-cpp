#include "../DlistIterator.cpp"
#include "../Dlist.cpp"


template <class typeOfElement, class typeOfKey>
class Dset: public Dlist<typeOfElement, typeOfKey>
{
public:
    Dset(int m): Dlist<typeOfElement, typeOfKey>(m)
    {
        // Constructor: khởi tạo tập rỗng, có thể chứa nhiều nhất là m phần tử.
    }

    bool isDsetEmpty()
    {
        // Kiểm tra xem tập có rỗng không.
        Dlist<typeOfElement, typeOfKey>::isDlistEmpty();
    }

    void DsetInsert(const item<typeOfElement, typeOfKey> &x)
    {
        // Postcondition: phần tử x trở thành thành viên của tập động.
        if (!searchElementByKey(x.key))
        // Phần tử x chưa tồn tại trong tập hợp.
        {
            Dlist<typeOfElement, typeOfKey>::append(x);
        }
        else
        {
            cout << "Phan tu da ton tai trong tap" << endl;
        }
    }

    void DsetDeleteElementByKey(typeOfKey k)
    {
        // Postcondition: phần tử với khóa k không có trong tập động.
        for (int i = 1; i <= Dlist<typeOfElement, typeOfKey>::length(); i++)
        {
            if (Dlist<typeOfElement, typeOfKey>::findElement(i).key == k)
            {
                Dlist<typeOfElement, typeOfKey>::deleteElement(i);
                break;
            }
        }
    }

    bool searchElementByKey(typeOfKey k)
    {
        /* 
        Postcondition: trả về true nếu tồn tại phần tử có khóa k có trong tập động 
        và false nếu không có trong tập động.
        */
        for (int i = 1; i <= Dlist<typeOfElement, typeOfKey>::length(); i++)
        {
            if (Dlist<typeOfElement, typeOfKey>::findElement(i).key == k)
            {
                return true;
            }
            return false;
        }
    }

    item<typeOfElement, typeOfKey> maxKeyOfElements()
    {
        /*
        Precondition: tập động không rỗng.
        Postcondition: trả về phần tử có khóa lớn nhất trong tập động.
        */
        if (!isDsetEmpty())
        {
            typeOfKey maxKey = Dlist<typeOfElement, typeOfKey>::findElement(1).key;
            for (int i = 1; i <= Dlist<typeOfElement, typeOfKey>::length(); i++)
            {
                if (Dlist<typeOfElement, typeOfKey>::findElement(i).key > maxKey)
                {
                    maxKey = Dlist<typeOfElement, typeOfKey>::findElement(i).key;
                } 
            }

            // Tìm element[maxKey]
            for (int i = 1; i <= Dlist<typeOfElement, typeOfKey>::length(); i++)
            {
                if (Dlist<typeOfElement, typeOfKey>::findElement(i).key == maxKey)
                {
                    return Dlist<typeOfElement, typeOfKey>::fineElement(i);
                }   
            }
        }
    }

    item<typeOfElement, typeOfKey> minKeyOfElements()
    {
        /*
        Precondition: tập động không rỗng.
        Postcondition: trả về phần tử có khóa nhỏ nhất trong tập động.
        */
        if (!isDsetEmpty())
        {
            typeOfKey minKey = Dlist<typeOfElement, typeOfKey>::findElement(1).key;
            for (int i = 1; i <= Dlist<typeOfElement, typeOfKey>::length(); i++)
            {
                if (Dlist<typeOfElement, typeOfKey>::findElement(i).key < minKey)
                {
                    minKey = Dlist<typeOfElement, typeOfKey>::findElement(i).key;
                }
            }

            // Tìm element[minKey]
            for (int i = 1; i <= Dlist<typeOfElement, typeOfKey>::length(); i++)
            {
                if (Dlist<typeOfElement, typeOfKey>::findElement(i).key == minKey)
                {
                    return Dlist<typeOfElement, typeOfKey>::fineElement(i);
                }  
            }
        }
    }

    void inputKeyForElements()
    {
        if (!isDsetEmpty())
        {
            cout << "\n\n\t\t NHAP KHOA KEY CHO CAC PHAN TU CUA TAP HOP: \n";
            for (int i = 1; i <= Dlist<typeOfElement, typeOfKey>::length(); i++)
            {
                cout << "Nhap khoa key cua phan tu thu " << i << ": ";
                cin >> Dlist<typeOfElement, typeOfKey>::element[i - 1].key;
            }            
        }
        else
        {
            cout << "Tap khong co phan tu nao, vui long nhap cac phan tu cua tap" << endl;
        }
    }

    void outputKeyOfElements()
    {
        if (!isDsetEmpty())
        {
            cout << "\n\n\t\t XUAT KHOA KEY CUA CAC PHAN TU: \n";
            for (int i = 1; i <= Dlist<typeOfElement, typeOfKey>::length(); i++)
            {
                cout << Dlist<typeOfElement, typeOfKey>::findElement(i).item << "(" << Dlist<typeOfElement, typeOfKey>::findElement(i).key << ")" << " "; 
            }
            cout << endl;
            system("pause");
        }
        else
        {
            cout << "Tap khong co phan tu nao, vui long nhap cac phan tu cua tap" << endl;
        }
    }
};