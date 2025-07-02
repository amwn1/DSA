/*
 * Problem: 3304. Find the K-th Character in String Game I
 * Link:    https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/
 *
 * Description:
 *   Start with the string "a".  To build the next layer, take the current
 *   string and append a copy where every character has been shifted +1
 *   in the alphabet (wrapping 'z' → 'a').  Repeat until the string length
 *   ≥ k, then return the k-th character (1-based).
 */

#include <iostream>
#include <string>

class Solution {
public:
    // Holds the entire built-up string
    std::string result = "a";
    // The last layer we appended (starts as "a")
    std::string hold   = "a";

    // Builds up `result` until it has at least k characters, then returns result[k-1].
    char kthCharacter(int k) {
        while (k > static_cast<int>(result.size())) {
            // Generate the next layer by shifting each char in `hold`
            for (size_t i = 0; i < hold.size(); ++i) {
                char curr = hold[i];
                char next = (curr == 'z') ? 'a' : static_cast<char>(curr + 1);
                result.push_back(next);
            }
            // Now the new "hold" is the full result so far
            hold = result;
        }
        return result[k - 1];
    }
};

int main() {
    Solution sol;
    int k;
    std::cout << "Enter k (positive integer): ";
    if (!(std::cin >> k) || k <= 0) {
        std::cerr << "Invalid input. Please enter a positive integer.\n";
        return 1;
    }

    char answer = sol.kthCharacter(k);
    std::cout << "The " << k << "-th character is: " << answer << "\n";
    return 0;
}
