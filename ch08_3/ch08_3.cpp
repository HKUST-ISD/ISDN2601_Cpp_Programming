#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Person {
    std::string name;
    int age;
    float height;
};

// Function to write data to a text file
void writeToFile(const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    // Writing different data types
    outFile << "This is a sample text file." << std::endl;
    outFile << 42 << std::endl;  // integer
    outFile << 3.14159 << std::endl;  // float

    // Writing a vector of integers
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    outFile << numbers.size() << std::endl;  // Write the size first
    for (int num : numbers) {
        outFile << num << " ";
    }
    outFile << std::endl;

    // Writing a custom structure
    Person person = {"Alice", 30, 1.75f};
    outFile << person.name << std::endl;
    outFile << person.age << std::endl;
    outFile << person.height << std::endl;

    outFile.close();
    std::cout << "Data written to " << filename << std::endl;
}

// Function to read data from a text file
void readFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    std::string line;
    int intValue;
    float floatValue;
    std::vector<int> numbers;
    Person person;

    // Reading a string
    std::getline(inFile, line);
    std::cout << "Text: " << line << std::endl;

    // Reading an integer
    inFile >> intValue;
    std::cout << "Integer: " << intValue << std::endl;

    // Reading a float
    inFile >> floatValue;
    std::cout << "Float: " << floatValue << std::endl;

    // Reading a vector of integers
    int vectorSize;
    inFile >> vectorSize;
    numbers.resize(vectorSize);
    for (int i = 0; i < vectorSize; ++i) {
        inFile >> numbers[i];
    }
    std::cout << "Vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Reading a custom structure
    inFile >> std::ws;  // Consume any whitespace
    std::getline(inFile, person.name);
    inFile >> person.age >> person.height;
    std::cout << "Person: " << person.name << ", " << person.age << " years old, " 
              << person.height << "m tall" << std::endl;

    inFile.close();
}

int main() {
    const std::string filename = "../sample.txt";

    writeToFile(filename);
    std::cout << "\nReading data from file:\n";
    readFromFile(filename);

    return 0;
}