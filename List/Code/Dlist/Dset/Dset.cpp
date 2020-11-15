#include "../Dlist.cpp"

class Dset: public Dlist
{
public:
    Dset(int m): Dlist(m)
    {
        // Constructor: khởi tạo tập rỗng, có thể chứa nhiều nhất là m phần tử.
    }

    bool isDsetEmpty()
    {
        // Kiểm tra xem tập có rỗng không.
        isDlistEmpty();
    }

    void DsetInsert(const item &x)
    {
        // Postcondition: phần tử x trở thành thành viên của tập động.
        if (!searchElementByKey(x.key))
        // Phần tử x chưa tồn tại trong tập hợp.
        {
            append(x);
        }
        else
        {
            cout << "Phan tu da ton tai trong tap" << endl;
        }
    }

    void DsetDeleteElementByKey(typeOfKey k)
    {
        // Postcondition: phần tử với khóa k không có trong tập động.
        for (int i = 1; i <= length(); i++)
        {
            if (findElement(i).key == k)
            {
                deleteElement(i);
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
        for (int i = 1; i <= length(); i++)
        {
            if (findElement(i).key == k)
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
            typeOfKey maxKey = findElement(1).key;
            for (int i = 1; i <= length(); i++)
            {
                if (findElement(i).key > maxKey)
                {
                    maxKey = findElement(i).key;
                } 
            }

            // Tìm element[maxKey]
            for (int i = 1; i <= length(); i++)
            {
                if (findElement(i).key == maxKey)
                {
                    return findElement(i);
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
            typeOfKey minKey = findElement(1).key;
            for (int i = 1; i <= length(); i++)
            {
                if (findElement(i).key < minKey)
                {
                    minKey = findElement(i).key;
                }
            }

            // Tìm element[minKey]
            for (int i = 1; i <= length(); i++)
            {
                if (findElement(i).key == minKey)
                {
                    return findElement(i);
                }  
            }
        }
    }

    void inputKeyForElements()
    {
        if (!isDsetEmpty())
        {
            cout << "\n\n\t\t NHAP KHOA KEY CHO CAC PHAN TU CUA TAP HOP: \n";
            for (int i = 1; i <= length(); i++)
            {
                typeOfKey key;
                cout << "Nhap khoa key cua phan tu thu " << i << ": ";
                cin >> key;
                setKeyOfElements(key, i);
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
            for (int i = 1; i <= length(); i++)
            {
                cout << findElement(i).item << "(" << findElement(i).key << ")" << " "; 
            }
            cout << endl;
        }
        else
        {
            cout << "Tap khong co phan tu nao, vui long nhap cac phan tu cua tap" << endl;
        }
    }
};