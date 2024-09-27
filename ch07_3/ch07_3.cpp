#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <vector>
#include <iomanip>
#include <algorithm>

class Person {
public:
    Person() = default;
    Person(std::string name, int age) : name_(std::move(name)), age_(age) {}
    
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        return os << p.name_ << " (age " << p.age_ << ")";
    }

private:
    std::string name_;
    int age_;
};

// Function to measure execution time
template<typename Func>
long long measureTime(Func func, int iterations) {
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        func();
    }
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}

int main() {
    std::map<std::string, Person> people;
    const int MAP_SIZE = 10000;
    const int ITERATIONS = 1000000;

    // Populate the map
    for (int i = 0; i < MAP_SIZE; ++i) {
        people["Person" + std::to_string(i)] = Person("Name" + std::to_string(i), i);
    }

    std::vector<std::pair<std::string, long long>> results;

    // 1. Using operator[]
    results.push_back(std::make_pair("operator[]", measureTime([&]() {
        volatile auto p = people["Person5000"];
    }, ITERATIONS)));

    // 2. Using at() method
    results.push_back(std::make_pair("at()", measureTime([&]() {
        volatile auto p = people.at("Person5000");
    }, ITERATIONS)));

    // 3. Using find() method
    results.push_back(std::make_pair("find()", measureTime([&]() {
        volatile auto it = people.find("Person5000");
    }, ITERATIONS)));

    // 4. Using count() to check existence before retrieving
    results.push_back(std::make_pair("count() + operator[]", measureTime([&]() {
        if (people.count("Person5000") > 0) {
            volatile auto p = people["Person5000"];
        }
    }, ITERATIONS)));

    // 5. Using lower_bound()
    results.push_back(std::make_pair("lower_bound()", measureTime([&]() {
        volatile auto lb = people.lower_bound("Person5000");
    }, ITERATIONS)));

    // Sort results by execution time
    std::sort(results.begin(), results.end(), 
              [](const std::pair<std::string, long long>& a, const std::pair<std::string, long long>& b) {
                  return a.second < b.second;
              });

    // Print results
    std::cout << std::left << std::setw(20) << "Method" 
              << std::right << std::setw(15) << "Time (nanoseconds)" 
              << std::setw(15) << "Relative" << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    for (const auto& result : results) {
        double relative = static_cast<double>(result.second) / results[0].second;
        std::cout << std::left << std::setw(20) << result.first 
                  << std::right << std::setw(15) << result.second 
                  << std::setw(15) << std::fixed << std::setprecision(2) << relative << std::endl;
    }

    return 0;
}