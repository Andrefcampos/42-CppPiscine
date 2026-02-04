# Frequently Asked Questions (FAQ)

Common questions and answers for 42 Piscine Object.

## General Questions

### Q: What is Piscine Object?

**A:** Piscine Object is an intensive bootcamp from 42 School focused on Object-Oriented Programming (OOP) in C++. It teaches fundamental OOP concepts including classes, inheritance, polymorphism, and more.

### Q: What's the difference between this and CPP modules?

**A:** While both cover C++ and OOP, Piscine Object is typically a shorter, more intensive introduction, while CPP modules (00-09) go deeper into specific C++ features and advanced concepts.

### Q: What C++ standard should I use?

**A:** Unless specified otherwise in the subject, use **C++98**. This is the default standard for 42 School projects.

## Getting Started

### Q: Where do I find the subject.pdf?

**A:** Download it from your 42 School intranet. Place it in the root directory of this repository. See [SUBJECT_README.md](SUBJECT_README.md) for details.

### Q: How do I set up a new exercise?

**A:** Use the setup script:
```bash
./setup_exercise.sh Module00 ex00 YourClassName
```

Or manually copy from `templates/exercise_template/`.

### Q: What tools do I need?

**A:** At minimum: C++ compiler (g++/clang++), Make, and Git. Valgrind is highly recommended for memory leak detection. See [SETUP.md](SETUP.md) for details.

## Coding Standards

### Q: What is the 42 School Norm?

**A:** The 42 Norm is a set of coding standards including:
- Max 80 characters per line
- Max 25 lines per function
- Specific naming conventions
- Forbidden constructs (e.g., `using namespace`)

See [CONTRIBUTING.md](CONTRIBUTING.md) for complete details.

### Q: Can I use the STL (Standard Template Library)?

**A:** It depends on the exercise. Check the subject.pdf for each specific exercise. Generally, basic STL like `std::string`, `std::cout` are allowed, but containers like `std::vector` may be forbidden in early modules.

### Q: What is Orthodox Canonical Form?

**A:** Also known as the "Coplien form," it's a standard class structure with four essential components:
1. Default constructor
2. Copy constructor
3. Assignment operator
4. Destructor

See examples in the templates.

### Q: Should I use `using namespace std;`?

**A:** **No!** This is forbidden by 42 School Norm. Always use the `std::` prefix explicitly.

```cpp
// ❌ DON'T
using namespace std;
cout << "Hello" << endl;

// ✅ DO
std::cout << "Hello" << std::endl;
```

## Compilation and Testing

### Q: How do I compile my code?

**A:** Use the provided Makefile:
```bash
make          # Compile
make clean    # Remove object files
make fclean   # Remove all generated files
make re       # Rebuild from scratch
```

### Q: What compilation flags should I use?

**A:** Always use: `-Wall -Wextra -Werror -std=c++98`

These are mandatory for 42 School projects.

### Q: My code compiles but crashes. What should I do?

**A:** 
1. Use a debugger: `gdb ./program`
2. Check for NULL pointers
3. Verify array bounds
4. Run with valgrind for memory issues

### Q: How do I check for memory leaks?

**A:** Use valgrind:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./program [args]
```

Expected output: "All heap blocks were freed -- no leaks are possible"

### Q: Valgrind isn't available on macOS. What can I use?

**A:** Use LeakSanitizer:
```bash
clang++ -g -fsanitize=address your_code.cpp -o program
./program
```

## Common Issues

### Q: I get "undefined reference to ClassName::method()"

**A:** Make sure:
1. The method is declared in the .hpp file
2. The method is implemented in the .cpp file
3. The .cpp file is listed in the Makefile SRCS

### Q: I get compilation errors about private members

**A:** You're trying to access private members from outside the class. Use public getters/setters or friend functions (if allowed).

### Q: My copy constructor causes a crash

**A:** You likely have a shallow copy problem. Implement a deep copy:

```cpp
// ❌ Shallow copy
this->_ptr = src._ptr;  // Both point to same memory!

// ✅ Deep copy
this->_ptr = new Type(*src._ptr);  // New memory allocated
```

### Q: How do I handle self-assignment in operator=?

**A:** Always check for self-assignment:

```cpp
ClassName &operator=(ClassName const &rhs) {
    if (this != &rhs) {  // Self-assignment check
        // Perform assignment
    }
    return *this;
}
```

### Q: My Makefile doesn't recompile when I change headers

**A:** Add header dependencies:

```makefile
%.o: %.cpp $(HEADERS)
    $(CXX) $(CXXFLAGS) -c $< -o $@
