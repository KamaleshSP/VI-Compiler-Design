# Lab 1 – Lexical Analyzer in C

## Objective
The objective of this lab is to design and implement a **basic lexical analyzer in C** that scans an input expression and identifies different types of tokens such as:
- Keywords
- Identifiers
- Operators
- Integers
- Delimiters

This lab introduces the **first phase of compiler design – Lexical Analysis**.

---

## Folder Structure

Lab1/<br>
├── README.md<br>
├── Lex.c<br>
└── Lex.exe (ignored in GitHub)<br>

> **Note:** Executable (`.exe`) files are generated during compilation and are not pushed to GitHub.

---

## Program Included

### Lexical Analyzer

**File:** `Lex.c`

**Description:**
- Accepts an arithmetic or programming expression as input at runtime
- Breaks the input into meaningful tokens
- Classifies tokens into keywords, identifiers, operators, integers, and delimiters

**Token Types Identified:**
- **Keyword** (e.g., `int`, `if`, `while`)
- **Identifier** (variable names)
- **Operator** (`+`, `-`, `*`, `/`, `=`, `<`, `>`)
- **Integer constants**
- **Unidentified tokens**

---

## Concepts Used
- Lexical analysis fundamentals
- Tokenization
- Character classification
- String processing
- Conditional logic
- Functions and modular programming

---

## How to Compile and Run

Use a C compiler like **GCC**.<br>

### Compile
gcc Lex.c -o Lex<br>

### Run
./Lex<br>

> (On Windows, use Lex.exe)<br>

---

### Sample Input
int x = a + 30<br>

### Sample Output
Token: Keyword, Value: int<br>
Token: Identifier, Value: x<br>
Token: Operator, Value: =<br>
Token: Identifier, Value: a<br>
Token: Operator, Value: +<br>
Token: Integer, Value: 30<br>

---

### Learning Outcomes

After completing this lab, you will be able to:
- Understand the role of lexical analysis in compiler design
- Identify and classify tokens from source code
- Implement a basic lexer using C
- Apply string handling and character validation techniques

---

### Author

**Name:** Kamalesh S P<br>
**Course:** Compiler Design<br>
**Lab:** Lab 1 – Lexical Analyzer<br>