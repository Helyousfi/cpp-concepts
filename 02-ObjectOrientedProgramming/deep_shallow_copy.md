#Example of Deep Copy
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


