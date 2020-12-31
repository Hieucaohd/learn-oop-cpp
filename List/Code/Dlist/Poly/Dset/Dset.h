#pragma once
#include "../Dlist/Dlist.h"

class Dset: public CDlist
{
public:
    Dset(int m): CDlist(m)
    /* Constructor: khởi tạo tập rỗng, có thể chứa nhiều nhất là m phần tử.
	 * */

    bool isDsetEmpty();
    /* Kiểm tra xem tập có rỗng không.
	 * */

    void DsetAppend(const item &x)
    {
        // Postcondition: phần tử x trở thành thành viên của tập động.
        if (!searchElementByKey(x.key))
        // Phần tử x chưa tồn tại trong tập hợp.
        {
            append(x); // them phan tu x vao cuoi tap.
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

    item maxKeyOfDset()
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

    item minKeyOfDset()
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

    void inputKeyForDset()
    {
        /*
        Precondition: tap khong rong.
        Postcondition: key cua cac phan tu trong tap duoc nhap vao.
        */
        if (!isDsetEmpty())
        {
            cout << "\n\n\t\t NHAP KHOA KEY CHO CAC PHAN TU CUA TAP HOP: \n";
            for (int i = 1; i <= length(); i++)
            {
                typeOfKey key;
                cout << "Nhap khoa key cua phan tu thu " << i << ": ";
                cin >> key;
                setKeyOfElement(key, i);
            }            
        }
        else
        {
            cout << "Tap khong co phan tu nao, vui long nhap cac phan tu cua tap" << endl;
        }
    }

    void outputKeyOfDset()
    {
        /*
        Precondition: tap khong rong.
        Postcondition: xuat ra man hinh cac phan_tu(key).
        */
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

    /*
    Doi voi tap da duoc sap xep.
    Cac key duoc sap xep theo thu tu tu be den lon.
    Phan tu co key be nhat duoc xep o vi tri dau tien trong tap.
    */

    item minKeyOfDsetSorted()
    {
        /*
        Precondition: tap khong rong.
        Postcondition: tra ve phan tu co key be nhat trong tap.
        */
        if (!isDsetEmpty())
        // Neu tap khong rong.
        {
            return findElement(1);
        }
        else
        {
            cout << "Tap rong." << endl;
        }
    }

    item maxKeyOfDsetSorted()
    {
        /*
        Precondition: tap khong rong.
        Postcondition: tra ve phan tu co key lon nhat trong tap.
        */
        if (!isDsetEmpty())
        // Neu tap khong rong.
        {
            return findElement(length());
        }
        else
        {
            cout << "Tap rong." << endl;
        }
    }

    void DsetSortedInsert(const item &x)
    {
        /*
        Precondition: 
        Postcondition: phan tu x duoc them vao vi tri thich hop trong tap,
        tap van trong trang thai duoc sap xep.
        */
        int i = 1;
        while(i <= length())
        {
            if (x.key < findElement(i).key)
            {
                insert(x, i);
                break;
            }
            else if (x.key == findElement(i).key)
            {
                break;
            }
            i++;
        }

        if (i > length())
        {
            append(x);
        }
    }

    void DsetSortedDeleteElementByKey(typeOfKey key)
    {
        /*
        Precondition: tap khong rong.
        Postcondition: phan tu co key bi loai ra khoi tap.
        */
        if (!isDsetEmpty())
        // Neu tap khong rong.
        {
            for (int i = 1; i <= length(); i++)
            {
                if (findElement(i).key == key)
                {
                    deleteElement(i);
                    break;
                }
                else if (findElement(i).key > key)
                // Neu phan tu khong co trong tap.
                {
                    cout << "Phan tu khong co trong tap." << endl;
                    break;
                }
            }
        }
    }

    bool searchElementByKeyInDsetSorted(typeOfKey key)
    {
        /*
        Precondition: tap khong rong;
        Postcondition: tra ve true neu tim thay phan tu,
        tra ve false neu khong tim thay phan tu.
        */
        int bottom, top, mid;
        bottom = 1;
        top = length();
        while(bottom <= top)
        {
            mid = (top + bottom) / 2;
            if (key == findElement(mid).key)
            {
                return true;
            }
            else if (key > findElement(mid).key)
            {
                bottom = mid + 1;
            }
            else
            {
                top = mid - 1;
            }
        }

        return false;
    }

    bool searchElementByKeyInDsetSortedUseRecursive(typeOfKey key, int bottom, int top)
    {
        if (bottom > top)
        {
            return false;
        }
        int mid = (bottom + top) / 2;
        if (key == findElement(mid).key)
        {
            return true;
        }
        else if (key > findElement(mid).key)
        {
            searchElementByKeyInDsetSortedUseRecursive(key, mid + 1, top);
        }
        else
        {
            searchElementByKeyInDsetSortedUseRecursive(key, bottom, mid - 1);
        }
    }
}; // end end end
