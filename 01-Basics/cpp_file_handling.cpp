// file_handling.cpp
// File Handling in C++

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // File streams: ifstream for reading, ofstream for writing, fstream for both
    string filename = "example.txt";
    
    // Writing to a file
    ofstream outFile(filename);
    if (!outFile) { // Error handling
        cerr << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile << "Hello, World!" << endl; // Writing to the file
    outFile << "This is a test file for file handling in C++." << endl;
    outFile.close(); // Close the file after writing

    // Reading from a file
    ifstream inFile(filename);
    if (!inFile) { // Error handling
        cerr << "Error opening file for reading!" << endl;
        return 1;
    }

    string line;
    cout << "Contents of the file:" << endl;
    while (getline(inFile, line)) { // Reading line by line
        cout << line << endl;
    }
    inFile.close(); // Close the file after reading

    // Binary files vs. Text files
    // Writing to a binary file
    const char* binaryFilename = "example.bin";
    ofstream binFile(binaryFilename, ios::binary);
    if (!binFile) {
        cerr << "Error opening binary file for writing!" << endl;
        return 1;
    }

    int numbers[] = {1, 2, 3, 4, 5};
    binFile.write(reinterpret_cast<char*>(numbers), sizeof(numbers)); // Write binary data
    binFile.close();

    // Reading from a binary file
    ifstream binInFile(binaryFilename, ios::binary);
    if (!binInFile) {
        cerr << "Error opening binary file for reading!" << endl;
        return 1;
    }

    int readNumbers[5];
    binInFile.read(reinterpret_cast<char*>(readNumbers), sizeof(readNumbers)); // Read binary data
    cout << "Contents of the binary file:" << endl;
    for (int num : readNumbers) {
        cout << num << " ";
    }
    cout << endl;
    binInFile.close();

    return 0;
}
