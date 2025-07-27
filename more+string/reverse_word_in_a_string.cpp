#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Function to reverse words in a string
string reverseWords(string s) {
    stringstream ss(s);           // Used for splitting the string into words
    string word;                  // Temporary variable to store each word
    vector<string> words;         // To store all words

    // Split the string into words and put them in the vector
    while (ss >> word) {
        words.push_back(word);
    }

    string res = "";              // To store the reversed sentence
    // Traverse the vector from the end to the beginning
    for (int i = words.size() - 1; i >= 0; i--) {
        res += words[i];
        if (i != 0) {             // Add space between words except after the last one
            res += " ";
        }
    }
    return res;
}

int main() {
    // Example input for testing
    string input = "  hello   world!  ";
    string reversed = reverseWords(input);
    cout << "Original: \"" << input << "\"" << endl;
    cout << "Reversed: \"" << reversed << "\"" << endl;
    return 0;
}
