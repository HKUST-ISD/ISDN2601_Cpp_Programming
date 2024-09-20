#include <iostream>
#include "globals.h"

#define LOCAL_MACRO 3.14159

int main() {
    std::cout << "Global variable from another file: " << globalVar << std::endl;

    // Access LOCAL_MACRO defined in this file
    std::cout << "Local macro: " << LOCAL_MACRO << std::endl;

    // Uncommenting the following line would cause an error
    // std::cout << "Trying to access EXTERNAL_MACRO: " << EXTERNAL_MACRO << std::endl;

    return 0;
}