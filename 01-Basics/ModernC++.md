# Reference Type
## When they were introduced?
- Introduced in C++98
## What are reference types
- Defines an alternative name for a variable (an alias)
- It is created with the & operator during declaration
- Always needs an initializer!
- It can be used to modify a variable like pointer
- A reference is NOT a new variable; it is just another name
- They have both same memory address
## Why they were introduced?
- safer because they must always refer to valid objects.
## Difference between a pointer & a reference
- Reference : needs initializer, cannot be nullptr, boud to its referent, no storage required. 
- Pointer : no need for initializer, can be nullptr, can point other variables, has it's own storage.

# Name mangling 
- Name mangling in C++ refers to the process by which the compiler modifies the names of functions, variables, or other identifiers to encode additional information about them
## Why is Mangling Needed?
- In C (and similar languages), functions have unique names, so there's no ambiguity when linking them. However, C++ allows:
- Function overloading: Multiple functions can have the same name but different parameter types.
- Namespaces: Identifiers can be scoped inside different namespaces.
- g++ -o myprogram myprogram.cpp -Wl,-Map=myprogram.map

