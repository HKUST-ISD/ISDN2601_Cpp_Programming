#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

template<typename T>
void printTypeInfo(const string& typeName, T min, T max) {
    cout << typeName << ":\n"
         << "  Min: " << min << "\n"
         << "  Max: " << max << "\n\n";
}

void printAllTypesInfo() {
    cout << fixed << setprecision(0);

    printTypeInfo<int>("int", numeric_limits<int>::min(), numeric_limits<int>::max());
    printTypeInfo<unsigned int>("unsigned int", numeric_limits<unsigned int>::min(), numeric_limits<unsigned int>::max());
    printTypeInfo<float>("float", numeric_limits<float>::lowest(), numeric_limits<float>::max());
    printTypeInfo<double>("double", numeric_limits<double>::lowest(), numeric_limits<double>::max());

    cout << "string:\n"
         << "  Min/Max: N/A (determined by available memory)\n\n";
}

int main(int argc, const char * argv[])
{
    // An integer
    int a = -1;

    // A non-negative integer
    unsigned int b = 1;

    // A real number (single-precision)
    float d = 1.23f;

    // A real number (double-precision)
    double e = 2.7182818284590452353602874713527;

    // A std::string (not a primitive type)
    std::string s = "Hi, I am a string!";

    // Output all variables in one line
    cout << "Variables:\n"
         << "a=" << a << " b=" << b << " d=" << d << " e=" << e << " s=\"" << s << "\"\n\n";

    // Print max and min values for each type
    cout << "Max and Min values for each type:\n";
    printAllTypesInfo();

    return 0;
}