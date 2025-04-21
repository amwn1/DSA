#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to check if two strings are anagrams
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> map;

    // Count characters in s
    for (auto c : s) {
        map[c]++;
    }

    // Subtract characters using t
    for (auto c : t) {
        if (map.find(c) == map.end() || map[c] == 0) {
            return false;
        }
        map[c]--;
    }

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    bool result = isAnagram(s, t);

    if (result)
        cout << "Yes, the strings are anagrams." << endl;
    else
        cout << "No, the strings are not anagrams." << endl;

    return 0;
}
