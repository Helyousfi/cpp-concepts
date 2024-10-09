# Introduction to Object-Oriented Programming (OOP) in C++

## What is OOP?
Object-Oriented Programming (OOP) is a programming paradigm that is based on the concept of "objects". Objects are instances of classes, which encapsulate data (attributes) and functions (methods) that operate on that data. OOP aims to provide a more intuitive way of organizing and structuring code, making it easier to maintain, reuse, and extend.

### Four Core Concepts of OOP:
1. **Encapsulation**: Bundling of data and methods that manipulate the data into a single unit (class).
2. **Abstraction**: Hiding the internal implementation and only exposing the functionality.
3. **Inheritance**: The ability to create new classes from existing classes to reuse and extend functionality.
4. **Polymorphism**: The ability to use the same interface for different data types or classes.

---

## Class and Object in C++

A **class** is a blueprint for creating objects. An **object** is an instance of a class.

### Syntax:
```cpp
class ClassName {
public:
    // Attributes (data members)
    int attribute;

    // Methods (member functions)
    void display() {
        std::cout << "Attribute value: " << attribute << std::endl;
    }
};

int main() {
    ClassName obj;      // Creating an object
    obj.attribute = 5;  // Accessing attribute
    obj.display();      // Calling method
    return 0;
}
```
### Explanation:
- ClassName: Defines the class.
- obj: An object of type ClassName.
- attribute: A public attribute of the class.
- display(): A method that prints the value of the attribute.
