# Setup Guide - 42 Piscine Object

This guide will help you get started with the 42 Piscine Object project.

## Prerequisites

### Required Software

1. **C++ Compiler**
   ```bash
   # On Ubuntu/Debian
   sudo apt-get update
   sudo apt-get install build-essential g++
   
   # On macOS
   xcode-select --install
   ```

2. **Make**
   ```bash
   # Usually comes with build-essential
   make --version
   ```

3. **Git**
   ```bash
   # On Ubuntu/Debian
   sudo apt-get install git
   
   # On macOS (with Homebrew)
   brew install git
   ```

### Recommended Tools

4. **Valgrind** (for memory leak detection)
   ```bash
   # On Ubuntu/Debian
   sudo apt-get install valgrind
   
   # On macOS
   # Note: Valgrind has limited macOS support
   # Consider using LeakSanitizer instead:
   # Compile with: -fsanitize=address
   ```

5. **Norminette** (if available from 42)
   ```bash
   # Follow 42 School instructions
   pip3 install norminette
   ```

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/Andrefcampos/42-CppPiscine.git
cd 42-CppPiscine
```

### 2. Read the Documentation

Before starting any exercise:

1. **Read `subject.pdf`** - The single source of truth
2. **Read `README.md`** - Project overview
3. **Read `CONTRIBUTING.md`** - Coding standards
4. **Read `CODE_REVIEW_GUIDE.md`** - Review guidelines

### 3. Set Up Your First Exercise

#### Option A: Using the Setup Script (Recommended)

```bash
./setup_exercise.sh Module00 ex00 Megaphone
cd Module00/ex00
```

#### Option B: Manual Setup

```bash
# Create directory
mkdir -p Module00/ex00
cd Module00/ex00

