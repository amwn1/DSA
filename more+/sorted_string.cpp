#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Leetcode Problem 1859: Sorting the Sentence
// Given a shuffled sentence with words ending in a digit (indicating their position), 
// reconstruct the original sentence.

class Solution {
public:
    string sortSentence(string s) {
        string ans;                   // Final reconstructed sentence
        vector<string> temp(10);      // Temporary storage for up to 9 words (1-9 indexing)
        string word;                  // To accumulate characters for each word

        for(int i = 0 ; i < s.length() ; i++) {
            if(isdigit(s[i])) {
                // When we find a digit, it means end of the current word
                // s[i] - '0' converts char digit to integer (e.g., '2' -> 2)
                temp[s[i] - '0'] = word + " ";  // Store the word at its correct index
                word = "";                      // Reset word accumulator
                i++;                            // Skip the space after the number
            } else {
                word += s[i];                   // Accumulate characters of the current word
            }
        }

        // Construct the final sentence by concatenating words in order
        for(auto a : temp) {
            ans += a; // Empty strings are skipped implicitly
        }

        ans.pop_back(); // Remove the trailing space at the end
        return ans;
    }
};

int main() {
    string s = "is2 sentence4 This1 a3";
    Solution sol;

    cout << "Original Sentence: " << s << endl;
    cout << "The final answer: " << sol.sortSentence(s) << endl;

    return 0;
}
