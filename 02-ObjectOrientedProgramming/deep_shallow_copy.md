# Default Copy Constructor (Shallow Copy)
If you do not explicitly define a copy constructor, the C++ compiler provides a default copy constructor that performs a shallow copy.
## Example of Default Shallow Copy
```cpp
class Shallow {
public:
    int *data;

    Shallow(int value) {
        data = new int;
        *data = value;
    }
};

int main() {
    Shallow obj1(10);
    Shallow obj2 = obj1; // Default copy constructor (shallow copy)

    // Both obj1.data and obj2.data point to the same memory
    *obj2.data = 20;

    // Now, obj1.data also reflects the change
    std::cout << *obj1.data; // Outputs: 20

    delete obj1.data; // Deleting data affects both obj1 and obj2
    return 0;
}
```
## Issues with Shallow Copy:
- Shared Resources: Both objects share the same dynamically allocated memory.
- Double Deletion: If both objects try to delete the same memory, it leads to undefined behavior.

# Implementing a Deep Copy
To perform a deep copy, you need to define your own copy constructor that allocates separate memory for the copied object and copies the actual data.
## Example of Deep Copy
```cpp
class Deep {
public:
    int *data;

    // Constructor
    Deep(int value) {
        data = new int;
        *data = value;
    }

    // Copy Constructor (Deep Copy)
    Deep(const Deep &other) {
        data = new int;          // Allocate new memory
        *data = *(other.data);   // Copy the value
    }

    // Destructor
    ~Deep() {
        delete data;
    }
};

int main() {
    Deep obj1(10);
    Deep obj2 = obj1; // Calls deep copy constructor

    *obj2.data = 20;

    std::cout << *obj1.data; // Outputs: 10
    std::cout << *obj2.data; // Outputs: 20

    // No double deletion issue since obj1 and obj2 have separate memory
    return 0;
}
```
## When to Use Deep Copy
Use a deep copy when your class manages resources that require ownership, such as:
- Dynamic Memory Allocation: If your class allocates memory using new, malloc, etc.
- File Handles or Network Connections: When your class manages resources like file descriptors, sockets, etc.
- Complex Data Structures: When your class contains complex members that require independent copies.


