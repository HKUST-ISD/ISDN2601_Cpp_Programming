# C++ Tutorial for ISDN2601 - Exploring the World through Smart Mechatronics
## First to Know about C++
1. Developed in 1970’s by Bjarne Stroustrup
2. It is the fastest high level language: [How slow is Python really? \(Or how fast is your language?\)](https://codegolf.stackexchange.com/questions/26323/how-slow-is-python-really-or-how-fast-is-your-language)
3. Flexible, Compatible, General-purpose
4. Multi-paradigm:
   * Object - oriented
   * Functional
   * Procedural
   * Generic

## Main Areas of C++
- [x] C Language Syntax
- [x] Preprocessor
- [ ] Classes and Objects
- [ ] C++ Templates
- [ ] STL & Standard Libraries


## Variables
Code: [ch01](ch01/ch01.cpp)

```
// An integer
int a = -1;

// A non-negative integer
unsigned int b = 1;

// A real number (single-precision)
float d = 1.23f;

// A real number (double-precision)
double e = 2.7182818284590452353602874713527;

// A std::string (not a primitive type)
std::string s = "Hi, I am a string!";
```

1. Integer Types

| Type      | Default Dign    | Bits  | Range                                                        |
|-----------|-----------------|-------|--------------------------------------------------------------|
| bool      | Always Unsigned | 1     | 0, 1 (false, true)                                           |
| char      | Unsigned        | 8     | Unsigned: 0 .. 255,<br>Signed: -128 .. 277                   |
| short     | Signed          | 16    | Unsigned: 0 .. 65535,<br>Signed: -32768 .. 32767             |
| int       | Signed          | 32    | Unsigned: 0 .. 4294967295<br>Signed: -2147483648 .. 2147483647 |
| long      | Signed          | 32/64 | Unsigned: 0 ..  2^nBits <br>Signed: -2^(nBits - 1) .. 2^(nBits - 1) - 1 |
| long long | Signed          | 64    | Unsigned: 0 .. 2^64<br>Signed: -2^63 .. 2^63 - 1             |
| size_t    | Always Unsigned | 32/64 | Unsigned: 0 .. 2^nBits <br>Signed: -2^(nBits - 1) .. 2^(nBits - 1) - 1 |

2. Floating Point Types

| Type   | IEEE754Name      | Bits | Decimal (Base10) Precision | Range               |
|--------|------------------|------|----------------------------|---------------------|
| float  | Single Precision | 32   | 6- 9 digits                | -3.4e38 .. 3.4e38   |
| double | Double Precision | 64   | 15-17 digits               | -1.7e308 .. 1.7e308 |

## Global Variables and MACRO
Code: [ch02](ch02/ch02.cpp)
1. Definitions
* A **global variable** is a variable accessible from any function within the same file or across multiple files, depending on how it is declared.
* The **\#define directive** is used to create macros. These are essentially textual replacements performed by the preprocessor before actual compilation begins.

2. Comparison
Code: [ch02_2](ch02_2/ch02_2.cpp)

| Type               | Scope                  | Lifetime               | Initialisation                                            |
|--------------------|------------------------|------------------------|-----------------------------------------------------------|
| Global Variable    | program-wide           | Program Execution Time | Zero-initialisation                                       |
| \#define directive | file, or until \#undef | Preprocessor Lifetime  | Macros are not variables and don't require initialization |


## Operation: Post and Pre Increment
Code: [ch03](ch03/ch03.cpp)

```
//post increment
std::cout << i++ << "\n"; // Prints 0
std::cout << i++ << "\n"; // Prints 1
std::cout << i++ << "\n"; // Prints 2

//pre increment
std::cout << ++j << "\n"; // Prints 1
std::cout << ++j << "\n"; // Prints 2
std::cout << ++j << "\n"; // Prints 3
```

## Operation: Conditions
Code: [ch04](ch04/ch04.cpp)
1. If/Else: allows for complex conditions using logical operators, such as && (and), || (or), and ! (not).
2. Switch: compares a variable against a list of discrete values. Each case represents a potential match. If a match is found, the code for that case executes.

## Operations: Loop
Code: [ch05](ch05)
* For Loop: 
  * Combines initialization, condition, and increment in a single line. 
  * Useful when the number of iterations is known beforehand. 
* While Loop: 
  * Separates initialization, condition, and increment. 
  * More flexible, can be used when the number of iterations isn't known in advance.

## Serial Print
Code: [ch06](ch06/ch06.cpp)
