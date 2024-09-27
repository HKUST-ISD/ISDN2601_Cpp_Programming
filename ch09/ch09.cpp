#include <iostream>
#include <string>
#include <vector>

// 1. Function Template
template <typename T>
T add(T a, T b) {
    return a + b;
}

// 2. Class Template
template <typename T>
class Box {
private:
    T content;

public:
    Box(T item) : content(item) {}
    T getContent() { return content; }
    void setContent(T item) { content = item; }
};

// 3. Template with multiple parameters
template <typename T, typename U>
class Pair {
private:
    T first;
    U second;

public:
    Pair(T f, U s) : first(f), second(s) {}
    T getFirst() { return first; }
    U getSecond() { return second; }
};

// 4. Template specialization
template <>
class Box<char> {
private:
    char content;

public:
    Box(char item) : content(item) {}
    char getContent() { return content; }
    void setContent(char item) { content = item; }
    void printUpperCase() { std::cout << static_cast<char>(std::toupper(content)) << std::endl; }
};

int main() {
    // Using function template
    std::cout << "Function template examples:" << std::endl;
    std::cout << "add(5, 3) = " << add(5, 3) << std::endl;
    std::cout << "add(3.14, 2.86) = " << add(3.14, 2.86) << std::endl;
    std::cout << "add(std::string(\"Hello, \"), std::string(\"World!\")) = " 
              << add(std::string("Hello, "), std::string("World!")) << std::endl;

    // Using class template
    std::cout << "\nClass template examples:" << std::endl;
    Box<int> intBox(42);
    std::cout << "intBox content: " << intBox.getContent() << std::endl;

    Box<std::string> stringBox("Hello, Templates!");
    std::cout << "stringBox content: " << stringBox.getContent() << std::endl;

    // Using template with multiple parameters
    std::cout << "\nTemplate with multiple parameters example:" << std::endl;
    Pair<int, std::string> pair(10, "Ten");
    std::cout << "Pair: (" << pair.getFirst() << ", " << pair.getSecond() << ")" << std::endl;

    // Using template specialization
    std::cout << "\nTemplate specialization example:" << std::endl;
    Box<char> charBox('a');
    std::cout << "charBox content: " << charBox.getContent() << std::endl;
    std::cout << "charBox content in uppercase: ";
    charBox.printUpperCase();

    // Using templates with STL containers
    std::cout << "\nTemplates with STL containers:" << std::endl;
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Vector contents: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}