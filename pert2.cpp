#include <iostream>
using namespace std;

int main()
{
    int x;
    int *px;

    x = 12;
    cout << "Alamat x : " << &x << endl;
    cout << "Nilai x : " << x << endl;

    px = &x;

    cout << endl;
    cout << "Variabel px berisi alamat x, yaitu : " << px << endl;
    cout << "Nilai yg diacu variabel px adalah : " << *px << endl;
}