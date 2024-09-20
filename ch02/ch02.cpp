#include <iostream>

// Global variable
int globalVar = 10;

// Define constant
#define PI 3.14159

void demonstrateScope() {
    // Local variable
    int localVar = 5;

    std::cout << "Inside function:" << std::endl;
    std::cout << "Local variable: " << localVar << std::endl;
    std::cout << "Global variable: " << globalVar << std::endl;
    std::cout << "Defined constant (PI): " << PI << std::endl;
}

int main() {
    // Local variable
    int localVar = 20;
    
    std::cout << "Inside main:" << std::endl;
    std::cout << "Local variable: " << localVar << std::endl;
    std::cout << "Global variable: " << globalVar << std::endl;
    std::cout << "Defined constant (PI): " << PI << std::endl;
    std::cout << std::endl;

    demonstrateScope();

    return 0;
}