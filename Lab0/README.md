# Lab 0 – String Operations in C

## 📌 Objective
The objective of this lab is to understand and implement basic **string manipulation operations in C** using:
- Built-in string functions
- Manual logic without using built-in functions

This lab strengthens fundamentals such as array handling, loops, conditionals, and character-level operations in C.

---

## 📂 Folder Structure

Lab0/<br>
├── README.md<br>
├── String Reverser.c<br>
├── String Length.c<br>
├── String Comparison.c<br>
├── String Reverser.exe (ignored in GitHub)<br>
├── String Length.exe (ignored in GitHub)<br>
└── String Comparison.exe (ignored in GitHub)<br>

> **Note:** Executable (`.exe`) files are generated during compilation and are not pushed to GitHub.

---

## 🧪 Programs Included

### 1️⃣ String Reverser

**File:** `String Reverser.c`

**Description:**
- Reverses a given string using:
  - Built-in function approach (`strlen`)
  - Manual logic without using any string functions
- Demonstrates character swapping and index-based reversal.

**Concepts Used:**
- Character arrays
- `strlen()` (built-in)
- Loop-based reversal logic
- Temporary variable swapping

**Sample Input:**
KamaleshSP<br>

**Sample Output:**
Enter string: KamaleshSP<br>
String Reverse with build-in function...<br>
Reversed string: PShselamaK<br>
String Reverse without build-in function...<br>
Reversed string: PShselamaK<br>

---

### 2️⃣ String Length

**File:** `String Length.c`

**Description:**
- Calculates the length of a string using:
  - Built-in function (`strlen`)
  - Manual counting until null character (`'\0'`)

**Concepts Used:**
- Null-terminated strings
- Loop traversal
- Difference between logical length and memory size

**Sample Input:**
KamaleshSP<br>

**Sample Output:**
Enter string: KamaleshSP<br>
Length of string with build-in function: 10<br>
Length of string without build-in function: 10<br>

---

### 3️⃣ String Comparison

**File:** `String Comparison.c`

**Description:**
- Compares two strings using:
  - Built-in function (`strcmp`)
  - Manual character-by-character comparison
- Determines whether the strings are equal or not.

**Concepts Used:**
- String comparison logic
- Conditional statements
- Loop-based validation

**Sample Input1:**
KamaleshSP<br>
KamaleshSP<br>

**Sample Output1:**
Enter first string: KamaleshSP<br>
Enter second string: KamaleshSP<br>
Comparing strings with build-in function...<br>
Strings are equal<br>
Comparing strings without build-in function...<br>
Strings are equal<br>

**Sample Input2:**
KamaleshSP<br>
kamaleshsp<br>

**Sample Output2:**
Enter first string: KamaleshSP<br>
Enter second string: kamaleshsp<br>
Comparing strings with build-in function...<br>
Strings are not equal<br>
Comparing strings without build-in function...<br>
Strings are not equal<br>

---

## ⚙️ How to Compile and Run

Use a C compiler like **GCC**.<br>

### Compile
gcc String\ Reverser.c -o StringReverser<br>
gcc String\ Length.c -o StringLength<br>
gcc String\ Comparison.c -o StringComparison<br>

### Run
./StringReverser<br>
./StringLength<br>
./StringComparison<br>

> (On Windows, replace ./ with the executable name.)<br>

---

### 📚 Learning Outcomes
After completing this lab, you will be able to:
- Understand string storage in C
- Differentiate between built-in functions and manual logic
- Implement basic string operations confidently
- Write clean, modular, and readable C programs

---

### 🧑‍💻 Author
**Name:** Kamalesh S P<br>
**Course:** Compiler Design<br>
**Lab:** Lab 0 – String Operations<br>