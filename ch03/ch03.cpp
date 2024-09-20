#include <iostream>

#define LOCAL_MACRO 3.14159

int main() {
    int i = 0;
    int j = 0;
    
    //post increment
    std::cout << i++ << "\n"; // Prints 0
    std::cout << i++ << "\n"; // Prints 1
    std::cout << i++ << "\n"; // Prints 2

    //pre increment
    std::cout << ++j << "\n"; // Prints 1
    std::cout << ++j << "\n"; // Prints 2
    std::cout << ++j << "\n"; // Prints 3
    return 0;
}