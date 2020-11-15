#include "Dlist.cpp"



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

    void DsetInsert(const int &x)
    {
        // Postcondition: phần tử x trở thành thành viên của tập động.
        if (!searchElementByKey(x))
        // Phần tử x chưa tồn tại trong tập hợp.
        {
            append(x);
        }
        else
        {
            cout << "Phan tu da ton tai trong tap" << endl;
        }
    }

    void DsetDeleteElementByKey(int k)
    {
        // Postcondition: phần tử với khóa k không có trong tập động.
        for (int i = 1; i <= length(); i++)
        {
            if (findElement(i) == k)
            {
                deleteElement(i);
                break;
            }
        }
    }       

    bool searchElementByKey(int k)
    {
        /* 
        Postcondition: trả về true nếu tồn tại phần tử có khóa k có trong tập động 
        và false nếu không có trong tập động.
        */
        for (int i = 1; i <= length(); i++)
        {
            if (findElement(i) == k)
            {
                return true;
            }
            return false;
        }
    }

    int maxKeyOfElements()
    {
        /*
        Precondition: tập động không rỗng.
        Postcondition: trả về phần tử có khóa lớn nhất trong tập động.
        */
        if (!isDsetEmpty())
        {
            int maxKey = findElement(1);
            for (int i = 1; i <= length(); i++)
            {
                if (findElement(i) > maxKey)
                {
                    maxKey = findElement(i);
                } 
            }

            // Tìm element[maxKey]
            for (int i = 1; i <= length(); i++)
            {
                if (findElement(i) == maxKey)
                {
                    return findElement(i);
                }   
            }
        }
    }

    int minKeyOfElements()
    {
        /*
        Precondition: tập động không rỗng.
        Postcondition: trả về phần tử có khóa nhỏ nhất trong tập động.
        */
        if (!isDsetEmpty())
        {
            int minKey = findElement(1);
            for (int i = 1; i <= length(); i++)
            {
                if (findElement(i) < minKey)
                {
                    minKey = findElement(i);
                }
            }

            // Tìm element[minKey]
            for (int i = 1; i <= length(); i++)
            {
                if (findElement(i) == minKey)
                {
                    return findElement(i);
                }  
            }
        }
    }

    
};