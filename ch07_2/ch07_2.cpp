#include <iostream>
#include <map>
#include <string>
#include <utility>

class Person {
public:
    Person(std::string name, int age) : name_(std::move(name)), age_(age) {}
    
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        return os << p.name_ << " (age " << p.age_ << ")";
    }

private:
    std::string name_;
    int age_;
};

int main() {
    std::map<std::string, Person> people;

    // Function to insert or update
    auto insert_or_assign = [&people](const std::string& key, const Person& value) {
        auto it = people.find(key);
        if (it != people.end()) {
            it->second = value;
            return std::make_pair(it, false);
        } else {
            return people.insert(std::make_pair(key, value));
        }
    };

    // Initial insertion
    auto result1 = insert_or_assign("Eve", Person("Eve Taylor", 22));
    std::cout << "First insert_or_assign:\n";
    std::cout << "Inserted: " << (result1.second ? "Yes" : "No") << "\n";
    std::cout << "Element: " << result1.first->first << " -> " << result1.first->second << "\n\n";

    // Update existing key
    auto result2 = insert_or_assign("Eve", Person("Eve Johnson", 23));
    std::cout << "Second insert_or_assign:\n";
    std::cout << "Inserted: " << (result2.second ? "Yes" : "No") << "\n";
    std::cout << "Element: " << result2.first->first << " -> " << result2.first->second << "\n\n";

    // Insert new key
    auto result3 = insert_or_assign("Alice", Person("Alice Brown", 24));
    std::cout << "Third insert_or_assign:\n";
    std::cout << "Inserted: " << (result3.second ? "Yes" : "No") << "\n";
    std::cout << "Element: " << result3.first->first << " -> " << result3.first->second << "\n\n";

    // Print all elements
    std::cout << "Final map contents:\n";
    for (const auto& pair : people) {
        std::cout << pair.first << " -> " << pair.second << "\n";
    }

    return 0;
}