```

## Exercise-Specific Questions

### Q: What if the exercise description is unclear?

**A:** 
1. Re-read the subject.pdf carefully
2. Check the expected output format
3. Look at test cases if provided
4. Ask peers (but don't copy code!)
5. During evaluation, ask your evaluator

### Q: Can I add extra features not mentioned in the subject?

**A:** Stick to the requirements. Extra features might violate constraints or complicate grading. Focus on doing what's asked, correctly.

### Q: Should I implement bonus features?

**A:** Only after completing all mandatory features perfectly. Bonuses are optional and should not compromise the mandatory part.

## Code Review and Submission

### Q: How do I know if my code is ready for review?

**A:** Check all items in the review checklist:
- Compiles without errors/warnings
- Tested with multiple cases
- No memory leaks
- Follows 42 Norm
- Matches subject requirements

See [CODE_REVIEW_GUIDE.md](CODE_REVIEW_GUIDE.md).

### Q: What happens if I fail a review?

**A:** You can fix the issues and resubmit. Use feedback to improve. It's part of the learning process!

### Q: Can I use code from other students?

**A:** **No!** This violates academic integrity. You must write your own code. You can discuss concepts but not share implementations.

## GitHub and Version Control

### Q: How should I organize my branches?

**A:** Create a branch per module or exercise:
```bash
git checkout -b module00-ex00
# Work on exercise
git commit -m "Complete Module00-ex00"
git push origin module00-ex00
```

### Q: Should I commit build artifacts?

**A:** **No!** The `.gitignore` file excludes `.o` files and executables. Only commit source code, headers, and Makefiles.

### Q: Can I update code after merging to main?

**A:** Yes, but create a new branch for fixes:
```bash
git checkout -b fix-module00-ex00
# Make fixes
git commit -m "Fix memory leak in Module00-ex00"
```

## Best Practices

### Q: How should I structure my code?

**A:** 
- One class per file pair (.hpp + .cpp)
- Header for declarations, .cpp for implementations
- main.cpp for testing
- Keep functions small and focused

### Q: How much should I comment my code?

**A:** 
- Explain WHY, not WHAT
- Don't over-comment obvious code
- Add comments for complex logic
- Document class purpose and member functions

### Q: What's the best way to learn OOP?

**A:**
1. Read the concepts in the subject
2. Implement the exercises yourself
3. Test thoroughly
4. Review others' code (but don't copy!)
5. Reflect on what you learned

## Debugging

### Q: How do I use GDB?

**A:** Basic GDB workflow:
```bash
# Compile with debug symbols
g++ -g your_code.cpp -o program

# Run with GDB
gdb ./program

# GDB commands
(gdb) run [args]        # Run program
(gdb) break main        # Set breakpoint
(gdb) next              # Step over
(gdb) step              # Step into
(gdb) print variable    # Print value
(gdb) backtrace         # Show call stack
```

### Q: How do I find where my segfault happens?

**A:** Run with GDB:
```bash
gdb ./program
(gdb) run [args]
# Program crashes
(gdb) backtrace
# Shows where crash occurred
```

## Performance

### Q: Should I worry about performance?

**A:** Focus on **correctness first**, then clarity, then performance. For Piscine Object, correctness and norm compliance are most important.

### Q: Is it okay if my code is slow?

**A:** As long as it works correctly and doesn't have obvious inefficiencies (like copying in loops unnecessarily), it's fine. Don't optimize prematurely.

## Resources

### Q: Where can I learn more about C++?

**A:** 
- [cppreference.com](https://en.cppreference.com/) - Comprehensive reference
- [learncpp.com](https://www.learncpp.com/) - Tutorial for beginners
- [isocpp.org](https://isocpp.org/) - Official C++ site

### Q: Are there example solutions available?

**A:** While examples exist online, **do not copy them**. This violates academic integrity and defeats the purpose of learning. Use them only as references for concepts, not implementations.

## Still Have Questions?

1. **Check the subject.pdf** - It's the ultimate authority
2. **Read the documentation** in this repository
3. **Ask peers** - But don't share code
4. **Consult 42 resources** - Slack, intranet, etc.
5. **Experiment** - Sometimes the best way to learn is to try!

---

**Remember**: The goal is to learn, not just to finish. Take your time to understand each concept! 🎯
