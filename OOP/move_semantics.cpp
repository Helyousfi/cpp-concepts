/*
What is a Move Constructor?
    In C++, a move constructor is a special constructor used to "move" resources from one object to another, 
    rather than copying them. This is particularly useful for optimizing performance by avoiding unnecessary 
    deep copies, especially for objects managing dynamic resources like memory, file handles, 
    or network connections.

Why Do We Need a Move Constructor?
    When you pass objects around in your program (like returning an object from a function or passing it 
    to a function), the default behavior involves copying the object, which can be expensive if the object 
    manages resources like large arrays or other dynamic memory.
*/