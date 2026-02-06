# 42 Piscine Object

[![C++](https://img.shields.io/badge/language-C%2B%2B-blue.svg)](https://isocpp.org/)
[![42 School](https://img.shields.io/badge/42-School-000000.svg)](https://42.fr/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

## 📚 About

This repository contains the **Piscine Object** project from 42 School. The Piscine Object is an intensive bootcamp designed to introduce students to Object-Oriented Programming (OOP) concepts and advanced C++ techniques.

The project focuses on:
- Object-Oriented Programming principles (Encapsulation, Inheritance, Polymorphism)
- C++ language specifics and best practices
- Design patterns and software architecture
- Memory management and resource handling
- Code organization and modularity

## 📋 Project Structure

The project is organized into modules, each focusing on specific OOP concepts:

```
.
├── Module00/          # Object Relationships (Composition, Aggregation, Inheritance, Association)
├── Module01/          # Advanced OOP concepts
├── Module02/          # Design patterns
├── Module03/          # Advanced C++ features
├── Module04/          # Practical applications
├── Module05/          # Final projects
├── Guides/            # Documentation and guides
│   ├── SETUP.md                   # Complete setup instructions
│   ├── SUBJECT_README.md          # About the subject PDF
│   ├── CODE_REVIEW_GUIDE.md       # Code review checklist
│   ├── IMPLEMENTATION_SUMMARY.md  # Implementation notes
│   ├── DOCUMENTATION_INDEX.md     # Documentation index
│   ├── PROGRESS.md                # Progress tracking
│   └── MODULE_README_TEMPLATE.md  # Template for module READMEs
├── Templates/         # Exercise templates
└── en.subject.pdf     # Official project subject (source of truth)
```

> **Note**: The `en.subject.pdf` is the single source of truth and overrides any assumptions or interpretations.

## 🚀 Getting Started

> **📖 New to this project?** Check out the [Setup Guide](Guides/SETUP.md) for detailed instructions!

### Prerequisites

- C++ compiler with C++98 standard support or higher (g++, clang++)
- Make
- Git
- Valgrind (recommended for memory leak detection)

### Quick Start

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Andrefcampos/42-CppPiscine.git
   cd 42-CppPiscine
   ```

2. **Understand the subject** (see [Guides/SUBJECT_README.md](Guides/SUBJECT_README.md))

3. **Navigate to a module**:
   ```bash
   cd Module00/ex00
   ```

4. **Build and test**:
   ```bash
   make
   ./relationship
   ```

For complete setup instructions, see [Guides/SETUP.md](Guides/SETUP.md).

### Building

Each module contains its own `Makefile`. To build a specific module:

```bash
cd ModuleXX/exYY
make
```

### Running

After building, execute the generated binary:

```bash
./program_name
```

### Cleaning

To clean object files and executables:

```bash
make clean    # Remove object files
make fclean   # Remove object files and executables
make re       # Rebuild from scratch
```

## 📐 42 School Norms

All code in this repository must comply with the **42 School Norm**, which includes:

### Allowed
- Standard C++ library (within project constraints)
- C++98 standard (unless specified otherwise)
- Proper class design with constructors/destructors
- Operator overloading when appropriate

### Forbidden
- Using namespace (except in specific cases)
- STL containers (unless explicitly allowed)
- External libraries (unless specified)
- Memory leaks
- Forbidden functions (varies by exercise)

### Code Style
- Maximum 80 characters per line
- Maximum 25 lines per function
- Maximum 5 functions per file
- Proper indentation (tabs or spaces, be consistent)
- No trailing whitespace
- One instruction per line

## 🔍 Code Review Guidelines

> **📝 See [Guides/CODE_REVIEW_GUIDE.md](Guides/CODE_REVIEW_GUIDE.md) for detailed checklist**

When submitting a pull request:

1. **Ensure compliance** with the subject requirements
2. **Test thoroughly** - No crashes, no memory leaks
3. **Follow the Norm** - Code style and restrictions
4. **Document your code** - Clear, concise comments
5. **Include test cases** - Demonstrate functionality

## 🛠️ Development

### Memory Leak Detection

Use valgrind to check for memory leaks:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./your_program
```

### Compilation

Standard compilation flags for 42 projects:

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program_name
```

## 📝 Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code review process and coding standards.

## 📖 Documentation

All guides and documentation are organized in the `Guides/` directory:

- **[Setup Guide](Guides/SETUP.md)** - Complete setup instructions
- **[Subject README](Guides/SUBJECT_README.md)** - Understanding the subject PDF
- **[Code Review Guide](Guides/CODE_REVIEW_GUIDE.md)** - Code review checklist
- **[Implementation Summary](Guides/IMPLEMENTATION_SUMMARY.md)** - Implementation notes
- **[Documentation Index](Guides/DOCUMENTATION_INDEX.md)** - Full documentation index
- **[Progress Tracking](Guides/PROGRESS.md)** - Track your progress

## ❓ FAQ

Check out [FAQ.md](FAQ.md) for answers to common questions about:
- Getting started
- Coding standards
- Compilation and testing
- Common issues and solutions
- Best practices

## 🤝 Acknowledgments

- 42 School for the project subject
- Fellow students and peer reviewers
- The C++ community

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Note**: This is an educational project. Solutions are provided for learning purposes only. Please respect 42 School's academic integrity policies.