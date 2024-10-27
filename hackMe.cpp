#include <iostream>
#include <string>

using namespace std;

void softwareAccess() {
    cout << "Hello! Hope you're having a fantastic day!" << endl;

    // Password check
    string password = "ab5&";
    string userInput;
    cout << "Enter the password to access the program: ";
    cin >> userInput;

    if (userInput == password) {
        cout << "Access granted!" << endl;
    } else {
        cout << "Access denied." << endl;
    }
}

int main() {
    softwareAccess();
    return 0;
}
