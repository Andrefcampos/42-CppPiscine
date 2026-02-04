# Module 00 - Exercise 00: Example Class

## Description

This is an example exercise demonstrating the basic structure of a C++ class following 42 School standards. It showcases the Orthodox Canonical Form and proper class organization.

## Learning Objectives

- Understand class structure in C++
- Implement Orthodox Canonical Form
- Practice proper encapsulation
- Learn member function implementation

## Files

- `ClassName.hpp` - Header file with class declaration
- `ClassName.cpp` - Implementation file
- `main.cpp` - Test program
- `Makefile` - Build configuration

## Compilation

```bash
make
```

## Usage

```bash
./program_name
```

## Expected Output

The program demonstrates:
1. Default constructor
2. Parameterized constructor
3. Copy constructor
4. Assignment operator
5. Member functions
6. Destructor

## Key Concepts Demonstrated

### Orthodox Canonical Form
```cpp
class ClassName {
public:
    ClassName(void);                           // Default constructor
    ClassName(ClassName const &src);           // Copy constructor
    ClassName &operator=(ClassName const &rhs);// Assignment operator
    ~ClassName(void);                          // Destructor
};
```

### Encapsulation
- Private members prefixed with `_`
- Public getters and setters
- Controlled access to data

### Const-Correctness
- Getters marked as `const`
- Const reference parameters

## Testing

### Memory Check
```bash
valgrind --leak-check=full ./program_name
```

Expected: No memory leaks, no errors.

## 42 Norm Compliance

- ✅ Orthodox Canonical Form
- ✅ Private members with underscore
- ✅ Include guards
- ✅ Proper formatting
- ✅ Header comments

## Notes

This is a template/example. Actual exercises should be implemented according to the subject.pdf requirements.
