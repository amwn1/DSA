#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> successfulPairs(std::vector<int>& spells,
                                     std::vector<int>& potions,
                                     long long success) {
        std::sort(potions.begin(), potions.end());
        std::vector<int> ans;
        ans.reserve(spells.size());

        for (int i = 0; i < static_cast<int>(spells.size()); ++i) {
            int left = 0;
            int right = static_cast<int>(potions.size()) - 1;
            long long least = potions.size();

            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long total = 1LL * spells[i] * potions[mid];
                if (total < success) {
                    left = mid + 1;
                } else {
                    least = mid;
                    right = mid - 1;
                }
            }
            ans.push_back(static_cast<int>(potions.size()) - static_cast<int>(least));
        }
        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> spells = {5, 1, 3};
    std::vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    std::vector<int> result = solution.successfulPairs(spells, potions, success);

    for (int count : result) {
        std::cout << count << " ";
    }
    std::cout << std::endl;

    return 0;
}
