#include <iostream>

void checkCharacterWithIfElse(char c) {
    if (c >= 'a' && c <= 'z') {
        std::cout << c << " is a lowercase letter.\n";
    } else if (c >= 'A' && c <= 'Z') {
        std::cout << c << " is an uppercase letter.\n";
    } else if (c >= '0' && c <= '9') {
        std::cout << c << " is a digit.\n";
    } else {
        std::cout << c << " is a special character.\n";
    }
}

void checkCharacterWithSwitch(char c) {
    switch (c) {
        case 'a' ... 'z':
            std::cout << c << " is a lowercase letter.\n";
            break;
        case 'A' ... 'Z':
            std::cout << c << " is an uppercase letter.\n";
            break;
        case '0' ... '9':
            std::cout << c << " is a digit.\n";
            break;
        default:
            std::cout << c << " is a special character.\n";
            break;
    }
}

int main() {
    char testChar;

    std::cout << "Enter a character: ";
    std::cin >> testChar;

    std::cout << "Using if/else:\n";
    checkCharacterWithIfElse(testChar);

    std::cout << "Using switch:\n";
    checkCharacterWithSwitch(testChar);

    return 0;
}