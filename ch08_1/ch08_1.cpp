#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class SimpleJSON {
private:
    std::map<std::string, std::string> data;

public:
    void parse(const std::string& json_str) {
        std::istringstream iss(json_str);
        std::string line;
        while (std::getline(iss, line, ',')) {
            size_t colon_pos = line.find(':');
            if (colon_pos != std::string::npos) {
                std::string key = line.substr(0, colon_pos);
                std::string value = line.substr(colon_pos + 1);
                
                // Remove whitespace and quotes
                key.erase(0, key.find_first_not_of(" \t\n\r\f\v\""));
                key.erase(key.find_last_not_of(" \t\n\r\f\v\"") + 1);
                value.erase(0, value.find_first_not_of(" \t\n\r\f\v\""));
                value.erase(value.find_last_not_of(" \t\n\r\f\v\"") + 1);
                
                data[key] = value;
            }
        }
    }

    std::string serialize() const {
        std::ostringstream oss;
        oss << "{";
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it != data.begin()) oss << ", ";
            oss << "\"" << it->first << "\": \"" << it->second << "\"";
        }
        oss << "}";
        return oss.str();
    }

    std::string get(const std::string& key) const {
        auto it = data.find(key);
        if (it != data.end()) {
            return it->second;
        }
        return "";
    }

    void set(const std::string& key, const std::string& value) {
        data[key] = value;
    }
};

int main() {
    SimpleJSON json;

    // Writing JSON to a file
    json.set("name", "John Doe");
    json.set("age", "30");
    json.set("city", "New York");

    std::ofstream outFile("../person.json");
    if (outFile.is_open()) {
        outFile << json.serialize() << std::endl;
        outFile.close();
        std::cout << "Successfully wrote to the file." << std::endl;
    } else {
        std::cerr << "Unable to open file for writing." << std::endl;
    }

    // Reading JSON from a file
    std::ifstream inFile("../person.json");
    if (inFile.is_open()) {
        std::string json_str((std::istreambuf_iterator<char>(inFile)),
                              std::istreambuf_iterator<char>());
        inFile.close();

        SimpleJSON json_read;
        json_read.parse(json_str);

        // Accessing JSON data
        std::cout << "Name: " << json_read.get("name") << std::endl;
        std::cout << "Age: " << json_read.get("age") << std::endl;
        std::cout << "City: " << json_read.get("city") << std::endl;
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }

    return 0;
}