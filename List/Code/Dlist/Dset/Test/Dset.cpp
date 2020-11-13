#include "Dlist.cpp"


template <class item>
class Dset: public Dlist<item>
{
public:
    Dset(int m): Dlist<item>(m)
    {
        // Constructor: khởi tạo tập rỗng, có thể chứa nhiều nhất là m phần tử.
    }

    bool isDsetEmpty()
    {
        // Kiểm tra xem tập có rỗng không.
        Dlist<item>::isDlistEmpty();
    }

    void DsetInsert(const item &x)
    {
        // Postcondition: phần tử x trở thành thành viên của tập động.
        if (!searchElementByKey(x.key))
        // Phần tử x chưa tồn tại trong tập hợp.
        {
            Dlist<item>::append(x);
        }
        else
        {
            cout << "Phan tu da ton tai trong tap" << endl;
        }
    }

    void DsetDeleteElementByKey(keyType k)
    {
        // Postcondition: phần tử với khóa k không có trong tập động.
        for (int i = 1; i <= Dlist<item>::length(); i++)
        {
            if (Dlist<item>::findElement(i).key == k)
            {
                Dlist<item>::deleteElement(i);
                break;
            }
        }
    }

    bool searchElementByKey(keyType k)
    {
        /* 
        Postcondition: trả về true nếu tồn tại phần tử có khóa k có trong tập động 
        và false nếu không có trong tập động.
        */
        for (int i = 1; i <= Dlist<item>::length(); i++)
        {
            if (Dlist<item>::findElement(i).key == k)
            {
                return true;
            }
            return false;
        }
    }

    item maxKeyOfElements()
    {
        /*
        Precondition: tập động không rỗng.
        Postcondition: trả về phần tử có khóa lớn nhất trong tập động.
        */
        if (!isDsetEmpty())
        {
            keyType maxKey = Dlist<item>::findElement(1).key;
            for (int i = 1; i <= Dlist<item>::length(); i++)
            {
                if (Dlist<item>::findElement(i).key > maxKey)
                {
                    maxKey = Dlist<item>::findElement(i).key;
                } 
            }

            // Tìm element[maxKey]
            for (int i = 1; i <= Dlist<item>::length(); i++)
            {
                if (Dlist<item>::findElement(i).key == maxKey)
                {
                    return Dlist<item>::fineElement(i);
                }   
            }
        }
    }

    item minKeyOfElements()
    {
        /*
        Precondition: tập động không rỗng.
        Postcondition: trả về phần tử có khóa nhỏ nhất trong tập động.
        */
        if (!isDsetEmpty())
        {
            keyType minKey = Dlist<item>::findElement(1).key;
            for (int i = 1; i <= Dlist<item>::length(); i++)
            {
                if (Dlist<item>::findElement(i).key < minKey)
                {
                    minKey = Dlist<item>::findElement(i).key;
                }
            }

            // Tìm element[minKey]
            for (int i = 1; i <= Dlist<item>::length(); i++)
            {
                if (Dlist<item>::findElement(i).key == minKey)
                {
                    return Dlist<item>::fineElement(i);
                }  
            }
        }
    }

    void setKeyForElements()
    {
        if (!isDsetEmpty())
        {
            cout << "\n\n\t\t NHAP KHOA KEY CHO CAC PHAN TU CUA TAP HOP: \n";
            for (int i = 1; i <= Dlist<item>::length(); i++)
            {
                cout << "Nhap khoa key cua phan tu thu " << i << ": ";
                cin >> Dlist<item>::findElement(i).key;
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
            for (int i = 1; i <= Dlist<item>::length(); i++)
            {
                cout << Dlist<item>::findElement(i) << "(" << Dlist<item>::findElement(i).key << ")" << " "; 
            }
            cout << endl;
        }
        else
        {
            cout << "Tap khong co phan tu nao, vui long nhap cac phan tu cua tap" << endl;
        }
    }
};