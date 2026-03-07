#include <iostream>

float fpb(float a, float b){
    if (b == 0){
        return a;
    }
    else {
    return fpb(b, a - (float (a/b) * b)); // akan mengereturn nilai ke fungsi fpb dengan parameter b dan sisa pembagian a dengan b
    }                                     // kemudian akan di cek  di fungsi fpb apakah b sama dengan 0 atau tidak, jika b sama dengan 0 maka akan mengembalikan nilai a sebagai hasil FPB,
                                          // jika tidak maka akan terus memanggil fungsi fpb dengan parameter yang baru sampai b menjadi 0
}

int main(){
    std :: cout << "===Mencari FPB===" << std :: endl;
    float a, b;
    std :: cout << "Masukkan angka pertama: ";
    std :: cin >> a;
    std :: cout << "Masukkan angka kedua: ";
    std :: cin >> b;
    float hasil = fpb(a, b); // memangil fungsi fpb dengan parameter a dan b, kemudian menyimpan hasilnya ke dalam variabel hasil
    std :: cout << "FPB dari " << a << " dan " << b << " adalah: " << hasil << std :: endl;
    return 0;
}
