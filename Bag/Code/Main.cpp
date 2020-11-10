#include "Bag.cpp"

int main(int argc, char const *argv[])
{
    //system("cls");
    Bag<int> B1;
    Bag<int> B2;
    for (int i = 0; i < 10; i++)
    {
        B1.insert(i);
    }

    for (int i = 10; i < 20; i++)
    {
        B2.insert(i);
    }

    B1.showElements();
    B2.showElements();
    
    
    
    
    return 0;
}
