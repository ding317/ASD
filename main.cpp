#include <iostream>

long long fibonacci(int n) {
    if (n <= 1) {
        return n;}
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);}
}

void printFibonacciBelow(long long limit, int index) {
    long long fib = fibonacci(index);
    if (fib >= limit) {
        return;
    }
    std::cout << fib << " ";
    printFibonacciBelow(limit, index + 1);
}

int main() {
    long long angka;
    std::cout << "Masukkan angka: ";
    if (!(std::cin >> angka)) {
        std::cerr << "Input tidak valid\n";
        return 1;
    }
    
    std::cout << "Bilangan Fibonacci sebelum " << angka << ": ";
    printFibonacciBelow(angka, 0);
    std::cout << "\n";
    
    return 0;
}