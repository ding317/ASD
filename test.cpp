#include<iostream>
using namespace std;

struct ayam
{
    int stok;

};
void kurang(ayam* a, int jumlah)
{

    a->stok = a->stok - jumlah;
    cout << a->stok << endl;
}

int main ()
{
    ayam Ayam;
    Ayam.stok = 234;
    kurang(&Ayam, 10);
    return 0;
}

