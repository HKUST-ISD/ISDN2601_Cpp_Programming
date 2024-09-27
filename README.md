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
  
## Always a Good Reading/Watching
1. [Arduino Tutorial for Beginners 2023](https://youtube.com/playlist?list=PLwWF-ICTWmB7-b9bsE3UcQzz-7ipI5tbR&si=vuufTEWZWUoGdkGX)
2. [https://youtube.com/playlist?list=PLv5bCJpKDWIazJBFmeTLXOJ6CwLAxvVGY&si=NNDlufr43CF4f1Df](https://youtube.com/playlist?list=PLv5bCJpKDWIazJBFmeTLXOJ6CwLAxvVGY&si=NNDlufr43CF4f1Df).
3. [C++ Primer 5th Edition](https://julac-hkust.primo.exlibrisgroup.com/discovery/fulldisplay?docid=alma991012883470003412&context=L&vid=852JULAC_HKUST:HKUST&lang=en&search_scope=HKUST_catalog_primo&adaptor=Local%20Search%20Engine&tab=Everything&query=any,contains,c%2B%2B%20primer%205th%20edition), and [its source code](https://github.com/Mooophy/Cpp-Primer).

## Main Areas of C++
- [x] C Language Syntax
- [x] Preprocessor
- [x] I/O
- [ ] Classes and Objects
- [x] Array and Set
- [x] Map/Dictionary
- [x] C++ Templates
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
| \#define derective | file, or until \#undef | Preprocessor Lifetime  | Macros are not variables and don't require initialization |


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

## C++ Map
1. The C++ map is an associative container that stores key-value pairs in a sorted order, allowing for efficient lookup, insertion, and deletion of elements based on their unique keys. It is the C++ format of Dictionary (e.g. Java, Python). It is implemented as a balanced binary search tree (typically a red-black tree), providing logarithmic time complexity for most operations and maintaining elements in a sorted order according to their keys.
2. Code: 
   * [ch07_1](ch07_1): Basic operations of C++ Map.
   * [ch07_2](ch07_2): Different ways to insert/update values.
   * [ch07_3](ch07_3): Different ways to retrieve values, and compare the runtimes among them.

## Array and Set
1. Shared Features:
   * Both are containers for storing elements
   * Both can be iterated over
   * Both have methods to check their size
   * Both can be cleared of all elements

2. Array Unique Features
   * Fixed size (for C-style arrays) or dynamic size (for std::array or std::vector)
   * Elements are stored in contiguous memory
   * Allows duplicate elements
   * Elements are accessed by index
   * Maintains insertion order

3. Set Unique Features
   * Dynamic size
   * Elements are unique (no duplicates allowed)
   * Elements are sorted automatically
   * Faster search operations (logarithmic time complexity)
   * No direct index access

4. Code Sample: Array
```
#include <iostream>
#include <array>

int main() {
    // Declare and initialize an array
    std::array<int, 5> myArray = {1, 2, 3, 4, 5};
    
    // Access elements
    std::cout << "First element: " << myArray[0] << std::endl;
    
    // Iterate over array
    for (int num : myArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Get size
    std::cout << "Array size: " << myArray.size() << std::endl;
    
    return 0;
}
```

5. Code Sample: Set
```
#include <iostream>
#include <set>

int main() {
    // Declare and initialize a set
    std::set<int> mySet = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    
    // Insert elements
    mySet.insert(7);
    
    // Iterate over set
    for (int num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // Check if element exists
    if (mySet.find(5) != mySet.end()) {
        std::cout << "5 is in the set" << std::endl;
    }
    
    // Get size
    std::cout << "Set size: " << mySet.size() << std::endl;
    
    return 0;
}
```


6. Code Sample: Dynamic Array (Vector)
```
#include <iostream>
#include <vector>
#include <set>

int main() {
    // Create a set
    std::set<int> mySet = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // Convert set to vector
    std::vector<int> myVector(mySet.begin(), mySet.end());

    // Print the vector
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
  ```

7. Transfer between Array and Set
* Array to set

```
#include <iostream>
#include <array>
#include <set>

int main() {
    // Create an array
    std::array<int, 5> myArray = {3, 1, 4, 1, 5};

    // Convert array to set
    std::set<int> mySet(myArray.begin(), myArray.end());

    // Print the set
    for (int num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

* Set to Array

```
#include <iostream>
#include <array>
#include <set>
#include <algorithm>

int main() {
    // Create a set
    std::set<int> mySet = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    // Convert set to array
    std::array<int, 7> myArray;
    std::copy_n(mySet.begin(), myArray.size(), myArray.begin());

    // Print the array
    for (int num : myArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## C++ Template
1. Sample code: [ch09](ch09)
2. Contents included:
   * Function Template: Think of a function template as a recipe for making functions. Instead of writing separate functions for different types (like int, float, string), you write one general function that can work with many types. The computer figures out which type to use when you actually use the function. Example: Our add function can add numbers or combine strings, using the same code.
   * Class Template: A class template is like a blueprint for making classes. You create a general design for a class, and when you use it, you specify what type of data it should work with. It's like having a adjustable container that can hold different types of items. Example: Our Box class can store any type of item, whether it's a number, a string, or something else.
   * Template with multiple parameters: This is when you use more than one type in your template. It's like having a recipe that can use different ingredients in different parts of the dish. Example: Our Pair class can hold two items of different types, like a number and a string together.
   * Template specialization: Sometimes you want your template to behave differently for a specific type. Template specialization lets you create a custom version of your template for that particular type. It's like having a general rule, but making an exception for a special case. Example: We made a special version of our Box class just for characters (char). This special version can do something extra - print the character in uppercase.

## C++ I/O
1. File I/O
```
#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Writing to a file
    std::ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << "Hello, File I/O!" << std::endl;
        outFile << "This is a sample text." << std::endl;
        outFile.close();
        std::cout << "Successfully wrote to the file." << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }

    // Reading from a file
    std::ifstream inFile("example.txt");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::cout << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }

    return 0;
}
```

2. JSON File I/O Sample: [ch08_1](ch08_1)
3. TXT File I/O Sample: [ch08_3](ch08_3)
4. CSV File I/O Sample: [ch08_2](ch08_2)
5. Argument I/O and Parsing
```
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <argument1> [argument2] ..." << std::endl;
        return 1;
    }

    std::cout << "Number of arguments: " << argc - 1 << std::endl;
    std::cout << "Arguments:" << std::endl;

    for (int i = 1; i < argc; ++i) {
        std::cout << i << ": " << argv[i] << std::endl;
    }

    return 0;
}
```

3. Network I/O
   For network I/O, we'll use the [Boost.Asio library](https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio.html), which provides a powerful and flexible networking API. First, make sure you have Boost installed. Here's a simple TCP client example:
```
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("example.com", "80");

        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        boost::asio::streambuf request;
        std::ostream request_stream(&request);
        request_stream << "GET / HTTP/1.0\r\n";
        request_stream << "Host: example.com\r\n";
        request_stream << "Accept: */*\r\n";
        request_stream << "Connection: close\r\n\r\n";

        boost::asio::write(socket, request);

        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");

        std::istream response_stream(&response);
        std::string http_version;
        response_stream >> http_version;
        unsigned int status_code;
        response_stream >> status_code;
        std::string status_message;
        std::getline(response_stream, status_message);

        std::cout << "HTTP version: " << http_version << std::endl;
        std::cout << "Status code: " << status_code << std::endl;
        std::cout << "Status message: " << status_message << std::endl;

        boost::asio::read_until(socket, response, "\r\n\r\n");

        std::string header;
        while (std::getline(response_stream, header) && header != "\r")
            std::cout << header << std::endl;

        std::cout << std::endl;

        if (response.size() > 0)
            std::cout << &response;

        while (boost::asio::read(socket, response, boost::asio::transfer_at_least(1), ec)) {
            std::cout << &response;
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
```
