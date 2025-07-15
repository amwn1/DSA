#include <iostream>
#include <vector>
#include <algorithm>

// Problem: For each spell, count how many potions will make a "successful pair".
// A pair is successful if: spell[i] * potion[j] >= success

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells,
                                     std::vector<int>& potions,
                                     long long success) {
        // Step 1: Sort the potions so we can apply binary search efficiently
        std::sort(potions.begin(), potions.end());

        std::vector<int> ans;
        ans.reserve(spells.size());  // To avoid memory reallocation while pushing answers

        // Step 2: For each spell, use binary search to find the number of valid potions
        for (int i = 0; i < static_cast<int>(spells.size()); ++i) {
            int left = 0;
            int right = static_cast<int>(potions.size()) - 1;

            // If no potion is found, we want the default value to be the size of the array
            // so potions.size() - least = 0
            long long least = potions.size();

            // Binary search: find the first potion such that spell * potion >= success
            while (left <= right) {
                int mid = left + (right - left) / 2;

                // We use 1LL to ensure 64-bit multiplication (avoid overflow)
                long long total = 1LL * spells[i] * potions[mid];

                if (total < success) {
                    // This potion is too weak → move right
                    left = mid + 1;
                } else {
                    // This potion works → store this index and try to find an earlier one
                    least = mid;
                    right = mid - 1;
                }
            }

            // All potions from index `least` to end are valid
            int count = static_cast<int>(potions.size()) - static_cast<int>(least);
            ans.push_back(count);
        }

        return ans;
    }
};

int main() {
    // Example input
    std::vector<int> spells = {5, 1, 3};
    std::vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    // Create Solution object and call the method
    Solution solution;
    std::vector<int> result = solution.successfulPairs(spells, potions, success);

    // Output the result
    // For spells: [5, 1, 3]
    // Successful pairs:
    // 5 → [2,3,4,5] → 4
    // 1 → []        → 0
    // 3 → [3,4,5]   → 3
    for (int count : result) {
        std::cout << count << " ";
    }
    std::cout << std::endl;

    return 0;
}
