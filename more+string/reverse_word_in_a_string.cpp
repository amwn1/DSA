#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// LeetCode-style Solution class
class Solution {
public:
    // Function to reverse the order of words in a given string
    string reverseWords(string s) {
        stringstream ss(s);    // String stream to split string by whitespace
        string word;
        vector<string> words;  // Vector to store each word

        // Extract words from the input string
        while (ss >> word) {
            words.push_back(word); // Add each word to the vector
        }

        string res = ""; // Resultant reversed sentence

        // Loop through the vector in reverse order
        for (int i = words.size() - 1; i >= 0; i--) {
            res += words[i]; // Add the word

            // Add a space between words, but not after the last word
            if (i != 0) {
                res += " ";
            }
        }
        return res;
    }
};

// Main function for local testing
int main() {
    Solution solution; // Create an object of Solution class

    // Test input: you can change this input to test other strings
    string input = "  hello   world!  ";
    string result = solution.reverseWords(input); // Call the function

    // Output the results
    cout << "Original: \"" << input << "\"" << endl;
    cout << "Reversed: \"" << result << "\"" << endl;

    // More test cases (optional)
    cout << "Test 2: \"" << solution.reverseWords("this is a test") << "\"" << endl;
    cout << "Test 3: \"" << solution.reverseWords("  quick  brown fox  ") << "\"" << endl;

    return 0;
}
