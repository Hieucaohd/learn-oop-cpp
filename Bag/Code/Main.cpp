#include "Bag.cpp"

int main(int argc, char const *argv[])
{
    Bag B1;
    Bag B2;
    Bag B3;

    for (int i = 0; i < 10; i++)
    {
        B1.insert(i);
    }

    for (int i = 10; i < 20; i++)
    {
        B2.insert(i);
    }
    // B1.showElements();
    // B1 += B2;
    // B1.showElements();

    Bag B;
    B = B1 + B2;
    B.showElements();
    
    
    
    
    
    return 0;
}
