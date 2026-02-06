# Module 01 - Object Relationships

## Overview

Module 01 explores the fundamental relationships between objects in Object-Oriented Programming. This module focuses on understanding how objects interact, share data, and collaborate through four main relationship types: Composition, Aggregation, Inheritance, and Association.

## Learning Objectives

- Understand **Composition**: Strong ownership (HAS-A relationship with same lifecycle)
- Implement **Aggregation**: Weak ownership (objects can be shared and transferred)
- Practice **Inheritance**: IS-A relationship with polymorphism
- Master **Association**: Collaboration without ownership
- Learn to choose the appropriate relationship for each scenario
- Understand object lifecycle management in different contexts

## Exercises

| Exercise | Name | Description | Status |
|----------|------|-------------|--------|
| ex00 | Putting it into practice | Implements all 4 object relationships | ✅ Complete |

## Project Structure

```
Module01/
  ex00/
    inc/              # Header files
    src/              # Implementation files
    Makefile          # Build configuration
    README.md         # Exercise documentation
  README.md           # Module overview
  en.subject.pdf      # Subject requirements
```

## Key Concepts

### 1. Composition (Strong Ownership)
**"Part-of" relationship** - Component cannot exist without the container

```cpp
class Worker {
private:
    Position coordonnee;  // Created and destroyed with Worker
    Statistic stat;       // Integral part of Worker
};
```

**Key Points:**
- Members are objects (not pointers)
- Same lifecycle as container
- Strong coupling

### 2. Aggregation (Weak Ownership)
**"Has-a" relationship** - Object can exist independently

```cpp
class Worker {
private:
    std::vector<Tool*> tools;  // Can be given/taken away
public:
    void takeTool(Tool* tool);
    void removeTool(Tool* tool);
};
```

**Key Points:**
- Members are pointers
- Independent lifecycle
- Can be shared/transferred
- Container doesn't delete them

### 3. Inheritance (IS-A Relationship)
**Hierarchical relationship** - Derived class is a specialized version of base class

```cpp
class Tool {
public:
    virtual void use() = 0;  // Pure virtual
    virtual ~Tool() {}
};

class Shovel : public Tool {
public:
    void use() override;  // Must implement
};
```

**Key Points:**
- Code reuse through inheritance
- Polymorphism via virtual functions
- Abstract classes define interfaces
- `dynamic_cast` for safe type checking

### 4. Association (Collaboration)
**"Uses-a" relationship** - Objects collaborate but neither owns the other

```cpp
class Workshop {
private:
    std::vector<Worker*> workers;  // References, not ownership
public:
    void registerWorker(Worker* w);
    void releaseWorker(Worker* w);
};
```

**Key Points:**
- Bidirectional relationship possible
- Loose coupling
- Both can exist independently
- No ownership implications

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

After completing Module 01:
- Understand the basics of OOP in C++
- Be comfortable with Orthodox Canonical Form
- Know how to manage memory properly
- Ready to tackle more complex OOP concepts in Module 01

---

**Remember**: The goal is to understand OOP concepts, not just complete exercises!
