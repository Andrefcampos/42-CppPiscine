#!/bin/bash

# 42 Piscine Object - Exercise Setup Script
# This script helps you quickly set up a new exercise from the template

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Print colored message
print_msg() {
    local color=$1
    local msg=$2
    echo -e "${color}${msg}${NC}"
}

# Print usage
usage() {
    cat << EOF
Usage: $0 <module> <exercise> <ClassName>

Creates a new exercise from the template with proper structure.

Arguments:
    module      - Module directory (e.g., Module00, Module01)
    exercise    - Exercise directory (e.g., ex00, ex01)
    ClassName   - Name of the main class (e.g., Megaphone, Fixed)

Example:
    $0 Module00 ex00 Megaphone

This will create:
    Module00/ex00/
        ├── Makefile
        ├── Megaphone.hpp
        ├── Megaphone.cpp
        └── main.cpp

EOF
    exit 1
}

# Check arguments
if [ $# -ne 3 ]; then
    print_msg "$RED" "❌ Error: Invalid number of arguments"
    echo ""
    usage
fi

MODULE=$1
EXERCISE=$2
CLASSNAME=$3

# Validate inputs
if [[ ! "$MODULE" =~ ^Module[0-9]{2}$ ]]; then
    print_msg "$RED" "❌ Error: Module must be in format 'ModuleXX' (e.g., Module00)"
    exit 1
fi

if [[ ! "$EXERCISE" =~ ^ex[0-9]{2}$ ]]; then
    print_msg "$RED" "❌ Error: Exercise must be in format 'exXX' (e.g., ex00)"
    exit 1
fi

if [[ -z "$CLASSNAME" ]]; then
    print_msg "$RED" "❌ Error: ClassName cannot be empty"
    exit 1
fi

# Check if template exists
TEMPLATE_DIR="templates/exercise_template"
if [ ! -d "$TEMPLATE_DIR" ]; then
    print_msg "$RED" "❌ Error: Template directory not found: $TEMPLATE_DIR"
    exit 1
fi

# Create target directory
TARGET_DIR="$MODULE/$EXERCISE"
print_msg "$BLUE" "📁 Creating directory: $TARGET_DIR"

if [ -d "$TARGET_DIR" ]; then
    print_msg "$YELLOW" "⚠️  Warning: Directory already exists: $TARGET_DIR"
    read -p "Overwrite? [y/N] " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        print_msg "$YELLOW" "❌ Cancelled"
        exit 0
    fi
    rm -rf "$TARGET_DIR"
fi

mkdir -p "$TARGET_DIR"

# Copy template files
print_msg "$BLUE" "📋 Copying template files..."
cp "$TEMPLATE_DIR"/* "$TARGET_DIR/"

# Navigate to target directory
cd "$TARGET_DIR"

# Rename files
print_msg "$BLUE" "✏️  Renaming files..."
mv ClassName.hpp "${CLASSNAME}.hpp"
mv ClassName.cpp "${CLASSNAME}.cpp"

# Update Makefile
print_msg "$BLUE" "⚙️  Updating Makefile..."
sed -i.bak "s/program_name/${EXERCISE}/g" Makefile
sed -i.bak "s/ClassName.cpp/${CLASSNAME}.cpp/g" Makefile
sed -i.bak "s/ClassName.hpp/${CLASSNAME}.hpp/g" Makefile
rm Makefile.bak 2>/dev/null || true

# Update source files
print_msg "$BLUE" "🔄 Updating source files..."
for file in *.cpp *.hpp; do
    if [ -f "$file" ]; then
        sed -i.bak "s/ClassName/${CLASSNAME}/g" "$file"
        sed -i.bak "s/CLASSNAME_HPP/${CLASSNAME^^}_HPP/g" "$file"
        rm "${file}.bak" 2>/dev/null || true
    fi
done

# Update header file name in comments
for file in *.cpp *.hpp; do
    if [ -f "$file" ]; then
        # Update the filename in the header comment
        sed -i.bak "s|/\*   ClassName\.|/*   ${CLASSNAME}.|g" "$file"
        rm "${file}.bak" 2>/dev/null || true
    fi
done

# Go back to original directory
cd - > /dev/null

# Print success message
print_msg "$GREEN" "✅ Exercise setup complete!"
echo ""
print_msg "$BLUE" "📍 Location: $TARGET_DIR"
echo ""
print_msg "$YELLOW" "Next steps:"
echo "  1. cd $TARGET_DIR"
echo "  2. Update header comments with your information"
echo "  3. Read the subject.pdf for this exercise"
echo "  4. Implement your solution"
echo "  5. make && ./${EXERCISE}"
echo "  6. Test with valgrind (if available)"
echo ""
print_msg "$GREEN" "Happy coding! 🚀"