# Copy template
cp -r ../../templates/exercise_template/* .

# Rename files
mv ClassName.hpp YourClassName.hpp
mv ClassName.cpp YourClassName.cpp

# Edit files to replace ClassName with your class name
```

### 4. Implement Your Solution

1. **Read the exercise requirements** in subject.pdf
2. **Edit the files** to implement your solution
3. **Update the Makefile** if needed (add/remove source files)
4. **Update header comments** with your information

### 5. Compile and Test

```bash
# Compile
make

# Run
./program_name [arguments]

# Check for memory leaks (if valgrind is available)
valgrind --leak-check=full ./program_name [arguments]

# Clean up
make fclean
```

## Project Structure

```
42-CppPiscine/
├── README.md                   # Main project documentation
├── CONTRIBUTING.md             # Coding standards and guidelines
├── CODE_REVIEW_GUIDE.md        # Guide for reviewers
├── SETUP.md                    # This file
├── MODULE_README_TEMPLATE.md   # Template for module READMEs
├── setup_exercise.sh           # Exercise setup script
├── subject.pdf                 # Project subject (add this file!)
├── .gitignore                  # Git ignore rules
│
├── .github/                    # GitHub configuration
│   ├── workflows/              # GitHub Actions
│   │   ├── cpp-quality.yml     # C++ quality checks
│   │   ├── pr-review.yml       # PR review automation
│   │   └── documentation.yml   # Documentation checks
│   ├── ISSUE_TEMPLATE/         # Issue templates
│   └── pull_request_template.md
│
├── templates/                  # Exercise templates
│   ├── README.md               # Template documentation
│   └── exercise_template/      # C++ exercise template
│       ├── Makefile
│       ├── ClassName.hpp
│       ├── ClassName.cpp
│       └── main.cpp
│
└── ModuleXX/                   # Module directories
    ├── README.md               # Module documentation
    └── exYY/                   # Exercise directories
        ├── README.md           # Exercise documentation
        ├── Makefile
        ├── *.hpp
        ├── *.cpp
        └── main.cpp
```

## Workflow

### Daily Workflow

1. **Choose an exercise** from the subject
2. **Set up the exercise** using the script
3. **Read the requirements** carefully
4. **Implement the solution**
5. **Test thoroughly**
6. **Check for memory leaks**
7. **Verify norm compliance**
8. **Commit your work**

### Git Workflow

```bash
# Create a feature branch
git checkout -b module00-ex00

# Make your changes
# ... work on exercise ...

# Stage and commit
git add Module00/ex00/
git commit -m "Add Module00-ex00: Exercise name"

# Push to GitHub
git push origin module00-ex00

# Create a Pull Request on GitHub
```

## Testing Your Code

### Compilation Test

```bash
# Must compile without errors
make

# Must compile with all warnings
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

### Functionality Test

Create test cases for:
- Basic functionality
- Edge cases (empty input, NULL, boundaries)
- Error cases (invalid input)
- Multiple operations

Example test script:
```bash
#!/bin/bash

echo "Test 1: Basic functionality"
./program arg1 arg2

echo "Test 2: Empty input"
./program ""

echo "Test 3: Edge case"
./program extreme_value

echo "Test 4: Error handling"
./program invalid_input
```

### Memory Test

```bash
# Test all scenarios with valgrind
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         ./program [args]

# Expected output:
# All heap blocks were freed -- no leaks are possible
# ERROR SUMMARY: 0 errors from 0 contexts
```

## Common Commands

### Compilation
```bash
make            # Compile the project
make clean      # Remove object files
make fclean     # Remove object files and executable
make re         # Rebuild from scratch
```

### Testing
```bash
# Basic test
./program

# With arguments
./program arg1 arg2

# Memory check
valgrind --leak-check=full ./program

# Norm check (if norminette available)
norminette *.cpp *.hpp
```

### Git
```bash
git status                    # Check status
git diff                      # See changes
git add .                     # Stage all changes
git commit -m "message"       # Commit changes
git push origin branch-name   # Push to GitHub
```

## Troubleshooting

### Compilation Errors

**Problem**: "undefined reference to..."
```
Solution: Make sure all .cpp files are listed in Makefile SRCS
```

**Problem**: "error: ... was not declared in this scope"
```
Solution: Check #include statements and namespace usage
```

### Runtime Errors

**Problem**: Segmentation fault
```
Solution: 
1. Check for NULL pointer dereferences
2. Check array bounds
3. Run with valgrind for details
```

**Problem**: Memory leaks
```
Solution:
1. Ensure every 'new' has a 'delete'
2. Use 'delete[]' for arrays
3. Implement proper destructors
```

### Norm Violations

**Problem**: "Line too long"
```
Solution: Break line into multiple lines (max 80 chars)
```

**Problem**: "using namespace std"
```
Solution: Don't use 'using namespace', use std:: prefix
```

## Resources

### Documentation
- [C++ Reference](https://en.cppreference.com/)
- [ISO C++](https://isocpp.org/)
- [Learn C++](https://www.learncpp.com/)

### Tools
- [Valgrind Quick Start](https://valgrind.org/docs/manual/quick-start.html)
- [GDB Tutorial](https://www.gdbtutorial.com/)
- [Makefile Tutorial](https://makefiletutorial.com/)

### 42 School
- Subject PDF (in repository)
- 42 Intra
- Peer evaluations

## Tips for Success

1. **Read the subject carefully** - Every word matters
2. **Start early** - Don't wait until the deadline
3. **Test incrementally** - Don't write everything at once
4. **Use valgrind** - Catch memory issues early
5. **Follow the Norm** - It will save you time later
6. **Ask for peer reviews** - Fresh eyes catch mistakes
7. **Keep it simple** - Clear code is better than clever code
8. **Comment your code** - Explain WHY, not WHAT
9. **Backup your work** - Commit and push regularly
10. **Take breaks** - Your brain needs rest too!

## Getting Help

- **Stuck on an exercise?** Read the subject again
- **Compilation error?** Check the error message carefully
- **Memory leak?** Use valgrind with --track-origins=yes
- **Norm violation?** Run norminette and fix each issue
- **Still stuck?** Ask a peer for review

## Next Steps

1. ✅ Complete setup
2. 📖 Read subject.pdf
3. 🎯 Choose Module00 - ex00
4. 💻 Implement solution
5. 🧪 Test thoroughly
6. 🔍 Review code
7. 📤 Submit for review
8. 🎉 Repeat for next exercise!

---

**Remember**: The goal is to learn OOP concepts, not just complete exercises!

Good luck with your Piscine Object journey! 🚀
