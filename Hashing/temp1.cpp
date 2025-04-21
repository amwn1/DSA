#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main() {
    // 1) Declare an unordered_map from string to int
    std::unordered_map<std::string, int> freq;

    // 2) Insert or update:
    freq["apple"] = 3;        // set freq["apple"] = 3
    freq["banana"] += 1;      // increment freq["banana"] (default 0 → 1)

    // 3) Access:
    std::cout << "apple: " << freq["apple"] << "\n";

    // 4) Check existence:
    if (freq.find("cherry") != freq.end()) {
        std::cout << "cherry exists\n";
    } else {
        std::cout << "cherry not found\n";
    }

    // 5) Iterate:
    for (auto &p : freq) {
        std::cout << p.first << " → " << p.second << "\n";
    }

    // // 6) Erase:
    // freq.erase("banana");

    // trying how to print out the values
    
}


