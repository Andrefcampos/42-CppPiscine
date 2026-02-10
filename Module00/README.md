# Module 00 - Encapsulation

## Overview
This module introduces the fundamental concept of **Encapsulation** in Object-Oriented Programming (OOP).

### Key Concepts
- **Object**: concept that represents a "thing"
- **Instance**: concrete entity of an object
- **Attributes**: internal variables of an instance
- **Methods**: ways to communicate with an instance
- **Encapsulation**: access control to attributes and methods
  - **Private**: accessible only by the class itself (and friends)
  - **Public**: accessible from anywhere

---

## Exercises

### [Exercise 00: Divide and Conquer](ex00/)
Banking system with proper encapsulation.

**Objectives:**
- Refactor code without encapsulation
- Implement banking account system
- Apply 5% fee on deposits
- Control loans based on liquidity

**Compile and run:**
```bash
cd ex00
make
./bank
```

**Requirements:**
- ✅ Bank receives 5% of each deposit
- ✅ Accounts with unique IDs
- ✅ Private attributes
- ✅ Bank manages accounts
- ✅ Loans limited by liquidity
- ✅ Const getters by reference

---

### [Exercise 01: I don't know what I'm doing!](ex01/)
ASCII graph system with points represented by Vector2.

**Objectives:**
- Create `Vector2` structure (x, y as floats)
- Create `Graph` class to plot points
- Display graph in ASCII art on console
- Apply proper encapsulation

**Compile and run:**
```bash
cd ex01
make
./graph
```

**Example output (points at 0/0, 2/2, 4/2, 2/4):**
```
>& 5 . . . . . .
>& 4 . . X . . .
>& 3 . . . . . .
>& 2 . . X . X .
>& 1 . . . . . .
>& 0 X . . . . .
>& 0 1 2 3 4 5
```

**Requirements:**
- ✅ Vector2 with encapsulated x and y
- ✅ Graph with size and list of points
- ✅ Add points to graph
- ✅ Display graph on console
- ✅ Justifiable encapsulation decisions

---

## Module00 Structure

```
Module00/
├── DivideAndRule.cpp       # Original code (without encapsulation)
├── en.subject.pdf          # Module subject
├── README.md               # This file
├── COMPARISON.md           # Before/after comparison
├── CHECKLIST.md            # Evaluation checklist
├── ex00/                   # Exercise 00: Bank
│   ├── inc/
│   │   ├── Account.hpp
│   │   └── Bank.hpp
│   ├── src/
│   │   ├── Account.cpp
│   │   ├── Bank.cpp
│   │   └── main.cpp
│   └── Makefile
└── ex01/                   # Exercise 01: Graph
    ├── inc/
    │   ├── Vector2.hpp
    │   └── Graph.hpp
    ├── src/
    │   ├── Vector2.cpp
    │   ├── Graph.cpp
    │   └── main.cpp
    └── Makefile
```

---

## Exercise Details

### Exercise 00: Divide and Conquer

#### Implemented Classes

**Account**
```cpp
class Account {
private:
    int _id;        // Unique ID
    int _value;     // Balance
    Account(int id); // Private constructor
    friend class Bank;
public:
    const int& getId() const;
    const int& getValue() const;
};
```

**Bank**
```cpp
class Bank {
private:
    int _liquidity;
    std::vector<Account*> _clientAccounts;
    int _nextAccountId;
public:
    Account* createAccount();
    void deleteAccount(int accountId);
    bool deposit(int accountId, int amount);    // 5% fee
    bool withdraw(int accountId, int amount);
    bool giveLoan(int accountId, int amount);
    const int& getLiquidity() const;
};
```

#### Encapsulation Decisions

1. **Account with private constructor**
   - Only Bank can create accounts
   - Ensures unique IDs

2. **Friend class**
   - Bank accesses Account's private members
   - Does not expose attributes publicly

3. **Getters by const reference**
   - Efficiency (no copies)
   - Safety (const prevents modification)

---

### Exercise 01: I don't know what I'm doing!

#### Implemented Classes

**Vector2**
```cpp
class Vector2 {
private:
    float _x;
    float _y;
public:
    Vector2(float x, float y);
    const float& getX() const;
    const float& getY() const;
    void setX(float x);
    void setY(float y);
};
```

**Graph**
```cpp
class Graph {
private:
    Vector2 _size;
    std::vector<Vector2> _points;
    bool _isPointValid(const Vector2& point) const;
public:
    Graph(float width, float height);
    bool addPoint(float x, float y);
    bool addPoint(const Vector2& point);
    void display() const;
    size_t getPointCount() const;
};
```

#### Encapsulation Decisions

1. **Vector2 with private attributes**
   - x and y cannot be modified directly
   - Setters allow validation if needed

2. **Graph with private list**
   - Points managed internally
   - Bounds validation when adding

3. **Public display() method**
   - Interface for visualization
   - Does not expose internal data

---

## Applied OOP Concepts

### 1. Encapsulation
- Private attributes
- Controlled access via getters/setters
- Validations in public methods

### 2. Friend Class
- Special relationship between classes
- Access to private members without public exposure

### 3. Const Correctness
- Const methods do not modify object
- Const references prevent modification

### 4. Business Rule Validation
- Deposits/withdrawals validated
- Points within graph bounds
- Loans limited by liquidity

---

## How to Evaluate

### Common Defense Questions

**Ex00:**
1. Why does Account have a private constructor?
2. What is friend class and when to use it?
3. Why getters by reference?
4. How to ensure unique IDs?
5. Why validate banking operations?

**Ex01:**
1. Why are x and y private?
2. How do you control point addition?
3. Why does Vector2 have setters but Account doesn't?
4. How does graph display work?
5. What encapsulation decisions did you make and why?

### Encapsulation Test

Try to access private attributes in main:
```cpp
account->_id = 999;      // ❌ Does not compile
vector._x = 100;         // ❌ Does not compile
graph._points.clear();   // ❌ Does not compile
```

If it doesn't compile = Encapsulation working! ✅

---

## Compilation

Both exercises follow the rules:
- Compiler: `c++`
- Flags: `-Wall -Wextra -Werror -std=c++98`
- Makefile with rules: `all`, `clean`, `fclean`, `re`
- No unnecessary relink
- No external libraries or Boost

