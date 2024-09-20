#include <iostream>

int main() {
    // Using a for loop
    std::cout << "Using a for loop:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Using a while loop
    int number;
    std::cout << "Enter a positive number: ";
    std::cin >> number;
    while (number > 0) {
        std::cout << number << std::endl;
        --number;
    }
    std::cout << "Reached zero!" << std::endl;

    return 0;
}