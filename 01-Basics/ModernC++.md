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


