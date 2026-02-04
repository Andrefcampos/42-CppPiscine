# Module 00 - Introduction to Object-Oriented Programming

## Overview

Module 00 introduces the fundamental concepts of Object-Oriented Programming in C++. This module covers the basics of classes, encapsulation, and the importance of proper resource management.

## Learning Objectives

- Understand the difference between procedural and object-oriented programming
- Learn how to define and use classes in C++
- Master the Orthodox Canonical Form
- Understand encapsulation and data hiding
- Learn proper memory management with constructors and destructors

## Exercises

| Exercise | Name | Description | Status |
|----------|------|-------------|--------|
| ex00 | Example Exercise | Demonstrates basic class structure | ✅ Example |

> **Note**: This is a template module. Actual exercises should be implemented according to the subject.pdf.

## Key Concepts

### Classes and Objects
- **Class**: A blueprint for creating objects (user-defined data type)
- **Object**: An instance of a class
- **Member variables**: Data stored in an object
- **Member functions**: Functions that operate on object data

### Encapsulation
- **Private members**: Hidden from outside access (prefix with `_`)
- **Public members**: Accessible interface
- **Getters/Setters**: Controlled access to private data

### Orthodox Canonical Form
The standard form that every C++ class should implement:
1. **Default Constructor**: Initializes an object
2. **Copy Constructor**: Creates a copy of an object
3. **Assignment Operator**: Assigns one object to another
4. **Destructor**: Cleans up resources when object is destroyed

## Compilation

Each exercise has its own Makefile. Navigate to the exercise directory and run:

```bash
cd ex00
make
./program_name [args]
```

### Standard Compilation Flags
```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

## Common Issues

### Issue 1: Shallow vs Deep Copy
**Problem**: Default copy constructor does shallow copy, which can cause issues with dynamic memory.

**Example:**
```cpp
// ❌ BAD: Shallow copy (default behavior)
ClassName obj2 = obj1;  // Both share same pointer!

// ✅ GOOD: Implement deep copy in copy constructor
ClassName::ClassName(ClassName const &src) {
    this->_data = new int(*src._data);  // Create new memory
}
```

### Issue 2: Memory Leaks
**Problem**: Forgetting to delete dynamically allocated memory.

**Solution**: Always pair `new` with `delete`, and `new[]` with `delete[]`.

```cpp
// ❌ BAD
ClassName::ClassName() {
    this->_ptr = new int(42);
    // No delete in destructor - memory leak!
}

// ✅ GOOD
ClassName::~ClassName() {
    delete this->_ptr;  // Clean up in destructor
}
```

### Issue 3: Self-Assignment
**Problem**: Assignment operator doesn't handle `obj = obj`.

**Solution**: Always check for self-assignment.

```cpp
ClassName &ClassName::operator=(ClassName const &rhs) {
    if (this != &rhs) {  // Check self-assignment
        // Perform assignment
    }
    return *this;
}
```

## Testing

### Basic Tests
```bash
# Compile
make

# Test basic functionality
./program

# Check for memory leaks
valgrind --leak-check=full ./program

# Clean up
make fclean
```

### Recommended Test Cases
1. **Default construction**: Create object with default constructor
2. **Copy construction**: Create copy of an object
3. **Assignment**: Assign one object to another
4. **Self-assignment**: Test `obj = obj`
5. **Destruction**: Verify proper cleanup

## Memory Leak Check

Always test with valgrind:

```bash
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         ./program [args]
```

**Expected output:**
```
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

## Resources

### Required Reading
- Subject: `subject.pdf`
- C++ Documentation: https://en.cppreference.com/

### Topics to Study
- Classes and Objects
- Constructors and Destructors
- The `this` pointer
- Operator Overloading
- Const-correctness
- Memory Management

### Helpful Examples
```cpp
// Basic class structure
class MyClass {
private:
    int _value;

public:
    MyClass(void);                           // Constructor
    MyClass(MyClass const &src);             // Copy constructor
    MyClass &operator=(MyClass const &rhs);  // Assignment
    ~MyClass(void);                          // Destructor
    
    int getValue(void) const;                // Getter
    void setValue(int val);                  // Setter
};
```

## 42 Norm Checklist

Before submitting:
- [ ] All files properly named
- [ ] Header guards in all .hpp files
- [ ] Orthodox Canonical Form implemented
- [ ] Private members use underscore prefix
- [ ] Maximum 80 characters per line
- [ ] No memory leaks
- [ ] Code compiles with `-Wall -Wextra -Werror`
- [ ] Follows subject.pdf requirements

## Tips

1. **Start simple**: Implement basic functionality first
2. **Test incrementally**: Don't wait until everything is done
3. **Use valgrind early**: Catch memory issues immediately
4. **Read the subject carefully**: Every detail matters
5. **Follow the Norm**: It's not just a suggestion
6. **Ask for help**: Peer reviews are valuable

## Next Steps

After completing Module 00:
- Understand the basics of OOP in C++
- Be comfortable with Orthodox Canonical Form
- Know how to manage memory properly
- Ready to tackle more complex OOP concepts in Module 01

---

**Remember**: The goal is to understand OOP concepts, not just complete exercises!
