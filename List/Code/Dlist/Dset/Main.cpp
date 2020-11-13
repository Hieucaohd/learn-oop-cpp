#include "Dset.cpp"

int main(int argc, char const *argv[])
{
    system("cls");
    Dset<int, int> set1(100);
    set1.inputDlistElement(3);
    set1.outputDlistElement();
    set1.inputKeyForElements();
    set1.outputKeyOfElements();
    
    system("pause");
    return 0;
}
