# Code Review Guide for 42 Piscine Object

This guide helps reviewers ensure submissions meet 42 School standards and project requirements.

## Review Checklist

### 1. Subject Compliance ⚖️

- [ ] **Read the subject.pdf** for this specific exercise
- [ ] All mandatory requirements implemented
- [ ] Bonus features (if any) clearly marked and working
- [ ] No forbidden functions or libraries used
- [ ] Follows exercise-specific constraints

**Common Issues:**
- Using STL when forbidden
- Missing required class members
- Incorrect output format

### 2. Compilation 🔨

- [ ] Compiles with `make` without errors
- [ ] Uses correct compilation flags: `-Wall -Wextra -Werror`
- [ ] C++98 standard compliance (unless specified otherwise)
- [ ] No compilation warnings
- [ ] Makefile follows 42 standards

**Test Commands:**
```bash
make
make re
make clean
make fclean
```

**Red Flags:**
- Warnings suppressed with pragmas
- Missing compilation flags
- Non-standard Makefile rules

### 3. Memory Management 💾

- [ ] **Run valgrind** on all test cases
- [ ] No memory leaks
- [ ] No invalid reads/writes
- [ ] Proper use of new/delete
- [ ] Array allocation uses delete[]

**Valgrind Command:**
```bash
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         ./program [test_args]
```

**Expected Output:**
```
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

**Red Flags:**
- "definitely lost" memory
- "invalid read" or "invalid write"
- "conditional jump depends on uninitialized value"

### 4. Orthodox Canonical Form 📋

When required, verify all four components:

- [ ] **Default Constructor**: Initializes all members
- [ ] **Copy Constructor**: Deep copy implementation
- [ ] **Assignment Operator**: Handles self-assignment, returns *this
- [ ] **Destructor**: Frees all resources

**Example Review:**
```cpp
// ❌ BAD: Shallow copy
ClassName::ClassName(ClassName const &src) {
    this->_ptr = src._ptr;  // Both point to same memory!
}

// ✅ GOOD: Deep copy
ClassName::ClassName(ClassName const &src) {
    this->_ptr = new Type(*src._ptr);
}

// ❌ BAD: No self-assignment check
ClassName &operator=(ClassName const &rhs) {
    delete this->_ptr;
    this->_ptr = new Type(*rhs._ptr);  // Crashes if this == &rhs
    return *this;
}

// ✅ GOOD: Self-assignment protection
ClassName &operator=(ClassName const &rhs) {
    if (this != &rhs) {
        delete this->_ptr;
        this->_ptr = new Type(*rhs._ptr);
    }
    return *this;
}
```

### 5. 42 School Norm 📐

#### File Organization
- [ ] Proper file naming (match class name)
- [ ] Header guards in all .hpp files
- [ ] Correct header comments with author info

#### Code Style
- [ ] Maximum 80 characters per line
- [ ] Maximum 25 lines per function (excluding comments)
- [ ] Maximum 5 functions per file
- [ ] Consistent indentation (tabs or spaces)
- [ ] No trailing whitespace
- [ ] One instruction per line

**Check Command:**
```bash
# Count lines in functions
grep -n "^{" filename.cpp  # Find function starts
grep -n "^}" filename.cpp  # Find function ends

# Check line length
awk 'length > 80' filename.cpp

# Check for trailing whitespace
grep -n " $" filename.cpp
```

#### Naming Conventions
- [ ] Classes: PascalCase (`MyClass`)
- [ ] Functions: camelCase (`myFunction`)
- [ ] Variables: camelCase (`myVariable`)
- [ ] Private members: underscore prefix (`_myMember`)
- [ ] Constants: UPPER_SNAKE_CASE (`MAX_SIZE`)

#### Forbidden
- [ ] No `using namespace` (except in .cpp files, carefully)
- [ ] No `friend` keyword (unless explicitly allowed)
- [ ] No global variables (unless required by subject)

### 6. Code Quality 💎

#### Error Handling
- [ ] Validates input parameters
- [ ] Handles edge cases (NULL, empty, extreme values)
- [ ] Appropriate error messages
- [ ] No silent failures

**Examples:**
```cpp
// ✅ GOOD: Input validation
void setAge(int age) {
    if (age < 0 || age > 150) {
        std::cerr << "Error: Invalid age" << std::endl;
        return;
    }
    this->_age = age;
}

