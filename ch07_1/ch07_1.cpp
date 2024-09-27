#include <iostream>
#include <map>
#include <string>

int main() {
    // Creating a map
    std::map<std::string, int> ages;

    // Inserting elements
    ages["Alice"] = 15;
    ages["Bob"] = 20;
    ages.insert({"Charlie", 25});

    // Accessing elements
    std::cout << "Alice's age: " << ages["Alice"] << std::endl;

    // Checking if a key exists
    if (ages.find("David") != ages.end()) {
        std::cout << "David's age found" << std::endl;
    } else {
        std::cout << "David not found" << std::endl;
    }

    // Iterating through the map
    for (const auto& pair : ages) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }

    // Removing an element
    ages.erase("Bob");

    // Getting the size
    std::cout << "Map size: " << ages.size() << std::endl;

    return 0;
}