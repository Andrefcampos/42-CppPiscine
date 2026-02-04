# Contributing to 42 Piscine Object

Thank you for your interest in contributing to this project! This document provides guidelines for contributing code that complies with 42 School standards.

## Table of Contents

1. [Code of Conduct](#code-of-conduct)
2. [42 School Norm](#42-school-norm)
3. [Pull Request Process](#pull-request-process)
4. [Coding Standards](#coding-standards)
5. [Testing Requirements](#testing-requirements)

## Code of Conduct

- Be respectful and constructive
- Focus on learning and improvement
- Help others understand concepts
- Follow 42 School's academic integrity policies

## 42 School Norm

All code **MUST** comply with the 42 School Norm. The subject.pdf is the ultimate authority.

### File Organization

```
ExerciseXX/
├── Makefile
├── ClassName.hpp
├── ClassName.cpp
└── main.cpp
```

### Naming Conventions

- **Classes**: PascalCase (`ClassName`, `MyClass`)
- **Files**: Match class name (`ClassName.hpp`, `ClassName.cpp`)
- **Variables**: camelCase (`myVariable`, `studentName`)
- **Private members**: Prefix with underscore (`_privateVar`, `_memberData`)
- **Constants**: UPPER_SNAKE_CASE (`MAX_VALUE`, `DEFAULT_SIZE`)

### Header Files

Every header file must have include guards:

```cpp
#ifndef CLASSNAME_HPP
# define CLASSNAME_HPP

// Class definition here

#endif
```

### Class Structure

Orthodox Canonical Form (when applicable):

```cpp
class ClassName {
private:
    // Private members with _ prefix
    int _privateVar;

public:
    // Default constructor
    ClassName(void);
    
    // Copy constructor
    ClassName(ClassName const &src);
    
    // Assignment operator
    ClassName &operator=(ClassName const &rhs);
    
    // Destructor
    ~ClassName(void);
    
    // Other public methods
    void publicMethod(void);
};
```

### Forbidden Items

Unless explicitly allowed in the subject:

- ❌ `using namespace`
- ❌ STL containers (vector, map, list, etc.)
- ❌ External libraries
- ❌ C-style casts (use C++ casts)
- ❌ `friend` keyword (unless required)
- ❌ Multiple inheritance (unless specifically allowed)

### Memory Management

- **No memory leaks**: Every `new` must have a corresponding `delete`
- **No dangling pointers**: Set pointers to NULL after deletion
- **Deep copy**: Implement proper copy constructors
- **Resource handling**: Use RAII principles

### Code Style

```cpp
// Maximum 80 characters per line
int function(int param)
{
    if (condition)
    {
        // Braces on new line
        // Consistent indentation (tabs or 4 spaces)
        return (value);  // Parentheses around return values
    }
    return (0);
}
```

## Pull Request Process

### Before Submitting

1. **Compile without errors**:
   ```bash
   make
   ```

2. **Check for memory leaks**:
   ```bash
   valgrind --leak-check=full ./your_program
   ```

3. **Verify norm compliance**:
   ```bash
   norminette *.cpp *.hpp  # If norminette is available
   ```

4. **Test edge cases**:
   - Empty inputs
   - Invalid parameters
   - Boundary conditions
   - Error handling

### PR Template

Your pull request should include:

- **Module and Exercise**: e.g., "Module00 - Ex00: Megaphone"
- **Description**: What does this exercise implement?
- **Testing**: How did you test it?
- **Compliance**: Confirm norm and subject compliance
- **Memory**: Valgrind results (no leaks)

### Review Process

PRs will be reviewed for:

1. ✅ Subject requirements compliance
2. ✅ 42 School Norm compliance
3. ✅ Code correctness and logic
4. ✅ Memory management (no leaks)
5. ✅ Error handling
6. ✅ Code clarity and maintainability

## Coding Standards

### Comments

```cpp
// Brief comments for clarity
// Don't over-comment obvious code
// Explain WHY, not WHAT

/*
** Multi-line comments
** for complex explanations
*/
```

### Error Handling

```cpp
// Check for errors and handle appropriately
if (ptr == NULL)
{
    std::cerr << "Error: allocation failed" << std::endl;
    return (ERROR_CODE);
}
```

### Output Format

- Use `std::cout` and `std::cerr` appropriately
- Follow subject's exact output format
- Include newlines where specified
- No extra spaces or formatting

## Testing Requirements

### Mandatory Tests

1. **Basic functionality**: Test main use case
2. **Edge cases**: Empty, NULL, extreme values
3. **Error cases**: Invalid input, allocation failures
4. **Memory**: No leaks under any condition

### Example Test Structure

```cpp
// Test 1: Basic functionality
// Test 2: Copy constructor
// Test 3: Assignment operator
// Test 4: Edge cases
// Test 5: Error handling
```

### Memory Testing

```bash
# Standard valgrind check
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         ./your_program

# Expected output: "All heap blocks were freed -- no leaks are possible"
```

## Common Issues and Solutions

### Compilation Errors

- **Unused variable**: Remove or comment out
- **Missing return**: Ensure all code paths return
- **Type mismatch**: Check implicit conversions

### Memory Leaks

- **Missing delete**: Every new needs delete
- **Exception safety**: Use RAII or try/catch
- **Array allocation**: Use `delete[]` for arrays

### Norm Violations

- **Line too long**: Break into multiple lines
- **Function too long**: Split into smaller functions
- **Too many functions**: Reorganize into multiple files

## Questions?

If you're unsure about:
- Subject requirements → Check `subject.pdf`
- Norm compliance → Ask a peer reviewer
- Code quality → Request a code review
- Concepts → Consult C++ documentation

## Resources

- [42 School Norm](https://github.com/42School/norminette) (if available)
- [C++ Reference](https://en.cppreference.com/)
- [ISO C++](https://isocpp.org/)
- Subject PDF (in repository)

---

Remember: **Clarity and correctness over cleverness!**
