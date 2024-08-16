// 02_pointer_arithmetic.cpp
#include <iostream>

int main() {
    int arr[3] = {10, 20, 30};
    int* p = arr;

    std::cout << "Pointer p points to: " << *p << std::endl;
    p++; // Move the pointer to the next element in the array
    std::cout << "After incrementing, p points to: " << *p << std::endl;
    p--;
    std::cout << "After decrementing, p points to: " << *p << std::endl;

    return 0;
}
