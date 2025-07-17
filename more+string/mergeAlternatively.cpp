#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
LeetCode Problem: Merge Strings Alternately
-------------------------------------------
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, 
starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"

Constraints:
- 1 <= word1.length, word2.length <= 100
- word1 and word2 consist of lowercase English letters.
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        // Get the size of each word
        int sizeWord1 = word1.size();
        int sizeWord2 = word2.size();

        // Find the minimum length to know how many characters can be alternated safely
        int minSize = min(sizeWord1, sizeWord2);

        // Merge characters from both strings alternately up to the length of the shorter word
        for (int i = 0; i < minSize; i++) {
            ans.push_back(word1[i]); // Add from word1
            ans.push_back(word2[i]); // Add from word2
        }

        // If word1 is longer, append the remaining characters from word1
        if (sizeWord1 > sizeWord2) {
            for (int i = minSize; i < sizeWord1; i++) {
                ans.push_back(word1[i]);
            }
        }
        // If word2 is longer, append the remaining characters from word2
        else {
            for (int i = minSize; i < sizeWord2; i++) {
                ans.push_back(word2[i]);
            }
        }

        return ans;
    }
};

int main() {
    // Input two strings from user
    string word1, word2;
    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;

    Solution sol;

    // Call the mergeAlternately function and output result
    string result = sol.mergeAlternately(word1, word2);
    cout << "Merged string: " << result << endl;

    return 0;
}
