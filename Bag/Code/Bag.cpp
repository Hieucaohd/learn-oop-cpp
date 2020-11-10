#pragma once
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class Bag
{
public:
    Bag()
    {
        size = 0;
    }
    // Postcondition: một lớp Bag rỗng được khởi tạo
    
    ~Bag()
    {
    }
    // dis-constructor

    // THE VARIABLES:
    static const int MAX = 50; 
    // The maximum of the numbers of elements in a bag

    typedef int item; 
    // Type of the element in a bag. Here, it is integer. You can change int to char, string,... or a class, struct is defined

    // THE FUNCTIONS:
    void showElements();
    // Hàm hiển thị các phần tử trong túi B

    int sum() const
    {
        return size;
    }
    // Postcondititon: trả về tổng số phần tử trong túi

    void insert(const item &element); 
    // Hàm thực hiện thêm element vào túi B
    // Precondition: B.sum() < MAX
    // Postcondition: một bản sao của element được thêm vào túi B

    void remove(const item &element);
    // Hàm loại một phần tử khỏi túi B
    // Postcondition: một phần tử là bản sao của element bị loại khỏi túi B nếu trong B có chứa element, nếu trong B không chứ element thì B không bị thay đổi

    int occurr(const item &element);
    // Postcondition: trả về số lần xuất hiện của element trong búi B

    void operator += (const Bag &B1);
    // Hàm thực hiện cộng túi B1 vào túi B, B += B1
    // Precondition: B.sum() + B1.sum() < MAX
    // Postcondition: tất cả các phần tử của túi B1 được thêm vào túi B

    friend Bag & operator + (const Bag &B1, const Bag &B2);
    // Precondition: B1.sum() + B2.sum() < MAX 
    // Postcondition: trả về túi B là hợp của túi B1 và B2

private:
    item data[MAX]; 
    // array store the elements of the bag

    int size; 
    // size of the bag
};

void Bag::showElements()
{
    cout << "\n\n\t\t THE ELEMENTS OF BAG: ";
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    
}

void Bag::insert(const item &element)
{
    if (size < MAX)
    {
        data[size] = element;
        size ++;
    }
    else
    {
        cout << "Bag was full" << endl;
    }
}

void Bag::remove(const item &element)
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == element)
        {
            data[i] = data[size - 1];
            size--;
            break;
        }
    }

}

int Bag::occurr(const item &element)
{
    int countElement = 0;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == element)
        {
            countElement++;
        }
        
    }
    return countElement;
}

void Bag::operator += (const Bag &B1)
{
    if ((this->sum() + B1.sum()) <= MAX)
    {
        for (int i = 0; i < B1.sum(); i++)
        {
            data[size] = B1.data[i];
            size++;
        }
           
    }
    
}

Bag & operator + (const Bag &B1, const Bag &B2)
{
    Bag B;
    if (B1.sum() + B2.sum() <= Bag::MAX)
    {
        B += B1;
        B += B2;
        
    }
    else
    {
        cout << "Can not enforce B1 + B2" << endl;
    }

    return B;
    
}





