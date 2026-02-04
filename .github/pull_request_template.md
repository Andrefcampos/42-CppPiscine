## Module and Exercise

**Module**: Module XX
**Exercise**: Exercise YY - [Exercise Name]

## Description

Brief description of what this PR implements or fixes.

## Changes Made

- [ ] Implemented [class/feature]
- [ ] Fixed [bug/issue]
- [ ] Updated [documentation]
- [ ] Other: [describe]

## Subject Compliance

- [ ] Follows all requirements from `subject.pdf`
- [ ] Uses only allowed functions/libraries
- [ ] Implements mandatory features
- [ ] Bonus features (if any): [list]

## 42 School Norm

- [ ] Code follows 42 School Norm
- [ ] No forbidden functions (`using namespace`, etc.)
- [ ] Proper file naming and organization
- [ ] Orthodox Canonical Form (when required)
- [ ] Maximum 80 characters per line
- [ ] Maximum 25 lines per function
- [ ] No trailing whitespace

## Compilation

```bash
# Compilation command used
make

# Result
✅ Compiles without errors or warnings
```

## Testing

### Basic Functionality
```bash
# Test case 1
./program arg1 arg2
# Output: [expected output]

# Test case 2
./program edge_case
# Output: [expected output]
```

### Memory Check
```bash
valgrind --leak-check=full ./program [args]
```

**Result**:
- [ ] No memory leaks
- [ ] No invalid memory access
- [ ] All heap blocks freed

<details>
<summary>Valgrind Output</summary>

```
[Paste full valgrind output here]
```

</details>

### Edge Cases Tested

- [ ] Empty input
- [ ] NULL pointers
- [ ] Invalid parameters
- [ ] Boundary conditions
- [ ] Error handling

## Code Quality

- [ ] Code is clear and readable
- [ ] Appropriate comments added
- [ ] No unnecessary complexity
- [ ] Efficient implementation
- [ ] Proper error messages

## Checklist

Before requesting review:

- [ ] Code compiles successfully
- [ ] All tests pass
- [ ] No memory leaks (valgrind clean)
- [ ] Follows subject requirements
- [ ] Complies with 42 Norm
- [ ] README updated (if needed)

## Additional Notes

[Any additional information, questions, or concerns for reviewers]

---

**Reviewer Guidelines**: Please verify:
1. Subject.pdf compliance
2. 42 School Norm adherence
3. No memory leaks
4. Code correctness and clarity
5. Proper error handling
