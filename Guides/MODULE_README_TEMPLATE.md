# Module README Template

Copy this template to each module directory and customize it.

---

# Module XX - [Module Name]

## Overview

Brief description of what this module covers and its learning objectives.

## Exercises

| Exercise | Name | Description | Status |
|----------|------|-------------|--------|
| ex00 | [Name] | [Brief description] | ⬜ Not started / 🟡 In progress / ✅ Complete |
| ex01 | [Name] | [Brief description] | ⬜ Not started / 🟡 In progress / ✅ Complete |
| ex02 | [Name] | [Brief description] | ⬜ Not started / 🟡 In progress / ✅ Complete |

## Key Concepts

- **Concept 1**: Explanation
- **Concept 2**: Explanation
- **Concept 3**: Explanation

## Compilation

Each exercise has its own Makefile:

```bash
cd exXX
make
./program_name [args]
```

## Common Issues

### Issue 1
**Problem**: Description of common issue
**Solution**: How to fix it

### Issue 2
**Problem**: Description of common issue
**Solution**: How to fix it

## Testing

Recommended test cases:

```bash
# Basic test
./program basic_input

# Edge case
./program edge_case

# Error case
./program invalid_input
```

## Memory Leak Check

```bash
valgrind --leak-check=full --show-leak-kinds=all ./program [args]
```

## Resources

- Subject: `subject.pdf` (pages XX-YY)
- Relevant C++ documentation:
  - [Link to concept 1]
  - [Link to concept 2]

## Notes

Any additional notes specific to this module.
