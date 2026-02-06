# 42 Piscine Object - Templates

This directory contains templates to help you get started with new exercises quickly and ensure consistency across the project.

## Exercise Template

The `exercise_template/` directory contains a complete C++ exercise template following 42 School norms.

### Files Included

- **Makefile**: Standard Makefile with proper flags and rules
- **ClassName.hpp**: Header file template with Orthodox Canonical Form
- **ClassName.cpp**: Implementation file template
- **main.cpp**: Main file with basic tests

### How to Use

1. **Copy the template** to your exercise directory:
   ```bash
   cp -r templates/exercise_template ModuleXX/exYY
   cd ModuleXX/exYY
   ```

2. **Rename the files**:
   ```bash
   mv ClassName.hpp YourClassName.hpp
   mv ClassName.cpp YourClassName.cpp
   ```

3. **Update the Makefile**:
   - Change `NAME` to your program name
   - Update `SRCS` with your source files
   - Update `HEADERS` with your header files

4. **Replace placeholders**:
   - Replace `ClassName` with your actual class name
   - Replace `[your login]`, `[your email]` with your info
   - Update the date/time in the header comments

5. **Implement your solution**:
   - Add your class members and methods
   - Implement the required functionality
   - Add proper tests in main.cpp

### Template Features

#### Orthodox Canonical Form
Every class template includes:
- Default constructor
- Copy constructor
- Assignment operator overload
- Destructor

#### Proper Structure
- Include guards in headers
- Private members with underscore prefix
- Const-correct getters
- Proper encapsulation

#### 42 Norm Compliant
- Proper header comments
- Correct indentation
- Standard compilation flags
- Clean code organization

## Module README Template

The `MODULE_README_TEMPLATE.md` provides a structure for documenting each module.

### How to Use

1. Copy to module directory:
   ```bash
   cp MODULE_README_TEMPLATE.md ModuleXX/README.md
   ```

2. Customize:
   - Fill in module number and name
   - List all exercises
   - Document key concepts
   - Add specific notes

## Quick Start Script

You can create a script to automate the setup:

```bash
#!/bin/bash
# setup_exercise.sh - Quick exercise setup

if [ $# -ne 3 ]; then
    echo "Usage: $0 <module> <exercise> <ClassName>"
    echo "Example: $0 Module00 ex00 Megaphone"
    exit 1
fi

MODULE=$1
EXERCISE=$2
CLASSNAME=$3

TARGET_DIR="$MODULE/$EXERCISE"

# Create directory
mkdir -p "$TARGET_DIR"

# Copy template
cp -r templates/exercise_template/* "$TARGET_DIR/"

# Rename files
cd "$TARGET_DIR"
mv ClassName.hpp "${CLASSNAME}.hpp"
mv ClassName.cpp "${CLASSNAME}.cpp"

# Update Makefile
sed -i "s/program_name/${EXERCISE}/g" Makefile
sed -i "s/ClassName/${CLASSNAME}/g" Makefile

# Update source files
sed -i "s/ClassName/${CLASSNAME}/g" *.cpp *.hpp

echo "✅ Exercise setup complete: $TARGET_DIR"
echo "Next steps:"
echo "  1. cd $TARGET_DIR"
echo "  2. Update header comments with your info"
echo "  3. Implement your solution"
echo "  4. make && ./program_name"
```

## Tips

- **Always start with the template** to ensure consistency
- **Update header comments** with current date and your information
- **Read the subject first** before modifying the template
- **Test incrementally** as you implement features
- **Use valgrind** to check for memory leaks

## Customization

Feel free to customize these templates based on your specific needs, but always ensure:
- 42 School Norm compliance
- Orthodox Canonical Form (when required)
- Proper error handling
- Clean compilation with `-Wall -Wextra -Werror`

---

Happy coding! 🚀
