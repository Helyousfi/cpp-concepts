// 01_basics_of_pointers.cpp
#include <iostream>

int main() {
    int a = 10;
    int* p = &a; // Pointer p holds the address of variable a

    std::cout << "Value of a: " << a << std::endl;
    std::cout << "Address of a: " << &a << std::endl;
    std::cout << "Value of p (Address of a): " << p << std::endl;
    std::cout << "Value pointed to by p: " << *p << std::endl; // Dereferencing the pointer

    return 0;
}
