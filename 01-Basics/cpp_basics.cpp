/*
 * Basic C++ Program
 * - Variables and Data Types
 * - Basic Input and Output
 * - Control Structures (if-else, loops)
 * - Functions
 * - Arrays
 * 
 */

#include <iostream>  // Required for input/output operations
using namespace std; // Allows the use of standard names without prefixing them with "std::"


// Function to demonstrate the use of functions
int add(int a, int b) {
    return a + b; // Returns the sum of a and b
}

int main() {
    // Variable declaration
    int x = 10;      // Integer variable
    float y = 20.5;  // Floating-point variable
    char z = 'A';    // Character variable
    bool isTrue = true; // Boolean variable

    // Printing the values of variables
    cout << "Integer: " << x << endl;
    cout << "Float: " << y << endl;
    cout << "Character: " << z << endl;
    cout << "Boolean: " << isTrue << endl;

    // Taking user input
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b; // Storing user input in variables a and b

    // Using the function
    int sum = add(a, b);
    cout << "The sum of " << a << " and " << b << " is: " << sum << endl;

    // Conditional statement
    if (sum > 10) {
        cout << "The sum is greater than 10." << endl;
    } else {
        cout << "The sum is 10 or less." << endl;
    }

    // Looping statement
    cout << "Counting from 1 to 5:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << i << " "; // Outputs numbers from 1 to 5
    }
    cout << endl;

    // Array declaration
    int arr[5] = {1, 2, 3, 4, 5};

    // Accessing array elements
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " "; // Outputs array elements
    }
    cout << endl;

    return 0; // Indicates that the program ended successfully
}

