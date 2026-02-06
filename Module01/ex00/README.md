# Module 01 - Exercise 00: Putting it into practice

## Description

This exercise demonstrates different types of object relationships in Object-Oriented Programming: Composition, Aggregation, Inheritance, and Association. The focus is on understanding how objects interact and share data.

## Learning Objectives

- Understand Composition (strong ownership)
- Implement Aggregation (weak ownership)
- Practice Inheritance (IS-A relationship)
- Learn Association (collaboration)

## Files

```
ex00/
  inc/                      # Header files
    Position.hpp           # Coordinates structure (x, y, z)
    Statistic.hpp          # Stats structure (level, exp)
    Worker.hpp             # Main class with all relationships
    Tool.hpp               # Abstract base class for tools
    Shovel.hpp             # Concrete tool implementation
    Hammer.hpp             # Concrete tool implementation
    Workshop.hpp           # Workshop for association
  src/                      # Implementation files
    Position.cpp
    Statistic.cpp
    Worker.cpp
    Tool.cpp
    Shovel.cpp
    Hammer.cpp
    Workshop.cpp
    main.cpp               # Comprehensive test suite
  Makefile                  # Build system
  README.md                 # This file
```

### Class Relationships

**Worker** (central class):
- **Composition**: Contains `Position` and `Statistic`
- **Aggregation**: Can have multiple `Tool*` (added/removed dynamically)
- **Association**: Can register to multiple `Workshop*`

**Tool** hierarchy:
- Abstract base class with pure virtual `use()`
- `Shovel` and `Hammer` inherit from `Tool`
- Polymorphic behavior through virtual functions

**Workshop**:
- Manages list of `Worker*` (association)
- Workers can join/leave freely
- Can be in multiple workshops simultaneously

## Compilation

```bash
make        # Compile the project
make re     # Recompile from scratch
make clean  # Remove object files
make fclean # Remove object files and executable
```

### Manual Compilation
```bash
c++ -Wall -Wextra -Werror -std=c++98 -I inc src/*.cpp -o relationship
```

## Usage

```bash
./relationship    # Run all tests
make run          # Compile and run
make valgrind     # Run with memory leak detection
```

## Program Output

The program runs 5 comprehensive tests:

1. **Test 1: Composition**
   - Creates Worker with Position and Statistic
   - Demonstrates same lifecycle (destroyed together)

2. **Test 2: Aggregation**
   - Creates Shovel independently
   - Transfers between Workers
   - Shovel survives Worker destruction

3. **Test 3: Inheritance**
   - Uses polymorphism (Tool* pointing to Shovel/Hammer)
   - Multiple tools per Worker
   - Template method `GetTool<T>()` for type-specific retrieval

4. **Test 4: Association**
   - Workers register to multiple Workshops
   - Workshops execute work days
   - Workers can leave freely
   - Independent lifecycles

5. **Test 5: Complete Scenario**
   - All relationships working together
   - Simulates real-world construction site

### Debug Output Features
- ✅ Constructor calls with messages
- ✅ Destructor calls with messages
- ✅ Method execution tracking
- ✅ Object lifecycle visualization
- ✅ Relationship behavior demonstration

## Key Concepts Demonstrated

### 1. Composition (Strong Ownership)
```cpp
class Worker {
private:
    Position position;    // Created/destroyed with Worker
    Statistic statistic;  // Part of Worker
};
```
**Characteristics:**
- Objects are members (not pointers)
- Same lifecycle as container
- Cannot exist independently

### 2. Aggregation (Weak Ownership)
```cpp
class Worker {
private:
    Tool* tool;  // Can be given/taken away
public:
    void takeTool(Tool* t);
    Tool* releaseTool();
};
```
**Characteristics:**
- Objects are pointers
- Independent lifecycle
- Can be transferred between objects
- Container doesn't delete them

