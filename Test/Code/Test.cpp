#include <iostream>
using namespace std;

int tong(const int &a,const int &b)
{
    int c = a + b;
    return c;
}

int main(int argc, char const *argv[])
{
    cout << tong(1, 2);
    system("pause");
    return 0;
}
