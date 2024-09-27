#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class CSV {
public:
    static void write(const std::string& filename, const std::vector<std::vector<std::string>>& data) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file for writing." << std::endl;
            return;
        }

        for (const auto& row : data) {
            for (size_t i = 0; i < row.size(); ++i) {
                file << row[i];
                if (i < row.size() - 1) file << ",";
            }
            file << "\n";
        }

        file.close();
    }

    static std::vector<std::vector<std::string>> read(const std::string& filename) {
        std::vector<std::vector<std::string>> data;
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file for reading." << std::endl;
            return data;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::vector<std::string> row;
            std::stringstream ss(line);
            std::string cell;
            while (std::getline(ss, cell, ',')) {
                row.push_back(cell);
            }
            data.push_back(row);
        }

        file.close();
        return data;
    }
};

int main() {
    // Writing CSV
    std::vector<std::vector<std::string>> writeData = {
        {"Name", "Age", "City"},
        {"John Doe", "30", "New York"},
        {"Jane Smith", "25", "Los Angeles"}
    };

    CSV::write("../output.csv", writeData);
    std::cout << "CSV file written successfully." << std::endl;

    // Reading CSV
    std::vector<std::vector<std::string>> readData = CSV::read("../output.csv");

    std::cout << "CSV file contents:" << std::endl;
    for (const auto& row : readData) {
        for (const auto& cell : row) {
            std::cout << cell << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}