### 3. Inheritance (IS-A Relationship)
```cpp
class Tool {
public:
    virtual void use() = 0;  // Pure virtual
    virtual ~Tool() {}
};

class Shovel : public Tool {
public:
    void use() override;
};
```
**Characteristics:**
- Abstract base class
- Polymorphism
- Code reuse

### 4. Association (Collaboration)
```cpp
class Workshop {
private:
    std::vector<Worker*> workers;  // Registered workers
public:
    void registerWorker(Worker* w);
    void executeWorkDay();
};
```
**Characteristics:**
- Loose coupling
- Neither owns the other
- Collaboration without dependency

## Testing

### Memory Check
```bash
valgrind --leak-check=full ./program_name
```

Expected: No memory leaks, no errors.

## 42 Standards Compliance

- ✅ C++98 standard
- ✅ Compilation flags: -Wall -Wextra -Werror
- ✅ Output in all constructors/destructors/methods
- ✅ Proper class organization
- ✅ Makefile with required rules

## Implementation Details

### Memory Management

**Composition** - Automatic:
```cpp
Worker worker;  // Position and Statistic created automatically
// Destroyed automatically when worker goes out of scope
```

**Aggregation** - Manual:
```cpp
Tool* shovel = new Shovel();  // Independent creation
worker.takeTool(shovel);       // Worker references it
worker.removeTool(shovel);     // Remove reference
delete shovel;                 // Manual cleanup
```

**Association** - Reference only:
```cpp
Workshop* workshop = new Workshop();
workshop->registerWorker(&worker);  // Just a reference
workshop->releaseWorker(&worker);   // Remove reference
// Worker not affected by workshop deletion
```

### Polymorphism Usage

```cpp
// Store different types in same container
std::vector<Tool*> tools;
tools.push_back(new Shovel());
tools.push_back(new Hammer());

// Use polymorphically
for (size_t i = 0; i < tools.size(); i++) {
    tools[i]->use();  // Calls correct override
}

// Type-specific retrieval
Shovel* shovel = worker.GetTool<Shovel>();
if (shovel) {
    shovel->use();
}
```

### C++98 Compatibility Notes

- ✅ Uses `size_t` instead of `auto`
- ✅ Manual loops instead of range-based for
- ✅ `NULL` instead of `nullptr`
- ✅ Template implementation in header file
- ✅ Standard containers (`std::vector`)
- ✅ `dynamic_cast` for runtime type checking

## Important Notes

- **Orthodox Canonical Form is NOT required** for this module
- Focus is on **object relationships**, not canonical form
- Debug output is **mandatory** in all functions for evaluation
- Each relationship type must be correctly implemented
- Tools must not be deleted when Worker is destroyed (Aggregation)
- Use `removeTool()` before deleting tools to avoid dangling pointers

## Evaluation Points

### Questions to Prepare
1. What is the difference between Composition and Aggregation?
2. When would you use each type of relationship?
3. Why is the Tool destructor virtual?
4. How does `dynamic_cast` work?
5. What happens if you don't remove a tool before deleting it?
6. Can a Worker be in multiple Workshops? Why?
7. What is polymorphism and how is it demonstrated here?

### Common Pitfalls

❌ **Double deletion**:
```cpp
Tool* tool = new Shovel();
worker.takeTool(tool);
delete tool;           // Tool still in worker's vector!
delete worker;         // Crash - dangling pointer
```

✅ **Correct approach**:
```cpp
Tool* tool = new Shovel();
worker.takeTool(tool);
worker.removeTool(tool);  // Remove from vector first
delete tool;              // Now safe to delete
```

## References

- [C++ Relationships](https://www.geeksforgeeks.org/association-composition-aggregation-java/)
- [Polymorphism in C++](https://www.learncpp.com/cpp-tutorial/virtual-functions/)
- [Dynamic Cast](https://en.cppreference.com/w/cpp/language/dynamic_cast)

This is a template/example. Actual exercises should be implemented according to the subject.pdf requirements.