// ❌ BAD: No validation
void setAge(int age) {
    this->_age = age;  // Accepts any value!
}
```

#### Encapsulation
- [ ] Private members properly encapsulated
- [ ] Getters marked `const`
- [ ] No unnecessary public members
- [ ] Proper use of const-correctness

#### Code Clarity
- [ ] Variable names are descriptive
- [ ] Functions have single responsibility
- [ ] No unnecessary complexity
- [ ] Comments explain WHY, not WHAT

### 7. Testing 🧪

#### Test Coverage
- [ ] Basic functionality works
- [ ] Edge cases tested
- [ ] Error cases handled
- [ ] No crashes or undefined behavior

**Standard Test Cases:**
```bash
# Test 1: Basic usage
./program normal_input

# Test 2: Empty input
./program ""

# Test 3: Invalid input
./program invalid

# Test 4: Boundary conditions
./program MAX_VALUE
./program MIN_VALUE

# Test 5: Multiple operations
./program test1 test2 test3
```

#### Output Verification
- [ ] Output matches subject exactly
- [ ] Correct newlines and spacing
- [ ] Error messages to stderr
- [ ] Normal output to stdout

### 8. Common Mistakes ⚠️

#### Memory Issues
```cpp
// ❌ Memory leak
char *str = new char[10];
// ... forgot to delete[]

// ❌ Double free
delete ptr;
delete ptr;  // Crash!

// ❌ Use after free
delete ptr;
ptr->method();  // Undefined behavior!

// ❌ Array delete mismatch
int *arr = new int[10];
delete arr;  // Should be delete[]
```

#### Logic Errors
```cpp
// ❌ Infinite loop
for (int i = 0; i < 10; i--) { }

// ❌ Off-by-one error
for (int i = 0; i <= array.size(); i++) { }

// ❌ Uninitialized variable
int result;
if (condition)
    result = 1;
// result used here - may be uninitialized!
```

#### Norm Violations
```cpp
// ❌ Using namespace
using namespace std;

// ❌ Line too long (>80 characters)
void myFunction(int param1, int param2, int param3, int param4, int param5) {

// ❌ Multiple statements per line
int a = 1; int b = 2; return a + b;
```

## Review Process

### Step 1: Initial Check (5 min)
1. Read the subject for this exercise
2. Verify all files are present
3. Check basic file structure
4. Quick scan for obvious issues

### Step 2: Compilation (5 min)
1. Run `make`
2. Check for warnings
3. Test `make re`, `make clean`, `make fclean`
4. Verify executable is created

### Step 3: Testing (10-15 min)
1. Run basic test cases
2. Test edge cases
3. Test error cases
4. Check output format

### Step 4: Memory Check (5-10 min)
1. Run valgrind with test cases
2. Verify no leaks
3. Check for invalid operations
4. Test with different scenarios

### Step 5: Code Review (15-20 min)
1. Check Orthodox Canonical Form
2. Verify 42 Norm compliance
3. Review code quality
4. Check for best practices

### Step 6: Subject Compliance (5-10 min)
1. Verify all requirements met
2. Check for forbidden items
3. Confirm output format
4. Test bonus features

### Step 7: Feedback (5 min)
1. List issues found
2. Suggest improvements
3. Highlight good practices
4. Approve or request changes

## Feedback Template

```markdown
## Code Review Feedback

### Summary
[Brief overview of the submission]

### Strengths ✅
- [What was done well]
- [Good practices observed]

### Issues Found ❌
1. **[Critical/Major/Minor]**: [Description]
   - Location: `file.cpp:line`
   - Issue: [What's wrong]
   - Fix: [How to fix it]

### Suggestions 💡
- [Improvement ideas]
- [Best practices to consider]

### Verdict
- [ ] Approved - Good work!
- [ ] Approved with minor suggestions
- [ ] Changes requested - Please fix issues and resubmit

### Memory Check
```
[Paste valgrind output]
```

### Test Results
- Basic functionality: ✅/❌
- Edge cases: ✅/❌
- Error handling: ✅/❌
- Memory leaks: ✅/❌
```

## Resources

- **42 Norm**: [Check with norminette if available]
- **Subject**: Always in `subject.pdf`
- **C++ Reference**: https://en.cppreference.com/
- **Valgrind**: https://valgrind.org/docs/manual/quick-start.html

## Tips for Reviewers

1. **Be constructive**: Focus on helping, not criticizing
2. **Be specific**: Point to exact lines and issues
3. **Explain why**: Don't just say "wrong", explain why it's wrong
4. **Suggest solutions**: Provide hints or examples
5. **Acknowledge good work**: Positive feedback is important
6. **Be thorough**: Check everything on the list
7. **Test yourself**: Don't just trust the code, run it
8. **Consult subject**: When in doubt, check subject.pdf

---

Remember: The goal is to help each other learn and improve! 🎯
